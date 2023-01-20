/*
 * Assignment 2 - Duration timer
 *
 * Created: 14/01/2023 11:45:58
 * Author : Jaap-Jan Groenendijk
 */ 

// Atmega328P config
#define F_CPU 16000000UL					// 16 MHz CPU clockspeed
#define BAUD 9600							// datatransfer rate for serial connection
#define MYUBRR (F_CPU/16/BAUD-1)			// macro for uart connection (from AVR-guy)

// Standard libraries
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>					// probably need this for measuring time

// Macros to make life easier
#define SWITCH_PRESSED (!(PINB & (1<<PINB7)))

// Function prototypes from AVR-guy
void USART_init(unsigned int ubrr);
void USART_transmit(unsigned char data);
unsigned char USART_receive(void);

// Self made functions
void send_text(char *text);					// done
void print_elapsed_time(uint32_t input_ms);	// done
void init();								// done
void wait_button_press();					// done
void led_on(int led_num);					// done
void led_off(int led_num);					// done
void start_timer();							// done
void stop_timer();							// done

// Global variables to store timer state and value
volatile uint32_t elapsed_time_ms;
volatile uint8_t timer_status = 0;			// Assume 0 for disabled and 1 for enabled.

// Interrupt Service Routine for button press
ISR(PCINT0_vect)
{
	// Execute this code when the button is pressed.
	if (SWITCH_PRESSED)
	{
		led_on(PORTB5);								// Turn on LED indicator
		/*send_text("\t\tbutton is pressed\n");*/	// remove later? useful for debugging right now
		
		// Start timer when timer_status is 1 (enabled)	
		if (timer_status == 1)
		{
			start_timer();
		}
	}
	
	// Execute this code when the button is released
	else if (!(SWITCH_PRESSED))
	{
		// Turn off LED indicator
		led_off(PORTB5);
							
		// remove later? useful for debugging right now
		/*send_text("\t\tbutton is released\n");*/
		
		// Enable timer if it's disabled, so it runs next time.
		if (timer_status == 0)
		{
			timer_status = 1;
		}
		
		// Disable timer if it's enabled, so it does not run next time.
		else if (timer_status == 1)
		{
			// disable timer status for next button press
			stop_timer();
			timer_status = 0;
		}
	}
}

// Interrupt Service Routine for timer 1. This is triggered every 1ms. 
ISR(TIMER1_COMPA_vect)
{
	/*led_on(PORTB3);*/
	elapsed_time_ms++;
}

int main(void)
{
	// initialize hardware components
	init();
		
    while (1) 
    {
		// send explanation to user
		send_text(	"\nThis program wil measure how long the button will be pressed.\n"
					"Press the button once to continue.\n"
					"System is ready for use!\n\n");
		
		// Wait until user has read instructions. Turn on LED1			
		wait_button_press();
		led_on(PORTB0);

		send_text("Next key press will be measured.\n");
		// ISR does the measuring bit here.

		// Give user some time before continuing. Turn off LED 1
		wait_button_press();
		led_off(PORTB0);

		// Let user know how long the button was pressed
        send_text("Time elapsed (ss:mmm):\n");
        print_elapsed_time(elapsed_time_ms);
        send_text("\n");
		
        // Reset elapsed time
        elapsed_time_ms = 0;
    }
}

void init()
{
	// initialize the uart connection
	USART_init(MYUBRR);
	
	// initialize the LEDs 0 to 5 as output
	DDRB |= (1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB3) | (1<<DDB4) | (1<<DDB5);
	
	// initialize button PB7 and enable pull-up resistor
	DDRD &= ~(1 << PD2);
	PORTD |= (1 << PD2);

	// enable interrupt on button
	PCMSK0 |= (1<<PCINT7);
	PCICR |= (1<<PCIE0);
	
	// Enable global interrupts
	sei();
	
	// Set timer status to 0 (disabled)
	timer_status = 0;
}

// default avr function from avr video.	Initialize the uart connection to the microcontroller.		
void USART_init(unsigned int ubrr)
{
	/* Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (3<<UCSZ00);
}

// default avr function from datasheet. send data over uart channel 0
void USART_transmit(unsigned char data)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) );
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

// default avr function from datasheet. receive data over uart channel 0
unsigned char USART_receive(void)
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) );
	/* Get and return received data from buffer */
	return UDR0;
}

// function for sending text over serial
void send_text(char *text)
{
	int character;
	// loop for sending characters over uart one by one
	for (character = 0; text[character]; character++)
	{
		USART_transmit(text[character]);
	}
}

// function to print time in ss:mmm format
void print_elapsed_time(uint32_t input_ms)
{
	// initialize the needed variables
	uint32_t output_s, output_ms;
	char buffer[6];
	
	// split input_ms in seconds and milliseconds
	output_s = input_ms / 1000;
	output_ms = input_ms % 1000;
	
	// convert int to char array
	sprintf(buffer, "%02lu:%03lu", output_s, output_ms);
	
	// send text (buffer[6]) to console
	send_text(buffer);
}

// function to wait until a button is pressed
void wait_button_press()
{
	// somehow the boolean logic is reversed here
	// wait until switch is pressed
	while (!(SWITCH_PRESSED));
	// wait until switch is released
	while (SWITCH_PRESSED);
}

void led_on(int led_num)
{
	PORTB |= (1<<led_num);
}

void led_off(int led_num)
{
	PORTB &= ~(1<<led_num);
}

void start_timer()
{
	// Using timer1 for 16bit precision.
	
	// For debugging show in the terminal that timer has started.
	/*send_text("\t\tstarting timer!\n");*/
	
	// Configure timer 1:
	// - 64 prescaler
	TCCR1B |= (1<<CS11) | (1<<CS10);

	// - CTC mode of operation
	TCCR1B |= (1<<WGM12);
	
	// Enable output compare match interrupt for channel A
	TIMSK1 |= (1<<OCIE1A);
	
	// Calculate and configure overflow value to get 1ms interrupts
	uint32_t overflow_compare = (((F_CPU/1000) / 64) - 1);
	OCR1A = overflow_compare;
	
}

void stop_timer()
{
	// For debugging show in the terminal that timer has started.
	/*send_text("\t\tstopping timer!\n");*/
	
	// Stop timer 1
	// disable the prescaler
	TCCR1B &= ~((1<<CS12) | (1<<CS11) | (1<<CS10));

	// Disable output compare mode
	TIMSK1 &= ~(1<<OCIE1A);
	
	// Set timer value to zero
	TCNT1 = 0;
	
	// Turn off LED 3 indicator
	led_off(PORTB3);
}