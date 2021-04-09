void setup (void)
{
  Serial.begin(115200);
  Serial.println("\nSPI Slave");

  SPI_SlaveInit();
}

void loop (void)
{
  Serial.print("\nReceive: ");
  uint8_t data = SPI_SlaveReceive();

  // Serial.print("\nAnswer: ");
  // SPI_SlaveAnswer(data);
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
   
   SPCR = (0 << SPIE )  // SPI Interrupt Enable
        | (1 << SPE)    // SPI Enable 
        | (0 << DORD)   // MSB == 0. LSB == 1
        | (0 << MSTR)   // Master == 1. Slave == 0
        | (0 << CPOL)   // Mode 0: CPOL == 0; CPHA == 0 / Mode 1: CPOL == 1; CPHA == 0 / Mode 2: CPOL == 0; CPHA == 1 / Mode 3: CPOL == 1; CPHA == 1 /
        | (0 << CPHA)
        | (0 << SPI2X)  // Freq
        | (1 << SPR1)   // Freq
        | (1 << SPR0);  // Freq
}

uint8_t SPI_SlaveReceive(void)
{
  // Ожидание завершения приема:
  while(!(SPSR & (1 << SPIF)));

  // Вывод в консоль
  Serial.println(SPDR);

  return SPDR;
}

void SPI_SlaveAnswer(uint8_t answer)
{
  // Ожидание завершения приема:
  while(!(SPSR & (1 << SPIF)));
 
  // Отправление ответа
  SPDR = answer;

  // Вывод в консоль
  Serial.println(SPDR);
}
