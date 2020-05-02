#ifndef _LIGHT_H
#define _LIGHT_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "main.h"

/* Define --------------------------------------------------------------------*/
#define LIGHT_L1_ON               GPIOA->BSRR = GPIO_BSRR_BR_4
#define LIGHT_L2_ON               GPIOA->BSRR = GPIO_BSRR_BR_5
#define LIGHT_L3_ON               GPIOA->BSRR = GPIO_BSRR_BR_6
#define LIGHT_L4_ON               GPIOA->BSRR = GPIO_BSRR_BR_7
#define LIGHT_LC_ON               GPIOA->BSRR = GPIO_BSRR_BS_0
#define LIGHT_LW_ON               GPIOA->BSRR = GPIO_BSRR_BS_1
#define LIGHT_LR_ON               GPIOA->BSRR = GPIO_BSRR_BS_2
#define LIGHT_LG_ON               GPIOA->BSRR = GPIO_BSRR_BS_3
#define LIGHT_LB_ON               GPIOF->BSRR = GPIO_BSRR_BS_1

#define LIGHT_L1_OFF              GPIOA->BSRR = GPIO_BSRR_BS_4
#define LIGHT_L2_OFF              GPIOA->BSRR = GPIO_BSRR_BS_5
#define LIGHT_L3_OFF              GPIOA->BSRR = GPIO_BSRR_BS_6
#define LIGHT_L4_OFF              GPIOA->BSRR = GPIO_BSRR_BS_7
#define LIGHT_LC_OFF              GPIOA->BSRR = GPIO_BSRR_BR_0
#define LIGHT_LW_OFF              GPIOA->BSRR = GPIO_BSRR_BR_1
#define LIGHT_LR_OFF              GPIOA->BSRR = GPIO_BSRR_BR_2
#define LIGHT_LG_OFF              GPIOA->BSRR = GPIO_BSRR_BR_3
#define LIGHT_LB_OFF              GPIOF->BSRR = GPIO_BSRR_BR_1

void lightInit(void);

#endif /* _LIGHT_H */
