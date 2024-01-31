

#define  DEBUG_TX_DDR     DDRD
#define  DEBUG_TX_PORT    PORTD
#define  DEBUG_TX_PIN     PIND
#define  DEBUG_TX_bp      4U


/*Must edit DEBUG_RX_XXXX definition*/
#define  DEBUG_RX_DDRC
#define  DEBUG_RX_DDR     DDRC
#define  DEBUG_RX_PORT    PORTC
#define  DEBUG_RX_PIN     PINC
#define  DEBUG_RX_bp      6U


/*Only for debugging purpose*/
//#define  DEBUG_GPIO_SWITCH_DEBUGGING
#define  DEBUG_TEST_DDR   DDRD
#define  DEBUG_TEST_PORT  PORTD
#define  DEBUG_TEST_PIN   PIND
#define  DEBUG_TEST_bp    1U


#define  DEBUG_BAUD_RATE_38400


//#define  DEBUG_USE_DELAY
#define  DEBUG_USE_TIMER0
//#define  DEBUG_USE_TIMER1
//#define  DEBUG_USE_TIMER2

#define  DEBUG_RX_BUF_SIZE 32


void     debug_struct_init(void);
void     debug_timings_init(void);
void     debug_timer_start(void);
void     debug_timer_stop(void);
void     debug_gpio_init(void);
void     debug_tx_high(void);
void     debug_tx_low(void);
void     debug_tx_set(uint8_t pin_state);
uint8_t  debug_rx_get(void);

void     debug_delay(uint16_t val);
void     debug_delay_index_0(void);
void     debug_delay_index_1(void);
void     debug_delay_index_2(void);

void     debug_tx_byte(uint8_t val);
uint8_t  debug_rx_byte(void);
uint8_t  debug_rx_byte_get(void);
void     debug_rx_byte_clear(void);
void     debug_rx_byte_set(uint8_t val);

void     debug_tx_hex(uint32_t val);
void     debug_tx_bin(uint32_t val);

void     debug_tx_nl(void);
void     debug_tx_sp(void);
void     debug_tx_cm(void);

void     debug_tx_text(char *str);
void     debug_tx_text_nl(char *str);
void     debug_tx_text_sp(char *str);
void     debug_tx_text_cm(char *str);

void     debug_determine_digit_numbers(uint32_t num);
void     debug_tx_number_digits(void);

void     debug_tx_number(int32_t num);
void     debug_tx_number_nl(int32_t num);
void     debug_tx_number_sp(int32_t num);
void     debug_tx_number_cm(int32_t num);

void     debug_tx_number_hex_nl(int32_t num);
void     debug_tx_number_hex_sp(int32_t num);
void     debug_tx_number_hex_cm(int32_t num);

void     debug_tx_number_bin_nl(int32_t num);
void     debug_tx_number_bin_sp(int32_t num);
void     debug_tx_number_bin_cm(int32_t num);

void     debug_tx_parameter_nl(char *name, int32_t num);
void     debug_tx_parameter_sp(char *name, int32_t num);
void     debug_tx_parameter_cm(char *name, int32_t num);

void     debug_tx_parameter_hex_nl(char *name, int32_t num);
void     debug_tx_parameter_hex_sp(char *name, int32_t num);
void     debug_tx_parameter_hex_cm(char *name, int32_t num);

void     debug_tx_parameter_bin_nl(char *name, int32_t num);
void     debug_tx_parameter_bin_sp(char *name, int32_t num);
void     debug_tx_parameter_bin_cm(char *name, int32_t num);

uint8_t  debug_buf_get(uint8_t index);
uint8_t  debug_buf_index_get(void);
void     debug_flush_buf(void);
uint8_t  debug_databsy_get(void);
uint8_t  debug_data_available_rx_buf(void);
uint8_t  debug_available_bytes_rx_buf(void);

void     debug_init(void);