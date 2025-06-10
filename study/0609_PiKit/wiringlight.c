#include <wiringPi.h>
#include <stdio.h>

#define SW	 5 	//gpio 25
#define CDS	 0 	//gpio 17
#define LED 	 1	//gpio 18

int cdsControl(){

	int i;
	
	pinMode(SW, INPUT);
	pinMode(CDS, INPUT);
	pinMode(LED, OUTPUT);

	for(;;){
		if(digitalRead(CDS) == HIGH){
			digitalWrite(LED, HIGH);
	
		}else{
			digitalWrite(LED, LOW);
		}
	delay(100);
	}
	
	return 0;
}

int main(){
	wiringPiSetup();
	cdsControl();
	return 0;
}	


