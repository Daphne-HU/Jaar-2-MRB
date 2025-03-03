// #include <Arduino.h>
// #include <SPI.h>
// #include <Wire.h>
// #include "Adafruit_VL6180X.h"
// #include "Adafruit_VL53L0X.h"





// // static const int servosPins[5] = {4, 16, 18, 19, 21};
// static const int servoPin = 5;

// Servo servo;

// void setServo(int degrees) {
//   // servo.write((degrees + (35 * i)) % 180);
//   servo.write(degrees);
// }

// void setup() {
//     Serial.begin(921600);

//     if(!servo.attach(servoPin)) {
//         Serial.print("Servo error");
//     }
// }

// void loop() {
//     for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
//         setServo(posDegrees);
//         Serial.println(posDegrees);
//         delay(20);
//     }

//     for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
//         setServo(posDegrees);
//         Serial.println(posDegrees);
//         delay(20);
//     }
// }



// void setup() {
//   pinMode(LED_BUILTIN, OUTPUT);
//   pinMode(GPIO_NUM_17, OUTPUT); //19
//   pinMode(GPIO_NUM_5, OUTPUT);  //23
//   Serial.begin(921600);
//   Serial.println("hello from setup");
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   Serial.println("hello from loop");
//   digitalWrite(LED_BUILTIN, HIGH);

//   // dit is omhoog
//   digitalWrite(GPIO_NUM_5, HIGH);
//   digitalWrite(GPIO_NUM_17, LOW);
//   delay(130);

//   //stop
//   digitalWrite(LED_BUILTIN, LOW);
//   digitalWrite(GPIO_NUM_5, HIGH);
//   digitalWrite(GPIO_NUM_17, HIGH);
//   delay(200);

//   // dit is omlaag
//   digitalWrite(GPIO_NUM_5, LOW);
//   digitalWrite(GPIO_NUM_17, HIGH);
//   delay(100);

//   // stop
//   digitalWrite(LED_BUILTIN, LOW);
//   digitalWrite(GPIO_NUM_5, HIGH);
//   digitalWrite(GPIO_NUM_17, HIGH);
//   delay(1000);

// }


// the number of the motor pin
// const int motorPinOnder = 17;  // 17 corresponds to GPIO17
// const int motorPinBoven = 5;

// // setting PWM properties
// const int freq = 5000;
// const int ChannelMotorPinOnder = 0;
// const int ChannelMotorPinBoven = 1;
// const int resolution = 8;

// void setup(){
//   // configure LED PWM functionalitites
//   ledcSetup(ChannelMotorPinOnder, freq, resolution);
//   ledcSetup(ChannelMotorPinBoven, freq, resolution);

//   // attach the channel to the GPIO to be controlled
//   ledcAttachPin(motorPinOnder, ChannelMotorPinOnder);
//   ledcAttachPin(motorPinBoven, ChannelMotorPinBoven);
// }

// void loop(){

//   // ledcWrite(ChannelMotorPinOnder, waarde); //waarde tussen de 0 en 255, 0 uit 255 aan

//   // dit is omhoog
//   ledcWrite(ChannelMotorPinBoven, 100);
//   ledcWrite(ChannelMotorPinOnder, 0);
//   delay(130);

//   //stop
//   ledcWrite(ChannelMotorPinBoven, 255);
//   ledcWrite(ChannelMotorPinOnder, 255);
//   delay(200);

//   // dit is omlaag
//   ledcWrite(ChannelMotorPinBoven, 0);
//   ledcWrite(ChannelMotorPinOnder, 100);
//   delay(100);

//   // stop
//   ledcWrite(ChannelMotorPinBoven, 255);
//   ledcWrite(ChannelMotorPinOnder, 255);
//   delay(1000);
// }




// // // //deze code doet het waneer de gpoi0 niet is aangesloten en de sda en scl alleen voor deze sensor zijn
// // // Adafruit_VL6180X vl = Adafruit_VL6180X();

// // // void setup() {
// // //   Serial.begin(921600);

// // //   // wait for serial port to open on native usb devices
// // //   while (!Serial) {
// // //     delay(1);
// // //   }
  
