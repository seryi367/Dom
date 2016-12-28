#include "Vent.h"

void initVent()
{
pinMode(fanPin, OUTPUT); 
}

void setVent(short isOn)
{ 
  if (isOn) 
  {
    digitalWrite(fanPin, HIGH);
  }
  else 
  {
    digitalWrite(fanPin, LOW);
  }
} 

  /*************************************************///////////////ПИД регулятор
  /*err = TempCon - TempFiltOut;//темпертурная ошибка
  P = err * Kp;//пропорциональная компонента
  I += err * Ki;//интегральная компонента
  D = (err - err_old) * Kd;//дифференциальная компонента
  err_old = err;
  OUT_PID = P + I + D;//выход пид регулятора
  if(OUT_PID >= 0)
  {
    digitalWrite(DirPelte, HIGH);//нагрев
  }
  else
  {
    digitalWrite(DirPelte, LOW);//охлаждение
  }
  
  
  OUT_PID = abs(OUT_PID);
  if(OUT_PID > 255) 
  {
  OUT_PID = 255;
  } 
  analogWrite(TEC, OUT_PID);
  */ 
