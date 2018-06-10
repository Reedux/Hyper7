#include <Arduino.h>
#include <define.h>

const int hallSensorPin = 2;
const unsigned long sampleTime = 300;

void rpmSetup()
{
  pinMode(hallSensorPin,INPUT);
}

int getRPM()
{
  int count = 0;
  boolean countFlag = LOW;
  unsigned long currentTime = 0;
  unsigned long startTime = millis();
  while (currentTime <= sampleTime)
  {
    if (digitalRead(hallSensorPin) == HIGH)
    {
      countFlag = HIGH;
    }
    if (digitalRead(hallSensorPin) == LOW && countFlag == HIGH)
    {
      count++;
      countFlag=LOW;
    }
    currentTime = millis() - startTime;
  }
  int countRpm = int(1000/float(sampleTime))*count;
  return countRpm;
}

void rpmLoop()
{
  currentRPM = getRPM();
  if (currentRPM > maxRPM) maxRPM = currentRPM;
}
