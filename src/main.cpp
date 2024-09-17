#include "Arduino.h"
#include "DHT.h"

// Pin to which the DHT sensor is connected
#define DHTPIN 16  // GPIO16

// Specify the DHT model being used (DHT22 or DHT11)
#define DHTTYPE DHT22  // Change to DHT11 if using DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);  // Use 115200 baud rate for serial communication
  Serial.println("Initializing DHT sensor...");
  dht.begin();
}

void loop() {
  // Read temperature and humidity values
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // If reading failed, print an error message
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the results to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C, Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  // Delay for 2 seconds before the next reading
  delay(2000);
}
