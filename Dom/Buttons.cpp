#include "Buttons.h"
#include "Door.h"


void initButtons()  
{
 pinMode(buttonExt, INPUT_PULLUP); //объявление используемых кнопок
 pinMode(buttonInt, INPUT_PULLUP); //объявление используемых кнопок
 pinMode(axis_Z, INPUT);    // Задаем как вход
 pinMode(Js, INPUT_PULLUP);  
 zeroX = analogRead(Jx);
 zeroY = analogRead(Jy);

 longClickTime = 0;
}

bool joyRight()
{
return analogRead(Jx) > (zeroX + 50);
}

bool joyLeft()
{
return analogRead(Jx) < (zeroX - 50); 
}

bool joyUp()
{
return analogRead(Jy) > (zeroY + 50); 
}

bool joyDown()
{
return analogRead(Jy) < (zeroY - 50); 
}

bool joyClick()
{
  return digitalRead(Js) == LOW;
/*if(digitalRead(Js) == LOW)
 {
  joyPressed = 1 ;
 } 
 else 
{
  if(joyPressed == 1)
  {
    joyPressed = 0 ;
    return 1;
  }  
} 
return 0;*/
}

 bool buttonIntPressed()
{
  return digitalRead(buttonInt) == LOW;
}

 bool buttonExtPressed()
{
  return digitalRead(buttonExt) == LOW;
}

bool buttonIntClick()
{
  if (buttonIntPressed())
  {
   ButtonIntPr = 1 ;
  }
  else 
  {
    if(ButtonIntPr == 1)
    {
      ButtonIntPr = 0 ;
      return 1;
    }  
  }
  return 0;
}

bool buttonClickLong()
 {
 if (buttonIntPressed())
 {
    if(longClickTime == 0)
    {
      longClickTime = millis();
    }
  }
  else
  {
    longClickTime = 0;
  }
  if (longClickTime != 0 && millis() - longClickTime > delayClick)
  {
    longClickTime = 0;
    return true;
  }
     
  return false;
 }



