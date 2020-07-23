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

static const uint8_t power[][0x10]={{0, 15, 24, 30, 35, 39, 44, 47, 51, 56, 60, 64, 69, 74, 82, 100},
																		{0, 15, 23, 28, 32, 36, 40, 44, 47, 51, 55, 59, 63, 68, 76, 92}};
void lightPwmInit(void);
void lightStepInit(void);

#endif /* _LIGHTPWM_H */
