#include <Arduino.h>
#include <define.h>
#include <lcd.h>
#include <rpm.h>

void setup()
{
  Serial.begin(9600);
  rpmSetup();
  lcdSetup();
}

void loop()
{
  int screenSwitchState = digitalRead(screenSwitch);
  rpmLoop();

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
    	buttonActive = false;
    }
    if (longPressActive == true)
    {
      longPressActive = false;
    } else
    {

    }
  }
}


  //Serial.println(digitalRead(screenSwitch));
  /* Original Button Code
  if(screenSwitchState == LOW)
  {
    currentScreen = 1;
    if(previousScreen == 2)
    {
      clearScreen();
    }
    batteryScreen();
    previousScreen = 1;
  }
  else
  {
    currentScreen = 2;
    if(previousScreen == 1)
    {
      clearScreen();
    }
    homeScreen();
    previousScreen = 2;
  }
  */
}
