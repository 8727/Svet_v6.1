#include "rs485.h"

struct Rs485InitTypeDef rs485;

void Rs485Sends(uint8_t *str){
  uint8_t i = 0x00;
  while(str[i]){
    rs485.txBuff[rs485.txStop++] = str[i++];
  }
  RX485_TX;
  USART1->CR1 |= USART_CR1_TXEIE;
}

void Rs485Init(void){
  GPIOA->MODER |= GPIO_MODER_MODER9_1 | GPIO_MODER_MODER10_1;
  GPIOB->MODER |= GPIO_MODER_MODER1_0;
  GPIOB->OTYPER &= ~GPIO_OTYPER_OT_1;
  GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEEDR9 | GPIO_OSPEEDR_OSPEEDR10;
  GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEEDR1;
  GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR9 | GPIO_PUPDR_PUPDR10);
  GPIOB->PUPDR &= ~GPIO_PUPDR_PUPDR8;
  GPIOA->AFR[0x01] |= 0x0010;
  GPIOA->AFR[0x01] |= 0x0100;
  
  
  RX485_RX;
  
  RCC->APB2ENR|= RCC_APB2ENR_USART1EN;
  
  USART1->BRR = RS485_SPEED;
  
  USART1->CR1 |= USART_CR1_TE | USART_CR1_RE;
  USART1->CR1 |= USART_CR1_RXNEIE;
//  USART1->CR1 |= USART_CR1_IDLEIE;
//  USART1->CR1 |= USART_CR1_TCIE;
  USART1->CR1 |= USART_CR1_UE;
  
  NVIC_SetPriority(USART1_IRQn, 0x00);
  NVIC_EnableIRQ(USART1_IRQn);
  Rs485Sends((uint8_t*)"Start");
}

void USART1_IRQHandler(void){
  if(USART1->ISR & USART_ISR_RXNE){
    USART1->ISR &= ~USART_ISR_RXNE;
    rs485.rxBuff[rs485.rxStop++] = USART1->TDR;
  }
  if(USART1->ISR & USART_ISR_TXE){
    if (rs485.txStart != rs485.txStop){
      USART1->RDR = rs485.txBuff[rs485.txStart++];
    }else{
      USART1->CR1 &= ~USART_CR1_TXEIE;
    }
  }
  if(USART1->ISR & USART_ISR_TC){
    USART1->ISR &= ~USART_ISR_TC;
    RX485_RX;
  }
}
