#ifndef Key_H
#define Key_H
#include <Arduino.h>

#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 7

static RFID rfid(SS_PIN, RST_PIN); 

static unsigned char reading_card[5]; //for reading card
static unsigned char master[5] = {20, 122, 187, 222 ,11 }; // allowed card
//static unsigned char last_card[5] = {0, 0, 0, 0 ,0 }; // allowed card

void initKey();
bool readMasterKey();
#endif //Key_H
