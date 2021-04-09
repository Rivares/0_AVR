//#include <SPI.h>
//
//char buf [100];
//volatile byte pos;
//volatile boolean process_it;
//
//// set pin 10 as the slave select
//const int m_pin_SS = 10;
//
//uint16_t receivedData_SPI();
//
//void setup (void)
//{
//  Serial.begin (115200);   // debugging
//
//  // set the controller is Slave
//  pinMode(m_pin_SS, INPUT);
//  pinMode(MISO, OUTPUT);
//  pinMode(MOSI, INPUT);
//  pinMode(SCK, INPUT);
//
//  SPI.begin();
// 
////  // turn on SPI in slave mode
////  SPCR |= _BV(SPE);
////  
////  // get ready for an interrupt 
////  pos = 0;   // buffer empty
////  process_it = false;
////
////  // now turn on interrupts
////  SPI.attachInterrupt();
//
//}  // end of setup
//
//
//// SPI interrupt routine
//ISR (SPI_STC_vect)
//{
//  byte c = SPDR;  // grab byte from SPI Data Register
//
////      /* Ожидание завершения приема: */
////       while(!(SPSR & (1 << SPIF)));
//       
//  // add to buffer if room
////  if (pos < sizeof buf)
////  {
////    buf[pos++] = c;
//  
////    // example: newline means time to process buffer
////    if (c == '\n')
////      process_it = true;
//
//Serial.print("ISR:");
//    Serial.print(c);
//
//    
////  }  // end of room available
//}  // end of interrupt routine SPI_STC_vect
//
//// main loop - wait for flag set in interrupt routine
//void loop (void)
//{
////  if (process_it)
////  {
////    buf [pos] = 0;  
////    Serial.println (buf);
////    pos = 0;
////    process_it = false;
////  }  // end of flag set
//
//  uint16_t m_data = 0;
//  
//  m_data = receivedData_SPI();
//
//  Serial.println("Recived: ");
//  Serial.print("m_data: ");Serial.println(m_data);   
//}
//
//uint16_t receivedData_SPI()
//{
//  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
//  
//  uint16_t data;
//  data = SPI.transfer16(m_pin_SS);  //0×00 is a dummy
////  data |= (uint16_t)SPI.transfer(m_pin_SS) << 8;
////  data |= (uint16_t)SPI.transfer(m_pin_SS) << 16;
////  data |= (uint16_t)SPI.transfer(0xff) << 24;
//
//  delay(1000);
//  SPI.endTransaction();     // this allows other to use the SPI bus
//  
//  return data;
//}








//
//#include <SPI.h>
//
//volatile uint8_t byteCount = 0;
//volatile bool dataReady = false;
//
//float data;
//byte *ptr = (byte *)&data;
//
//// SPI interrupt routine
//ISR(SPI_STC_vect)
//{
//  ptr[byteCount++] = SPDR;    //read one byte form SPI Data Regiser
//  if (byteCount == 4)
//  {
//    dataReady = true;
//  }
//}
//
//void setup (void)
//{
//  Serial.begin(115200);
//  Serial.println("\nSPI Slave");
//  
//  SPCR |= bit(SPE);        // enable SPI slave mode
//  
//  pinMode(SS, INPUT);
//  pinMode(MISO, OUTPUT);
//  pinMode(MOSI, INPUT);
//  pinMode(SCK, INPUT);
//  
//  SPI.attachInterrupt();
//}
//
//void loop (void)
//{
////  uint16_t data;
////  data = SPI.transfer(SS);  //0×00 is a dummy
////    data |= (uint16_t)SPI.transfer(SS) << 8;
////  //  data |= (uint16_t)SPI.transfer(m_pin_SS) << 16;
////  //  data |= (uint16_t)SPI.transfer(0xff) << 24;
//  
////  Serial.println(data);
//
//  
//  if (dataReady)
//  {
//    Serial.println("Ready");
//    Serial.println(*ptr, 5);
//    byteCount = 0;    // reset byteCount and dataReady flag
//    dataReady = false;
//  }
//}






