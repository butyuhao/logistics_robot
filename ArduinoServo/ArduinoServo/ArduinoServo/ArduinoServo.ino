#include "include.h"

void setup() 
{
	pinMode(LED,OUTPUT);
	pinMode(BUZZER,OUTPUT);
	pinMode(KEY,INPUT_PULLUP);

	InitPWM();
	InitTimer2();
	
	InitUart1();
	InitPS2();
	InitFlash();
	InitMemory();

}


void loop() 
{
	TaskRun(); 
}




