/*
 * test1.c
 *
 * Created: 16.01.2019 23:40:20
 * Author : user
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000L

void portInit(void);

int main()
{
	portInit();
	
	while(1)
	{
		PORTA = PORTB = PORTC = 0x00;
		_delay_ms(10000);
		PORTA = PORTB = PORTC = 0xFF;
		_delay_ms(10000);
	}
}

void portInit()
{
	DDRA = 0xff;
	DDRB = 0xff;
	DDRC = 0xff;
	DDRD = 0xff;
}