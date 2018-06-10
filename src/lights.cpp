#include <Arduino.h>
#include <define.h>

void lightSetup()
{
  
}

void disableLights()
{

}

void enableLights()
{

}

void lightLoop()
{
  if(lightStatus == 0)
  {disableLights();}
  if(lightStatus == 1)
  {enableLights();}
}
