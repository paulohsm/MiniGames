#ifndef SOUND_H
#define SOUND_H

#include <Arduino.h>
#include "config.h"

class Sound {
  public:
  void init();
  void playTone(uint16_t frequency, uint32_t durationMs);
  void stopTone();

  void playIntro() {
    // Melodia "8-bit Fanfare" (duração total: 1500ms)
    playTone(784, 200);   // Sol5 - Tema heroico (início forte)
    delay(50);            // Pequena pausa entre notas
    playTone(659, 150);   // Mi5  
    playTone(523, 150);   // Dó5
    playTone(587, 150);   // Ré5 (transição)
    delay(30);
    playTone(659, 250);   // Mi5 (clímax)
    delay(100);
    playTone(880, 400);   // Lá5 (final glorioso - mais longo)
  };

  void click(){
    playTone(2000, 50);
  };

  void move(){
    playTone(220, 30);
  };

  void point(){
    playTone(330, 40);
  };

  void score(){
    playTone(330, 40);
  };

  void newGame(){
    playTone(523, 30);
  };

  void explosion(){
    playTone(300, 200); 
    playTone(150, 300);
  };

  void gameOver(){
    playTone(300, 200);
    playTone(650, 100);
    playTone(400, 100);
    playTone(150, 200);
  };
    
  void gameWon(){
    playTone(262, 100);  // Dó4
    delay(120);
    playTone(330, 100);  // Mi4
    delay(120);
    playTone(392, 100);  // Sol4
    delay(120);
    playTone(523, 150);  // Dó5
  };
};

extern Sound sound;

#endif