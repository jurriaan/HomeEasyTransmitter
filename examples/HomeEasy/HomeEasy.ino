/*
 * HE300W by Jurriaan Pruis
 */
#include <HomeEasyTransmitter.h>

// 6 byte identification code
byte code[6]={B10001111,B00101110,B11010100,B01111011,B01011000,B11101100}; // exclusive start and stop bit, and has to be OR-red with channel and state(10/01)

HomeEasyTransmitter transmitter = HomeEasyTransmitter(code, 10); // pin 433 Mhz transmitter on pin 10

void setup()
{
  transmitter.transmit(0, true); // turn on device on first channel
}

void loop()
{
  
}

