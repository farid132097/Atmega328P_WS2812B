

#define  WS2812B_DDR          DDRD
#define  WS2812B_PORT         PORTD
#define  WS2812B_bp           5U

#define  WS2812B_TOTAL_PIXEL  10

void     WS2812B_Gpio_Init(void);
void     WS2812B_Send_Byte(uint8_t val);
void     WS2812B_Send_Pixel(uint8_t r, uint8_t g, uint8_t b);
void     WS2812B_Pixel_Delay(void);
void     WS2812_Clear_All_Pixels(void);
void     WS2812B_Init(void);
void     WS2812B_Rotate_All_Color(void);