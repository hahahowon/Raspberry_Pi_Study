#include <wiringPi.h>
#include <softTone.h>

#define SPKR		6
#define TOTAL		8

int notes[] = {
	391, 391, 440, 440, 391, 391, 330, 330,\
	391, 391, 339, 330, 294, 294, 294, 0
};
int musicPlay()
{

	int i;
	
	softToneCreate(SPKR);
	
	for (i = 0; i < TOTAL; ++i){
		softToneWrite(SPKR, notes[i]);
		delay(280);
	}
	break;
	return 0;
}

int main()
{
	wiringPiSetup();
	musicPlay();
	return 0;
}

