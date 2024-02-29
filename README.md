Arduino code 
- epdif.c
'''
// 如果是ESP8266平台
#ifdef ESP8266
  // 在这里放置ESP8266特定的代码
  // Pin definition for ESP8266 (e.g. NodeMCU)
// Connect display CLK signal to GPIO 14 (Node MCU pin D5)
// Connect display DIN signal to GPIO 13 (Node MCU pin D7)
// Connect display 3.3V to NodeMCU 3V3
// Connect display GND to NodeMCU GND
#define BUSY_PIN        5 // D1
#define RST_PIN         4 // D2
#define DC_PIN          0 // D3
#define CS_PIN          2 // D4

#endif

// 如果是ESP32平台
#ifdef ESP32
  // 在这里放置ESP32特定的代码
  //      Display       GPIO   ESP32 pin
#define BUSY_PIN        25 
#define RST_PIN         26 
#define DC_PIN          27 
#define CS_PIN         15 

#endif

// 如果是AVR平台
#ifdef __AVR__
  // 在这里放置AVR特定的代码
#define RST_PIN         8
#define DC_PIN          9
#define CS_PIN          10
#define BUSY_PIN        7
#endif
'''
- imagedata.cpp

  '''
#include "imagedata.h"
#if(__AVR__)
#include <avr/pgmspace.h>
#else
#include <pgmspace.h>
#endif

  '''
