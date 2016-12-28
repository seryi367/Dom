#ifndef Light_H
#define Light_H
#include <Arduino.h>

#define Light_ON 1
#define Light_OFF 0

static int Light = 4;

void initLight();

void setLight(short isOn);

#endif //Light_H
