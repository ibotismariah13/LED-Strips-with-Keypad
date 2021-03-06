#define FASTLED_INTERNAL
#include <FastLED.h>
#include <Keypad.h>
#define NUM_LEDS 65 //number of LEDs
# define NUM_WHITE 3
# define LED_PIN 10

//initialized variables
int brightNum = 50;
int r = 0;
int g = 0;
int b = 0;
int amount = 1;
int delayNum = 5;
int amountDelay = 1;
boolean delaytf = true;
char key;
int lastDelay = delayNum;
const byte rows = 4; //four rows
const byte cols = 4; //three columns
boolean isHashtagHold = false;
boolean isStarHold = false;
CRGB leds[NUM_LEDS];
boolean wtf = false;
char mode;
unsigned long previousMillis = 0;
const long interval = 50;
char function = '0';
CRGB color = CRGB::Blue;
char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[rows] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[cols] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad
Keypad key2 = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

//sets up everything
void setup() {
  FastLED.addLeds < WS2812, LED_PIN, GRB > (leds, NUM_LEDS);
  Serial.begin(9600);
  mode = 'A';
  key2.addEventListener(keypadEvent);
}
//constant running code
void loop() {
  Serial.println(delayNum);
  delayThing();
  colorChange(); //change color
  brightness(); // change brightness
  key = key2.getKey();
  Serial.println(function);
  /* leds[0] = CRGB::Black;
    leds[1] = CRGB::Black;
    leds[2] = CRGB::Black;
    leds[3] = CRGB::Black;
    leds[4] = CRGB::Black; */
  // aris code
  if (mode == 'A') {
    ariLogic();

  } //Mariah Code Red
  else if (mode == 'C') {
    mariahLogic(CRGB::Red, CRGB::Black);
  }
  //Mariah Code Blue
  else if (mode == 'B') {
    mariahLogic(CRGB::Blue, CRGB::Black );

  }
  //Mariah Code GaCo
  else if (mode == 'D') {
    mariahLogic(CRGB::Red, CRGB::Blue );

  }
}

//sets strip to current color
void colorOn() {
  amount = 1;
  for (int i = 1; i < NUM_LEDS; i++) {
    leds[i] = color;
  }
  FastLED.show();
  if (mode == '1') {

  }
}


void whiteLine() {
  if (function == '2') {
    for (int j = 25; j < NUM_LEDS - 2; j++) {

      //a++;
      leds[j] = CRGB(255, 255, 255);
      /* leds[0] = CRGB::Black;
        leds[1] = CRGB::Black;
        leds[2] = CRGB::Black;
        leds[3] = CRGB::Black;
        leds[4] = CRGB::Black; */
      FastLED.show();
      leds[NUM_LEDS - j] = CRGB(255, 255, 255);
      /* leds[0] = CRGB::Black;
        leds[1] = CRGB::Black;
        leds[2] = CRGB::Black;
        leds[3] = CRGB::Black;
        leds[4] = CRGB::Black; */
      FastLED.show();
      leds[j + 1] = CRGB(255, 255, 255);
      /* leds[0] = CRGB::Black;
        leds[1] = CRGB::Black;
        leds[2] = CRGB::Black;
        leds[3] = CRGB::Black;
        leds[4] = CRGB::Black; */
      FastLED.show();
      leds[NUM_LEDS - j - 1] = CRGB(255, 255, 255);
      /* leds[0] = CRGB::Black;
        leds[1] = CRGB::Black;
        leds[2] = CRGB::Black;
        leds[3] = CRGB::Black;
        leds[4] = CRGB::Black; */
      FastLED.show();
      leds[j + 2] = CRGB(255, 255, 255);
      /* leds[0] = CRGB::Black;
        leds[1] = CRGB::Black;
        leds[2] = CRGB::Black;
        leds[3] = CRGB::Black;
        leds[4] = CRGB::Black; */
      FastLED.show();
      leds[NUM_LEDS - j - 2] = CRGB(255, 255, 255);
      /* leds[0] = CRGB::Black;
        leds[1] = CRGB::Black;
        leds[2] = CRGB::Black;
        leds[3] = CRGB::Black;
        leds[4] = CRGB::Black; */
      FastLED.show();

      leds[j] = color;
      leds[NUM_LEDS - j] = color;
      /* leds[0] = CRGB::Black;
        leds[1] = CRGB::Black;
        leds[2] = CRGB::Black;
        leds[3] = CRGB::Black;
        leds[4] = CRGB::Black; */
      Serial.println(j);
      Serial.println(j);
      myDelay(delayNum);

      Serial.println("white line");

    }
    for (int i = 1; i < NUM_LEDS; i++) {
      leds[i] = color;
    }
    FastLED.show();
  }
}