//
//#include <SPI.h>
//
//char buf [100];
//volatile byte pos;
//volatile boolean process_it;
//
//// set pin 10 as the slave select
//const int m_pin_SS = 10;
//
//uint16_t receivedData_SPI();
//
//void setup (void)
//{
//  Serial.begin (115200);   // debugging
//
//  // set the controller is Slave
//  pinMode(m_pin_SS, INPUT);
//  pinMode(MISO, OUTPUT);
//  pinMode(MOSI, INPUT);
//  pinMode(SCK, INPUT);
//
//  SPI.begin();
// 
////  // turn on SPI in slave mode
////  SPCR |= _BV(SPE);
////  
////  // get ready for an interrupt 
////  pos = 0;   // buffer empty
////  process_it = false;
////
////  // now turn on interrupts
////  SPI.attachInterrupt();
//
//}  // end of setup
//
//
//// SPI interrupt routine
//ISR (SPI_STC_vect)
//{
//  byte c = SPDR;  // grab byte from SPI Data Register
//  
//  // add to buffer if room
//  if (pos < sizeof buf)
//  {
//    buf [pos++] = c;
//  
//    // example: newline means time to process buffer
//    if (c == '\n')
//      process_it = true;
//    
//  }  // end of room available
//}  // end of interrupt routine SPI_STC_vect
//
//// main loop - wait for flag set in interrupt routine
//void loop (void)
//{
////  if (process_it)
////  {
////    buf [pos] = 0;  
////    Serial.println (buf);
////    pos = 0;
////    process_it = false;
////  }  // end of flag set
//
//  uint16_t m_data = 0;
//  
//  m_data = receivedData_SPI();
//
//  Serial.println("Recived: ");
//  Serial.print("m_data: ");Serial.println(m_data);   
//}
//
//uint16_t receivedData_SPI()
//{
//  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
//  
//  uint16_t data;
//  data = SPI.transfer16(m_pin_SS);  //0×00 is a dummy
////  data |= (uint16_t)SPI.transfer(m_pin_SS) << 8;
////  data |= (uint16_t)SPI.transfer(m_pin_SS) << 16;
////  data |= (uint16_t)SPI.transfer(0xff) << 24;
//
//  delay(1000);
//  SPI.endTransaction();     // this allows other to use the SPI bus
//  
//  return data;
//}









//#include <SPI.h>
//
//volatile uint8_t byteCount = 0;
//volatile bool dataReady = false;
//
//float data;
//uint8_t *ptr = (uint8_t *)&data;
//
//// SPI interrupt routine
//ISR(SPI_STC_vect)
//{
//  ptr[byteCount++] = SPDR;    //read one byte form SPI Data Regiser
//  if (byteCount == 4)
//  {
//    dataReady = true;
//  }
//}
//
//void setup (void)
//{
//  Serial.begin(115200);
//  Serial.println("\nSPI Slave");
//  
//  SPCR |= bit(SPE);        // enable SPI slave mode
//  
//  pinMode(SS, INPUT);
//  pinMode(MISO, OUTPUT);
//  pinMode(MOSI, INPUT);
//  pinMode(SCK, INPUT);
//  
//  SPI.attachInterrupt();
//}
//
//void loop (void)
//{
//  uint16_t data;
//  data = SPI.transfer(SS);  //0×00 is a dummy
//    data |= (uint16_t)SPI.transfer(SS) << 8;
//    data |= (uint16_t)SPI.transfer(SS) << 16;
//  //  data |= (uint16_t)SPI.transfer(0xff) << 24;
//  
//  Serial.println(data);
//
//  
//  if (dataReady)
//  {
//    Serial.println(*ptr, 5);
//    byteCount = 0;    // reset byteCount and dataReady flag
//    dataReady = false;
//  }
//}





