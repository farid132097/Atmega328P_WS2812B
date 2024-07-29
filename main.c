#include <avr/io.h>
#include <util/delay.h>
#include "ws2812b.h"
#include "animation.h"
#include "debug.h"

#define  TOTAL_COLOR      10
#define  TOTAL_COLOR_LOOP 5

uint8_t  colors[TOTAL_COLOR*3]={
  0xfe,0xd7,0x00,
  0x66,0xcc,0x00,
  0x73,0x9B,0xD0,
  0x33,0x33,0xfe,
  0xb2,0x66,0xfe,
  0x00,0x10,0x20,
  0x00,0x10,0x20,
  0x00,0x10,0x20,
  0x00,0x10,0x20,
  0x00,0x10,0x20
};

uint8_t color_index=0, red_val=0, green_val=0, blue_val=0;

int main(void){

  WS2812B_Init();
  RGB_Animation_Init();
  debug_init();
  
  RGB_Clear_Buf_2D();
  
  RGB_Set_Pixel(15,100,0,0);
  
  RGB_Push_Buffer();
  while(1){
    
	red_val   = colors[(color_index*3)+0];
	green_val = colors[(color_index*3)+1];
	blue_val  = colors[(color_index*3)+2];
	
    RGB_Animation_Slide_Fill(red_val, green_val, blue_val);
	_delay_ms(1000);
	RGB_Animation_Slide_Unfill(red_val, green_val, blue_val);
	_delay_ms(1000);
	
	color_index++;
	if(color_index>=TOTAL_COLOR_LOOP){
	  color_index=0;
	}
	
	//RGB_Animation_Slide_Fill_Mid(100,0,0);
	//RGB_Animation_Slide_Unfill_Mid(100,0,0);
	
	//RGB_Set_Pixel(15);
	
	//RGB_Inc_Brightness(15,120,0,0);
	//_delay_ms(100);
  }
}