

#include <avr/io.h>
#include <util/delay.h>
#include "ws2812b.h"
#include "animation.h"
#include "debug.h"

uint8_t  red=0, green=0, blue=0;
uint8_t  red_dir=0, green_dir=0, blue_dir=0;

#define  RED_MAX   255
#define  GREEN_MAX 255
#define  BLUE_MAX  255

#define  UPCOUNT   0
#define  DOWNCOUNT 1
#define  HALT      2

#define  RGB_INC_STEP 1
#define  RGB_DEC_STEP 4

typedef struct rgb_anim_t{
  uint8_t MaxVal;
  uint8_t MaxNumLedEven;
  uint8_t Red;
  uint8_t Green;
  uint8_t Blue;
  uint8_t PixelBuf[WS2812B_ANIMATION_PIXELS];
}rgb_anim_t;

rgb_anim_t RGBAnim;

void RGB_Animation_Clear_Pixel_Buf(void){
  for(uint16_t i=0;i<WS2812B_ANIMATION_PIXELS;i++){
	RGBAnim.PixelBuf[i]=0;
  }
}

void RGB_Animation_Clear_All_Pixels(void){
  for(uint16_t j=0;j<WS2812B_TOTAL_PIXEL_CLEAR;j++){
	WS2812B_Send_Pixel(0,0,0);
  }
}


void RGB_Brightness_Inc(uint8_t r, uint8_t g, uint8_t b, uint16_t pixel){
  RGBAnim.MaxVal=r;
  
  if(g>RGBAnim.MaxVal){
    RGBAnim.MaxVal=g;
  }
  
  if(b>RGBAnim.MaxVal){
    RGBAnim.MaxVal=b;
  }
  
  uint16_t temp[3];
  temp[0]=0;
  temp[1]=0;
  temp[2]=0;
  
  if((RGBAnim.MaxVal % RGB_INC_STEP)!=0){
    uint16_t temp=RGBAnim.MaxVal % RGB_INC_STEP;
	RGBAnim.MaxVal-=temp;
  }
  
  uint16_t loop_cnt=RGBAnim.MaxVal/3;
  
  for(uint16_t i=0;i<loop_cnt;i+=RGB_INC_STEP){
    
	
    uint16_t idle_pix=pixel;
    for(uint16_t j=0;j<idle_pix;j++){
      if(RGBAnim.PixelBuf[j]){
	    WS2812B_Send_Pixel(r,g,b);
	  }else{
	    WS2812B_Send_Pixel(0,0,0);
	  }
    }
	
	if(i>r){
	  temp[0]=r;
	}else{
	  temp[0]=i;
	}
	
	if(i>g){
	  temp[1]=g;
	}else{
	  temp[1]=i;
	}
	
	if(i>b){
	  temp[2]=b;
	}else{
	  temp[2]=i;
	}
	
	
	WS2812B_Send_Pixel(temp[0],temp[1],temp[2]);
	
	for(uint16_t j=idle_pix;j<=WS2812B_ANIMATION_PIXELS;j++){
      WS2812B_Send_Pixel(0,0,0);
    }
	_delay_us(100);
  }
}

void RGB_Brightness_Dec(uint8_t r, uint8_t g, uint8_t b, uint16_t pixel){
  RGBAnim.MaxVal=r;
  
  if(g>RGBAnim.MaxVal){
    RGBAnim.MaxVal=g;
  }
  
  if(b>RGBAnim.MaxVal){
    RGBAnim.MaxVal=b;
  }
  
  uint16_t temp[3];
  temp[0]=0;
  temp[1]=0;
  temp[2]=0;
  
  if((RGBAnim.MaxVal % RGB_DEC_STEP)!=0){
    uint16_t temp=RGBAnim.MaxVal % RGB_DEC_STEP;
	RGBAnim.MaxVal-=temp;
  }
  
  for(int i=RGBAnim.MaxVal;i>=0;i-=RGB_DEC_STEP){
    uint16_t idle_pix=pixel;
    for(uint16_t j=0;j<idle_pix;j++){
      if(RGBAnim.PixelBuf[j]){
	    WS2812B_Send_Pixel(r,g,b);
	  }else{
	    WS2812B_Send_Pixel(0,0,0);
	  }
    }
	
	if(i>r){
	  temp[0]=r;
	}else{
	  temp[0]=i;
	}
	
	if(i>g){
	  temp[1]=g;
	}else{
	  temp[1]=i;
	}
	
	if(i>b){
	  temp[2]=b;
	}else{
	  temp[2]=i;
	}
	
	
	WS2812B_Send_Pixel(temp[0],temp[1],temp[2]);
	
    for(uint16_t j=idle_pix;j<=WS2812B_ANIMATION_PIXELS;j++){
      WS2812B_Send_Pixel(0,0,0);
    }
	
	_delay_us(200);
  }
}



