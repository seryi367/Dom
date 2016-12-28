#include "Door.h"

void initDoor()
{
  servo.attach(3); //привязываем привод к порту 10
  servo.write(180);
}

void openDoor(short isOn)
{
  if (isOn)
 { 
  servo.write(90);
 }
 else
 {
  servo.write(180);
 }
}

