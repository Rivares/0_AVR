void setup (void)
{
  Serial.begin(115200);
  Serial.println("\nSPI Slave");

  SPI_SlaveInit();
}

void loop (void)
{
  Serial.print("\nReceive: ");
  
  uint8_t data = SPI_SlaveTranceiver(0x00);
  
  // Вывод в консоль
  Serial.println(data);
}

void SPI_SlaveInit(void)
{
//  pinMode(SS, INPUT);
  pinMode(MISO, OUTPUT);
//  pinMode(MOSI, INPUT);
//  pinMode(SCK, INPUT);

  // Разрешить работу SPI:

  //SPCR – SPI Control Register – This register is basically the master register i.e. it contains the bits to initialize SPI and control it.
  //SPSR – SPI Status Register – This is the status register. This register is used to read the status of the bus lines.
  //SPDR – SPI Data Register – The SPI Data Register is the read/write register where the actual data transfer takes place.
  
  // SPIF – SPI Interrupt Flag
   
   SPCR = (0 << SPIE )  // SPI Interrupt Enable
        | (1 << SPE)    // SPI Enable 
        | (0 << DORD)   // MSB == 0. LSB == 1
        | (0 << MSTR)   // Master == 1. Slave == 0
        ;
}

uint8_t SPI_SlaveTranceiver(uint8_t data)
{
  SPDR = data;
  
  // Ожидание завершения приема:
  while(!(SPSR & (1 << SPIF)));

  return SPDR;
}