//color fashing
void party() {
  for (int i = 1; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
  }
  myDelay(delayNum);
  for (int i = 1; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Purple;
    FastLED.show();
  }
  myDelay(delayNum);
  for (int i = 1; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
  }
  myDelay(delayNum);
  for (int i = 1; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Yellow;
    FastLED.show();
  }
  myDelay(delayNum);
  for (int i = 1; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
  }
  myDelay(delayNum);

}

//snake of lights
void snake() {
  if (function != '4') goto stupid;
  for (int i = 1; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay4(delayNum, '4');
    Serial.println(function);
  }
  if (function != '4') goto stupid;
  for (int i = 4; i < NUM_LEDS; i++) {
    leds[i] = color;
    FastLED.show();
    delay4(delayNum, '4');
  }
stupid: String stupid = "Bennett";
}
//delays?
void delay4(int time, char fun) {
  unsigned long t = millis();
  t = 0;
  while (t < time) {
    check();
    delayThing();
    colorChange();
    brightness();
    if (function != '4') {
      goto nothing;
    }
    t++;
  }
  Serial.println(t);
nothing: String no = "no";
}

void festivalLights() {
  int Position = 0;
  for (int i = 0; i < 6; i++) {
    Position++; // = 0; //Position + Rate;
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(((sin(i + Position) * 127 + 128) / 255) * r,
                     ((sin(i + Position) * 127 + 128) / 255) * g,
                     ((sin(i + Position) * 127 + 128) / 255) * b);
    }

    FastLED.show();
    myDelay(delayNum);
  }
}

// from https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
void meteorRain(byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay) {
  FastLED.clear();
  for (int i = 4; i < NUM_LEDS; i++) {

    if (function != '6') goto hello;
    // fade brightness all LEDs one step
    for (int j = 0; j < NUM_LEDS; j++) {
      if ((!meteorRandomDecay) || (random(10) > 5)) {
        fadeToBlack(j, meteorTrailDecay);
      }
    }
    if (function != '6') goto hello;
    // draw meteor
    for (int j = 0; j < meteorSize; j++) {
      if ((i - j < NUM_LEDS) && (i - j >= 0)) {
        leds[i] = CRGB(r, g, b);
      }
    }

    FastLED.show();
    myDelay(delayNum);
hello: String hello = "hi";
  }
}

