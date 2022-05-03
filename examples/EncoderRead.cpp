
// Encoder
#include "QuadDecode_def.h" // Hardware quadrature encoder
QuadDecode<1> myEnc;

void setup(){
	Serial.begin(9600);
	myEnc.setup();
	myEnc.start();
	myEnc.zeroFTM();
}

void loop(){
	printStats();
}

elapsedMillis printTimer = 0;
const unsigned int printTime = 50;
void printStats(){
	if(printTimer >= printTime){
		Serial.print(myEnc.calcPosn());

		Serial.println();
	}
}