#include <filters.h>
const float cutoff_freq   = 17.0;  //Cutoff frequency in Hz
const float sampling_time = 0.007; //Sampling time in seconds.
IIR::ORDER  order  = IIR::ORDER::OD4; // Order (OD1 to OD4)

// Low-pass filter
Filter f(cutoff_freq, sampling_time, order);

int ecg_filtered() {
  int ecg_signal = analogRead(A5);
    float filteredval = f.filterIn(ecg_signal);
    /* Serial.println(ecg_signal); */
    Serial.println(filteredval);
    delay(5);
    return filteredval;
    
   //f.filterIn(analogRead(A0));
   
}

void loop(){
	ecg_filtered();
	delay(0);
	/* loop_1(); */
}
