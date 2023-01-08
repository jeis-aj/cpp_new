#include <millisDelay.h>
#define USE_ARDUINO_INTERRUPTS true 
#include <PulseSensorPlayground.h>

PulseSensorPlayground pulseSensor;

int pulseSensorPin = A0;

void setup(){
	Serial.begin(9600);
	pulseSensor.analogInput(pulseSensorPin);
	pulseSensor.blinkOnPulse(LED_BUILTIN);
	pulseSensor.setThreshold(512);
	if(pulseSensor.begin()){
		Serial.println("Pulse Sensor initialized");
	};
}


void loop(){
	int bpm = pulseSensor.getBeatsPerMinute();
	Serial.print("bpm : ");
	Serial.println( bpm );
}

/*
void other()	{

	Serial.println(readValue);
	uint64_t tm1 = millis();
	uint64_t tm2;
	if(readPulseSensor()  ){
		tm2 = millis(); }
	
	float diff_Time = (tm2 - tm1); // in seconds
	if(diff_Time < 0) return;

	float mul = 1000/diff_Time;
	int bpm =  mul * 60; 			// beats per minute
	Serial.println( bpm );
	Serial.print("bpm : ");
	Serial.println( diff_Time );
	Serial.println( tm1 );
	delay(500);
}

*/
bool readPulseSensor(){
	millisDelay maxTime;
	maxTime.start(2000);
	while(1){
		//
	int thr = 512;
	int readValue = analogRead(pulseSensorPin);
	if ( thr > readValue ){
		digitalWrite(LED_BUILTIN,HIGH);
		return true;}
	else{
		digitalWrite(LED_BUILTIN,LOW); }
		//
		if(maxTime.justFinished()){
			return false; }
	}
}
