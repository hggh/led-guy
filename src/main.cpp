#include <Arduino.h>
#include <MAX7219_8x8_matrix.h>
#include <FastLED.h>

#include "chars.h"

#define NUM_LEDS 2
#define EYE_PIN 7
/*
 * 1 = display message
 * 2 = display stars
 */
uint8_t matrix_mode = 1;
CRGB eyes[NUM_LEDS];
uint8_t eyes_color_index = 1;
unsigned long eyes_start_time = 0;
unsigned long eyes_interval_time = 40;

unsigned long matrix_start_time = 0;
unsigned long matrix_interval_time = 0;
bool message_same_char = false;

// LOAD = 11 = CS
// CLK = 13 = CLK
// DIN = 10 = DATA
MAX7219_8x8_matrix LEDmatrix(10,11,13);

String message = String("halloo jonas!");
unsigned int message_index = 0;

const static CRGB::HTMLColorCode colors[35] = {
  CRGB::Crimson,
  CRGB::Red,
  CRGB::DeepPink,
  CRGB::OrangeRed,
  CRGB::SkyBlue,
  CRGB::Orange,
  CRGB::Gold,
  CRGB::Yellow,
  CRGB::DarkRed,
  CRGB::Violet,
  CRGB::Navy,
  CRGB::Fuchsia,
  CRGB::RosyBrown,
  CRGB::MediumOrchid,
  CRGB::BlueViolet,
  CRGB::Indigo,
  CRGB::DarkSlateBlue,
  CRGB::GreenYellow,
  CRGB::Purple,
  CRGB::Lime,
  CRGB::MediumSpringGreen,
  CRGB::ForestGreen,
  CRGB::CadetBlue,
  CRGB::DarkGreen,
  CRGB::LightSeaGreen,
  CRGB::Teal,
  CRGB::Cyan,
  CRGB::SteelBlue,
  CRGB::Blue,
  CRGB::Brown,
  CRGB::DarkBlue,
  CRGB::Chocolate,
  CRGB::SaddleBrown,
  CRGB::Maroon,
  CRGB::DarkSlateGray
};

void print_char(char c) {
  uint8_t *matrix;
  switch (c) {
    case 'a':
      matrix = char_5x5_A;
      break;
    case 'b':
      matrix = char_5x5_B;
      break;
    case 'c':
      matrix = char_5x5_C;
      break;
    case 'd':
      matrix = char_5x5_D;
      break;
    case 'e':
      matrix = char_5x5_E;
      break;
    case 'f':
      matrix = char_5x5_F;
      break;
    case 'g':
      matrix = char_5x5_G;
      break;
    case 'h':
      matrix = char_5x5_H;
      break;
    case 'i':
      matrix = char_5x5_I;
      break;
    case 'j':
      matrix = char_5x5_J;
      break;
    case 'k':
      matrix = char_5x5_K;
      break;
    case 'l':
      matrix = char_5x5_L;
      break;
    case 'm':
      matrix = char_5x5_M;
      break;
    case 'n':
      matrix = char_5x5_N;
      break;
    case 'o':
      matrix = char_5x5_O;
      break;
    case 'p':
      matrix = char_5x5_P;
      break;
    case 'q':
      matrix = char_5x5_Q;
      break;
    case 'r':
      matrix = char_5x5_R;
      break;
    case 's':
      matrix = char_5x5_S;
      break;
    case 't':
      matrix = char_5x5_T;
      break;
    case 'u':
      matrix = char_5x5_U;
      break;
    case 'v':
      matrix = char_5x5_V;
      break;
    case 'w':
      matrix = char_5x5_W;
      break;
    case 'x':
      matrix = char_5x5_X;
      break;
    case 'y':
      matrix = char_5x5_Y;
      break;
    case 'z':
      matrix = char_5x5_Z;
      break;
    case '!':
      matrix = char_5x5_EXCLA;
      break;
  }
  LEDmatrix.setBrightness(0);
  LEDmatrix.matrix(matrix);
}


void setup() {
  Serial.begin(9600);

  LEDmatrix.clear();
  LEDmatrix.setBrightness(0);

  FastLED.addLeds<NEOPIXEL, EYE_PIN>(eyes, NUM_LEDS);
  FastLED.setBrightness(5);

  randomSeed(analogRead(0));

  message.toLowerCase();
}

void clear() {
  LEDmatrix.clear();
}

void set_matrix_interval_time(unsigned long t) {
  matrix_interval_time = t;
  matrix_start_time = millis();
}

void print_message() {
  if (message.charAt(message_index) == message.charAt(message_index - 1)) {
    if (message_same_char == false) {
      message_same_char = true;
      // if the next char is the same as current clear the display for some time
      clear();
      set_matrix_interval_time(400);
      return;
    }
  }
  else {
    message_same_char = false;
  }
  print_char(message.charAt(message_index));
  message_index++;
  set_matrix_interval_time(650);
  return;
}

void print_stars() {
  uint8_t stars[8] = {
    (uint8_t)random(0, 248),
    (uint8_t)random(0, 248),
    (uint8_t)random(0, 248),
    (uint8_t)random(0, 248),
    (uint8_t)random(0, 248),
    0,
    0,
    0
  };
  LEDmatrix.setBrightness(random(0, 3));
  LEDmatrix.matrix(stars);
  set_matrix_interval_time(random(500, 1500));
}

void loop() {
  if (millis() - eyes_start_time >= eyes_interval_time) {
    eyes_start_time = millis();
    eyes_color_index = random(0, 35);
    eyes_interval_time = random(800, 1400);
    FastLED.setBrightness(random(4, 30));
  }
  fill_solid(eyes, NUM_LEDS, colors[eyes_color_index]);
  FastLED.show();

  if (matrix_mode == 1) {
    if (millis() - matrix_start_time >= matrix_interval_time) {
      print_message();
    }
    // we reach the end of the string..
    if (message_index == message.length()) {
      message_index = 0;

      // jump to mode 2
      matrix_mode = 2;
    }
  }

  // Mode: Stars
  if (matrix_mode == 2) {
    if (millis() - matrix_start_time >= matrix_interval_time) {
      print_stars();
    }
  }
}

