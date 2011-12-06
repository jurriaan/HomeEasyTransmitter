// 
// Home Easy Transmitter v1.0
// Copyright (c) 2011 Jurriaan Pruis <email@jurriaanpruis.nl>
// MIT Licensed
//

#include "Arduino.h"
#include "HomeEasyTransmitter.h"

const byte HomeEasyTransmitter::_channels[16] = {B00111,B01011,B01101,B01110,
												B10011,B10101,B10110,B11001,
												B11010,B11100,B00011,B00101,
												B00110,B01001,B01010,B01100};

// PUBLIC
HomeEasyTransmitter::HomeEasyTransmitter(byte address[6], int pin) {
	_address = address;
	_pin = pin;
	pinMode(_pin,OUTPUT); 
}

void HomeEasyTransmitter::transmit(int channel, bool state) {
	_transmit(channel,state);
	delay(7); 
	_transmit(channel,state);
	delay(7); 
	_transmit(channel,state);
	delay(15);
}

// PRIVATE
void HomeEasyTransmitter::_transmit(int channel, bool state) {
  int i;
  _sendBit(true); // Start bit?
  for(i = 0; i < 5;i++) {
    _sendByte(_address[i]); // Device code(the 6th and 7th byte are also part of it, but the last two bytes decide the state)
  }
  _sendByte(_address[5] | (state? B10:B01)); // ON/OFF
  _sendByte(B01000000 | _channels[channel]); // Channel
  _sendBit(true); // Stop bit?
}

void HomeEasyTransmitter::_sendByte(byte b) {
  int i;
  for(i = 0;i < 8;i++) {
    _sendBit((B10000000 & (b << i)) != 0);
  }
}


void HomeEasyTransmitter::_sendBit(bool b) {
	digitalWrite(_pin, HIGH);
    delayMicroseconds(275);   
	digitalWrite(_pin, LOW);
	delayMicroseconds(b? 1225:275);  
}

