/********************************************************************/
/*          Arduino Projekt – Pc Led Lights control                 */
/*                             EsciTec                              */
/********************************************************************/

void initLED_Port()
{
	pinMode(Green_Port, OUTPUT);
	pinMode(Blue_Port, OUTPUT);
	pinMode(Red_Port, OUTPUT);
}

void init_Serialport(int i)
{
	Serial.begin(i);
}

void serialEvent()
{
	DataSerialRX[0] = DataSerialRX[1];
	DataSerialRX[1] = DataSerialRX[2];
	DataSerialRX[2] = DataSerialRX[3];
	DataSerialRX[3] = Serial.read();
	mode = stop;
}

void Del_Input()
{
	DataSerialRX[0] = 0;
	DataSerialRX[1] = 0;
	DataSerialRX[2] = 0;
	DataSerialRX[3] = 0;
}

int randomzal()
{
	return (rand()%1000);
}

int RandomColorCalc()
{
	return (rand()%255);
}

int randomzalloc()
{
	return (rand()%3);
}

void Rainbow(int t)
{
	long timeout_count = 0;
	long timeout= t + millis();
		
	// Green Up 
	// Blue Down
	for (int i= 0; i < 255; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i++;
			timeout = t + millis();
			analogWrite(Green_Port, i);
			analogWrite(Blue_Port, 255-i);
		}
		ReadMode();
		if (mode != rainbow)
		{
			i = forout;
		}
}

	// Red Up
	// Green Down
	for (int i= 0; i < 255; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i++;
			timeout = t + millis();
			analogWrite(Red_Port, i);
			analogWrite(Green_Port, 255-i);
		}
		ReadMode();
		if (mode != rainbow)
		{
			i = forout;
		}
	}
		
	// Blue Up
	// Red Down
	for (int i= 0; i < 255; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i++;
			timeout = t + millis();
			analogWrite(Blue_Port, i);
			analogWrite(Red_Port, 255-i);
		}
		ReadMode();
		if (mode != rainbow)
		{
			i = forout;
		}
	}
}

void UpDown_Start(int t)
{
	long timeout_count = 0;
	long timeout= t + millis();
	
	// Green Up and Down
	for (int i= 0; i < 255; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i++;
			timeout = t + millis();
		}
		analogWrite(Green_Port, i);
	}
	for (int i= 255; i > 0; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i--;
			timeout = t + millis();
		}
		analogWrite(Green_Port, i);
	}

	// Red Up and Down
	for (int i= 0; i < 255; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i++;
			timeout = t + millis();
		}
		analogWrite(Red_Port, i);
	}
	for (int i= 255; i > 0; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i--;
			timeout = t + millis();
		}
		analogWrite(Red_Port, i);
	}
	
	// Blue Up and Down
	for (int i= 0; i < 255; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i++;
			timeout = t + millis();
		}
		analogWrite(Blue_Port, i);
	}
	for (int i= 255; i > 0; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i--;
			timeout = t + millis();
		}
		analogWrite(Blue_Port, i);
	}
	modeback = pulse;
}

void UpDown(int t)
{
	long timeout_count = 0;
	long timeout= t + millis();
	
	// Green Up and Down
	for (int i= 0; i < 255; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i++;
			timeout = t + millis();
		}
		analogWrite(Green_Port, i);		
		ReadMode();
		if (mode != updown)
		{
			i = forout;
		}
	}
	for (int i= 255; i > 0; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i--;
			timeout = t + millis();
		}
		analogWrite(Green_Port, i);
		ReadMode();
		if (mode != updown)
		{
			i = forout;
		}
	}

	// Red Up and Down
	for (int i= 0; i < 255; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i++;
			timeout = t + millis();
		}
		analogWrite(Red_Port, i);
		ReadMode();
		if (mode != updown)
		{
			i = forout;
		}
	}
	for (int i= 255; i > 0; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i--;
			timeout = t + millis();
		}
		analogWrite(Red_Port, i);
		ReadMode();
		if (mode != updown)
		{
			i = forout;
		}
	}
	
	// Blue Up and Down
	for (int i= 0; i < 255; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i++;
			timeout = t + millis();
		}
		analogWrite(Blue_Port, i);
		ReadMode();
		if (mode != updown)
		{
			i = forout;
		}
 	}
	for (int i= 255; i > 0; i=i)
	{
	 	timeout_count = millis();
	 	if (timeout_count > timeout)
		{
	 		i--;
	 		timeout = t + millis();
		}
	 	analogWrite(Blue_Port, i);
		ReadMode();
		if (mode != updown)
		{
			i = forout;
		}
	}
}

void Manual()
{
	analogWrite(Green_Port, green_PWM);
	analogWrite(Blue_Port, blue_PWM);
	analogWrite(Red_Port, red_PWM);
}

void Pulse(int t)
{
	long timeout_count = 0;
	long timeout= t + millis();
		

	for (int i= 0; i < Top_PWM; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i++;
			timeout = t + millis();
			ReadMode();
			if (mode != pulse)
			{
				i = forout ;
			}
		}
		if (green_PWM > min_pulse)	analogWrite(Green_Port, i);
		if (blue_PWM > min_pulse)	analogWrite(Blue_Port, i);
		if (red_PWM > min_pulse)	analogWrite(Red_Port, i);

	}
	
	for (int i= Top_PWM; i > 0; i=i)
	{
		timeout_count = millis();
		if (timeout_count > timeout)
		{
			i--;
			timeout = t + millis();
		}
		if (green_PWM > min_pulse)	analogWrite(Green_Port, i);
		if (blue_PWM > min_pulse)	analogWrite(Blue_Port, i);
		if (red_PWM > min_pulse)	analogWrite(Red_Port, i);
		ReadMode();
		if (mode != pulse)
		{
			i = forout ;
		}
	}
}

