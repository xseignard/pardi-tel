#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
	{'*', '0', '#'}};
byte rowPins[ROWS] = {5, 6, 7, 8};
byte colPins[COLS] = {2, 3, 4};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
SoftwareSerial sws(10, 11); // RX, TX
DFRobotDFPlayerMini mp3;

void setup()
{
	sws.begin(9600);
	Serial.begin(115200);
	if (!mp3.begin(sws))
		while (true)
			;
	mp3.volume(25);
}

void loop()
{
	char key = keypad.getKey();
	if (key != NO_KEY)
	{
		switch (key)
		{
		case '1':
			mp3.playMp3Folder(1);
			break;
		case '2':
			mp3.playMp3Folder(2);
			break;
		case '3':
			mp3.playMp3Folder(3);
			break;
		case '4':
			mp3.playMp3Folder(4);
			break;
		case '5':
			mp3.playMp3Folder(5);
			break;
		case '6':
			mp3.playMp3Folder(6);
			break;
		case '7':
			mp3.playMp3Folder(7);
			break;
		case '8':
			mp3.playMp3Folder(8);
			break;
		case '9':
			mp3.playMp3Folder(9);
			break;
		case '0':
			mp3.playMp3Folder(10);
			break;
		case '*':
			mp3.playMp3Folder(11);
			break;
		case '#':
			mp3.playMp3Folder(12);
			break;
		}
		delay(300);
	}
}