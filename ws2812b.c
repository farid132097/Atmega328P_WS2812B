
/*
Addressable LEDs are highly dependent on precise timings
Please check clock frequency and timings before proceed

Used System:

CPU  : ATmega328P
F_CPU: 12MHz

For other clock frequency, nop operations must be modified
*/

#include <avr/io.h>
#include <util/delay.h>
#include "ws2812b.h"


void WS2812B_Gpio_Init(void){
  WS2812B_DDR  |=  (1<<WS2812B_bp);
  WS2812B_PORT &=~ (1<<WS2812B_bp);
}

void WS2812B_Send_Byte(uint8_t val){
  if(val & 0x80){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x40){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x20){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x10){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x08){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x04){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x02){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x01){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
}

void WS2812B_Send_Pixel(uint8_t r, uint8_t g, uint8_t b){
  WS2812B_Send_Byte(g);
  WS2812B_Send_Byte(r);
  WS2812B_Send_Byte(b);
}

void WS2812B_Pixel_Delay(void){
  for(uint32_t i=0;i<40000;i++){
	asm( "nop ");
  }
}

  
void WS2812B_Init(void){
  WS2812B_Gpio_Init();
}


