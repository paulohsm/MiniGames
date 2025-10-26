#include "display.h"

//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT);

void initDisplay() {
  Wire.begin(PIN_SDA, PIN_SCL);
  
//  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
//    Serial.println(F("SSD1306 allocation failed"));
//    for(;;);
//  }

// Tenta o endereço mais comum (0x3C)
  if(!display.begin(SCREEN_ADDRESS)) {
    Serial.println(F("SH1106G não encontrado no endereço 0x3C, tentando 0x3D..."));
    
    // Se falhar, tenta o endereço alternativo (0x3D)
    if(!display.begin(0x3D)) {
        Serial.println(F("SH1106G não encontrado em 0x3D. Parando a execução."));
        while(true); // Bloqueia o programa se nenhum display for encontrado
    }
    Serial.println(F("SH1106G encontrado em 0x3D!"));
  } else {
    Serial.println(F("SH1106G encontrado em 0x3C!"));
  }
  
  display.clearDisplay();
  display.display();

  display.setRotation(2); // Orientação normal  
}

void clearDisplay() {
  display.clearDisplay();
}

void updateDisplay() {
  display.display();
}

void drawCenteredText(const char* text, int y, int textSize) {
  display.setTextSize(textSize);
  //display.setTextColor(SSD1306_WHITE);
  display.setTextColor(SH110X_WHITE);
  
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  display.setCursor((SCREEN_WIDTH - w) / 2, y);
  display.print(text);
}

void drawHighlightBox(int x, int y, int w, int h, bool inverted) {
  if (inverted) {
    //display.fillRect(x, y, w, h, SSD1306_WHITE);
    display.fillRect(x, y, w, h, SH110X_WHITE);
  } else {
    //display.drawRect(x, y, w, h, SSD1306_WHITE);
    display.drawRect(x, y, w, h, SH110X_WHITE);
  }
}