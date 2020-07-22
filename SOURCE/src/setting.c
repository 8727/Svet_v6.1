#include "setting.h"

struct settingsInitTypeDef settings;
static __IO uint32_t msTicks;

void SysTick_Handler(void){ msTicks++; }

uint32_t GetTick(void){ return msTicks; }

void DelayMs(uint32_t ms){ uint32_t tickstart = GetTick();
  while((GetTick() - tickstart) < ms){}
}

void DelayMc(uint32_t mc){ mc *= (SystemCoreClock / 1000000) / 9;
  while (mc--);
}

void Setting(void){
  SysTick_Config(SystemCoreClock / 1000);   //1ms
  
  RCC->APB1ENR |= RCC_APB1ENR_PWREN;
//  RCC->APB1ENR |= RCC_APB1ENR_BKPEN;
//  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
  
//  AFIO->MAPR = AFIO_MAPR_SWJ_CFG_JTAGDISABLE;
  
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
  RCC->AHBENR |= RCC_AHBENR_GPIOFEN;
  
  lightInit();
  lightPwmInit();
  lightStepInit();
  Rs485Init();
}
