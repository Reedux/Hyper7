#include <Arduino.h>
#include <LiquidCrystal.h>
#include <define.h>
#include <rpm.h>

static int rs = 7, en = 8, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

void lcdSetup()
{
  pinMode(screenSwitch, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Hyper 7 Diag.");
  lcd.setCursor(0, 1);
  lcd.print("Version 0.0.1");
  delay(2000);
  lcd.clear();
}

void clearScreen()
{
  lcd.clear();
}

void batteryScreen()
{
lcd.setCursor(0,0);
lcd.print("1s=" + String(oneCell,2));

lcd.setCursor(9,0);
lcd.print("2s=" + String(twoCell,2));

lcd.setCursor(0,1);
lcd.print("3s=" + String(threeCell,2));

lcd.setCursor(9,1);
lcd.print("4s=" + String(fourCell,2));

}

void homeScreen()
{
  unsigned long Now = millis()/1000;
  Seconds = Now%60;
  Minutes = (Now/60)%60;
  runTime = Minutes + Seconds;
  lcd.setCursor(0,0);
  lcd.print("MPH=" + maxSpeed);
  lcd.setCursor(8,0);
  lcd.print("RT=" + runTime);
  lcd.setCursor(0,1);
  lcd.print("RPM=" + currentRPM);
  lcd.setCursor(8,1);
  lcd.print("Max=" + maxRPM);

}
