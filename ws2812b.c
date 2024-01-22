
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


void WS2812_Clear_All_Pixels(void){
  for(uint8_t j=0;j<WS2812B_TOTAL_PIXEL;j++){
	WS2812B_Send_Pixel(0,0,0);
  }
}


uint8_t  red=0, green=0, blue=0;
uint8_t  red_dir=0, green_dir=0, blue_dir=0;

#define  RED_MAX   255
#define  GREEN_MAX 255
#define  BLUE_MAX  255

#define  UPCOUNT   0
#define  DOWNCOUNT 1
#define  HALT      2
  
  
void WS2812B_Init(void){
  WS2812B_Gpio_Init();
  WS2812_Clear_All_Pixels();
  red=RED_MAX;
  red_dir=HALT;
  green_dir=HALT;
  blue_dir=HALT;
}

void WS2812B_Rotate_All_Color(void){
  for(uint8_t j=0;j<WS2812B_TOTAL_PIXEL;j++){
	WS2812B_Send_Pixel(red,green,blue);
  }

  if(red_dir==UPCOUNT){
	if(red<RED_MAX){
	  red++;
	}
  }else if(red_dir==DOWNCOUNT){
	if(red>0){
	  red--;
	}
  }
	
  if(green_dir==UPCOUNT){
	if(green<GREEN_MAX){
	  green++;
	}
  }else if(green_dir==DOWNCOUNT){
	if(green>0){
	  green--;
	}
  }

  if(blue_dir==UPCOUNT){
	if(blue<BLUE_MAX){
	  blue++;
	}
  }else if(blue_dir==DOWNCOUNT){
	if(blue>0){
	  blue--;
	}
  }

  if     ((red == RED_MAX) && (green == 0  ) && (blue == 0)){
	red_dir   = HALT;
	green_dir = UPCOUNT;
	blue_dir  = HALT;
  }
  else if((red == RED_MAX) && (green == GREEN_MAX) && (blue == 0)){
	red_dir   = DOWNCOUNT;
	green_dir = HALT;
	blue_dir  = HALT;
  }	
  else if((red == 0  ) && (green == GREEN_MAX) && (blue == 0)){
	red_dir   = HALT;
	green_dir = HALT;
	blue_dir  = UPCOUNT;
  }

  else if((red == 0  ) && (green == GREEN_MAX) && (blue == BLUE_MAX)){
	red_dir   = UPCOUNT;
	green_dir = DOWNCOUNT;
	blue_dir  = HALT;
  }
	
  /*else if((red == 0  ) && (green == 0) && (blue == BLUE_MAX)){
	red_dir   = UPCOUNT;
	green_dir = HALT;
	blue_dir  = HALT;
  }*/
  else if((red == RED_MAX) && (green == 0) && (blue == BLUE_MAX)){
	red_dir   = HALT;
	green_dir = HALT;
	blue_dir  = DOWNCOUNT;
  }
}

void WS2812B_Slide(void){
  
}