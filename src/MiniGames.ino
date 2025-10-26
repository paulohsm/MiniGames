// GameSystem.ino - Hack_updt
#include "config.h"
#include "display.h"
#include "input.h"
#include "gamemanager.h"
#include "highscore.h"
#include "sound.h"

void intro(){
  display.clearDisplay();
  display.drawBitmap(0, 0, epd_bitmap_Intro, 128, 64, 1);
  display.display();
  sound.playIntro();
}

void setup() {
  Serial.begin(115200);
  initDisplay();
  sound.init();
  intro();
  delay(3000);
  initInput();
  initHighscores();
  initGameManager();
}

void loop() {
  updateInput();
  updateGameManager();
  delay(16); // ~60 FPS
}