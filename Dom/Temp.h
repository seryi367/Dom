#ifndef Temp_H
#define Temp_H
#include <Arduino.h>

static int DirPelte = A0;
static int TEC = 6;

static float TempAcc = 4000;//Аккумулятор фильтра
static float TempFiltOut = 20;//Фильтрованная температура

static float err = 0, err_old  = 0;//ошибка установки температуры
static float TempCon = 27;//заданное значение температуры
static float P = 0, I = 0, D = 0, OUT_PID = 0;//Пропорциональная компонента

static float Kp = 1;//коэффициент пид регулятора
static float Ki = 1;//коэффициент пид регулятора
static float Kd = 1;//коэффициент пид регулятора

static int tempPin = A0;    // select the input pin for the potentiometer
static float lastValue;
static float lastTemp = 24;

const long interval = 3;
const float alpha = 0.8;
const float beta = 0.2;

float getTemp();

void initTemp();
#endif //Temp_H
