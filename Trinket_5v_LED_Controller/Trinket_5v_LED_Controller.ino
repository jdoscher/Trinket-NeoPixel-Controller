#include <Adafruit_NeoPixel.h>
#define PIN 3
#define NUM_LIGHTS  30
#ifdef __AVR__
  #include <avr/power.h>
#endif

const int SWITCH_PIN = 0;
const  int BRIGHT_PIN = 1;
const  int AUTO_PIN = 4;
int firston = 0;  
int autoval = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LIGHTS, PIN, NEO_GRBW + NEO_KHZ800);
int val = 0;
int brightval = 0;
void setup() {
    // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  pinMode(SWITCH_PIN, INPUT);
  pinMode(BRIGHT_PIN, INPUT);
  pinMode(AUTO_PIN, INPUT);


}

void loop() {
    //brightval = analogRead(BRIGHT_PIN);
    brightval = map(analogRead(BRIGHT_PIN), 0, 1023, 0, 255);
    val = digitalRead(SWITCH_PIN);
    if ((val == HIGH) && (analogRead(BRIGHT_PIN) > 20)) {
        for( int i = 0; i<NUM_LIGHTS; i++){
        brightval = map(analogRead(BRIGHT_PIN), 0, 1023, 0, 255);
        strip.setPixelColor(i, brightval,brightval,brightval,brightval);
        strip.show();
        }

          }
//    }
      autoval = digitalRead(AUTO_PIN);
      if (autoval == HIGH) {
          for( int i = 0; i<NUM_LIGHTS; i++){
        strip.setPixelColor(i, 0,255,255,255);
        strip.show();
          }
    }
      if ((val == LOW) && (autoval == LOW)) {
          for( int i = 0; i<NUM_LIGHTS; i++){
        strip.setPixelColor(i, 0,0,0,0);
        strip.show();
          }
    }

}
