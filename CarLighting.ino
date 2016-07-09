#include "PIDEngineLoad.h"
#include "PID.h"
#include "LEDColor.h"
#include "ColorInterpolater.h"
#include <Adafruit_NeoPixel.h>
#include "LED.h"

LED led(13);
Adafruit_NeoPixel neo = Adafruit_NeoPixel(8, 6, NEO_GRB + NEO_KHZ800);
uint8_t blue = 0;

void setup()
{
  /* add setup code here */
	//uint8_t n = 256;
	PIDEngineLoad load = PIDEngineLoad();

	neo.begin();
	neo.setPixelColor(0, 255, 0, 0);
	neo.setPixelColor(1, 255, 0, 0);
	neo.setPixelColor(2, 0, 0, 255);
	neo.setPixelColor(3, 0, 0, 255);
	neo.setPixelColor(4, 255, 255, 255);
	neo.setPixelColor(5, 255, 255, 255);
	neo.setPixelColor(6, 255, 255, 255);
	neo.setPixelColor(7, 255, 255, 255);
	neo.show();
}

void loop()
{

  /* add main program code here */
	//led.on();
	//delay(100);
	//led.off();
	//delay(100);
	/*for (int i = 0; i < 256; i++) {
		neo.setPixelColor(0, 0, 0, i);
		neo.show();
		delay(10);
	}
	for (int i = 254; i >= 0; i--) {
		neo.setPixelColor(0, 0, 0, i);
		neo.show();
		delay(10);
	}*/
	neo.setPixelColor(0, 255, 0, 0);
	neo.setPixelColor(1, 255, 0, 0);
	neo.setPixelColor(2, 0, 0, 255);
	neo.setPixelColor(3, 0, 0, 255);
	neo.setPixelColor(4, 255, 255, 255);
	neo.setPixelColor(5, 255, 255, 255);
	neo.setPixelColor(6, 255, 255, 255);
	neo.setPixelColor(7, 255, 255, 255);
	neo.show();
}