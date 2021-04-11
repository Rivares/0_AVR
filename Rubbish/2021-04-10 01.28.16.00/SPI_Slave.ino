volatile uint8_t m_data = 0x05;

void setup (void)
{
  Serial.begin(115200);

  SPI_SlaveInit();
}

void loop (void)
{ 
  volatile uint8_t local_tmp = SPI_SlaveReceive();
  SPI_SlaveSend(m_data);

 SPDR = 0x00;
  SPSR = 0x00; 
 
  
  Serial.print("\nSPDR = "); Serial.print(SPDR);
}

void SPI_SlaveInit(void)
{
  pinMode(MISO, OUTPUT);

  // Разрешить работу SPI:

  //SPCR – SPI Control Register – This register is basically the master register i.e. it contains the bits to initialize SPI and control it.
  //SPSR – SPI Status Register – This is the status register. This register is used to read the status of the bus lines.
  //SPDR – SPI Data Register – The SPI Data Register is the read/write register where the actual data transfer takes place.
  
  // SPIF – SPI Interrupt Flag
   
   SPCR |= (1 << SPE);    // SPI Enable 
}

void SPI_SlaveSend(uint8_t data)
{ 
  SPDR = m_data;  
}

uint8_t SPI_SlaveReceive()
{ 
  // Ожидание окончания передачи 
  while(!(SPSR & (1 << SPIF)));

  return SPDR;
}
