

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "debug.h"

#ifdef  DEBUG_USE_TIMER0
uint16_t TIM0_BAUD_9600[3] = {1230, 1180, 590};
uint16_t TIM0_BAUD_19200[3]= { 590,  570, 230};
uint16_t TIM0_BAUD_38400[3]= { 200,  210,  20};
#endif


#ifdef  DEBUG_USE_TIMER1
uint16_t TIM1_BAUD_9600[3] = {1230, 1180, 590};
uint16_t TIM1_BAUD_19200[3]= { 590,  570, 230};
uint16_t TIM1_BAUD_38400[3]= { 280,  280,  70};
#endif


#ifdef  DEBUG_USE_TIMER2
uint16_t TIM2_BAUD_9600[3] = {1230, 1180, 590};
uint16_t TIM2_BAUD_19200[3]= { 590,  570, 230};
uint16_t TIM2_BAUD_38400[3]= { 280,  270,  70};
#endif


typedef struct debug_t{
  volatile uint8_t   error;
  volatile uint8_t   datareg;
  volatile uint8_t   databsy;
  volatile uint8_t   buf[DEBUG_RX_BUF_SIZE];
  volatile uint8_t   bufindex;
  uint8_t            digits[8];
  uint8_t            input_num_digits;
}debug_t;

debug_t debug;

void debug_struct_init(void){
  debug.error=0;
  debug.datareg=0;
  debug.databsy=1;
  for(uint8_t i=0;i<DEBUG_RX_BUF_SIZE;i++){
    debug.buf[i]=0;
  }
  debug.bufindex=0;
  for(uint8_t i=0;i<8;i++){
    debug.digits[i]=0;
  }
  debug.input_num_digits=0;
}

void debug_timings_init(void){
  #ifdef DEBUG_USE_TIMER0
  TCCR0A=0x00;
  TCCR0B=0x00;
  TIMSK0=0x00;
  TIFR0 =0xff;
  #endif
  
  #ifdef DEBUG_USE_TIMER1
  TCCR1A=0x00;
  TCCR1B=0x00;
  TCCR1C=0x00;
  TIMSK1=0x00;
  TIFR1 =0xff;
  #endif
  
  #ifdef DEBUG_USE_TIMER2
  TCCR2A=0x00;
  TCCR2B=0x00;
  TIMSK2=0x00;
  TIFR2 =0xff;
  #endif
  
  #ifdef DEBUG_RX_DDRB
  PCICR |=(1<<PCIE0);
  PCMSK0|=(1<<DEBUG_RX_bp);
  PCIFR |=(1<<PCIF0);
  sei();
  #define ISR_PCINT_VECT PCINT0_vect
  #endif
  
  #ifdef DEBUG_RX_DDRC
  PCICR |=(1<<PCIE1);
  PCMSK1|=(1<<DEBUG_RX_bp);
  PCIFR |=(1<<PCIF1);
  sei();
  #define ISR_PCINT_VECT PCINT1_vect
  #endif
  
  #ifdef DEBUG_RX_DDRD
  PCICR |=(1<<PCIE2);
  PCMSK2|=(1<<DEBUG_RX_bp);
  PCIFR |=(1<<PCIF2);
  sei();
  #define ISR_PCINT_VECT PCINT2_vect
  #endif
}

void debug_timer_start(void){
  #ifdef DEBUG_USE_TIMER0
  TIFR0 =0xff;
  TIMSK0=0x00;
  TCNT0 =200;
  TCCR0B=(1<<CS02);
  TIFR0 =(1<<TOV0);
  TIMSK0=(1<<TOIE0);
  #define TIMER_OVF_VECT TIMER0_OVF_vect
  #endif

  #ifdef DEBUG_USE_TIMER1
  TIFR1 =0xff;
  TIMSK1=0x00;
  TCNT1 =53000;
  TCCR1B=(1<<CS10);
  TIFR1 =(1<<TOV1);
  TIMSK1=(1<<TOIE1);
  #define TIMER_OVF_VECT TIMER1_OVF_vect
  #endif
  
  #ifdef DEBUG_USE_TIMER2
  TIFR2 =0xff;
  TIMSK2=0x00;
  TCNT2 =10;
  TCCR2B=(1<<CS22);
  TIFR2 =(1<<TOV2);
  TIMSK2=(1<<TOIE2);
  #define TIMER_OVF_VECT TIMER2_OVF_vect
  #endif
}

