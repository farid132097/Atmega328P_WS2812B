#include <avr/io.h>
#include <util/delay.h>
#include "ws2812b.h"

int main(void){

  WS2812B_Init();
  
  
  while(1){
  
	WS2812B_Rotate_All_Color();
	//WS2812B_Send_Pixel(255,0,0);
	//WS2812B_Send_Pixel(0,255,0);
	//WS2812B_Send_Pixel(0,0,255);
	_delay_ms(15);
	
  }
}