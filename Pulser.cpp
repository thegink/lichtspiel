#include <Arduino.h>
#include "Pulser.h"

Pulser::Pulser(uint8_t _pin) {
  pin = _pin;
  lastUpdate = 0;
  value = 255;
  direction = -1;
}

void Pulser::pulse() {
  uint32_t now = millis();
  while (now - lastUpdate > delay) {
    lastUpdate += delay;
    value += direction;
    if (value == 280 || value == 160) direction = -direction;
  }
  if (value < 256) analogWrite(pin, value);
}

void Pulser::steady() {
  analogWrite(pin, 128);
}