void fadeToBlack(int ledNo, byte fadeValue) {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  uint32_t oldColor;
  uint8_t red, green, blue;
  int value;

  oldColor = strip.getPixelColor(ledNo);
  red = (oldColor & 0x00ff0000 UL) >> 16;
  green = (oldColor & 0x0000ff00 UL) >> 8;
  blue = (oldColor & 0x000000ff UL);

  red = (r <= 10) ? 0 : (int) red - (red * fadeValue / 256);
  green = (g <= 10) ? 0 : (int) green - (green * fadeValue / 256);
  blue = (b <= 10) ? 0 : (int) blue - (blue * fadeValue / 256);

  strip.setPixelColor(ledNo, red, green, blue);
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[ledNo].fadeToBlackBy(fadeValue);
#endif
}
void sparkles() {
  for (int i = 4; i < NUM_LEDS; i++) {
    leds[i] = CRGB(random(0, r), random(0, g), random(0, b));
  }
  FastLED.show();
  myDelay(delayNum);
}
void rainbow() {
  if (function != '8') goto lol;
  for (int colorStep = 0; colorStep < 256; colorStep++) {
    int r = 255 - colorStep; // Redness starts at zero and goes up to full
    int g = colorStep; // Blue starts at full and goes down to zero
    int b = 0; // No green needed to go from blue to red
    if (function != '8') goto lol;
    for (int x = 0; x < NUM_LEDS; x++) {
      leds[x] = CRGB(r, g, b);
    }
    FastLED.show();
    myDelay(delayNum);
  }
  if (function != '8') goto lol;
  for (int colorStep = 0; colorStep < 256; colorStep++) {
    int r = 0; // Redness starts at zero and goes up to full
    int g = 255 - colorStep; // Blue starts at full and goes down to zero
    int b = colorStep; // No green needed to go from blue to red
    if (function != '8') goto lol;
    for (int x = 0; x < NUM_LEDS; x++) {
      leds[x] = CRGB(r, g, b);
    }
    FastLED.show();
    myDelay(delayNum);
  }
  if (function != '8') goto lol;
  for (int colorStep = 0; colorStep < 256; colorStep++) {
    int r = colorStep; // Redness starts at zero and goes up to full
    int g = 0; // Blue starts at full and goes down to zero
    int b = 255 - colorStep; // No green needed to go from blue to red
    if (function != '8') goto lol;
    for (int x = 0; x < NUM_LEDS; x++) {
      leds[x] = CRGB(r, g, b);
    }
    FastLED.show();
    myDelay(delayNum);
  }
lol: String lol = "lol";
}

// from https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
void rainbowSparkles() {
  if (function != '9') goto lol;
  for (int colorStep = 0; colorStep < 256; colorStep++) {
    int r = 255 - colorStep; // Redness starts at zero and goes up to full
    int g = colorStep; // Blue starts at full and goes down to zero
    int b = 0; // No green needed to go from blue to red
    if (function != '9') goto lol;
    for (int x = 0; x < NUM_LEDS; x++) {
      leds[random(0, NUM_LEDS)] = CRGB(r, g, b);
      leds[random(0, NUM_LEDS)] = CRGB::Black;
    }
    FastLED.show();
    myDelay(delayNum);
  }
  if (function != '9') goto lol;
  for (int colorStep = 0; colorStep < 256; colorStep++) {
    int r = 0; // Redness starts at zero and goes up to full
    int g = 255 - colorStep; // Blue starts at full and goes down to zero
    int b = colorStep; // No green needed to go from blue to red
    if (function != '9') goto lol;
    for (int x = 0; x < NUM_LEDS; x++) {
      leds[random(0, NUM_LEDS)] = CRGB(r, g, b);
      leds[random(0, NUM_LEDS)] = CRGB::Black;
    }
    FastLED.show();
    myDelay(delayNum);
  }
  if (function != '9') goto lol;
  for (int colorStep = 0; colorStep < 256; colorStep++) {
    int r = colorStep; // Redness starts at zero and goes up to full
    int g = 0; // Blue starts at full and goes down to zero
    int b = 255 - colorStep; // No green needed to go from blue to red
    if (function != '9') goto lol;
    for (int x = 0; x < NUM_LEDS; x++) {
      leds[random(0, NUM_LEDS)] = CRGB(r, g, b);
      leds[random(0, NUM_LEDS)] = CRGB::Black;
    }
    FastLED.show();
    myDelay(delayNum);
  }
lol: String lol = "lol";
}
void check() {
  Serial.println(key2.getKey());
  if (key2.getKey() == '1') {
    function = key2.getKey();
    Serial.println(key2.getKey());
  }
}
void myDelay(int time) {
  unsigned long t = millis();
  t = 0;
  while (t < time) {
    check();
    delayThing();
    colorChange();
    brightness();
    if (function == '1') {
      goto nothing;
    }
    t++;
  }
  Serial.println(t);
nothing: String no = "no";
}

