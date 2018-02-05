# Arduino-RGB-PC-Light
Arduino Control PC Light from Serialport

I will Update esci.ch with a Layout and photos of the Projekt soon.

I have created a LED-Driver that can be controlled over Serial Commands for my PC.  It’s possible to set a color or to use one of the implemented lights pattern. The Arduino possesses 6 different Operation modes: Rainbow, Color Up and Down, Manual, Breathing, Xmas and Random Color mode.
You can adjust the brightness of the 3 Basic Colors in an 8bit resolution, this mean you have 256 steps per Color. So, with this setup are you able to create 16.777.216 different colors.
The Arduino is connected directly to the PC so that you can control the unit with Serial commands.

x 	  – stays for the number to deliver to the Microcontroller

mxxx 	– m represents the mode so you can change it.

rxxx 	–	r represents the red value so you can change it.

bxxx 	–	b represents the blue value so you can change it.

gxxx 	– g represents the green value so you can change it.

txxx 	–	t represents the top value of the breathing so you can change it.

sxxx 	–	s represents the speed value so you can change it.

m000 	–	represents the Rainbow mode.

m001	–	represents the UpDown mode.

m002 	–	represents the Manual mode.

m003 	–	represents the Pulse mode.

m004 	–	represents the Xmas mode.

m005 	–	represents the Random mode.

For all color the max value is 255

