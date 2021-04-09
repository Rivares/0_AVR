/***************************************************************************************************
  This chip uses I2C bus to communicate, specials pins are required to interface
  Board:                                    SDA                    SCL                    Level
  Uno, Mini, Pro, ATmega168, ATmega328..... A4                     A5                     5v
  Mega2560................................. 20                     21                     5v
***************************************************************************************************/
#include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// #include <OneWire.h>


// #define COLUMS           16
// #define ROWS             2

// #define LCD_SPACE_SYMBOL 0x20  //space symbol from the LCD ROM, see p.9 of GDM2004D datasheet

// LiquidCrystal_I2C lcd(PCF8574A_ADDR_A21_A11_A01, 4, 5, 6, 16, 11, 12, 13, 14, POSITIVE);
// OneWire  ds(2);  // on pin d2 (a 4.7K resistor is necessary)
// int sensorPin1 = A3;
// int sensorPin2 = 3;

void setup()
{
  Serial.begin(115200);

  // while (lcd.begin(COLUMS, ROWS) != 1) //colums - 20, rows - 4
  // {
  //   Serial.println(F("PCF8574 is not connected or lcd pins declaration is wrong. Only pins numbers: 4,5,6,16,11,12,13,14 are legal."));
  //   delay(5000);   
  // }

  // lcd.print(F("PCF8574 is OK..."));    //(F()) saves string to flash & keeps dynamic memory free
  // delay(2000);

  // lcd.clear();
  
  // lcd.print(F("Hello my lord!"));
  // delay(2000);

  // lcd.clear();
  
  // lcd.print(F("Temp., C:"));

  // lcd.setCursor(0, 2);
  // lcd.print(F("Humidity, %:"));


  
}

void loop()
{
  // int sensorValue = 0;
  // byte i;
  // byte present = 0;
  // byte type_s;
  // byte data[12];
  // byte addr[8];
  // float celsius, fahrenheit;
  
  // if ( !ds.search(addr))
  // {
  //   Serial.println("No more addresses.");
  //   Serial.println();
  //   ds.reset_search();
  //   delay(250);
  //   return;
  // }

  // Serial.print("ROM =");
  // for( i = 0; i < 8; i++) {
  //   Serial.write(' ');
  //   Serial.print(addr[i], HEX);
  // }
  
  // if (OneWire::crc8(addr, 7) != addr[7]) {
  //     Serial.println("CRC is not valid!");
  //     return;
  // }
  // Serial.println();
 
  // // the first ROM byte indicates which chip
  // switch (addr[0]) {
  //   case 0x10:
  //     Serial.println("  Chip = DS18S20");  // or old DS1820
  //     type_s = 1;
  //     break;
  //   case 0x28:
  //     Serial.println("  Chip = DS18B20");
  //     type_s = 0;
  //     break;
  //   case 0x22:
  //     Serial.println("  Chip = DS1822");
  //     type_s = 0;
  //     break;
  //   default:
  //     Serial.println("Device is not a DS18x20 family device.");
  //     return;
  // } 

  // ds.reset();
  // ds.select(addr);
  // ds.write(0x44, 1);        // start conversion, with parasite power on at the end
  
  // delay(1000);     // maybe 750ms is enough, maybe not
  // // we might do a ds.depower() here, but the reset will take care of it.
  
  // present = ds.reset();
  // ds.select(addr);    
  // ds.write(0xBE);         // Read Scratchpad

  // Serial.print("  Data = ");
  // Serial.print(present, HEX);
  // Serial.print(" ");
  // for ( i = 0; i < 9; i++) {           // we need 9 bytes
  //   data[i] = ds.read();
  //   Serial.print(data[i], HEX);
  //   Serial.print(" ");
  // }
  // Serial.print(" CRC=");
  // Serial.print(OneWire::crc8(data, 8), HEX);
  // Serial.println();

  // // Convert the data to actual temperature
  // // because the result is a 16 bit signed integer, it should
  // // be stored to an "int16_t" type, which is always 16 bits
  // // even when compiled on a 32 bit processor.
  // int16_t raw = (data[1] << 8) | data[0];
  // if (type_s)
  // {
  //   raw = raw << 3; // 9 bit resolution default
  //   if (data[7] == 0x10)
  //   {
  //     // "count remain" gives full 12 bit resolution
  //     raw = (raw & 0xFFF0) + 12 - data[6];
  //   }
  // }
  // else
  // {
  //   byte cfg = (data[4] & 0x60);
  //   // at lower res, the low bits are undefined, so let's zero them
  //   if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
  //   else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
  //   else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
  //   //// default is 12 bit resolution, 750 ms conversion time
  // }
  // celsius = (float)raw / 16.0;
  // fahrenheit = celsius * 1.8 + 32.0;
  // Serial.print("  Temperature = ");
  // Serial.print(celsius);
  // Serial.print(" Celsius, ");
  // Serial.print(fahrenheit);
  // Serial.println(" Fahrenheit");

  // // Set temperature value to LCD
  // lcd.setCursor(11, 0);
  // lcd.print(celsius);
  // //lcd.write(LCD_SPACE_SYMBOL);

  // // Get value humidity of sensor
  // sensorValue = analogRead(sensorPin1) / 10;
  // Serial.println(sensorValue);
  // //sensorValue = digitalRead(sensorPin2);
  // //Serial.println(sensorValue);
  // delay(100);

  // // Set value humidity to LCD
  // lcd.setCursor(12, 1);
  // lcd.print(sensorValue);
  // lcd.write(LCD_SPACE_SYMBOL);

  // delay(1000);


}