//switches patterns and colors
void keypadEvent(KeypadEvent key) {
  switch (key2.getState()) {

    case PRESSED:
      delaytf = !delaytf;
      if (key == '1') {
        function = '1';
        colorOn();
      } else if (key == '2') {
        function = '2';
      } else if (key == '3') {
        function = '3';
      } else if (key == '4') {
        function = '4';
      } else if (key == '5') {
        function = '5';
        Serial.println("WTFDFF");
      } else if (key == '6') {
        function = '6';
      } else if (key == '7') {
        function = '7';
      } else if (key == '8') {
        function = '8';
      } else if (key == '9') {
        function = '9';
      }
      if (key == 'A') {
        mode = 'A';
        Serial.println(mode);

      } else if (key == 'B') {
        mode = 'B';
        Serial.println(mode);
      } else if (key == 'C') {
        mode = 'C';
        Serial.println(mode);
      } else if (key == 'D') {
        mode = 'D';
        Serial.println(mode);
      } else if (key == '#') {
        isHashtagHold = !isHashtagHold;
      } else if (key == '*') {
        isStarHold = !isStarHold;
        Serial.println("HELLO");
      } else if (key == '0') {
        mode = '0';
      }
      break;

    case RELEASED:
      //false statement
      delaytf = !delaytf;
      if (key == '*') {
        isStarHold = !isStarHold;
        Serial.println("HELLO");
      } else if (key == '#') {
        isHashtagHold = !isHashtagHold;
      }
  }

}
void delayThing() {
  if (mode == 'A') {
    if (isHashtagHold && delayNum <= 69) {
      delayNum += amountDelay;
      if (amountDelay > 69) {
        delayNum = 69;
      }
    } else if (isStarHold && delayNum > 1) {
      delayNum -= amountDelay;
      if (amountDelay < 1) {
        delayNum = 1;
      }
    }
  }
}
//changes colors based off of keypad
int colorChange() {
  if (mode == 'B') {
    r = increase(r);
    r = decrease(r);
    Serial.print("r ");
    Serial.print(r);
    Serial.println();
  } else if (mode == 'C') {
    g = increase(g);
    g = decrease(g);
    Serial.print("g ");
    Serial.print(g);
    Serial.println();
  } else if (mode == 'D') {
    b = increase(b);
    b = decrease(b);
    Serial.print("b ");
    Serial.print(b);
    Serial.println();
  }
  color = CRGB(r, g, b);
}
int increase(int num) {
  if (isHashtagHold && num <= 255 && num >= 0) {
    num += amount;

    if (num > 255) {
      num = 255;
    }
    //delay(20);
  }
  return num;
}
int decrease(int num) {
  if (isStarHold && num <= 255 && num >= 0) {
    num -= amount;
    if (num < 0) {
      num = 0;
    }
    //delay(20);
  }
  return num;
}
void brightness() {
  if (mode == '0') {
    brightNum = increase(brightNum);
    brightNum = decrease(brightNum);
    FastLED.setBrightness(brightNum);
  }

}



///////////////////////////////////
// mariahs functions to be calle/////
//test if index is odd
boolean ifOdd(int i) {
  if (i % 2 != 0) {
    return true;
  }
  return false;
}

//switches off all leds
void showProgramCleanUp(long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(delayTime);
}

//switches the color of the whole strip
void colorSwitch(CRGB color1, CRGB color2, long delayTime) {


  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = color1;
  }
  FastLED.show();
  delay(delayTime);
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = color2;
  }
  FastLED.show();
  delay(delayTime);

}

