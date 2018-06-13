#include <Arduino.h>
#include <define.h>

unsigned long previousBatteryMillis = 0;
const long batteryInterval = 10000;

void batteryOne()
{
oneCell = analogRead(batteryCellOnePin);
}

void batteryTwo()
{
twoCell = analogRead(batteryCellTwoPin);
}

void batteryThree()
{
threeCell = analogRead(batteryCellThreePin);
}

void batteryFour()
{
fourCell = analogRead(batteryCellFourPin);
}

void runBatteryVolt()
{
  unsigned long batteryCurrentMillis = millis();
  if (batteryCurrentMillis - previousBatteryMillis >= batteryInterval) {

    previousBatteryMillis = batteryCurrentMillis;

    batteryOne();
    batteryTwo();
    batteryThree();
    batteryFour();
    }

}
