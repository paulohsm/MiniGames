#include "sound.h"
#include <Arduino.h>

void Sound::init() {
    pinMode(PIN_BUZZER, OUTPUT);
}

void Sound::playTone(uint16_t frequency, uint32_t durationMs) {
    tone(PIN_BUZZER, frequency, durationMs);
}

void Sound::stopTone() {
    noTone(PIN_BUZZER);
}

Sound sound;