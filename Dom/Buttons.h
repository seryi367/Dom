#ifndef Buttons_H
#define Buttons_H
#include <Arduino.h>
#define axis_Y 1    // Ось Y подключена к Analog 1
#define axis_Z 2    // Ось Z (кнопка джойстика) подключена к Digital 2


static int buttonExt = 6;// объявил входную кнопку
static int buttonInt = 5;


static unsigned long lastButtonPressed = 0;
static unsigned long previousMillis = 0;

static int serNum0;
static int serNum1;
static int serNum2;
static int serNum3;
static int serNum4;

static float zeroX;
static float zeroY;

static const int Jx = A2;
static const int Jy = A1;
static const int Js = 8;
static bool joyPressed = 0;
static bool ButtonIntPr = 0;

bool joyRight();
bool joyLeft();
bool joyUp();
bool joyDown();
bool joyClick();

bool buttonClickLong();
bool buttonIntPressed();
bool buttonExtPressed();
bool buttonIntClick();



static unsigned long longClickTime = 0;
const int delayClick = 2500;

static unsigned long buttonExtTime = 0;
const int delayExtClick = 5000;


void initButtons();
#endif //Buttons_H
