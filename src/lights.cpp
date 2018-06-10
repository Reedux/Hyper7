#include <Arduino.h>
#include <define.h>

void lightSetup()
{
  pinMode(frontLights, OUTPUT);
  pinMode(rearLights, OUTPUT);
  pinMode(floorLights, OUTPUT);
}

void disableLights()
{
  digitalWrite(frontLights, LOW);
  digitalWrite(rearLights, LOW);
  digitalWrite(floorLights, LOW);
}

void enableLights()
{
  digitalWrite(frontLights, HIGH);
  digitalWrite(rearLights, HIGH);
  digitalWrite(floorLights, HIGH);
}

void lightLoop()
{
  if(lightStatus == 0)
  {disableLights();}
  if(lightStatus == 1)
  {enableLights();}
}
