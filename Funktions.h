/********************************************************************/
/*          Arduino Projekt – Pc Led Lights control                 */
/*                             EsciTec                              */
/********************************************************************/


#ifndef FUNKTIONS_H_
#define FUNKTIONS_H_

//Ports
#define Green_Port	9
#define Red_Port	10
#define Blue_Port	11

//Config
#define baudspeed 9600
#define testdauer 1
#define min_pulse 100

// Init
void initLED_Port();
void init_Serialport(int i);
void Config_Serial();

// Mode
void ReadMode();
void SwitchMode();

// Colorsfunk
void Rainbow();
void UpDown(int t);
void UpDown_Start(int t);
void Manual();
void Pulse();

#endif /* FUNKTIONS_H_ */
