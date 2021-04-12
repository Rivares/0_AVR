#define PIN_PIR 7
#define PIN_LED 4

volatile uint8_t m_data = 0x05;

void setup (void)
{
  Serial.begin(115200);

  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_LED, OUTPUT);

  SPI_SlaveInit();
}

void loop (void)
{ 
  // Slave work.........

  int m_detect_action = digitalRead(PIN_PIR);
    
  if (m_detect_action)
  {
    //Если обнаружили движение
    digitalWrite(PIN_LED, HIGH);
  }
  else
  {
    digitalWrite(PIN_LED, LOW);
  }

  // ________________________________________________
  
  // Connection with Master

  m_data = m_data + m_detect_action;
  Serial.println(m_data);

  volatile uint8_t local_tmp = SPI_SlaveReceive();
  SPI_SlaveSend(m_data);
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
