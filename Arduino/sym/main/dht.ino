#include "DHT.h"
#define AMBIENT_pin 2     // Digital pin connected to the DHT sensor
#define ATHLETE_pin 8     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT ATHLETE( ATHLETE_pin , DHTTYPE);
DHT AMBIENT( AMBIENT_pin , DHTTYPE);

struct dht_data{
	float temp;
	float hum;
};
/* typedef struct dht_data dht_data_t; */
void read_dht(bool bl) {
	/* delay(2000); */
	float h1 = AMBIENT.readHumidity();
	// Read temperature as Celsius (the default)
	float t1 = AMBIENT.readTemperature();
	// Read temperature as Fahrenheit (isFahrenheit = true)
	float f1 = AMBIENT.readTemperature(true);
	
	float h2 = ATHLETE.readHumidity();
	// Read temperature as Celsius (the default)
	float t2 = ATHLETE.readTemperature();
	// Read temperature as Fahrenheit (isFahrenheit = true)
	float f2 = ATHLETE.readTemperature(true);
	bool error_flag = 0;
	// Check if any reads failed and exit early (to try again).
	if (isnan(h1) || isnan(t1) || isnan(f1)) {
		Serial.println(F("Failed to read from DHT sensor! AMBIENT"));
		/* return dht_data{ -1,-1 }; */
		error_flag = 1;
	}
	if (isnan(h2) || isnan(t2) || isnan(f2)) {
		Serial.println(F("Failed to read from DHT sensor! ATHLETE"));
		/* return dht_data{ -1,-1 }; */
		error_flag = 1;
	}
	if (error_flag)
		return;
	/* Serial.println("Temperature: "); */
	/* Serial.println(t1); */
	if (bl ==0){
	Serial.print("Humidity AMBIENT: ");
	Serial.println(h1);
	/* return dht_data{ t,h }; */
	Serial.print("Humidity ATHLETE: ");
	Serial.println(h2);
}
	if (bl == 1){
	Serial.print("Relative Humidity ");
	Serial.println(h2-h1);
	}
	return ;
}
