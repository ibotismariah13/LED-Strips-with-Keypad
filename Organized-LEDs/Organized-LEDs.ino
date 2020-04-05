#define FASTLED_INTERNAL
#include <FastLED.h>
#include <Keypad.h>
#define NUM_LEDS 65 //number of LEDs
# define NUM_WHITE 3
# define LED_PIN 10

//initialized variables
int brightNum = 100;
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
  
  key2.addEventListener(keypadEvent);
}
//constant running code
void loop() {

  key = key2.getKey();
  Serial.println(function);

  if (function == '1') {
    collegeLights();

  } else  {
    showProgramCleanUp(10);
  }


}








void check() {
  Serial.println(key2.getKey());
  if (key2.getKey() == '1') {
    function = key2.getKey();
    Serial.println(key2.getKey());
  }
}


//switches patterns and colors
void keypadEvent(KeypadEvent key) {
  switch (key2.getState()) {

    case PRESSED:

      if (key == '1') {
        function = '1';
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

    case RELEASED:

      if (key == '*') {
        isStarHold = !isStarHold;
        Serial.println("HELLO");
      } else if (key == '#') {
        isHashtagHold = !isHashtagHold;
      }
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
//varibles needed: 2 colors, time between flashes, number of lights same color, overall time
void boilerHookie(  long timeDelay) {

  double delayTime = timeDelay;
  while (delayTime < 1250) {
    for (int i = 0; i < NUM_LEDS; ++i) {

      if (ifOdd(i) == true) {
        leds[i] = CRGB::Orange;
      }
      else if (ifOdd(i) == false) {
        leds[i] = CRGB::Maroon;
      }



    }
    FastLED.show();
    delay(delayTime);
    showProgramCleanUp(10);

    for (int i = 0; i < NUM_LEDS; ++i) {
      if (ifOdd(i) == true) {
        leds[i] = CRGB::Black;
      }
      else if (ifOdd(i) == false) {
        leds[i] = CRGB::Yellow;
      }

    }
    FastLED.show();
    delay(delayTime);
    showProgramCleanUp(10);
    delayTime = delayTime * 1.25;
  }
  showProgramCleanUp(50);
}

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
void showTech(long delayTime) {
  for (int i = 1; i < NUM_LEDS; i++) {
    if (ifOdd(i)) {
      leds[i] = CRGB::Orange;
    } else {
      leds[i] = CRGB::Maroon;
    }

  }
  FastLED.show();
  delay(delayTime);
}

void collegeLights() {

  //coil up as PD
  coil(CRGB::Black, CRGB::Yellow, 50);
  coil(CRGB::Orange, CRGB::Maroon, 50);
  boilerHookie(50);
  showTech(500);
  showProgramCleanUp(500);
  showTech(500);
  showProgramCleanUp(500);
  checkerFlashD(CRGB::Orange, CRGB::Maroon,1000);
  coil(CRGB::Orange, CRGB::Maroon, 50);
  function='2';


}
