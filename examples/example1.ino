#include <Arduino.h>
#include "pcb.h"
#include <AbsoluteEncoder.h>

#define ROTARYRESOLUTION 12 // nuber bits for rotations
#define STEPRESOLUTION 10 // nuber bits for steps/rotation

AbsoluteEncoder myEncoder(PIN_CLOCK_TX, PIN_DATA_RX, ROTARYRESOLUTION, STEPRESOLUTION, 0);

uint16_t rotation;
uint16_t step;
uint8_t  errorBit;


void setup() {
  myEncoder.begin();
  Serial.end();
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  delay(1000);
}

void loop() {
  myEncoder.read(rotation, step, errorBit, 1);
  Serial2.print(" Rotation -> "); Serial2.print(rotation, 10);
  Serial2.print(" Error bit -> "); Serial2.print(errorBit, 10);
  Serial2.print(" step ->"); Serial2.println(step, 10);
  delay(500);
}

