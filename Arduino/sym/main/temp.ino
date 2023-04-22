int thermister_read(){
	const int thermister_pin = A1; 	// thermister pin

	pinMode( thermister_pin, INPUT_PULLUP );
	int read_v = analogRead( thermister_pin );
	int out =  map(read_v, 200, 0 , 0 ,255);
	return out;
}
