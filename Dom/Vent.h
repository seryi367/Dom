#ifndef Vent_H
#define Vent_H
#include <Arduino.h>

static int fanPin = 2;

void initVent();
void setVent(short isOn);
#endif //Vent_H

