#include <Servo.h> //используем библиотеку для работы с сервоприводом
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <RFID.h>
#include "display.h"
#include "Temp.h"
#include "Buttons.h"
#include "Key.h"
#include "Light.h"
#include "Door.h"
#include "Vent.h"

/*
  #include "globals.h"
  #include "messages.h"
  #include "keyboard.h"
  #include "menu.h"
*/

const int joyDelay = 500;
const int zmrDelay = 500;

int countPeoples = 0;

int zmr = 9;
bool inMenu = 0;
short cursor = 0;
unsigned long lastJoyDown = 0;
unsigned long lastJoyUp = 0;
bool joyDowned = 0;
bool joyUpped = 0;

const int menuDelay = 5000;
int menuTime = 0 ;
const int doorDelay = 5000;
unsigned long doorTime =  0;



void setup()  //обязательная процедура setup, запускаемая в начале программы; объявление процедур начинается словом void
{
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  Serial.begin(9600);

  initLight();
  initDisplay();
  initTemp();
  initDoor();
  initButtons();
  initVent();
  initKey();

  /*
    initMessages();
    initMenu();
    KBD_init();
    sei();
    //DDRC = _BV(PC0) | _BV(PC1) | _BV(PC2);

    setHandler(MSG_MENU_SELECT, &selectMenu);
    startMenu();

  */

}

/*uint8_t selectMenu(msg_par par) {
	switch (par) {
	case MENU_CANCEL: { // тут обработать выбор пункта Mode 1

		break;
	}

	// ... и так далее по всем пунктам
	}

	// после выбора возвращаемся в главное меню.
	startMenu();
	return 1;
  }*/

void loop() //обязательная процедура loop, запускаемая циклично после процедуры setup
{

  if (joyClick())
  {
    //printMenu(cursor);
    menuTime = millis();
    inMenu = 1;
  }

  if (!inMenu)
  {
    printTemp(getTemp());
    printCountPeoples(countPeoples);
  }
  else
  {
    //dispatchMessage();
  }

  if (millis() - menuTime > menuDelay)
  {
    if (inMenu)
      displyClear( );
    inMenu = 0;
    //cursor = 0;
  }

  if (buttonExtPressed())
  {
    digitalWrite(9, HIGH);
    buttonExtTime = millis();

  }

  if ((millis() - buttonExtTime) > zmrDelay)
  {
    digitalWrite(9, LOW);
  }

  if (readMasterKey())
  {
    menuTime = millis();
    inMenu = 1;

    displyClear();
    printSecondLine("Hello,owner");
    openDoor(1);
    doorTime = millis();
    countPeoples++;
  }

  //open dor fo guest
  if (buttonIntClick())
  {
    openDoor(1);
    doorTime = millis();
    if (millis() - buttonExtTime < delayExtClick)
    {
      countPeoples++;
    }
    else
    {
      inMenu = 1;
      menuTime = millis();
      displyClear();
      printSecondLine("Come again");
      openDoor(1);
      countPeoples--;
    }
  }

  if (millis() - doorTime > doorDelay)
  {
    openDoor(0);
  }

  if (countPeoples > 0)
  {
    setLight(1);

    if (getTemp() > 26)
    {
      setVent(1);
    }
    else
    {
      setVent(0);
    }
  }
  else
  {
    setLight(0);
    setVent(0);
  }

  if (buttonClickLong())
  {
    displyClear();
    menuTime = millis();
    inMenu = 1;
    printSecondLine("Good buy");
    countPeoples = 1;

  }

}



















