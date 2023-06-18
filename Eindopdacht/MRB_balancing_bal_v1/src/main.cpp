#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "Adafruit_VL6180X.h"
#include "Adafruit_VL53L0X.h"
#include <Servo.h>


// ========== initialisatie ==========
Servo servo;

// #define SEN_KORT_ADDRESS 0x31
#define SEN_LANG_ADDRESS 0x32

// set the pins to shutdown
#define SHT_SEN_KORT GPIO_NUM_4
#define SHT_SEN_LANG GPIO_NUM_2

// pin voor reset knop van de I
#define RESET_KI GPIO_NUM_18

// lange en korte afstandsensor
Adafruit_VL6180X sensor_kort = Adafruit_VL6180X();
Adafruit_VL53L0X sensor_lang = Adafruit_VL53L0X();

// this holds the measurement voor de lange afstand sensor
VL53L0X_RangingMeasurementData_t measurements_lang;



// ========== variablelen ==========
static const int servoPin = 5;

// the number of the motor pin
const int motorPinOnder = 17;  // 17 corresponds to GPIO17
const int motorPinBoven = 5;

// setting PWM properties
const int freq = 5000;
const int ChannelMotorPinOnder = 0;
const int ChannelMotorPinBoven = 1;
const int resolution = 8;

// Potentiometer pin 
const int potPin = 15;

// vatiablen voor PID reken waardes
int setPoint = 150;
int error = 0;
int error_sum = 0;
int error_div = 0;
int error_prev = 0;
float stuuractie = 0;

// PID weging instellingen
const float kp = 0.003;
const float ki = 0.0002;
const float kd = 0.011;
const float dt = 0.1;

// variablen voor het opslaan van gemeten waarden
const int moving_average_count = 20;
int average = 0;
int array_index = 0;
int distance[moving_average_count] = {};



// ========== funkties ==========
int exponentieel_moving_average(int inputArray[moving_average_count]){
  double ema = inputArray[array_index];
  if(array_index == 0){
    for (int i = 1; i < moving_average_count; i++){
      ema = (inputArray[i] + ema) / 2.0;
    }
  } else {
    if(array_index != moving_average_count-1){
      for (int i = array_index+1; i < moving_average_count; ++i) {
        ema = (inputArray[i] + ema) / 2.0;
      }
    }
    for (int i = 0; i < array_index; ++i) {
      ema = (inputArray[i] + ema) / 2.0;
    }
  }
  return ema;
}

int moving_average(int array[moving_average_count]){
  int totaal = 0;
  for (int i = 0; i < moving_average_count; i++) {
    totaal += array[i];
  }
  return totaal/moving_average_count;
}

void set_servo(float stuuractie) {
  int degrees = 90;
  if (stuuractie > 0.05)
  {
    if (stuuractie > 1)
    {
      stuuractie = 1;
    }
    degrees -= (asin((35 * stuuractie)/35)) * (180.0/3.141592653);
  }
  else if (stuuractie < -0.05)
  {
    if (stuuractie < -1){
      stuuractie = -1;
    }
    degrees += (asin((35 * -stuuractie)/35)) * (180.0/3.141592653);
  }
  servo.write(degrees);
}

// ========== setUp ==========
void setup() {
  Serial.begin(921600);
  while (! Serial) {
    delay(1);
  }
 
  if(!servo.attach(servoPin)) {
      Serial.print("Servo error");
  }

  pinMode (RESET_KI, INPUT);

  // sensoren initialiseren door een van de twee een nieuw addres te geven aangezien ze beide standaart dezelfde hebben
  // je kunt de chip een nieuw addre geven door even uit te schakelen en dan te starten met zijn nieuwe addres
  pinMode(SHT_SEN_KORT, OUTPUT);
  pinMode(SHT_SEN_LANG, OUTPUT);

  digitalWrite(SHT_SEN_KORT, LOW);
  digitalWrite(SHT_SEN_LANG, LOW);
  delay(10);
  digitalWrite(SHT_SEN_KORT, HIGH);
  digitalWrite(SHT_SEN_LANG, HIGH);
  delay(10);

  digitalWrite(SHT_SEN_KORT, LOW);
  digitalWrite(SHT_SEN_LANG, HIGH);
  delay(10);
  Serial.println("Adafruit VL53L0X test");
  if (!sensor_lang.begin(SEN_LANG_ADDRESS)) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  Serial.println(F("Sensor VL53L0X found!")); 


  digitalWrite(SHT_SEN_KORT, HIGH);
  delay(10);
  Serial.println("\nAdafruit VL6180x test!");
  if (! sensor_kort.begin()) {
    Serial.println("Failed to boot VL6180X");
    while (1);
  }
  Serial.println("Sensor VL6180X found!");
}


// ========== loop ==========
void loop() {
  // haalt het nieuwe setpoint op uit de aangesloten potmeter
  setPoint = 270.0 - (240.0 / 4095.0 * analogRead(potPin));

  // leest de lange afstandsensor uit, kijkt of die waarde geldig is en zo ja slaat hem op
  // wameer de waarde onder de 10cm is gebruikt die ook de korte afstand sensor om precies te kunnen zien waar in dat 0 tot 10 cm gebeid die zit
  sensor_lang.rangingTest(&measurements_lang, false);
  if (measurements_lang.RangeStatus != 4) {
    int result = measurements_lang.RangeMilliMeter;
    distance[array_index] = int((result - 23) - (result/50*4));

    if (distance[array_index] <= 100){
        uint8_t range = sensor_kort.readRange();
        uint8_t status = sensor_kort.readRangeStatus();
        if (status == VL6180X_ERROR_NONE) {
          if(range > 90){
            distance[array_index] = ((range + 5) + distance[array_index]) / 2;
          } else {
            distance[array_index] = range+5;
          }
        }
    }

    // verplaats de index naar de plek waard de oudste meedwaarde staat zodat die de volgede loop word vervangen
    if (array_index >= moving_average_count-1) {
      array_index = 0;
    }
    else{ 
      array_index += 1;
    }

    // kijk of de reset_KI knop is ingedrukt en of de waardes te hoog worden, als dat zo is brengt die i terug naar 0
    if (digitalRead(RESET_KI) or error_sum > 1200 or error_sum < -1200)
    {
      error_sum = 0;
    }

    // de berekeningen van de PID systeem
    error = setPoint - ((moving_average(distance) + exponentieel_moving_average(distance)) /2 );
    error_sum += error;
    error_div = (error - error_prev) / dt;
    stuuractie = kp * error + ki * error_sum + kd * error_div;
    error_prev = error;

    // de stuuractie word in de funktie set_servo omgezet naar een graad en de servo word in die graad gezet
    set_servo(stuuractie);
  }
}


