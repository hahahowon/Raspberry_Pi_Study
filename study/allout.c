#include <wiringPi.h>

int main(){
	wiringPiSetup();
	/*for(int pin = 0; pin <=29; pin++){
		pinMode(pin, INPUT);
		pullUpDnControl(pin,PUD_OFF);
	}*/

	pinMode(17, INPUT);
	pullUpDnControl(17,PUD_OFF);
	
	return 0;
}