// // //   Serial.println("Adafruit VL6180x test!");
// // //   if (! vl.begin()) {
// // //     Serial.println("Failed to find sensor");
// // //     while (1);
// // //   }
// // //   Serial.println("Sensor found!");
// // // }

// // // void loop() {
// // //   uint8_t range = vl.readRange();
// // //   uint8_t status = vl.readRangeStatus();

// // // //De library van de sensor heeft zelf allemaal test erin zitten of de gemeten waarde klopt en geeft een status terug, waneer de status goed is gebruiken wij de waarde, zoals hieronder te zien
// // //   if (status == VL6180X_ERROR_NONE) {
// // //     Serial.print("Range: "); Serial.println(range);
// // //   }
// // //   delay(200);
// // // }




// // // lange afstands sensor doet het ook individueel
// // Adafruit_VL53L0X lox = Adafruit_VL53L0X();

// // void setup() {
// //   Serial.begin(921600);

// //   // wait until serial port opens for native USB devices
// //   while (! Serial) {
// //     delay(1);
// //   }

// //   pinMode(GPIO_NUM_2, OUTPUT);
// //   pinMode(GPIO_NUM_4, OUTPUT);

// //   digitalWrite(GPIO_NUM_2, HIGH);
// //   digitalWrite(GPIO_NUM_4, LOW);


// //   Serial.println("Adafruit VL53L0X test.");
// //   if (!lox.begin()) {
// //     Serial.println(F("Failed to boot VL53L0X"));
// //     while(1);
// //   }
// //   // power
// //   Serial.println(F("VL53L0X API Continuous Ranging example\n\n"));

// //   // start continuous ranging
// //   lox.startRangeContinuous();
// // }

// // void loop() {
// //   if (lox.isRangeComplete()) {
// //     Serial.print("Distance in mm: ");
// //     Serial.println(lox.readRange());
// //   }
// //   delay(500);
// // }


// int moving_avarage_10(int array[10]){
//   int totaal = 0;
//   for (int i = 0; i < 10; i++) {
//     totaal += array[i];
//   }
//   return totaal/10;
// }

// int moving_avarage_15(int array[15]){
//   int totaal = 0;
//   for (int i = 0; i < 15; i++) {
//     totaal += array[i];
//   }
//   return totaal/15;
// }

// int moving_avarage_20(int array[20]){
//   int totaal = 0;
//   for (int i = 0; i < 20; i++) {
//     totaal += array[i];
//   }
//   return totaal/20;
// }

// // #define SEN_KORT_ADDRESS 0x31
// #define SEN_LANG_ADDRESS 0x32

// // set the pins to shutdown
// #define SHT_SEN_KORT GPIO_NUM_4
// #define SHT_SEN_LANG GPIO_NUM_2

// // lange en korte afstandsensor
// Adafruit_VL6180X sensor_kort = Adafruit_VL6180X();
// Adafruit_VL53L0X sensor_lang = Adafruit_VL53L0X();

// // this holds the measurement voor de lange afstand sensor
// VL53L0X_RangingMeasurementData_t measurements_lang;

// // int avarage_kort = 0;
// // int avarage_lang = 0;
// // int array_index_short = 0;
// // int array_index_long = 0;
// // int distance_short[10] = {};
// // int distance_long[20] = {};

// int setPoint = 150;
// int error = 0;
// // int error_sum = 0;
// int error_div = 0;
// int error_prev = 0;

// float stuuractie = 0; // 1 is 100%

// float kp = 0.01;
// // float ki = 0.0001; // Niet nodig bij dit systeem
// float kd = 0.001;
// float dt = 1; // de tijd in sec hoe lang een ronden metingen duurt, waneer het is sec is kan die worden weg gelaten

// int avarage = 0;
// int array_index = 0;
// int distance[20] = {};

// void setup() {
//   Serial.begin(921600);
//   // wait until serial port opens for native USB devices
//   while (! Serial) {
//     delay(1);
//   }
//   pinMode(SHT_SEN_KORT, OUTPUT);
//   pinMode(SHT_SEN_LANG, OUTPUT);

