#ifndef _LIGHTPWM_H
#define _LIGHTPWM_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "main.h"

struct pwmInitTypeDef{
  //Timer
  uint16_t counter;
  uint8_t  step;
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

extern struct pwmInitTypeDef pwm;

void lightPwmInit(void);

#endif /* _LIGHTPWM_H */