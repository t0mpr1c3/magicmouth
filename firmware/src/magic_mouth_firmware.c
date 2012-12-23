/* 
 * Magic Mouth Firmware
 *
 * Revision History
 * ================
 * 
 * Revision 1.0 21.12.12 Tom Price
 * initial commit
 *
 * ===========
 *
 * Copyright (C) 2012 Tom Price (t0mpr1c3 <at> gmail <dot> com)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "hardware.h"

enum Mode 
{
	Wait,
	Speak,
	Demo,
	Stop,
	Pause,
	SetPitch,
	SetVolume,
	SetRate,
	RevertSettings,
	PrintSettings,
	PrintVersion,
	PrintCommands
};

volatile enum Mode mode = Wait;


// The i2c slave has received a message	
void myI2cRxHandler(cBuffer* rxData)
{
	// parse message
	uint8_t c;
	while ( bufferGet( rxData, &c ) )
	{
		switch ( mode )
		{
			case Wait:
				switch ( c )
				{
					case 'S':
						mode = Speak;
						break;
						
					case 'D':
						mode = Demo;
						break;
						
					case 'X':	// stop speaking, flush buffers
						mode = Stop;
						// clear speech buffers
						rprintfChar( 26 );
						// Reset I2C input buffer
						bufferFlush( rxData );
						rxData->dataindex = 0;
						mode = Wait;
						break;
						
					case 'Z':	// pause/unpause
						// accept no further input until unpause command
						mode = Pause;
						break;
						
					case 'P':	//set speech pitch
						mode = SetPitch;
						break;
					
					/*
					// software volume change not implemented
					case 'V':	// set volume
						mode = SetVolume;
						mode = Wait;
						break;
					*/
					
					/*
					// speech rate change not implemented
					case 'W':	// set speech rate
						mode = SetRate;
						// do something with _speech_timeFactor
						mode = Wait;
						break;
					*/
					
					case 'R':	// revert settings
						mode = RevertSettings;
						setPitch( 7 ); // default pitch
						mode = Wait;
						break;
					
					/*		
					// I2C print commands not yet implemented
					case 'C':	// print settings to I2C master
						mode = PrintSettings;
						// bufferQueue(cBuffer* buffer, const void* src, size_t len)
						// getPitch();
						mode = Wait;
						break;
					
					case 'I':	// print firmware version to I2C master
						mode = PrintVersion;
						// bufferQueue(cBuffer* buffer, const void* src, size_t len)
						mode = Wait;
						break;
						
					case 'H':	// print available commands to I2C master
						mode = PrintCommands;
						// bufferQueue(cBuffer* buffer, const void* src, size_t len)
						mde = Wait;
						break;
					*/
						
					default:
						break;
				};
				break; // case Wait
				
			case Speak:
				switch ( c )
				{
					case '\n':
						rprintfChar( c );
						mode = Wait;
						break;
					default:
						rprintfChar( c );
				};
				break; // case Speak
				
			case Demo:
				switch ( c )
				{
					case '0':	// Announcement
						rprintfProgStrM( "Laydeez and jenntulmen.\n" );
						rprintfProgStrM( "You are lissning to the Madgick\n");
						rprintfProgStrM( "Mouth, Ardweeno sheeyld.\n");
						mode = Wait;
						break;
					case '1':	// Daisy Bell
						rprintfProgStrM( "Daisy, Daisy, give me your answer do.\n" );
						rprintfProgStrM( "I'm half crazy all for the love of you.\n" );
						rprintfProgStrM( "It won't be a stylish marriage, I can't afford a carriage.\n" );
						rprintfProgStrM( "But you'll look sweet upon the seat of a bicycle made for two.\n" );
						mode = Wait;
						break;
					case '2':	// Test					
						setPitch( 7 );
						rprintfProgStrM( "This izzu test.\n" );		
						setPitch( 10 );	
						rprintfProgStrM( "Low pitch.\n" );		
						rprintfProgStrM( "1,2,3.\n" );
						setPitch( 7 );
						rprintfProgStrM( "Normal pitch.\n" );	
						rprintfProgStrM( "1,2,3.\n" );
						setPitch( 3 );
						rprintfProgStrM( "High pitch.\n" );		
						rprintfProgStrM( "1,2,3.\n" );				
						setPitch( 7 );
					default:
						mode = Wait;
				};
				break;	// case Demo
			
			case Pause:
				if ( c == 'Z' ) // unpause
				{
					mode = Wait;
				};
				break;	// case Pause
			
			case SetPitch: 
				// Parameter is a single, hexadecimal digit
				// Higher numbers will result in a lower voice 
				// and smaller number will give a higher voice.
				if ( c >= '0' && c <= '9' )
				{
					setPitch( c - 0x30 ); // '0' = 0x30
				} else if ( c >= 'A' && c <= 'F' )
				{
					setPitch( c - 0x41 + 10 ); // 'A' = 0x41
				} else if ( c >= 'a' && c <= 'f' )
				{
					setPitch( c - 0x61 + 10 ); // 'a' = 0x61
				}
				mode = Wait;
				break;
			
			default:
				mode = Wait;
				break;
		}
	}
}	

// The i2c slave needs to send back some data
void myI2cTxHandler(cBuffer* txData){
	// Add code here to write the response into txData
}

// Initialise the hardware
void appInitHardware(void) {
	initHardware();
}
// Initialise the software
TICK_COUNT appInitSoftware(TICK_COUNT loopStart){
	// Set up callbacks for i2c	
	i2cSlaveSetReceiveHandler(&myI2cRxHandler);
	i2cSlaveSetTransmitHandler(&myI2cTxHandler);
	return 0;
}
// This is the main loop
TICK_COUNT appControl(LOOP_COUNT loopCount, TICK_COUNT loopStart) {

	return 0;
}
