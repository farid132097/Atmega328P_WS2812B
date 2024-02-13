
#define  WS2812B_TOTAL_PIXEL_CLEAR  300
#define  WS2812B_ANIMATION_PIXELS   29

void     RGB_Animation_Clear_Pixel_Buf(void);
void     RGB_Animation_Clear_All_Pixels(void);
void     RGB_Animation_Rotate_All_Color(void);

void     RGB_Brightness_Inc(uint8_t r, uint8_t g, uint8_t b, uint16_t pixel);
void     RGB_Brightness_Dec(uint8_t r, uint8_t g, uint8_t b, uint16_t pixel);

void     RGB_Brightness_Inc_Mid(uint8_t r, uint8_t g, uint8_t b, uint16_t pixel);
void     RGB_Brightness_Dec_Mid(uint8_t r, uint8_t g, uint8_t b, uint16_t pixel);

uint16_t RGB_Get_Mid_Point(void);
void     RGB_Brightness_Inc_Mid_Act(uint8_t r, uint8_t g, uint8_t b, uint16_t pixel);

void     RGB_Animation_Slide(void);
void     RGB_Animation_Slide_Fill(uint8_t r, uint8_t g, uint8_t b);
void     RGB_Animation_Slide_Unfill(uint8_t r, uint8_t g, uint8_t b);

void     RGB_Animation_Slide_Fill_Mid(uint8_t r, uint8_t g, uint8_t b);
void     RGB_Animation_Slide_Unfill_Mid(uint8_t r, uint8_t g, uint8_t b);

void     RGB_Animation_Brightness_Inc(uint8_t r, uint8_t g, uint8_t b);
void     RGB_Animation_Brightness_Dec(uint8_t r, uint8_t g, uint8_t b);

void     RGB_Animation_Init(void);


void     RGB_Clear_Buf_2D(void);
void     RGB_Set_Pixel(uint8_t pos, uint8_t red, uint8_t green, uint8_t blue);
void     RGB_Push_Buffer(void);

void     RGB_Inc_Brightness(uint8_t pos, uint8_t red, uint8_t green, uint8_t blue);


