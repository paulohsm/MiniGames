// config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_SH110X.h>
#include <EEPROM.h>
#include <Ethnocentric_Rg_It5pt7b.h>


// Button Pins
#define PIN_BUTTON_UP 5 //4
#define PIN_BUTTON_DOWN 22 //5
#define PIN_BUTTON_LEFT 4 //15
#define PIN_BUTTON_RIGHT 21 //18

// Display Pins
#define PIN_SCL 27 //22
#define PIN_SDA 26 //21

// Display Setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

// Sound Setup
#define PIN_BUZZER 25 //13
#define BUZZER_CHANNEL LEDC_CHANNEL_0
#define BUZZER_RESOLUTION 8

// Game Constants
#define MAX_GAMES 8
#define BUTTON_DELAY 150

// Game IDs
enum GameID {
  GAME_SNAKE = 0,
  GAME_TETRIS = 1,
  GAME_FLAPPY = 2,
  GAME_2048 = 3,
  GAME_BREAKOUT = 4,
  GAME_FROGGER = 5,
  GAME_HELICOPTER = 6,
  GAME_PACMAN = 7
};

// Game States
enum GameState {
  STATE_MENU,
  STATE_PLAYING,
  STATE_GAME_OVER,
  STATE_GAME_WON
};

// Global display object
//extern Adafruit_SSD1306 display;
//Adafruit_SH1106 display(OLED_RESET);
//Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
extern Adafruit_SH1106G display;

#endif