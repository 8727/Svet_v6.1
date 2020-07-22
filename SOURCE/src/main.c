#include "main.h"

int main(void){
  Setting();

  while(0x01){
    DelayMs(0x01);
    if(rs485.rxStart != rs485.rxStop){
      rs485.buff = rs485.rxBuff[rs485.rxStart++];
      if((rs485.buff & 0xF0) == 0x01) settings.light_1 = power[rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x02) settings.light_2 = power[rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x03) settings.light_3 = power[rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x04) settings.light_4 = power[rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x05) settings.light_c = power[rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x06) settings.light_w = power[rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x07) settings.light_r = power[rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x08) settings.light_g = power[rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x09) settings.light_b = power[rs485.buff & 0x0F];
    }
  }
}
