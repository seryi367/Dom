#ifndef DISPLAY_H
#define DISPLAY_H
#include <Arduino.h>
//#include <String>

#include <LiquidCrystal_I2C.h>
static String mainMenu[4]
{
  "Light",
  "Door",
  "Call",
  "Temp",
};

static byte temper[8] = 
{
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000,
  B00000,
};

static byte smile[8] = 
{
  B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B10001,
  B01110,
  B00000,
};

void printTemp(int T);

void printMenu(short cursor = 0);
void printCountPeoples(int P);

void printFirstLine(String T);
void printSecondLine(String P);

void displyClear();

static LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, 1);

void initDisplay();
#endif //DISPLAY_H
