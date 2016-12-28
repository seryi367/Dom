#include "Key.h"

void initKey() 
{

  SPI.begin(); 
  rfid.init();
}

bool readMasterKey()
{
    if (rfid.isCard()) 
    {
        if (rfid.readCardSerial()) 
        {
              /* Reading card */
              Serial.println(" ");
              Serial.println("Card found");
              Serial.println("Cardnumber:");

              int repeat = 0;
              for (int i = 0; i < 5; i++)
              {     
                Serial.print(rfid.serNum[i]);
                Serial.print(" ");
                if(reading_card[i] != rfid.serNum[i])
                  reading_card[i] = rfid.serNum[i];
                else
                  repeat++;
              }

              if(repeat == 5) //если  карта та-же
              {
                Serial.print("Old");
                rfid.halt();
                return false;                
              }
              Serial.println();
              //verification
              int i;
              for (i = 0; i < 5; i++)
              {
                if (reading_card[i]!=master[i])
                {
                  break;
                }
              }
              if (i == 5)
              {
                Serial.println("Read masret card ");
                rfid.halt();
                return 1 ;
                 
              }
         }
    }
    rfid.halt();
    for (int i = 0; i < 5; i++)
    {
      reading_card[i] = 0;
    }
    return 0;
}
