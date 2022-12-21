

int fsr_pin = A0;
int rainDrop_pin = A1;
int tempS_pin = A2;
int Dehydrate_ind = 5;		// connected to an LED indication of dehydration

void setup (){
	pinMode( Dehydrate_ind ,OUTPUT);
}

struct value{
	int fsr_read;	
	int rainDrop_read;	
	int tempS_read;	
};

data getValue();

typedef struct value data;

void loop(){
	/* run();			// run main program */
	debug();		// debug value
}

void debug(){
	
	auto d = getValue();			// get data in strut form

	Serial.print("temp read: ");
	Serial.println(d.tempS_read);

	Serial.print("fsr read: ");
	Serial.println(d.fsr_read);

	Serial.print("wet read: ");
	Serial.println(d.rainDrop_read);
}


void run(){

	int temp_thr = 39;					// max temperature value before dehydration
	int wet_thr = 500;					// wet sensor value, max water loss value

	auto d = getValue();			// get data in strut form

	bool dehydrated = d.tempS_read > temp_thr && d.rainDrop_read > wet_thr;			// assuming if temp and wetSensor exceed respective threshold value then dehydrated 

	if ( dehydrated ){
		digitalWrite(Dehydrate_ind ,HIGH);		// if dehydrated light-up indication LED
	}

	else
	{
		digitalWrite(Dehydrate_ind ,LOW);	}
}

data getValue(){
	int fsr_read = analogRead(fsr_pin);
	int rainDrop_read = analogRead(rainDrop_pin);
	int tempS_read = analogRead(tempS_pin);
	data rtData { fsr_read,rainDrop_read,tempS_read };
	return data;
}