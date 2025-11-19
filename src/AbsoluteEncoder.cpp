#include "AbsoluteEncoder.h"

AbsoluteEncoder::AbsoluteEncoder(int pinClock, int pinData, uint8_t rotaryRes, uint8_t stepRes, int pinSet){
    _pinClock = pinClock;
    _pinData = pinData;
    _pinSet = pinSet;
}

AbsoluteEncoder::~AbsoluteEncoder()
{
}

void AbsoluteEncoder::read(uint16_t &rotations, uint16_t &step, uint8_t &error, uint8_t typeResult){
    rotations = 0;
    step = 0;
    error = 0;
    digitalWrite(this->_pinClock,LOW);  //(1) technical_information_ssi_interface_description_en_im0100079.pdf page 5
  delayMicroseconds(5);
  digitalWrite(this->_pinClock,HIGH); //(2)
  delayMicroseconds(5);

  for (int i=0; i<this->_rotaryRes; i++) {
    rotations <<= 1;
    digitalWrite(this->_pinClock,LOW);
    delayMicroseconds(5);
    rotations |= digitalRead(_pinData);
    digitalWrite(this->_pinClock,HIGH);
    delayMicroseconds(5);
  }
  
  for (int i=0; i<_stepRes; i++) {
    step <<= 1;
    digitalWrite(this->_pinClock,LOW);
    delayMicroseconds(5);
    step |= digitalRead(_pinData);
    digitalWrite(this->_pinClock,HIGH);
    delayMicroseconds(5);
  }

  for (int i=0; i<_errorRes; i++) {
  error <<= 1;
  digitalWrite(this->_pinClock,LOW);
  delayMicroseconds(5);
  error |= digitalRead(_pinData);
  digitalWrite(this->_pinClock,HIGH);
  delayMicroseconds(5);
  }

  if (typeResult == 1)
  {
    step = gray2bin(step);
    rotations = gray2bin(rotations);
  }
  

}

uint16_t AbsoluteEncoder::gray2bin(uint16_t gray){
  int res = gray;
	while (gray > 0)
	{
		gray >>= 1;
		res ^= gray;
	}
	return res;
}

void AbsoluteEncoder::begin(){
  pinMode(this->_pinClock, OUTPUT);
  pinMode(this->_pinData, INPUT_PULLUP);
  pinMode(this->_pinSet, OUTPUT);
  digitalWrite(this->_pinClock, HIGH);
  digitalWrite(this->_pinSet, LOW);
}