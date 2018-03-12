#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#define PIN 6
#define NUMPINS 60

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPINS, PIN, NEO_GRB + NEO_KHZ800);
int mode = 0;

void setup() {
  // put your setup code here, to run once:

  strip.begin();
  strip.show();

  Wire.begin(0);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  randomWipe();
  strip.show();
  delay(50);
}

void colorWipe(int r,int g,int b) {
  for(int i = 0; i < NUMPINS; i ++) {
    strip.setPixelColor(i,r,g,b);
  }
}

void randomWipe() {
  for(int i = 0; i < NUMPINS; i ++) {
    if(mode == 0) {
      strip.setPixelColor(i,255,random(100),random(100));
    } else {
      strip.setPixelColor(i,random(100),255,random(100));
    }
  }
}

void receiveEvent(int howMany) {
  /*int count = 0;
  while (0 < Wire.available()) {
    int i = Wire.read();
    Serial.println(i);
    count++;
  }
  Serial.print("Count: ");
  Serial.println(count);*/
  int x = Wire.read();
  Serial.println(x);
  while(Wire.available() > 0) {
    Wire.read();
  }
  mode = x;
}

