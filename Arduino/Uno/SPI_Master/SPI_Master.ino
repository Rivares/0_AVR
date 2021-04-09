#include <SPI.h>

// set pin 10 as the slave select
const int m_pin_SS = 10;

float pi = 3.14159;

void setup()
{
  Serial.begin (115200);   // debugging
  
  // set the controller is Master
  pinMode(m_pin_SS, OUTPUT);
  pinMode(MISO, INPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(SCK, OUTPUT);

  SPI.begin();

  Serial.println("Send: ");
}

void loop()
{
  uint16_t addr = 0;
  
  uint8_t *value = (uint8_t *)&pi;    //cast the address of a float into a pointer of byte

  
  sendData_SPI(addr, value);
  
}

void sendData_SPI(uint16_t address, uint8_t *value)
{
   // Разрешить работу SPI:

  //SPCR – SPI Control Register – This register is basically the master register i.e. it contains the bits to initialize SPI and control it.
  //SPSR – SPI Status Register – This is the status register. This register is used to read the status of the bus lines.
  //SPDR – SPI Data Register – The SPI Data Register is the read/write register where the actual data transfer takes place.
  
  // SPIF – SPI Interrupt Flag
   
   SPCR = (0 << SPIE )  // SPI Interrupt Enable
        | (1 << SPE)    // SPI Enable 
        | (0 << DORD)   // MSB == 0. LSB == 1
        | (1 << MSTR)   // Master == 1. Slave == 0
        | (0 << CPOL)   // Mode 0: CPOL == 0; CPHA == 0 / Mode 1: CPOL == 1; CPHA == 0 / Mode 2: CPOL == 0; CPHA == 1 / Mode 3: CPOL == 1; CPHA == 1 /
        | (0 << CPHA)
        | (0 << SPI2X)  // Freq
        | (1 << SPR1)   // Freq
        | (1 << SPR0);  // Freq

  // to select the chip:
  digitalWrite(m_pin_SS, LOW);
  
  byte val = 0b01010101;
  SPI.transfer(val);
  Serial.print(val);
  
//  for (int i = 0; i < sizeof(pi); ++i)
//  {
//    SPI.transfer(*value);    // send the pi byte by byte
//    Serial.print(*value);    // for debugging, print out each byte
//    Serial.print(", ");
//    *value++;
//  }

  digitalWrite(m_pin_SS, HIGH);
  // to unselect the chip:  
  
  Serial.println();
  delay(100);
    
}

void receiveData_SPI()
{
  const int CS_Pin = 7;
  byte firstByte, secondByte;
   
  pinMode(m_pin_SS, OUTPUT); // The CS_Pin should remain in a high impedance state (INPUT) when it is not in use.
  digitalWrite(m_pin_SS, LOW); // Activate the CS line (CS is active LOW)
   
  SPI.transfer(0); // In this case, 0x42 commands the slave to transmit 2 bytes of data
  firstByte = SPI.transfer(0x00); // Send dummy data to receive first byte
  secondByte = SPI.transfer(0x00); // Send dummy data to receive second byte
   
  pinMode(m_pin_SS, INPUT); // Set CS_Pin to high impedance to allow pull-up to reset CS to inactive
  digitalWrite(m_pin_SS, HIGH); // Enable internal pull-up
}