// void setup (void)
// {
//   Serial.begin(115200);
//   Serial.println("\nSPI Slave");

//   SPI_SlaveInit();
// }

// void loop (void)
// {
//   Serial.print("\nReceive: ");
//   uint8_t data = SPI_SlaveReceive();

//   Serial.print("\nAnswer: ");
//   SPI_SlaveAnswer(data);
// }

// void SPI_SlaveInit(void)
// {
//   pinMode(SS, INPUT);
//   pinMode(MISO, OUTPUT);
//   pinMode(MOSI, INPUT);
//   pinMode(SCK, INPUT);

//   // Разрешить работу SPI:

//   //SPCR – SPI Control Register – This register is basically the master register i.e. it contains the bits to initialize SPI and control it.
//   //SPSR – SPI Status Register – This is the status register. This register is used to read the status of the bus lines.
//   //SPDR – SPI Data Register – The SPI Data Register is the read/write register where the actual data transfer takes place.
  
//   // SPIF – SPI Interrupt Flag
   
//    SPCR = (0 << SPIE )  // SPI Interrupt Enable
//         | (1 << SPE)    // SPI Enable 
//         | (0 << DORD)   // MSB == 0. LSB == 1
//         | (0 << MSTR)   // Master == 1. Slave == 0
//         | (0 << CPOL)   // Mode 0: CPOL == 0; CPHA == 0 / Mode 1: CPOL == 1; CPHA == 0 / Mode 2: CPOL == 0; CPHA == 1 / Mode 3: CPOL == 1; CPHA == 1 /
//         | (0 << CPHA)
//         | (0 << SPI2X)  // Freq
//         | (1 << SPR1)   // Freq
//         | (1 << SPR0);  // Freq
// }

// uint8_t SPI_SlaveReceive(void)
// {
//   // Ожидание завершения приема:
//   while(!(SPSR & (1 << SPIF)));

//   // Вывод в консоль
//   Serial.println(SPDR);

//   return SPDR;
// }

// void SPI_SlaveAnswer(uint8_t answer)
// {
//   // Ожидание завершения приема:
//   while(!(SPSR & (1 << SPIF)));
 
//   // Отправление ответа
//   SPDR = answer;

//   // Вывод в консоль
//   Serial.println(SPDR);
// }




#define LED_PIN  8
 
volatile uint8_t led_blink = 0;
static uint8_t data_byte = 0;
 
ISR(SPI_STC_vect)
{
    data_byte = SPDR;
 
    switch (data_byte)
    {
        case 0x21:
            // Place LED blinking status in SPDR register for next transfer
            led_blink = 1;
            SPDR = led_blink;  
        break;
    }  
}
 
void setup()
{
    Serial.begin(115200);
    
    pinMode(LED_PIN, OUTPUT);
    
    Serial.println("Recieve:");
    SPI_SlaveInit();
}
 
void loop() 
{
    // If LED blink status is on, then blink LED for 250ms
    if (led_blink == 1)
    {
        digitalWrite(LED_PIN, HIGH);
        delay(250);
        digitalWrite(LED_PIN, LOW);
        delay(250);  
    }
    else if (led_blink == 0)
    {
        digitalWrite(LED_PIN, LOW); 
    }

    Serial.println(data_byte);
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
   
   SPCR = (1 << SPIE )  // SPI Interrupt Enable
        | (1 << SPE)    // SPI Enable 
        | (0 << DORD)   // MSB == 0. LSB == 1
        | (0 << MSTR)   // Master == 1. Slave == 0
        | (0 << CPOL)   // Mode 0: CPOL == 0; CPHA == 0 / Mode 1: CPOL == 1; CPHA == 0 / Mode 2: CPOL == 0; CPHA == 1 / Mode 3: CPOL == 1; CPHA == 1 /
        | (0 << CPHA)
        | (0 << SPI2X)  // Freq
        | (1 << SPR1)   // Freq
        | (1 << SPR0);  // Freq
}
