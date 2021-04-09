#ifndef I2C_H
#define I2C_H

#include <avr/io.h>
#include <util/delay.h>

#define DDR_I2C  DDRC
#define PORT_I2C PORTC
#define PIN_I2C  PINC
#define SDA      PC4
#define SCL      PC5
#define pause    5

void i2c_start (void);      
void i2c_stop (void);      
void i2c_mack (void);       
void i2c_nack (void);       
void i2c_write (unsigned char);
unsigned char i2c_read (void);  
unsigned char i2c_ack (void);

#endif