void debug_timer_stop(void){
  #ifdef DEBUG_USE_TIMER0
  TIMSK0=0;
  TCCR0B=0;
  TCNT0 =0;
  #endif
  
  #ifdef DEBUG_USE_TIMER1
  TIMSK1=0;
  TCCR1B=0;
  TCNT1 =0;
  #endif
  
  #ifdef DEBUG_USE_TIMER2
  TIMSK2=0;
  TCCR2B=0;
  TCNT2 =0;
  #endif
}

void debug_gpio_init(void){
  DEBUG_TX_DDR |= (1<<DEBUG_TX_bp);
  DEBUG_TX_PORT|= (1<<DEBUG_TX_bp);
  DEBUG_RX_DDR &=~(1<<DEBUG_RX_bp);
  DEBUG_RX_PORT|= (1<<DEBUG_RX_bp);
  
  #ifdef DEBUG_GPIO_SWITCH_DEBUGGING
  DEBUG_TEST_DDR|=(1<<DEBUG_TEST_bp);
  DEBUG_TEST_PORT&=~(1<<DEBUG_TEST_bp);
  #endif
}

void debug_tx_high(void){
  DEBUG_TX_PORT|= (1<<DEBUG_TX_bp);
}

void debug_tx_low(void){
  DEBUG_TX_PORT&=~(1<<DEBUG_TX_bp);
}

void debug_tx_set(uint8_t pin_state){
  if(pin_state==1){
    debug_tx_high();
  }else{
    debug_tx_low();
  }
}



uint8_t debug_rx_get(void){
  if(DEBUG_RX_PIN & (1<<DEBUG_RX_bp)){
    return 1;
  }else{
    return 0;
  }
}





////////////////////delay related functions//////////////////

void debug_delay(uint16_t val){
  #ifdef DEBUG_USE_DELAY
  _delay_us(val);
  #endif
  
  #ifdef DEBUG_USE_TIMER0
  TCNT0=0;
    #ifdef DEBUG_BAUD_RATE_9600
	#endif
	
	#ifdef DEBUG_BAUD_RATE_19200
	#endif
	
	#ifdef DEBUG_BAUD_RATE_38400
	TCCR0B=(1<<CS00);
	while(TCNT0<50){}
    TCNT0=0;
	#endif
  
  while(TCNT0<val){}
  TCCR0B=0;
  #endif
  
  #ifdef DEBUG_USE_TIMER1
  TCNT1=0;
  TCCR1B=(1<<CS10);
  while(TCNT1<val){}
  TCCR1B=0;
  #endif
  
  #ifdef DEBUG_USE_TIMER2
  TCNT2=0;
  TCCR2B=(1<<CS20);
  while(TCNT2<val){}
  TCCR2B=0;
  #endif
}


