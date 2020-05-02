#ifndef _SETTING_H
#define _SETTING_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "main.h"
#include "light.h"
#include "lightpwm.h"
#include "rs485.h"


/* Define --------------------------------------------------------------------*/
#define HW_BUILD                          "0.06"      // "0.06" 0x302E3036
#define SW_BUILD                          "1.00"      // "1.00" 0x312E3033

/* Define --------------------------------------------------------------------*/
#define LIGHT_9                           true
#define LIGHT_0_100                       true
#define RS485_SPEED                       0x1388      //0x0034       //921600
                                                      //0x0060       //500000
                                                      //0x0068       //460800
                                                      //0x00C0       //250000
                                                      //0x00D0       //230400
                                                      //0x0180       //125000
                                                      //0x01A0       //115200
                                                      //0x0341       //57600
                                                      //0x04E2       //38400
                                                      //0x09C4       //19200
                                                      //0x1388       //9600

/* Define --------------------------------------------------------------------*/
struct settingsInitTypeDef{
  //Timer
  uint16_t counter;
  uint8_t  light_1;
  uint8_t  light_2;
  uint8_t  light_3;
  uint8_t  light_4;
  uint8_t  light_r;
  uint8_t  light_g;
  uint8_t  light_b;
  uint8_t  light_c;
  uint8_t  light_w;
};

extern struct settingsInitTypeDef settings;

uint32_t GetTick(void);
void DelayMs(uint32_t ms);
void DelayMc(uint32_t mc);

void Setting(void);

#endif /* _SETTING_H */
