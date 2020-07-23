#include "main.h"

int main(void){
  Setting();

  while(0x01){
    DelayMs(0x01);
    if(rs485.rxStart != rs485.rxStop){
      rs485.buff = rs485.rxBuff[rs485.rxStart++];
      if((rs485.buff & 0xF0) == 0x10) settings.light_1 = power[POWER_M][rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x20) settings.light_2 = power[POWER_M][rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x30) settings.light_3 = power[POWER_M][rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x40) settings.light_4 = power[POWER_M][rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x50) settings.light_c = power[POWER_M][rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x60) settings.light_w = power[POWER_M][rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x70) settings.light_r = power[POWER_M][rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x80) settings.light_g = power[POWER_M][rs485.buff & 0x0F];
      if((rs485.buff & 0xF0) == 0x90) settings.light_b = power[POWER_M][rs485.buff & 0x0F];
    }
  }
}