void debug_delay_index_0(void){
  #ifdef  DEBUG_USE_TIMER0
    #ifdef DEBUG_BAUD_RATE_9600
    debug_delay(TIM0_BAUD_9600[0]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_19200
    debug_delay(TIM0_BAUD_19200[0]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_38400
    debug_delay(TIM0_BAUD_38400[0]);
    #endif
  #endif

  #ifdef  DEBUG_USE_TIMER1
    #ifdef DEBUG_BAUD_RATE_9600
    debug_delay(TIM1_BAUD_9600[0]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_19200
    debug_delay(TIM1_BAUD_19200[0]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_38400
    debug_delay(TIM1_BAUD_38400[0]);
    #endif
  #endif
  
  #ifdef  DEBUG_USE_TIMER2
    #ifdef DEBUG_BAUD_RATE_9600
    debug_delay(TIM2_BAUD_9600[0]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_19200
    debug_delay(TIM2_BAUD_19200[0]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_38400
    debug_delay(TIM2_BAUD_38400[0]);
    #endif
  #endif
}

void debug_delay_index_1(void){
  #ifdef  DEBUG_USE_TIMER0
    #ifdef DEBUG_BAUD_RATE_9600
    debug_delay(TIM0_BAUD_9600[1]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_19200
    debug_delay(TIM0_BAUD_19200[1]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_38400
    debug_delay(TIM0_BAUD_38400[1]);
    #endif
  #endif

  #ifdef  DEBUG_USE_TIMER1
    #ifdef DEBUG_BAUD_RATE_9600
    debug_delay(TIM1_BAUD_9600[1]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_19200
    debug_delay(TIM1_BAUD_19200[1]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_38400
    debug_delay(TIM1_BAUD_38400[1]);
    #endif
  #endif
  
  #ifdef  DEBUG_USE_TIMER2
    #ifdef DEBUG_BAUD_RATE_9600
    debug_delay(TIM2_BAUD_9600[1]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_19200
    debug_delay(TIM2_BAUD_19200[1]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_38400
    debug_delay(TIM2_BAUD_38400[1]);
    #endif
  #endif
}

void debug_delay_index_2(void){
  #ifdef  DEBUG_USE_TIMER0
    #ifdef DEBUG_BAUD_RATE_9600
    debug_delay(TIM0_BAUD_9600[2]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_19200
    debug_delay(TIM0_BAUD_19200[2]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_38400
    debug_delay(TIM0_BAUD_38400[2]);
    #endif
  #endif

  #ifdef  DEBUG_USE_TIMER1
    #ifdef DEBUG_BAUD_RATE_9600
    debug_delay(TIM1_BAUD_9600[2]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_19200
    debug_delay(TIM1_BAUD_19200[2]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_38400
    debug_delay(TIM1_BAUD_38400[2]);
    #endif
  #endif
  
  #ifdef  DEBUG_USE_TIMER2
    #ifdef DEBUG_BAUD_RATE_9600
    debug_delay(TIM2_BAUD_9600[2]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_19200
    debug_delay(TIM2_BAUD_19200[2]);
    #endif
	
    #ifdef DEBUG_BAUD_RATE_38400
    debug_delay(TIM2_BAUD_38400[2]);
    #endif
  #endif
}





//////////////////tx-rx functions//////////////////
void debug_tx_byte(uint8_t val){
  uint8_t buf[10]={0,0,0,0,0,0,0,0,0,1};
  for(uint8_t i=0;i<8;i++){
    if(val & (1<<i)){
	  buf[i+1]=1;
	}else{
	  buf[i+1]=0;
	}
  }
  uint8_t sreg=SREG;
  cli();
  for(uint8_t i=0;i<10;i++){
    debug_tx_set(buf[i]);
	
	debug_delay_index_0();    //tx one bit
  }
  SREG=sreg;
}

uint8_t debug_rx_byte(void){
  if(debug_rx_get()==0){
    uint8_t val=0, dval=0, st=1, sp=0;
	debug_delay_index_2();    //half bit
	#ifdef DEBUG_GPIO_SWITCH_DEBUGGING
	DEBUG_TEST_PORT|=(1<<DEBUG_TEST_bp);
    DEBUG_TEST_PORT&=~(1<<DEBUG_TEST_bp);
    #endif
	st=debug_rx_get();
	for(uint8_t i=0;i<8;i++){
	  debug_delay_index_1();
	  #ifdef DEBUG_GPIO_SWITCH_DEBUGGING
	  DEBUG_TEST_PORT|=(1<<DEBUG_TEST_bp);
      DEBUG_TEST_PORT&=~(1<<DEBUG_TEST_bp);
      #endif
	  if(debug_rx_get()){
	    val|=0x80;
	  }else{
	    dval|=0x80;
	  }
	  if(i<7){
	    val>>=1;
	  }
	}
	debug_delay_index_1();
	#ifdef DEBUG_GPIO_SWITCH_DEBUGGING
	DEBUG_TEST_PORT|=(1<<DEBUG_TEST_bp);
    DEBUG_TEST_PORT&=~(1<<DEBUG_TEST_bp);
    #endif
	sp=debug_rx_get();
	if( (st==0) && (sp==1) ){
	  debug.datareg=val;
	  debug.error=0x00;
	}else{
	  debug.error=0x01;
	}
	
	#ifdef DEBUG_GPIO_SWITCH_DEBUGGING
	DEBUG_TEST_PORT|=(1<<DEBUG_TEST_bp);
    DEBUG_TEST_PORT&=~(1<<DEBUG_TEST_bp);
    #endif
  }else{
    debug.error=0x02;
  }
  return debug.datareg;
}

uint8_t debug_rx_byte_get(void){
  return debug.datareg;
}

void debug_rx_byte_clear(void){
  debug.datareg=0;
}

void debug_rx_byte_set(uint8_t val){
  debug.datareg=val;
}



///////////////////////hex and bin data tx///////////////////////

void debug_tx_hex(uint32_t val){
  uint16_t hex_digit, index=0, loop_counter=0;
  if(val <= 0xFF){
    index=8;
    loop_counter=2;
  }else if(val <= 0xFFFF){
    index=16;
    loop_counter=4;     
  }else{
    index=32;
    loop_counter=8;
  }
  debug_tx_byte('0');
  debug_tx_byte('x');
	for(uint8_t i=0;i<loop_counter;i++){
	  index-=4;
	  hex_digit=(uint8_t)((val>>index) & 0x0F);
	  if(hex_digit>9){
	    hex_digit+=55;
	  }else {
	    hex_digit+=48;
	  }
	  debug_tx_byte((uint8_t)hex_digit);
	}
}

void debug_tx_bin(uint32_t val){
  uint8_t loop_counter=0;
  if(val <= 0xFF){
    loop_counter=7;
  }else if(val <= 0xFFFF){
    loop_counter=15;     
  }else{
    loop_counter=31;
  }
  
  debug_tx_byte('0');
  debug_tx_byte('b');
  for(int i=loop_counter; i>=0; i--){
    if( (val>>i) & 1){
      debug_tx_byte( 49 );   
    }else{
      debug_tx_byte( 48 );         
    }
  }
}



/////////////////end char functions//////////////////////

void debug_tx_nl(void){
  debug_tx_byte('\r');
  debug_tx_byte('\n');
}

void debug_tx_sp(void){
  debug_tx_byte(' ');
}

void debug_tx_cm(void){
  debug_tx_byte(',');
}



/////////////////tx text functions//////////////////////

void debug_tx_text(char *str){
    uint8_t i=0;
    while(str[i]!='\0'){
        debug_tx_byte(str[i]);
        i++;
    }
}

void debug_tx_text_nl(char *str){
  debug_tx_text(str);
  debug_tx_nl();
}

void debug_tx_text_sp(char *str){
  debug_tx_text(str);
  debug_tx_sp();
}

void debug_tx_text_cm(char *str){
  debug_tx_text(str);
  debug_tx_cm();
}



//////////////////number tx functions///////////////////

void debug_determine_digit_numbers(uint32_t num){
  uint8_t i=0;
  if(num==0){
    debug.digits[0]=0;
    debug.input_num_digits=1;
  }else{
    while(num!=0){
      debug.digits[i]=num%10;
      num/=10;
      i++;
    }
	debug.input_num_digits=i;
  }
}

void debug_tx_number_digits(void){
  for(uint8_t i=debug.input_num_digits; i>0; i--){
    uint8_t temp=i;
    temp-=1;
    temp=debug.digits[temp];
    temp+=48;
    debug_tx_byte(temp);
  }
}

void debug_tx_number(int32_t num){
  if(num<0){
    debug_tx_byte('-');
	num=-num;
  }
  debug_determine_digit_numbers((uint32_t)num);
  debug_tx_number_digits();
}




/////////////////////number with end functions/////////////
void debug_tx_number_nl(int32_t num){
  debug_tx_number(num);
  debug_tx_nl();
}

void debug_tx_number_sp(int32_t num){
  debug_tx_number(num);
  debug_tx_sp();
}

void debug_tx_number_cm(int32_t num){
  debug_tx_number(num);
  debug_tx_text(",");
}




///////////////hex number with end functions/////////////

void debug_tx_number_hex_nl(int32_t num){
  debug_tx_hex(num);
  debug_tx_nl();
}

void debug_tx_number_hex_sp(int32_t num){
  debug_tx_hex(num);
  debug_tx_sp();
}

void debug_tx_number_hex_cm(int32_t num){
  debug_tx_hex(num);
  debug_tx_text(",");
}



///////////////bin number with end functions/////////////

void debug_tx_number_bin_nl(int32_t num){
  debug_tx_bin(num);
  debug_tx_nl();
}

void debug_tx_number_bin_sp(int32_t num){
  debug_tx_bin(num);
  debug_tx_sp();
}

void debug_tx_number_bin_cm(int32_t num){
  debug_tx_bin(num);
  debug_tx_text(",");
}



///////////////parameter & number with end functions/////////////

void debug_tx_parameter_nl(char *name, int32_t num){
  debug_tx_text(name);
  debug_tx_sp();
  debug_tx_number_nl(num);
}

void debug_tx_parameter_sp(char *name, int32_t num){
  debug_tx_text(name);
  debug_tx_sp();
  debug_tx_number_sp(num);
}

void debug_tx_parameter_cm(char *name, int32_t num){
  debug_tx_text(name);
  debug_tx_sp();
  debug_tx_number_cm(num);
}


///////////parameter & hex number with end functions///////////

void debug_tx_parameter_hex_nl(char *name, int32_t num){
  debug_tx_text(name);
  debug_tx_sp();
  debug_tx_number_hex_nl(num);
}

void debug_tx_parameter_hex_sp(char *name, int32_t num){
  debug_tx_text(name);
  debug_tx_sp();
  debug_tx_number_hex_sp(num);
}

void Debug_tx_parameter_hex_cm(char *name, int32_t num){
  debug_tx_text(name);
  debug_tx_sp();
  debug_tx_number_hex_cm(num);
}


///////////parameter & bin number with end functions///////////

void debug_tx_parameter_bin_nl(char *name, int32_t num){
  debug_tx_text(name);
  debug_tx_sp();
  debug_tx_number_bin_nl(num);
}

void debug_tx_parameter_bin_sp(char *name, int32_t num){
  debug_tx_text(name);
  debug_tx_sp();
  debug_tx_number_bin_sp(num);
}

void Debug_tx_parameter_bin_cm(char *name, int32_t num){
  debug_tx_text(name);
  debug_tx_sp();
  debug_tx_number_bin_cm(num);
}



uint8_t debug_buf_get(uint8_t index){
  return debug.buf[index];
}

uint8_t debug_buf_index_get(void){
  return debug.bufindex;
}

void debug_flush_buf(void){
  for(uint8_t i=0;i<DEBUG_RX_BUF_SIZE;i++){
    debug.buf[i]=0;
  }
  debug.bufindex=0;
}

uint8_t debug_databsy_get(void){
  return debug.databsy;
}

uint8_t debug_data_available_rx_buf(void){
  if( (debug_databsy_get()==0) && (debug_buf_index_get()!=0) ){
    return 1;
  }else{
    return 0;
  }
}

uint8_t debug_available_bytes_rx_buf(void){
  return debug_buf_index_get();
}

void debug_init(void){
  debug_struct_init();
  debug_timings_init();
  debug_gpio_init();
}


ISR(ISR_PCINT_VECT){
  debug.databsy=1;
  uint8_t val=debug_rx_byte();
  if(debug.error==0){
    debug.buf[debug.bufindex]=val;
	debug.bufindex++;
	if(debug.bufindex>DEBUG_RX_BUF_SIZE){
	  debug.bufindex=0;
	}
    debug_timer_start();
	#ifdef DEBUG_GPIO_SWITCH_DEBUGGING
    DEBUG_TEST_PORT|= (1<<DEBUG_TEST_bp);
    DEBUG_TEST_PORT&=~(1<<DEBUG_TEST_bp);
    #endif
  }
}

ISR(TIMER_OVF_VECT){
  debug_timer_stop();
  #ifdef DEBUG_GPIO_SWITCH_DEBUGGING
  DEBUG_TEST_PORT|= (1<<DEBUG_TEST_bp);
  DEBUG_TEST_PORT&=~(1<<DEBUG_TEST_bp);
  #endif
  debug.databsy=0;
}
  
  
  
  
  
  
  
  