//   // reset de sensoren
//   digitalWrite(SHT_SEN_KORT, LOW);
//   digitalWrite(SHT_SEN_LANG, LOW);
//   delay(10);
//   digitalWrite(SHT_SEN_KORT, HIGH);
//   digitalWrite(SHT_SEN_LANG, HIGH);
//   delay(10);

//   // 
//   digitalWrite(SHT_SEN_KORT, LOW);
//   digitalWrite(SHT_SEN_LANG, HIGH);
//   delay(10);
//   Serial.println("Adafruit VL53L0X test");
//   if (!sensor_lang.begin(SEN_LANG_ADDRESS)) {
//     Serial.println(F("Failed to boot VL53L0X"));
//     while(1);
//   }
//   Serial.println(F("Sensor VL53L0X found!")); 


//   digitalWrite(SHT_SEN_KORT, HIGH);
//   delay(10);
//   Serial.println("\nAdafruit VL6180x test!");
//   if (! sensor_kort.begin()) {
//     Serial.println("Failed to boot VL6180X");
//     while (1);
//   }
//   Serial.println("Sensor VL6180X found!");
// }

// void loop() {
//   // uint8_t range = sensor_kort.readRange();
//   // uint8_t status = sensor_kort.readRangeStatus();
//   // //De library van de sensor heeft zelf allemaal test erin zitten of de gemeten waarde klopt en geeft een status terug, waneer de status goed is gebruiken wij de waarde, zoals hieronder te zien
//   // if (status == VL6180X_ERROR_NONE) {
//   //   // Serial.print("Distance (mm) korte afstand sensor: "); Serial.println(range+6);
//   //   distance_short[array_index_short] = range+5;
//   //   if(array_index_short >= 9){
//   //     array_index_short = 0;
//   //     Serial.print("kort: ");
//   //     avarage_kort = moving_avarage(distance_short);
//   //     Serial.println(avarage_kort);
//   //   }
//   //   else{
//   //     array_index_short += 1;
//   //   }
//   // }
  
//   // sensor_lang.rangingTest(&measurements_lang, false); // pass in 'true' to get debug data printout!
//   // if (measurements_lang.RangeStatus != 4) {  // phase failures have incorrect data
//   //   // Serial.print("Distance (mm) lange afstand sensor: "); Serial.println(measurements_lang.RangeMilliMeter-26);
//   //   distance_long[array_index_long] = measurements_lang.RangeMilliMeter;
//   //   int result = measurements_lang.RangeMilliMeter;
//   //   distance_long[array_index_long] = int((result - 23) - (result/50*4));
//   //   if (array_index_long >= 19)
//   //   {
//   //     array_index_long = 0;
//   //     Serial.print("Lang: ");
//   //     avarage_lang = moving_avarage_20(distance_long);
//   //     Serial.println(avarage_lang);
//   //   }
//   //   else{
//   //     array_index_long += 1;
//   //   }
//   // }


  
//   sensor_lang.rangingTest(&measurements_lang, false); // pass in 'true' to get debug data printout!
//   if (measurements_lang.RangeStatus != 4) {  // phase failures have incorrect data
//   int result = measurements_lang.RangeMilliMeter;
//   distance[array_index] = int((result - 23) - (result/50*4));

//     if (distance[array_index] <= 100){
//         uint8_t range = sensor_kort.readRange();
//         uint8_t status = sensor_kort.readRangeStatus();
//         if (status == VL6180X_ERROR_NONE) { // check of de gemeten waarde goed is
//           if(range > 90){
//             distance[array_index] = ((range + 5) + distance[array_index]) / 2;
//           } else {
//             distance[array_index] = range+5;
//           }
//         }
//     }

//     if (array_index >= 19) {
//       array_index = 0;
//       // Serial.print("Distance: ");
//       // avarage = moving_avarage_20(distance);
//       // Serial.println(avarage);

//       error = setPoint - moving_avarage_20(distance);
//       // error_sum += error*dt; // error maal verstreken tijd  // Ki hoeft niet aangeien i niet werkt voor dit systeem
//       error_div = (error - error_prev) / dt;
//       stuuractie = kp * error + kd * error_div;
//       error_prev = error;
//       // Serial.println(stuuractie);
//     }
//     else{ 
//       array_index += 1;
//     }
//   }


// }