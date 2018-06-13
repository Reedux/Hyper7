#include <Arduino.h>

bool buttonActive = false;
bool longPressActive = false;
long buttonTimer = 0;
long longPressTime = 250;

int screenSwitch = 30;

int frontLights = 20;
int rearLights = 21;
int floorLights = 22;

int previousScreen;
int currentScreen = 0;

int currentSpeed;
int maxSpeed;

int currentRPM;
int maxRPM;

int runTime;
int Seconds;
int Minutes;

int lightStatus = 0;

int batteryCellOnePin = A0;
int batteryCellTwoPin = A1;
int batteryCellThreePin = A2;
int batteryCellFourPin = A3;

float oneCell=0.00;
float twoCell=0.00;
float threeCell=0.00;
float fourCell=0.00;
