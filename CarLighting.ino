#include "AnalogButtonsDown.h"
#include "EngineColor.h"
#include "SolidColor.h"
#include "GaugeColor.h"
#include "LEDColor.h"
#include "ColorInterpolater.h"
#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include "ELM327.h"

static const int LED_COUNT = 8;
static const int SETTING_COUNT = 10;
static const int BUTTON_COUNT = 6;
static const int BUTTON_TOLERANCE = 2;

SoftwareSerial *Bluetooth = new SoftwareSerial(5, 3);;// (5, 3); // RX, TX
Elm327 *obd  = new Elm327(Bluetooth);

Adafruit_NeoPixel neo = Adafruit_NeoPixel(8, 2, NEO_GRB + NEO_KHZ800);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

GaugeColor* gaugeColors[SETTING_COUNT] = { new SolidColor(LEDColor(0, 0, 255), "Blue"),
											new SolidColor(LEDColor(255, 0, 0), "Red"),
											new SolidColor(LEDColor(255, 255, 255), "White"),
											new SolidColor(LEDColor(255, 255, 155), "Real White"),
											new SolidColor(LEDColor(0, 255, 0), "Green"),
											new SolidColor(LEDColor(160, 0, 255), "Purple"),
											new SolidColor(LEDColor(255, 100, 0), "Orange"),
											new SolidColor(LEDColor(255, 255, 0), "Yellow"),
											new EngineColor(obd, RPM, "RPM", LEDColor(255, 255, 255), LEDColor(255, 0, 0), 0, 6500),
											new EngineColor(obd, SPEED, "Speed", LEDColor(255, 255, 255), LEDColor(255, 0, 0), 0, 160)};

uint8_t lightSettingIndicies[LED_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0};

int buttonValues[BUTTON_COUNT] = { 959, 985, 839, 512, 696, 1009 };
AnalogButtonsDown buttons = AnalogButtonsDown(0, BUTTON_COUNT, buttonValues, BUTTON_TOLERANCE);

String gaugeNames[BUTTON_COUNT] = { "Fuel Level", "RPM", "Trip", "Info", "Speed", "Engine Temp" };

void setup()
{
	Serial.begin(9600);

	//initialize and print welcome to the display
	lcd.begin(16, 2);
	lcd.print("Welcome");

	//initialize the lights and fade them in to white across a second for a startup animation
	neo.begin();
	for (int i = 1; i <= 25; i++) {
		for (int j = 0; j < LED_COUNT; j++) {
			neo.setPixelColor(j, i * 10, i * 10, i * 10);
		}
		neo.show();
		delay(60);
	}

	//read the eeprom into light setting indicies
	loadSettings();

	//Initialize the obd2 adapter
	obd->begin();
	delay(500);
}

void loop()
{
	int buttonPressed = buttons.GetButtonDown();
	if (buttonPressed != -1) {
		incrementBasedOnGroup(buttonPressed);
		setLCD(buttonPressed);
		saveSettings();
	}

	for (int i = 0; i < LED_COUNT; i++) {
		neo.setPixelColor(i, gaugeColors[lightSettingIndicies[i]]->GetColor());
	}
	neo.show();
}

void setLCD(int buttonPressed) {
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(gaugeNames[buttonPressed]);
	lcd.setCursor(0, 1); 
	switch (buttonPressed) {
	case 0:
		lcd.print(gaugeColors[lightSettingIndicies[0]]->_name);
		break;
	case 1:
		lcd.print(gaugeColors[lightSettingIndicies[1]]->_name);
		break;
	case 2:
		lcd.print(gaugeColors[lightSettingIndicies[6]]->_name);
		break;
	case 3:
		lcd.print(gaugeColors[lightSettingIndicies[4]]->_name);
		break;
	case 4:
		lcd.print(gaugeColors[lightSettingIndicies[3]]->_name);
		break;
	case 5:
		lcd.print(gaugeColors[lightSettingIndicies[2]]->_name);
		break;
	}
}

void incrementBasedOnGroup(int buttonPressed) { //LEDs 4 and 5 and LEDs 6 and 7 are paired up for a single gauge
	switch (buttonPressed) {
	case 0: 
		incrementSetting(0);
		break;
	case 1:
		incrementSetting(1);
		break;
	case 2:
		incrementSetting(6);
		incrementSetting(7);
		break;
	case 3:
		incrementSetting(4);
		incrementSetting(5);
		break;
	case 4:
		incrementSetting(3);
		break;
	case 5:
		incrementSetting(2);
		break;
	}
}

void incrementSetting(int index) {
	lightSettingIndicies[index]++;
	if (lightSettingIndicies[index] >= SETTING_COUNT) {
		lightSettingIndicies[index] = 0;
	}
}

void loadSettings() {
	for (int i = 0; i < LED_COUNT; i++) {
		lightSettingIndicies[i] = EEPROM.read(i);
		if (lightSettingIndicies[i] >= SETTING_COUNT) {
			lightSettingIndicies[i] = 0;
		}
	}
}

void saveSettings() {
	for (int i = 0; i < LED_COUNT; i++) {
		EEPROM.write(i, lightSettingIndicies[i]);
	}
}