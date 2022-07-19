#include <Adafruit_NeoPixel.h>


// PIXELS
#define PIXELS_PIN D6
#define PIXEL_COUNT 8

int PIXELS_DATA[8]={0,0,0,0,0,0,0,0};


const byte colors[8][3] = {
  {255, 0, 0}, //red
  {0, 255, 0}, //green
  {0, 255, 0}, //green
  {0, 255, 0}, //green
  {0, 255, 0}, //green
  {0, 255, 0}, //green
  {0, 255, 0}, //green
  {0, 255, 0}, //green
};


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXEL_COUNT, PIXELS_PIN, NEO_GRB + NEO_KHZ800);


void setup() {

  // PIXELS
  pixels.begin();
  pixels.clear();
  pixels.setBrightness(80);

  for (int i = 0; i < PIXEL_COUNT; i++)
  {
    setPixel(i, 255, 0, 0);
    pixels.show();
    delay(100);
  }  

}

void loop() {

 setLED(0,1); 
 setLED(1,0);
 delay(500);
 setLED(1,1); 

 setLED(2,1);
 setLED(3,1);
 delay(500);

}


void setPixel(int pixel, byte red, byte green, byte blue) {
  pixels.setPixelColor(pixel, pixels.Color(red, green, blue));
}


void setLED(int led, int state){
 
  PIXELS_DATA[led] = state;
 
  for (int i = 0; i < PIXEL_COUNT; i++){    
    if(PIXELS_DATA[i] == 1){
      setPixel(i, colors[i][0], colors[i][1], colors[i][2]); 
    } else{
      setPixel(i, 0, 0, 0);
    }  
  }  
  pixels.show();
}
