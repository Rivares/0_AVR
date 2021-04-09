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
		i2c_init(void); // ������������� ����.
		i2c_start(void); // ������ ������� �����
		//i2c_restart(void); // ������ ������� ��������
		
		// SEND
		BYTE data = 0x3;
		BYTE successSend = 0x0;
		successSend = i2c_send_byte(data); // �������� �� ���� ���� � ���������� ACK ��� NACK
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
		successGet = i2c_read_byte(ACK); // ������ �� ���� ���� � � ����� �������� ACK ��� NACK � ����������� ��� �������� ���������� �������.
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
			
	if(status == 0x0) // ������ ������� ����. ���������� 0 ��� ������
	{
		_delay_ms(FREQ);
		PORTD = 0x1;
		_delay_ms(FREQ);
	}
	if(status == 0x1) // ������ ������� ����. ���������� 1 ������ SDA
	{
		_delay_ms(FREQ);
		PORTD = 0x4;
		_delay_ms(FREQ);
	}
	if(status == 0x2) // ������ ������� ����. ���������� 2 ������ SCL
	{
		_delay_ms(FREQ);
		PORTD = 0x8;
		_delay_ms(FREQ);
	}
	if(status == 0x3) // ������ ������� ����. ���������� 3 ������ SDA � SCL
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