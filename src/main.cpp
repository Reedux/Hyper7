#include <Arduino.h>
#include <define.h>
#include <lcd.h>
#include <rpm.h>

void setup()
{
  rpmSetup();
  lcdSetup();
  Serial.begin(9600);
}

void loop()
{

  rpmLoop();

  int screenSwitchState = digitalRead(screenSwitch);
  //Serial.println(digitalRead(screenSwitch));
  if(screenSwitchState == LOW)
  {
    currentScreen = 1;
    if(previousScreen == 2)
    {
      clearScreen();
    }
    screenOne();
    previousScreen = 1;
  }
  else
  {
    currentScreen = 2;
    if(previousScreen == 1)
    {
      clearScreen();
    }
    screenTwo();
    previousScreen = 2;
  }
}
