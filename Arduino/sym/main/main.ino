#include <millisDelay.h>


int pulseSensorPin = A0;
int fsr_pin = A2;				
int rainDrop_pin = A3;
int tempS_pin = A5;

int LED_MSB = 12;    // connected to an LED indication of dehydration
int LED_MID = 11;  // connected to an LED indication of deadly impact
int LED_LSB = 10;

void setup() {
	Serial.begin(9600);
	pinMode(LED_MSB, OUTPUT);			// green
	pinMode(LED_MID, OUTPUT);			// red led
	pinMode(LED_LSB, OUTPUT);			// blue led
	pinMode(rainDrop_pin, INPUT_PULLUP);
	pinMode(tempS_pin, INPUT_PULLUP);
	pinMode(fsr_pin, INPUT_PULLUP);
	pulse_setup();
}

enum colours{
	NOCOLOR	,
	RED	=	1,
	GREEN		,
	YELLOW	,
	BLUE		,
	MAGENTA	,
	CYAN		,
	WHITE		,
};

struct value {
	int fsr_read;
	int rainDrop_read;
	int tempS_read;
};
typedef struct value data;

data getValue(bool);
void debug();
void run();

void read_dht(void);
bool state = HIGH;

void led_indicator(uint8_t colour_no);
uint8_t colour_no ;

/* void command(String cmd,int del){ */
void command(String cmd ){

	/* millisDelay runTime; */
	/* runTime.start( del ); */
/* L1: */
	if (cmd == "read pulse"){
		pulse_read();
		/* led_indicator(CYAN); */
	}
	else if (cmd == "get value" ){
		getValue(1);
		/* led_indicator(RED); */
	}
	else if (cmd == "run" ){
		run();
		/* led_indicator(GREEN); */
	}
	else if (cmd == "read dht" ){
		read_dht();
		led_indicator(MAGENTA);
	}
	else if (cmd == "red" ){
		led_indicator(RED);
	}
	else if (cmd == "blue" ){
		led_indicator(BLUE);
	}
	else if (cmd == "green" ){
		led_indicator(GREEN);
	}
	else{
		Serial.println("Wrong Command");
		led_indicator(NOCOLOR);
	}
	/* if(! runTime.justFinished ()) */
		/* goto L1; */
	
}
void loop() {
	/* run();			// run main program .. */
	/* debug();  // debug value */
	/* pulseSensorRead(); */
	/* pulse_read(); */
	/* state = !state ; */
	/* digitalWrite(Dehydrate_ind,state); */
	String cmd;
	if(Serial.available()){
		Serial.println("Enter Command: ");
		cmd = Serial.readString();
	}
	Serial.println(cmd);
	/* cmd ="read pulse"; */
	/* int del = 25000; */
	/* command(cmd, del); */

	/* cmd ="read pulse"; */
	/* cmd ="read dht"; */
	cmd ="run";
	command(cmd );
	/* led_indicator(CYAN); */
	/* read_dht11(); */
	delay(500);
}

void led_indicator(uint8_t colour_no){
	digitalWrite(LED_MSB, colour_no & 0x04);
	digitalWrite(LED_MID, colour_no & 0x02);
	digitalWrite(LED_LSB, colour_no & 0x01);
}
/*
   -------------------
   10	11	12			
   BLUE	GREEN	RED	
   -------------------
   0	0	1	RED		1
   0	1	0	GREEN		2
   0	1	1	YELLOW	3	
   1	0	0	BLUE		4
   1	0	1	MAGENTA	5
   1	1	0	CYAN		6
   1	1	1	WHITE		7
 */

/*
   void debug() {
   auto d = getValue();  // get data in strut form
   read_dht11();
   Serial.print("temp read: ");
   Serial.println(d.tempS_read);
   Serial.print("fsr read: ");
   Serial.println(d.fsr_read);
   Serial.print("wet read: ");
   Serial.println(d.rainDrop_read);
   Serial.println();
   delay(500);
   }

 */
bool pulseSensorRead() {
	millisDelay period;
	int maxbeat = 76;				// max beat set 
	int interval =	60 / maxbeat;			 // interval = cycle period for maxbeat
	period.start( interval );
	while(1){
		if (period.justFinished()){
			return false; }
		int readValue = analogRead(pulseSensorPin);
		Serial.println(readValue);
		int threshold = 512;
		bool pr = readValue > threshold;
		if (pr){
			digitalWrite(LED_BUILTIN, HIGH);
			delay(70);
			digitalWrite(LED_BUILTIN, LOW);
			return true; }
	}
}

void run() {

	int temp_thr = 140;    // max temperature value before dehydration
	int wet_thr = 300;     // wet sensor value, max water loss value
	int impact_thr = 26;  // init impact threshold

	auto d = getValue(1);  // get data in strut form
	bool excessive = d.tempS_read < temp_thr;
	bool dehydrated = excessive && d.rainDrop_read < wet_thr;  // assuming if temp and wetSensor exceed respective threshold value then dehydrated

	if (excessive) {
		/* digitalWrite(tempIndicator, HIGH); */
		/* led_indicator(RED); */
		Serial.print("Excessive Temperature.....##");
	}  // if temp excessive indicator led
	else {
		/* led_indicator(GREEN); */
		/* digitalWrite(tempIndicator, LOW); */
	}

	if (dehydrated &&  pulseSensorRead()) {
		/* led_indicator(BLUE); */
		Serial.print("Dehydrated .....##");
	}  // if dehydrated light-up indication LED
}

struct value getValue(bool visible) {
	int fsr_read = analogRead(fsr_pin);
	int rainDrop_read = analogRead(rainDrop_pin);
	/* int tempS_read = analogRead(tempS_pin); */
	int tempS_read = 150;
	/* tempS_read = tempS_pin * 500 / 1023; */

	if(visible){
		/* Serial.print("temp read: "); */
		/* Serial.println(tempS_read); */
		Serial.print("fsr read: ");
		Serial.println(fsr_read);
		Serial.print("wet read: ");
		Serial.println(rainDrop_read);
		Serial.println();
	}
	if (fsr_read < 35){
		led_indicator(RED);
		Serial.println("Heavy punch");
	}
	else if (fsr_read < 50){
		led_indicator(MAGENTA);
		Serial.println("Moderate punch");
	}
	else if (fsr_read < 80){
		led_indicator(YELLOW);
		Serial.println("Light punch");
	}
	else if (fsr_read > 80){
		led_indicator(WHITE);
		Serial.println("Very Light Touch");
	}

	data rtData{ fsr_read, rainDrop_read, tempS_read };
	return rtData;
}
