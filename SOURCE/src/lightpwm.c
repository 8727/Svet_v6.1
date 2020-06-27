#include "lightpwm.h"

struct pwmInitTypeDef pwm;

void TIM3_IRQHandler(void){
  TIM3->SR &= ~TIM_SR_UIF;
  if(!(GPIOF->IDR & GPIO_IDR_0)){
    settings.counter = 0x00;
    if(0x00 == pwm.step){
      pwm.step++;
      if(settings.light_1 > pwm.light_1) pwm.light_1++;
      if(settings.light_1 < pwm.light_1) pwm.light_1--;
      
      if(settings.light_2 > pwm.light_2) pwm.light_2++;
      if(settings.light_2 < pwm.light_2) pwm.light_2--;
      
      if(settings.light_3 > pwm.light_3) pwm.light_3++;
      if(settings.light_3 < pwm.light_3) pwm.light_3--;
      
      if(settings.light_4 > pwm.light_4) pwm.light_4++;
      if(settings.light_4 < pwm.light_4) pwm.light_4--;
      
      if(settings.light_c > pwm.light_c) pwm.light_c++;
      if(settings.light_c < pwm.light_c) pwm.light_c--;
      
      if(settings.light_w > pwm.light_w) pwm.light_w++;
      if(settings.light_w < pwm.light_w) pwm.light_w--;
      
      if(settings.light_r > pwm.light_r) pwm.light_r++;
      if(settings.light_r < pwm.light_r) pwm.light_r--;
      
      if(settings.light_g > pwm.light_g) pwm.light_g++;
      if(settings.light_g < pwm.light_g) pwm.light_g--;
      
      if(settings.light_b > pwm.light_b) pwm.light_b++;
      if(settings.light_b < pwm.light_b) pwm.light_b--;
    }
  }else{
    settings.counter++;
    pwm.step = 0x00;
  }
  if(settings.counter > 0xFE){ settings.counter = 0xFE; }
  
  if(0x00 < pwm.light_1){ if(settings.counter < pwm.light_1){ LIGHT_L1_ON; }else{ LIGHT_L1_OFF; }}else{ LIGHT_L1_OFF; }
  if(0x00 < pwm.light_2){ if(settings.counter < pwm.light_2){ LIGHT_L2_ON; }else{ LIGHT_L2_OFF; }}else{ LIGHT_L2_OFF; }
  if(0x00 < pwm.light_3){ if(settings.counter < pwm.light_3){ LIGHT_L3_ON; }else{ LIGHT_L3_OFF; }}else{ LIGHT_L3_OFF; }
  if(0x00 < pwm.light_4){ if(settings.counter < pwm.light_4){ LIGHT_L4_ON; }else{ LIGHT_L4_OFF; }}else{ LIGHT_L4_OFF; }
  if(0x00 < pwm.light_c){ if(settings.counter < pwm.light_c){ LIGHT_LC_ON; }else{ LIGHT_LC_OFF; }}else{ LIGHT_LC_OFF; }
  if(0x00 < pwm.light_w){ if(settings.counter < pwm.light_w){ LIGHT_LW_ON; }else{ LIGHT_LW_OFF; }}else{ LIGHT_LW_OFF; }
  if(0x00 < pwm.light_r){ if(settings.counter < pwm.light_r){ LIGHT_LR_ON; }else{ LIGHT_LR_OFF; }}else{ LIGHT_LR_OFF; }
  if(0x00 < pwm.light_g){ if(settings.counter < pwm.light_g){ LIGHT_LG_ON; }else{ LIGHT_LG_OFF; }}else{ LIGHT_LG_OFF; }
  if(0x00 < pwm.light_b){ if(settings.counter < pwm.light_b){ LIGHT_LB_ON; }else{ LIGHT_LB_OFF; }}else{ LIGHT_LB_OFF; }
}

void lightPwmInit(void){
  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
  if(LIGHT_0_100 == true){
    TIM3->PSC = 0x01DF; // 479 48000000:480=100000Hz
    TIM3->ARR = 0x0009; // 100000:10=10000Hz
  }else{
    TIM3->PSC = 0x0000; // 48000000Hz
    TIM3->ARR = 0x0752; // 25600Hz     752
  }
  TIM3->SR = 0x00;
  TIM3->DIER |= TIM_DIER_UIE;
  TIM3->CR1 = TIM_CR1_CEN | TIM_CR1_ARPE;
  
  NVIC_SetPriority(TIM3_IRQn, 0x00);
  NVIC_EnableIRQ(TIM3_IRQn);
}
