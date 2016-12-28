#ifndef Door_H
#define Door_H
#include <Arduino.h>

#include <Servo.h> //используем библиотеку для работы с сервоприводом


static Servo servo; //объявляем переменную servo типа Servo

void initDoor();
void openDoor(short isOn);
#endif //Door_H
