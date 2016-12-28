#include "Light.h"

void initLight()
{
  pinMode(Light , OUTPUT);
}

void setLight(short isOn)
{
  if(isOn)
    digitalWrite(Light, HIGH);
  else
    digitalWrite(Light, LOW);
}
