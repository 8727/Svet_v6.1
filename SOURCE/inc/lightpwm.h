#ifndef _LIGHTPWM_H
#define _LIGHTPWM_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "main.h"

struct pwmInitTypeDef{
  //Timer
  uint8_t counter;
  uint8_t light_1;
  uint8_t light_2;
  uint8_t light_3;
  uint8_t light_4;
  uint8_t light_r;
  uint8_t light_g;
  uint8_t light_b;
  uint8_t light_c;
  uint8_t light_w;
};

extern struct pwmInitTypeDef pwm;

static const uint8_t power[]={0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x10, 0x20, 0x30, 0x40, 0x50, 0x10, 0x20, 0x30, 0x40, 0x50};

void lightPwmInit(void);
void lightStepInit(void);

#endif /* _LIGHTPWM_H */
