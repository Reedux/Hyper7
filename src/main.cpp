#include <Arduino.h>
#include <define.h>
#include <lcd.h>
#include <rpm.h>
#include <lights.h>

void setup()
{
  Serial.begin(9600);
  rpmSetup();
  lcdSetup();
  lightSetup();
}

void loop()
{
  int screenSwitchState = digitalRead(screenSwitch);
  rpmLoop();
  lightLoop();
  lcdLoop();

  if (screenSwitchState == HIGH)
  {
    if (buttonActive == false)
    {
      buttonActive = true;
      buttonTimer = millis();
    }
    if ((millis() - buttonTimer > longPressTime) && (longPressActive == false))
    {
      longPressActive = true;
    } else {
    if (buttonActive == true)
    {
      if(currentScreen == 0)
      {
        currentScreen = 1;
      } else if(currentScreen == 1)
      {
        currentScreen = 0;
      }
    	buttonActive = false;
    }
    if (longPressActive == true)
    {
      if(lightStatus == 0)
      {
        lightStatus = 1;
      }
      if(lightStatus == 1)
      {
        lightStatus = 0;
      }
      lightStatus = 1;
      longPressActive = false;
      }
    }
  }
}