void RGB_Brightness_Inc_Mid(uint8_t r, uint8_t g, uint8_t b, uint16_t pixel){
  RGBAnim.MaxVal=r;
  
  if(g>RGBAnim.MaxVal){
    RGBAnim.MaxVal=g;
  }
  
  if(b>RGBAnim.MaxVal){
    RGBAnim.MaxVal=b;
  }
  
  uint16_t temp[3];
  temp[0]=0;
  temp[1]=0;
  temp[2]=0;

  for(uint16_t i=0;i<RGBAnim.MaxVal;i++){
    
	
	for(uint16_t j=0;j<pixel;j++){
	  WS2812B_Send_Pixel(r,g,b);
    }
	
	if(i>r){
	  temp[0]=r;
	}else{
	  temp[0]=i;
	}
	
	if(i>g){
	  temp[1]=g;
	}else{
	  temp[1]=i;
	}
	
	if(i>b){
	  temp[2]=b;
	}else{
	  temp[2]=i;
	}
	
	WS2812B_Send_Pixel(temp[0],temp[1],temp[2]); //lit-up-gradually
	
	for(uint16_t j=pixel+1;j<WS2812B_ANIMATION_PIXELS-pixel-1;j++){
	    WS2812B_Send_Pixel(0,0,0);
    }
	
	WS2812B_Send_Pixel(temp[0],temp[1],temp[2]);
	
	for(uint16_t j=0;j<pixel;j++){
	  WS2812B_Send_Pixel(r,g,b);
    }
	
	_delay_us(100);
  }
}

void RGB_Brightness_Dec_Mid(uint8_t r, uint8_t g, uint8_t b, uint16_t pixel){
  RGBAnim.MaxVal=r;
  
  if(g>RGBAnim.MaxVal){
    RGBAnim.MaxVal=g;
  }
  
  if(b>RGBAnim.MaxVal){
    RGBAnim.MaxVal=b;
  }
  
  uint16_t temp[3];
  temp[0]=0;
  temp[1]=0;
  temp[2]=0;

  for(uint16_t i=0;i<RGBAnim.MaxVal;i++){
    uint16_t idle_pix=pixel;
    for(uint16_t j=0;j<idle_pix;j++){
      if(RGBAnim.PixelBuf[j]){
	    WS2812B_Send_Pixel(r,g,b);
	  }else{
	    WS2812B_Send_Pixel(0,0,0);
	  }
    }
	
	if(i>r){
	  temp[0]=r;
	}else{
	  temp[0]=i;
	}
	
	if(i>g){
	  temp[1]=g;
	}else{
	  temp[1]=i;
	}
	
	if(i>b){
	  temp[2]=b;
	}else{
	  temp[2]=i;
	}
	
	
	WS2812B_Send_Pixel(temp[0],temp[1],temp[2]);
	
	for(uint16_t j=idle_pix;j<WS2812B_ANIMATION_PIXELS;j++){
      _delay_us(24);
    }
	_delay_us(100);
  }
}