void RandomColor()
{
	if(millis()>timeoutcolor)
	{
		analogWrite(Red_Port,RandomColorCalc());
		analogWrite(Green_Port,RandomColorCalc());
		analogWrite(Blue_Port,RandomColorCalc());
		timeoutcolor = millis() + RandomColorCalc()*2+800;
	}
}

void Xmas()
{
	if(timeoutxmas < millis())
	{
		switch(randomzalloc())
		{
			case 0:
				analogWrite(Red_Port,255);
				analogWrite(Green_Port,0);
				timeoutxmas= randomzal() + millis();
				break;
				
			case 1:
				analogWrite(Red_Port,0);
				analogWrite(Green_Port,0);
				timeoutxmas= randomzal() + millis();
				break;
			
			case 2:
				analogWrite(Red_Port,0);
				analogWrite(Green_Port,255);
				timeoutxmas= randomzal() + millis();
				break;
		}
	}
}

void set_Default(int funk)
{
	switch(funk)
	{
		case 'r':
			red_PWM = ((DataSerialRX[1]-48) * 100) + ((DataSerialRX[2]-48) * 10) + (DataSerialRX[3]-48);
			if (red_PWM > 255) 
			{
				red_PWM = 255;
			}
			analogWrite(Red_Port, red_PWM);
			Serial.print("Red default PWM ");
			Serial.println(red_PWM);
			break;
			
		case 'b':
			blue_PWM = ((DataSerialRX[1]-48) * 100) + ((DataSerialRX[2]-48) * 10) + (DataSerialRX[3]-48);
			if (blue_PWM > 255)
			{ 
				blue_PWM = 255;
			}
			analogWrite(Blue_Port, blue_PWM);
			Serial.print("Blue default PWM ");
			Serial.println(blue_PWM);
			break;
	
		case 'g':
			green_PWM = ((DataSerialRX[1]-48) * 100) + ((DataSerialRX[2]-48) * 10) + (DataSerialRX[3]-48);
			if (green_PWM > 255) 
			{
				green_PWM = 255;
			}
			analogWrite(Green_Port,green_PWM);
			Serial.print("Green default PWM ");
			Serial.println(green_PWM);
			break; 
			
		case 't':
			Top_PWM = ((DataSerialRX[1]-48) * 100) + ((DataSerialRX[2]-48) * 10) + (DataSerialRX[3]-48);
			if (Top_PWM > 255) Top_PWM = 255;
			Serial.print("Top default PWM only for Pulsemode ");
			Serial.println(Top_PWM);
			break;
			
		case 's':
			changespeed = ((DataSerialRX[1]-48) * 100) + ((DataSerialRX[2]-48) * 10) + (DataSerialRX[3]-48);
			if (changespeed == 0) changespeed = 0;
			Serial.print("Step speed default ");
			Serial.println(changespeed);
			break; 
	}
}

void SwitchMode()
{
	switch(mode)
	{
		case rainbow:
			Rainbow(changespeed);
			break;
		
		case updown:
			UpDown(changespeed);
			break;
		
		case manual:
			Manual();
			break;
		
		case pulse:
			Pulse(changespeed);
			break;
		
		case xmas:
			Xmas();
			break;
			
		case ramdomcolor:
			RandomColor();
			break;
		
 		 default:
 			mode = modeback;
 			break;
	}
}

void ReadMode()
{
	// Mode
	if((DataSerialRX[0] == 'm') && (DataSerialRX[1] = '0') && (DataSerialRX[2] == '0') && (DataSerialRX[3] == '0'))
	{
		mode = rainbow;
		modeback = rainbow;
		Serial.print("Rainbow Mode enabled\n");
		Del_Input();
	}
	else if((DataSerialRX[0] == 'm') && (DataSerialRX[1] = '0') && (DataSerialRX[2] == '0') && (DataSerialRX[3] == '1'))
	{
		mode = updown;
		Serial.print("UpDown Mode enabled\n");
		Del_Input();
	}
	else if((DataSerialRX[0] == 'm') && (DataSerialRX[1] = '0') && (DataSerialRX[2] == '0') && (DataSerialRX[3] == '2'))
	{
		mode = manual;
		modeback = manual;
		Serial.print("Manual Mode enabled\n");
		Del_Input();
	}
	else if((DataSerialRX[0] == 'm') && (DataSerialRX[1] = '0') && (DataSerialRX[2] == '0') && (DataSerialRX[3] == '3'))
	{
		mode = pulse;
		modeback = pulse;
		Serial.print("pulse Mode enabled\n");
		Del_Input();
	}
	else if((DataSerialRX[0] == 'm') && (DataSerialRX[1] = '0') && (DataSerialRX[2] == '0') && (DataSerialRX[3] == '4'))
	{
		mode = xmas;
		modeback = xmas;
		Serial.print("Xmas Mode enabled\n");
		Del_Input();
	}
	else if((DataSerialRX[0] == 'm') && (DataSerialRX[1] = '0') && (DataSerialRX[2] == '0') && (DataSerialRX[3] == '5'))
	{
		mode = ramdomcolor;
		modeback = ramdomcolor;
		Serial.print("Random Color Mode enabled\n");
		Del_Input();
	}
	else if((DataSerialRX[0] == 'b') || (DataSerialRX[0] == 'g') || (DataSerialRX[0] == 'r') || (DataSerialRX[0] == 't') || (DataSerialRX[0] == 's'))
	{
		set_Default(DataSerialRX[0]);
		Del_Input();
	}
}
