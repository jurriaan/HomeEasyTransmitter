// 
// Home Easy Transmitter v1.0
// Copyright (c) 2011 Jurriaan Pruis <email@jurriaanpruis.nl>
// MIT Licensed
// 

#ifndef HETrans
#define HETrans 

#include "Arduino.h"

class HomeEasyTransmitter
{
public:
  HomeEasyTransmitter(byte address[6], int pin);
	void transmit(int channel, bool state);
private:
	int _pin;
	byte *_address;
	static const byte _channels[16];
	void _transmit(int channel, bool state);
	void _sendBit(bool b);
	void _sendByte(byte b);
};

#endif