//takes to color lights and makes them follow each other.
//varibles needed: 2 colors, time between flashes, number of lights same color,
void follow( CRGB color1, CRGB color2,  long delayTime) {
  CRGB newPixel = CRGB::Black;
  for (int i = 0; i < NUM_LEDS; ++i) {
    if (ifOdd(i) == true) {
      newPixel = color2;
    }
    else if (ifOdd(i) == false) {
      newPixel = color1;
    }
    for (int j = i; j > 0; --j) {
      leds[j] = leds[j - 1];
    }
    leds[0] = newPixel;
    FastLED.show();
    delay(delayTime);
  }

}

//flashes 2 differnt colors in alternating paterns
//varibles needed: 2 colors, time between flashes, number of lights same color, overall time
void checkerFlashD( CRGB color1, CRGB color2,  long timeDelay) {

  double delayTime = timeDelay;
  while (delayTime > 50) {
    for (int i = 0; i < NUM_LEDS; ++i) {

      if (ifOdd(i) == true) {
        leds[i] = color2;
      }
      else if (ifOdd(i) == false) {
        leds[i] = color1;
      }

    }
    FastLED.show();
    delay(delayTime);
    showProgramCleanUp(10);

    for (int i = 0; i < NUM_LEDS; ++i) {

      if (ifOdd(i) == true) {
        leds[i] = color1;
      }
      else if (ifOdd(i) == false) {
        leds[i] = color2;
      }

    }
    FastLED.show();
    delay(delayTime);
    showProgramCleanUp(10);
    delayTime = delayTime * .25;
  }
  showProgramCleanUp(50);
}
//alternate flasshing


// follows then follows back
void backwards (  long delayTime) {

  for (int i = NUM_LEDS; i > 0; --i) {

    leds[i] = CRGB::Black;
    FastLED.show();
    delay(delayTime);
  }

}
void coil ( CRGB color1, CRGB color2,  long delayTime) {
 
  follow(color1, color2, delayTime);
  backwards(delayTime);
  

  showProgramCleanUp(50);
}

  void mariahSparkles() {
  for (int i = 0; i < NUM_LEDS; i++) {
    if (mode == 'B'){
      leds[i] = CRGB(0, 0, random(0,255));
    } else   if (mode == 'C'){
      leds[i] = CRGB(random(0, 255), 0, random(0, 255));
    } else  if (mode == 'D'){
      leds[i] = CRGB(random(0, 255), 0,0);
    }
    
 
  }
  FastLED.show();
  myDelay(delayNum);
}
 /*void mariahSnake(CRGB::color1){
  if (function != '4') goto stupid;
    leds[i] = CRGB::Black;
    FastLED.show();
    delay4(delayNum, '4');
    Serial.println(function);
  
  if (function != '4') goto stupid;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color1;
    FastLED.show();
    delay4(delayNum, '4');
  }
  stupid: String stupid = "Bennett";
}*/

///logic functions
void ariLogic() {
  if (function == '1') {
    colorOn(); //does nothing
  } else if (function == '2') {
    whiteLine(); //white dashing line across standard colors
  } else if (function == '3') {
    party(); //party function
  } else if (function == '4') {
    snake(); //Snake
  } else if (function == '5') {
    festivalLights(); //festival lights
  } else if (function == '6') {
    meteorRain(10, 64, true); // meteor rain from https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
  } else if (function == '7') {
    sparkles(); //random sparkles with input color
  } else if (function == '8') {
    rainbow(); // rainbow changing colors from https://www.tweaking4all.com/ardware/arduino/adruino-led-strip-effects/
  } else if (function == '9') {
    rainbowSparkles(); // rainbow changing colors with sparkles
  }
}


/// mariahs logic
void mariahLogic(CRGB color1, CRGB color2) {

  if (function == '1') {
    coil(color1, color2, 100);
  } else if (function == '2') {
    checkerFlashD(color1, color2, 100);
  } else if (function == '3') {
    colorSwitch(color1, color2, 100);
  } else if (function == '4') {
    // mariahSnake(color1);
  } else if (function == '5') {
      mariahSparkles();
  } else if (function == '6') {

  } else if (function == '7') {

  } else if (function == '8') {

  } else if (function == '9') {

  }
}
