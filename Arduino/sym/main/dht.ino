#include "DHT.h"
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

struct dht_data{
	float temp;
	float hum;
};
/* typedef struct dht_data dht_data_t; */
void read_dht() {
	/* delay(2000); */
	float h = dht.readHumidity();
	// Read temperature as Celsius (the default)
	float t = dht.readTemperature();
	// Read temperature as Fahrenheit (isFahrenheit = true)
	float f = dht.readTemperature(true);

	// Check if any reads failed and exit early (to try again).
	if (isnan(h) || isnan(t) || isnan(f)) {
		Serial.println(F("Failed to read from DHT sensor!"));
		/* return dht_data{ -1,-1 }; */
		return ;
	}
	Serial.println("Temperature: ");
	Serial.println(t+20);
	Serial.println("Humidity: ");
	Serial.println(h);
	/* return dht_data{ t,h }; */
	return ;
}