void RGB_Brightness_Inc_Mid_Act(uint8_t r, uint8_t g, uint8_t b, uint16_t pixel){
  RGBAnim.MaxVal=r;
  
  if(g>RGBAnim.MaxVal){
    RGBAnim.MaxVal=g;
  }
  
  if(b>RGBAnim.MaxVal){
    RGBAnim.MaxVal=b;
  }
  
  uint16_t temp[4];
  temp[0]=0;
  temp[1]=0;
  temp[2]=0;
  
  temp[3]=RGB_Get_Mid_Point();
  
  if((RGBAnim.MaxVal % RGB_INC_STEP)!=0){
    uint16_t temp=RGBAnim.MaxVal % RGB_INC_STEP;
	RGBAnim.MaxVal-=temp;
  }
  
  uint16_t loop_cnt=RGBAnim.MaxVal/3;
  
  for(uint16_t i=0;i<loop_cnt;i+=RGB_INC_STEP){
    
    uint16_t idle_pix=pixel;
    for(uint16_t j=0;j<idle_pix;j++){
      if(RGBAnim.PixelBuf[j]){
	    WS2812B_Send_Pixel(r,g,b);
	  }else{
	    WS2812B_Send_Pixel(0,0,0);
	  }
    }
	
	if(i>r){
	  temp[0]=r;
	}else{
	  temp[0]=i;
	}
	
	if(i>g){
	  temp[1]=g;
	}else{
	  temp[1]=i;
	}
	
	if(i>b){
	  temp[2]=b;
	}else{
	  temp[2]=i;
	}
	
	
	WS2812B_Send_Pixel(temp[0],temp[1],temp[2]);
	
	for(uint16_t j=idle_pix;j<=WS2812B_ANIMATION_PIXELS;j++){
      WS2812B_Send_Pixel(0,0,0);
    }
	_delay_us(100);
  }
}



