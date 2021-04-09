#include <avr/io.h>
#include <util/delay.h>
#include "i2c.h"

//#define F_CPU 16000000L
//#define FREQ 16000L

#define RS	(1 << 0)
#define E	(1 << 2)

unsigned char lcd_bufer, ack;

void portInit(void);
void lcd_init(void);
void PCF8574_Write(unsigned char data);
unsigned char PCF8574_read(void);
void lcd_com(unsigned char value);
void lcd_string(unsigned char *data, unsigned char nBytes);
void lcd_data(unsigned char value);


int main()
{
	portInit();
	
	lcd_init();
	
    while (1) 
    {
		lcd_com(0x80);
		lcd_string("KEY #1", 6);
				
    }
	
	return 0;
}

void portInit()
{
	//DDRE = 0xff;
	
	DDRC |= (1 << PC4)|(1 << PC5);	//  SDA, SCL - out
	PORTC |= (1 << PC4)|(1 << PC5); //  SDA, SCL = 1
}

void blink()
{
	//PORTE = 0x00;
	//_delay_ms(FREQ);
	//PORTE = 0xf;
	//_delay_ms(FREQ);
}

void lcd_init(void)
{
	PCF8574_Write(0b00000000);
	_delay_ms(40);

	lcd_bufer = 0b00110000;
	PCF8574_Write(lcd_bufer);

	lcd_bufer |= E;
	PCF8574_Write(lcd_bufer);
	lcd_bufer &= ~E;
	PCF8574_Write(lcd_bufer);

	_delay_ms(5);

	lcd_bufer |= E;
	PCF8574_Write(lcd_bufer);
	lcd_bufer &= ~E;
	PCF8574_Write(lcd_bufer);

	_delay_us(100);

	lcd_bufer |= E;
	PCF8574_Write(lcd_bufer);
	lcd_bufer &= ~E;
	PCF8574_Write(lcd_bufer);

	_delay_us(100);

	lcd_bufer = 0b00100000;
	PCF8574_Write(lcd_bufer);

	lcd_bufer |= E;
	PCF8574_Write(lcd_bufer);
	lcd_bufer &= ~E;
	PCF8574_Write(lcd_bufer);

	_delay_us(100);

	lcd_com(0x28); // ???? 4 ???, LCD - 2 ??????
	lcd_com(0x08); // ?????? ?????????? ???????
	lcd_com(0x01); // ??????? ???????
	_delay_us(100);
	lcd_com(0x06); // ????? ??????? ??????
	lcd_com(0x0C); // ????????? ???????, ?????? ?? ?????
}

void PCF8574_Write(unsigned char data)
{
	do
	{
		ack = 0;
		i2c_start();              //  ??????? ?????
		i2c_write(0x40);          //  ???????? ?????? PCF8574
		ack |= i2c_ack();         //  ????????????? ?? ????????
		i2c_write(data);          //  ?????? ?????? ? PCF8574
		ack |= i2c_ack();         //  ????????????? ?? ????????
		i2c_stop();               //  ??????? ????
		blink();
	}
	while(ack);
}

unsigned char PCF8574_read(void)
{
	unsigned char data;
	do
	{
		ack = 0;
		i2c_start();              //  ??????? ?????
		i2c_write(0x42);          //  ???????? ?????? PCF8574
		ack |= i2c_ack();         //  ????????????? ?? ????????
		data = i2c_read();        //  ?????? ?????? ?? PCF8574
		i2c_nack();               //  ??????????????? ?? ????????
		i2c_stop();               //  ??????? ????
	}
	while(ack);
	return data;
}

void lcd_com(unsigned char value)
{
	lcd_bufer = value & 0xF0;
	lcd_bufer &= ~RS;
	
	lcd_bufer |= E;
	PCF8574_Write(lcd_bufer);
	lcd_bufer &= ~E;
	PCF8574_Write(lcd_bufer);

	_delay_us(100);
	
	lcd_bufer = (value & 0x0F)<<4;
	lcd_bufer &= ~RS;

	lcd_bufer |= E;
	PCF8574_Write(lcd_bufer);
	lcd_bufer &= ~E;
	PCF8574_Write(lcd_bufer);

	if(value & 0b11111100)
	_delay_us(100);
	else _delay_ms(2);
}

void lcd_string(unsigned char *data, unsigned char nBytes)
{
	if(!data) return;
	for(unsigned char i = 0; i < nBytes; i++)
	{
		lcd_data(data[i]);
	}
}

void lcd_data(unsigned char value)
{
	lcd_bufer = (value & 0xF0);
	lcd_bufer |= RS;

	lcd_bufer |= E;
	PCF8574_Write(lcd_bufer);
	lcd_bufer &= ~E;
	PCF8574_Write(lcd_bufer);

	_delay_us(100);
	
	lcd_bufer = (value & 0x0F)<<4;
	lcd_bufer |= RS;

	lcd_bufer |= E;
	PCF8574_Write(lcd_bufer);
	lcd_bufer &= ~E;
	PCF8574_Write(lcd_bufer);

	_delay_ms(2);
}