#include<SPI.h>

void write_to_MAX7219(unsigned char addr,unsigned char data)
{
  delay(2);
  digitalWrite(10,LOW);
  SPI.transfer(addr);
  SPI.transfer(data);
  digitalWrite(10,HIGH);
}

void MAX7219_init()
{
  write_to_MAX7219(0x0C,0x01); //Shutdown Register Format - Normal  Operation
  write_to_MAX7219(0x09,0x00); //Decode-Mode Register - No decode for digits 7-0
  write_to_MAX7219(0x0A,0x0D); //Intensity Register Format - 27/32
  write_to_MAX7219(0x0B,0x07); //Scan-Limit Register Format - Display digits 0 1 2 3 4 5 6 7
}

void setup()
{
  SPI.begin();
  pinMode(10,OUTPUT);
  MAX7219_init();
  delay(1000);
}

void loop()
{
  write_to_MAX7219(0x01,0x3C); //Digit 0
  write_to_MAX7219(0x02,0x42); //Digit 1
  write_to_MAX7219(0x03,0x95); //Digit 2
  write_to_MAX7219(0x04,0xA1); //Digit 3
  write_to_MAX7219(0x05,0xA1); //Digit 4
  write_to_MAX7219(0x06,0x95); //Digit 5
  write_to_MAX7219(0x07,0x42); //Digit 6
  write_to_MAX7219(0x08,0x3C); //Digit 7
}
