#include "Temp.h"

void initTemp()  
{
 pinMode(DirPelte, OUTPUT);//настройка на выход вывода направления теплопередачи модуля Пельтье

 pinMode(tempPin, INPUT);
 lastValue = 298.55 * exp(-0.00462 * analogRead(tempPin));
 pinMode(19, OUTPUT); 
}


float getTemp()
{
  float temp = (alpha * lastTemp) + (beta * (386.36 * exp(-0.00462 * analogRead(tempPin)))) ;
 
  TempAcc = TempAcc + temp - TempFiltOut;//фильтр НЧ
  TempFiltOut = TempAcc / 200;
  lastValue = TempFiltOut;
  return TempFiltOut;

}

