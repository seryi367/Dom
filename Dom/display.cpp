#include "display.h"

void initDisplay()
{  
  lcd.begin(16,2);
  lcd.createChar(1,temper);
  lcd.createChar(2,smile);
  /*
  lcd.setCursor(2,0);
  
  lcd.print("\1C");

  lcd.setCursor(0,8);
  lcd.write(2);*/

}

void printTemp(int T)
{
    lcd.setCursor(0,0); 
    lcd.print(T);
    lcd.setCursor(2,0);  
    lcd.print("\1C");
}

void printCountPeoples(int P)
{
    lcd.setCursor(2,1);
    lcd.print(P);
    lcd.print("  ");
    lcd.setCursor(0,8);
    lcd.write(2);
}


void printFirstLine(String T)
{
    lcd.setCursor(0,0); 
    lcd.print(T);
}

void printSecondLine(String P)
{
    lcd.setCursor(0,1);
    lcd.print(P);
}

void printMenu(short cursor)
{
  lcd.clear();
  if(cursor > 3)
  {
  cursor = 3;
  }
  for(int i = (cursor > 0 ? cursor - 1: 0), j = 0 ; i < ((cursor > 0) ? (cursor + 1): 2) ; i++, j++) 
  {
    lcd.setCursor(1,j);
    lcd.print(mainMenu[i]);
  } 
  lcd.setCursor( 0, cursor > 2 ? 1 : cursor);
  lcd.print(">");
  
} 

void displyClear()
{
lcd.clear();  
}

