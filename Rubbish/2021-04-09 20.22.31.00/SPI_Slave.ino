static uint8_t data = 0x00;

// ISR(SPI_STC_vect)
// {
//   data = SPDR;
// }

void setup (void)
{
  Serial.begin(115200);
  Serial.println("\nSPI Slave");

  SPI_SlaveInit();
}

void loop (void)
{ 
  data = SPI_SlaveTranceiver(0x05);
}

void SPI_SlaveInit(void)
{
  pinMode(SS, INPUT);
  pinMode(MISO, OUTPUT);
  pinMode(MOSI, INPUT);
  pinMode(SCK, INPUT);

  // Разрешить работу SPI:

  //SPCR – SPI Control Register – This register is basically the master register i.e. it contains the bits to initialize SPI and control it.
  //SPSR – SPI Status Register – This is the status register. This register is used to read the status of the bus lines.
  //SPDR – SPI Data Register – The SPI Data Register is the read/write register where the actual data transfer takes place.
  
  // SPIF – SPI Interrupt Flag
   
   SPCR = (1 << SPIE)  // SPI Interrupt Enable
        | (1 << SPE)    // SPI Enable 
        | (0 << DORD)   // MSB == 0. LSB == 1
        | (0 << MSTR)   // Master == 1. Slave == 0
        ;
}

uint8_t SPI_SlaveTranceiver(uint8_t m_data)
{ 
  // Ожидание окончания передачи 
  while(!(SPSR & (1 << SPIF)));

  uint8_t temp = SPSR;   //обнуляем флаг SPIF
  data = SPDR;      //считываем данные

  Serial.print("\ndata = "); Serial.print(data);

  SPDR = m_data;

  return SPDR;
}
