#include <avr/io.h>
#include <util/delay.h>
#include "ws2812b.h"
#include "animation.h"

int main(void){

  WS2812B_Init();
  
  RGB_Animation_Init();
  //WS2812B_Send_Pixel(0,0,0);
  //WS2812B_Send_Pixel(0,100,200);
  //RGB_Brightness_Inc(0,100,200,1);
  //WS2812B_Send_Pixel(0,100,200);
  while(1){
    RGB_Animation_Slide_Fill(0,100,200);
	RGB_Animation_Slide_Unfill(0,100,200);
	//RGB_Animation_Init();
	//RGB_Animation_Slide();
	_delay_ms(1);
	
  }
}