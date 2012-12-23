Uploading firmware
===============

Attach the Magic Mouth shield on top of the Arduino.
Set the power jumper on the shield to either +5V or VIN. The power LED should be on.
Upload the ArduinoISP sketch to the Arduino (found under File >> Examples >> ArduinoISP).
Connect the 4 programming jumpers on the Magic Mouth shield. 
These connect RST, MOSI, MISO, and SCK to Arduino Digital pins 9-13.
Type the following into the command line editor,
substituting for 'XXX' the name of the port to which the Arduino is connected:

	avrdude -c avrisp -n 19200 -p atmega328p -P XXX -U flash:w:magic_mouth_firmware.hex


Demonstration
=============

Upload magic_mouth_serial_demo_sketch.ino sketch to the Arduino.
Open a serial monitor (Tools >> Serial Monitor) on the port to which the Arduino is connected.
Use the default settings of the serial monitor (9600 baud, Both NL & CR).
Starting typing commands into the serial monitor.


Magic Mouth commands
====================

Sx
Speak the text x: x is a string terminating in a carriage return.

Dx
Speak the demonstration phrase: x = 0, 1, 2.

Px
Set voice pitch: x is a single hexadecimal digit. 0 = highest pitch, 7 = default, F = lowest pitch.

R
Revert to default settings

Z
Pause/unpause

	
Generating source code
======================

Download the src directory
Unzip src/webbotlibV2/webbotavrclib-2.09 into src/webbotlibV2/webbotavrclib-2.09
Delete old AVRstudio file magic_mouth_firmware.aps
Open magic_mouth_firmware.prj in the webbotlib project designer.
Edit project design as desired.
Navigate to Tools >> Generate to generate the project code.
Choose options:
	Send rprintf output to: << speech >>
	Send error output to: << myUart >>
	Create AVRstudio project file? << Yes >>
	Enable compiler optimization? << Yes >>
	Use C++? << No >>
	Webbotlib installed in << src\webbotlibV2\webbotavrclib-2.09 >>
	printf options << Minimal >>


Compiling firmware
==================

Edit src file file magic_mouth_firmware.c as desired
Open magic_mouth_firmware.aps in AVR studio.
Navigate to Build >> Build
