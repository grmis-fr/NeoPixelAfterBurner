// ================================================
// Grmis @ RCGroups, march 2017
// GNU General Public Licence v3
//=================================================
#include <Adafruit_NeoPixel.h>
#define PIN 6 //NeoPixel strip data pin
#define PWM_PIN 5 // Connected to the throttle channel
#define NUM_LEDS 35

#define BRIGHTNESS 255
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int pwm_min = 1150;
int pwm_max = 1800;
//----------------------------------------------------------

void setup() {

  pinMode(PWM_PIN, INPUT);
  pinMode(PIN, OUTPUT);

  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  const int turns = 10;
  for (int i = 0; i < NUM_LEDS * turns; i++) {

    int c = (i < NUM_LEDS * turns / 2) ?
            map(i, 0, NUM_LEDS * turns / 2 - 1, 0, 255) :
            map(i, NUM_LEDS * turns / 2, NUM_LEDS * turns - 1, 255, 0);

    int r, g, b;
    AB_color(c, r, g, b);
    strip.setPixelColor(i % NUM_LEDS, r, g, b); strip.show();
    delay(15);
    strip.setPixelColor(i % NUM_LEDS, 0, 0, 0);
  }
  strip.show();
}
//----------------------------------------------------------
void set_color(int r, int g, int b) {
  for (int i = 0; i < NUM_LEDS; i++) {
    int r_ = random((1 * r) / 2, min(255, (4 * r) / 3));
    int g_ = random((1 * g) / 2, min(255, (4 * g) / 3));
    int b_ = random((1 * b) / 2, min(255, (4 * b) / 3));
    strip.setPixelColor(i, r_, g_, b_);
  }
  strip.show();
}
//----------------------------------------------------------
void AB_color(int c, int &r, int &g, int &b) {
  const int c1 = 5, c2 = 64, c3 = 128, c4 = 192;
  if (c < c1) {
    r = 0; g = 0; b = 0;
  } else if (c < c2) {
    r = map(c, c1, c2 - 1, 0, 32);
    g = map(c, c1, c2 - 1, 0, 11);
    b = map(c, c1, c2 - 1, 0, 0);
  } else if (c < c3) {
    r = map(c, c2, c3 - 1, 32, 100);
    g = map(c, c2, c3 - 1, 11, 25 );
    b = map(c, c2, c3 - 1, 0, 8);
  } else if (c < c4) {
    r = map(c, c3, c4 - 1, 100, 240 );
    g = map(c, 128, c4 - 1, 25, 45 );
    b = map(c, 128, c4 - 1, 8, 18);
  } else {
    r = map(c, c4, 255, 240, 255 );
    g = map(c, c4, 255, 45, 63 );
    b = map(c, c4, 255, 18, 60);
  }
}
//----------------------------------------------------------
void set_color(int c) {
  int r, g, b;
  if (c > 128) c = random(c / 2, c);
  AB_color(c, r, g, b);
  set_color(r, g, b);
}
//----------------------------------------------------------

void loop() {
  int ch = pulseIn(5, HIGH, 25000);
  if (ch > 800 && ch < 2200) {
    if (ch > pwm_max) pwm_max = ch;
    if (ch < pwm_min) pwm_min = ch;

    int c = map(ch, pwm_min, pwm_max, 0, 255);
    set_color(c);
  }
  delay(40);
}
//----------------------------------------------------------

