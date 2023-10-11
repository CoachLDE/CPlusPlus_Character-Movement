/************************************************************************************************
	Name: CoachLDE
	Date: 10.10.2023
	Purpose: This will be the beginnings of how I implement the function to take in user input
			 and move a character based on that user input.  In this example I will use the
			 _kbhit() function.  Today I will introduce a while loop
			 which is common in gameing.  A While Loop keeps the prgram/game running until a 
			 certain condition is met that will close the program.
*************************************************************************************************/

#include <iostream>
#include <Windows.h>	//In this library is the function that will allow is to control cursor position
#include <conio.h>		//In this library is a function to detect keypresses

using namespace std;

void GoToXY(int x, int y)
{
	HANDLE conHandle;	//Variable to hold the console handle
	conHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;		//Variable of the type/struct COORD/COORDINATE that holds the X and Y positions
	coord.X = x;
	coord.Y = y;
	//Takes two parameters.  The ID of the console window and Structure of the type COORD which are the coordinates where
	//we want to position the cursor
	SetConsoleCursorPosition(conHandle, coord);
}

int main()
{
	bool gameOver = false;

	int x = 10;
	int y = 10;

	GoToXY(x, y);		//At the initial position draw a star
	cout << '*';

	while (!gameOver)
	{
		//_kbhit() is a function that tells you if a key has been pressed.  Part of the conio.h library
		//_getch() is a function that saves the key that has been pressed.  If you press 'a', getch() saves that the 'a'
		//key has been pressed.
		if (_kbhit())			
		{
			char key = _getch();		//If a key has been pressed we will save which key it was in the varibale key.
			GoToXY(x, y); cout << " ";	//With each loop we will erase where the star was
			if (key == 'j') x--;
			if (key == 'l') x++;
			if (key == 'i') y--;
			if (key == 'k') y++;
			if (key == 'q') { gameOver = true; }
			GoToXY(x, y); cout << "*";	//With each loop we will draw where the star is

		}
	}

	return 0;
}