/**
 *  @filename   :   epdif.h
 *  @brief      :   Header file of epdif.cpp providing EPD interface functions
 *                  Users have to implement all the functions in epdif.cpp
 *  @author     :   Yehui from Waveshare
 *
 *  Copyright (C) Waveshare     August 10 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef EPDIF_H
#define EPDIF_H

#include <arduino.h>

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

class EpdIf {
public:
    EpdIf(void);
    ~EpdIf(void);

    static int  IfInit(void);
    static void DigitalWrite(int pin, int value); 
    static int  DigitalRead(int pin);
    static void DelayMs(unsigned int delaytime);
    static void SpiTransfer(unsigned char data);
};

#endif
