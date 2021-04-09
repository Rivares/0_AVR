#include <avr/io.h>
#include <util/delay.h>
#include "i2c.h"

#define F_CPU 16000000L
#define FREQ 100000

#define SDA PE0
#define SCL PE1

void portInit(void);

int main()
{
	portInit(void);
	
	while(1)
	{
		PORTA = PORTB = PORTC = PORTD = PORTE = PORTF = 0x00;
		
		// START
		i2c_init(void); // Инициализация шины.
		i2c_start(void); // Подача условия старт
		//i2c_restart(void); // Подача условия повстарт
		
		// SEND
		BYTE data = 0x3;
		BYTE successSend = 0x0;
		successSend = i2c_send_byte(data); // Посылает на шину байт и возвращает ACK или NACK
		if(successSend == 0x0)
		{
			_delay_ms(FREQ);
			PORTD = 0x8;
			_delay_ms(FREQ);
		}
		else
		{
			break;
		}
		
		// READ
		BYTE successGet = 0x0;
		successGet = i2c_read_byte(ACK); // Читает из шины байт и в конце отсылает ACK или NACK в зависимости что передали аргументом функции.
		if(successGet == 0x0)
		{
			_delay_ms(FREQ);
			PORTD = 0x8;
			_delay_ms(FREQ);
		}
		else
		{
			break;
		}
	}
	
	// STOP
	BYTE status = 0b00000000;
	status == i2c_stop();
			
	if(status == 0x0) // Подача условия стоп. Возвращает 0 все хорошо
	{
		_delay_ms(FREQ);
		PORTD = 0x1;
		_delay_ms(FREQ);
	}
	if(status == 0x1) // Подача условия стоп. Возвращает 1 ошибка SDA
	{
		_delay_ms(FREQ);
		PORTD = 0x4;
		_delay_ms(FREQ);
	}
	if(status == 0x2) // Подача условия стоп. Возвращает 2 ошибка SCL
	{
		_delay_ms(FREQ);
		PORTD = 0x8;
		_delay_ms(FREQ);
	}
	if(status == 0x3) // Подача условия стоп. Возвращает 3 ошибка SDA и SCL
	{
		_delay_ms(FREQ);
		PORTD = 0xC;
		_delay_ms(FREQ);
	}
}

void portInit()
{
	DDRA = 0xff;
	DDRB = 0xff;
	DDRC = 0xff;
	DDRD = 0xff;
	DDRE = 0xff;
	DDRF = 0xff;
}