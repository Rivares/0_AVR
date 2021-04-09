volatile uint8_t m_data = 0x05;

// ISR(SPI_STC_vect)
// {
//   data = SPDR;
// }

void setup (void)
{
  Serial.begin(115200);

  SPI_SlaveInit();
}

void loop (void)
{ 
  uint8_t local_tmp = SPI_SlaveReceive();
  SPI_SlaveSend(m_data);


  local_tmp = SPSR;
  local_tmp = SPDR;
  
  Serial.print("\nSPDR = "); Serial.print(local_tmp);
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












































// //  Слейв, принимает строки от мастера
// //  На каждый принятый байт отвечает числом - 
// //  длиной принятой на данный момент строки
// // Когда строка прията полностью (ограничена '\0'),\
// //  строка печатается для визуального контроля.
// //
// #include <SPI.h>
// #include "Printing.h"

// void setup(void)
// {
//   Serial.begin(115200);

//   SPI.begin();
//   SPI.beginTransaction(SPISettings());
  
//   pinMode(MISO, OUTPUT);
//   pinMode(MOSI, INPUT);
//   pinMode(SCK, INPUT);
//   pinMode(SS, INPUT);
  
//   SPI.attachInterrupt();  // Включаем прерывания
// }

// //
// //  Буфер, указатель и флаг готовности строки для печати
// //  Контроля переполнения буфера нет, чтобы не усложнять пример
// //
// static char receivedBuffer[128];
// static volatile char * bufPtr = receivedBuffer;
// static bool stringIsReady = false;

// ISR(SPI_STC_vect)
// {
//   // принятый байт кладём в буфер, в br и продвигаем указатель буфера
//   const char br = *bufPtr++ = SPDR;

//   // длина принятой на данный момент строки уйдёт 
//   // мастеру при передаче следующего байта 
//   SPDR = bufPtr - receivedBuffer;  

//   // Если приняли 0, сигнализируем, что строка принята
//   // и восстанавливаем буфер на начало
//   if (br == '\0')
//   {
//     bufPtr = receivedBuffer;
//     stringIsReady = true;
//   }
// }

// void loop(void)
// {
//   //  Если принята строка, то печатем её
//   if (stringIsReady)
//   {
//     stringIsReady = false;
    
//     // в начале печтаем : - чтобы было видно,
//     //  если приняли пустую строку
//     Serial << ':' << receivedBuffer << "\r\n";
//   }
// }
