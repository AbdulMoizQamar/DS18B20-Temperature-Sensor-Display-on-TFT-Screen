#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <TFT_eSPI.h>

#define TFT_MISO 37
#define TFT_MOSI 35
#define TFT_SCLK 36
#define TFT_CS   39  // TFT chip select
#define TFT_DC   2  // TFT data/command
#define TFT_RST  4  // TFT reset (-1 if not used)

TFT_eSPI tft = TFT_eSPI();  // Initialize TFT
// GPIO where the DS18B20 is connected to
  const int oneWireBus = 7;     

// Setup a oneWire instance to communicate with any OneWire devices
  OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
  DallasTemperature sensors(&oneWire);


void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);

 // Start the DS18B20 sensor
  sensors.begin();
  
  tft.begin();
  tft.setRotation(1); // Adjust rotation (1 = landscape)
 // int downloadpercent = 50;
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);      // Set text size
  tft.setTextColor(TFT_BLUE);  // White text on blue background
  tft.setCursor(60, 50);   // Set cursor position (X=20, Y=30)
}

void loop() {
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);

  Serial.print(temperatureC);
  Serial.println("ºC");
  tft.println("Temperature");
  tft.setCursor(145, 170);
  tft.printf("%.2f");
  delay(500);
}