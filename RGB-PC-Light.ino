/********************************************************************/
/*          Arduino Projekt – Pc Led Lights control                 */
/*                             EsciTec                              */
/********************************************************************/

#include "Funktions.h"
#include <Arduino.h>

void setup() 
{
	initLED_Port();
	init_Serialport(baudspeed);
	UpDown_Start(testdauer);
}

void loop() 
{
	//Config_Serial();
	ReadMode();
	SwitchMode();
}
