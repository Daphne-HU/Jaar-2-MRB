// Millis value when the data was last sent. 
long timeLastSent;

// Interval (milliseconds) between sending analog data
const unsigned SendInterval = 5; // [ms]

const int FIR_size = 11;  // must be an odd number (to keep finding the median simple)
int arMeasurements[FIR_size];
int arTmp[FIR_size];
int nLastMeasurementIndex=0;

void setup() {
  Serial.begin(115200);

  timeLastSent = millis();

  
}
int getMedian()
{
    // TODO: implementeer zelf
    // bubbelsort
    for (int i = 0; i < FIR_size - 1 ; i++)
    {
        for (int j = 0; j < FIR_size - i - 1; j++)
        {
            if (arMeasurements[j] > arMeasurements[j + 1])
            {
                // Wissel van plaats
                int temp = arMeasurements[j];
                arMeasurements[j] = arMeasurements[j + 1];
                arMeasurements[j + 1] = temp;
            }
        }
    }
    return arMeasurements[FIR_size / 2];
}



int getAverage()
{
  int total = 0;
  for (int index = 0; index < FIR_size ; index++) {
    total += (arMeasurements[index]/11);
    }
  return total;
}

// Tip: Je kunt de serieel geprinte nummers ook via Serial Monitor (in plaats van Serial Plotter) weergeven.
// Google daarvoor evt op Serial Plotter - Arduino IDE.
void loop() {
  if ((millis() - timeLastSent) > SendInterval)
  {
    timeLastSent = millis();
    int dataValue = analogRead(A0);
    nLastMeasurementIndex = (nLastMeasurementIndex+1)%FIR_size;
    arMeasurements[nLastMeasurementIndex]=dataValue;
//    Serial.print(dataValue);
//    Serial.print(" ");
//    Serial.print(getMedian());
//    Serial.print(" ");
    Serial.println(getAverage());
    Serial.print(" ");
  }

//    arMeasurements[0] = 5;
//    arMeasurements[1] = 9;
//    arMeasurements[2] = 2;
//    arMeasurements[3] = 56;
//    arMeasurements[4] = 7;
//    arMeasurements[5] = 74;
//    arMeasurements[6] = 23;
//    arMeasurements[7] = 76;
//    arMeasurements[8] = 34;
//    arMeasurements[9] = 57;
//    arMeasurements[10] = 3;
//
//    for (int index = 0; index < FIR_size ; index++) {
//      Serial.print(arMeasurements[index]);
//      Serial.print(" ");
//    }
//    Serial.print(" ");
//    Serial.print(" ");
//    Serial.print(" ");
//    Serial.print(getMedian());
//    Serial.print(" ");
//    Serial.print(" ");
//    Serial.print(" ");
//    for (int index = 0; index < FIR_size ; index++) {
//      Serial.print(arMeasurements[index]);
//      Serial.print(" ");
//    }
//
//    Serial.print(" ");
//    Serial.print(" ");
//    Serial.print(" ");
//
//    delay(2000);
    
}