void RGB_Animation_Rotate_All_Color(void){
  for(uint16_t j=0;j<WS2812B_ANIMATION_PIXELS;j++){
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


uint16_t  color=0,color1=0,color2=0,color3=0;

void RGB_Animation_Slide(void){
  uint16_t leading_blank=0;
  uint16_t trailing_blank=0;
  
  if(color==0){
	  color1=0xFF;
	  color2=0x00;
	  color3=0x00;
	}
	else if(color==1){
	  color1=0xFF;
	  color2=0xFF;
	  color3=0x00;
	}
	else if(color==2){
	  color1=0x00;
	  color2=0xFF;
	  color3=0x00;
	}
	else if(color==3){
	  color1=0x00;
	  color2=0xFF;
	  color3=0xFF;
	}
	else if(color==4){
	  color1=0x00;
	  color2=0x00;
	  color3=0xFF;
	}
	else if(color==4){
	  color1=0xFF;
	  color2=0x00;
	  color3=0xFF;
	}
  
  for(uint16_t i=0;i<WS2812B_ANIMATION_PIXELS;i++){
    
	trailing_blank = WS2812B_ANIMATION_PIXELS;
	trailing_blank-= leading_blank;
	
	
	
    for(uint16_t i=0;i<leading_blank;i++){
      WS2812B_Send_Pixel(0x00,0x00,0x00);
    }
	
	for(uint16_t i=0;i<3;i++){
	  WS2812B_Send_Pixel(color1,color2,color3);
	}
	
    for(uint16_t i=0;i<trailing_blank;i++){
      WS2812B_Send_Pixel(0x00,0x00,0x00);
    }
	
	leading_blank++;
	if(leading_blank>=WS2812B_ANIMATION_PIXELS){
	  leading_blank=0;
	}
	
	
	_delay_ms(1);
  }
  
  color++;
	if(color>4){
	  color=0;
	}
}




void RGB_Animation_Slide_Fill(uint8_t r, uint8_t g, uint8_t b){
  for(uint16_t i=0;i<WS2812B_ANIMATION_PIXELS;i++){
    RGB_Brightness_Inc(r,g,b,i);
	RGBAnim.PixelBuf[i]=1;
  }
}

void RGB_Animation_Slide_Unfill(uint8_t r, uint8_t g, uint8_t b){
  for(int i=WS2812B_ANIMATION_PIXELS-1;i>=0;i--){
    RGB_Brightness_Dec(r,g,b,i);
	RGBAnim.PixelBuf[i]=0;
  }
}


void RGB_Animation_Slide_Fill_Mid(uint8_t r, uint8_t g, uint8_t b){
  for(uint16_t i=0;i<WS2812B_ANIMATION_PIXELS/2;i++){
    RGB_Brightness_Inc_Mid(r,g,b,i);
	RGBAnim.PixelBuf[i]=1;
	RGBAnim.PixelBuf[WS2812B_ANIMATION_PIXELS-i-1]=1;
  }
}

void RGB_Animation_Slide_Unfill_Mid(uint8_t r, uint8_t g, uint8_t b){
  for(int i=WS2812B_ANIMATION_PIXELS-1;i>=0;i--){
    RGB_Brightness_Dec(r,g,b,i);
	RGBAnim.PixelBuf[i]=0;
  }
}


void RGB_Animation_Brightness_Inc(uint8_t r, uint8_t g, uint8_t b){
  RGBAnim.MaxVal=r;
  
  if(g>RGBAnim.MaxVal){
    RGBAnim.MaxVal=g;
  }
  
  if(b>RGBAnim.MaxVal){
    RGBAnim.MaxVal=b;
  }
  
  
  for(int i=0;i<WS2812B_ANIMATION_PIXELS;i++){
    WS2812B_Send_Pixel(r,g,b);
	_delay_ms(10);
  }
}

void RGB_Animation_Brightness_Dec(uint8_t r, uint8_t g, uint8_t b){
  for(int i=0;i<WS2812B_ANIMATION_PIXELS;i++){
    WS2812B_Send_Pixel(r,g,b);
	_delay_ms(10);
  }
}


void RGB_Animation_Init(void){
  red=RED_MAX;
  red_dir=HALT;
  green_dir=HALT;
  blue_dir=HALT;
  _delay_ms(100);
  RGB_Animation_Clear_All_Pixels();
  _delay_ms(100);
  RGB_Animation_Clear_Pixel_Buf(); 
}



///////////////////////////////////////New Structured/////////////////////

typedef struct rgb_t{
  uint8_t MaxVal;
  uint8_t MaxNumLedEven;
  uint8_t PixelBuf[WS2812B_ANIMATION_PIXELS][4];  //r,g,b,complete
}rgb_t;

rgb_t RGB;


void RGB_Clear_Buf_2D(void){
  for (uint8_t i=0;i<WS2812B_ANIMATION_PIXELS;i++){
    RGB.PixelBuf[i][0]=0;
	RGB.PixelBuf[i][1]=0;
	RGB.PixelBuf[i][2]=0;
  }
}

void RGB_Set_Pixel(uint8_t pos, uint8_t red, uint8_t green, uint8_t blue){
  RGB.PixelBuf[pos][0]=red;
  RGB.PixelBuf[pos][1]=green;
  RGB.PixelBuf[pos][2]=blue;
}


void RGB_Push_Buffer(void){
  for(uint8_t i=0;i<WS2812B_ANIMATION_PIXELS;i++){
	WS2812B_Send_Pixel(RGB.PixelBuf[i][0], RGB.PixelBuf[i][1], RGB.PixelBuf[i][2]);
  }
}

uint16_t RGB_Get_Mid_Point(void){
  uint16_t temp=WS2812B_ANIMATION_PIXELS;
  if(temp%2==0){
    temp/=2;
	RGB.MaxNumLedEven=1;
  }else{
    temp/=2;
	temp+=1;
	RGB.MaxNumLedEven=0;
  }
  return temp;
}

void RGB_Inc_Brightness(uint8_t pos, uint8_t red, uint8_t green, uint8_t blue){
  if(RGB.PixelBuf[pos][3]==0){
    for(uint8_t i=0;i<red;i++){
      RGB_Set_Pixel(pos, i, 0, 0);
	  RGB_Push_Buffer();
	  _delay_us(1000);
	}
  }
}
