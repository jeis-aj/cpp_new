#include <millisDelay.h>

int pulseSensorPin = A0;
int fsr_pin = A2;				
int rainDrop_pin = A3;
int tempS_pin = A5;
int Dehydrate_ind = 12;    // connected to an LED indication of dehydration
int impactIndicator = 11;  // connected to an LED indication of deadly impact
int tempIndicator = 10;

void setup() {
  pinMode(Dehydrate_ind, OUTPUT);			// green
  pinMode(impactIndicator, OUTPUT);			// red led
  pinMode(tempIndicator, OUTPUT);			// blue led
  pinMode(rainDrop_pin, INPUT_PULLUP);
  pinMode(tempS_pin, INPUT_PULLUP);
  pinMode(fsr_pin, INPUT_PULLUP);
  Serial.begin(9600);
}

struct value {
  int fsr_read;
  int rainDrop_read;
  int tempS_read;
};

typedef struct value data;
data getValue();
void debug();
void run();


void loop() {
  bool pr = pulseSensorRead();
  digitalWrite(LED_BUILTIN, pr);
  run();			// run main program ..
  debug();  // debug value
}

void debug() {
  auto d = getValue();  // get data in strut form
  Serial.print("temp read: ");
  Serial.println(d.tempS_read);
  Serial.print("fsr read: ");
  Serial.println(d.fsr_read);
  Serial.print("wet read: ");
  Serial.println(d.rainDrop_read);
  Serial.println();
  delay(500);
}

bool pulseSensorRead() {
  int readValue = analogRead(pulseSensorPin);
  int threshold = 512;
  bool pr = readValue > threshold;
  return pr;
}

void run() {

  int temp_thr = 140;    // max temperature value before dehydration
  int wet_thr = 300;     // wet sensor value, max water loss value
  int impact_thr = 26;  // init impact threshold

  auto d = getValue();  // get data in strut form
  bool excessive = d.tempS_read < temp_thr;
  bool dehydrated = excessive && d.rainDrop_read < wet_thr;  // assuming if temp and wetSensor exceed respective threshold value then dehydrated

  if (excessive) {
    digitalWrite(tempIndicator, HIGH);
  }  // if temp excessive indicator led
  else {
    digitalWrite(tempIndicator, LOW);
  }

  if (dehydrated) {
    digitalWrite(Dehydrate_ind, HIGH);
  }  // if dehydrated light-up indication LED
  else {
    digitalWrite(Dehydrate_ind, LOW);
  }

  bool isSeriousImpact = d.fsr_read < impact_thr;
  if (isSeriousImpact) {
    digitalWrite(impactIndicator, HIGH);
  } else {
    digitalWrite(impactIndicator, LOW);
  }
}

data getValue() {
  int fsr_read = analogRead(fsr_pin);
  int rainDrop_read = analogRead(rainDrop_pin);
  int tempS_read = analogRead(tempS_pin);
  /* tempS_read = tempS_pin * 500 / 1023; */
  data rtData{ fsr_read, rainDrop_read, tempS_read };
  return rtData;
}
