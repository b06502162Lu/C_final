#include <stdlib.h> //Standard c and c++ libraries
#include <conio.h>
#include <stdio.h>
#include <windows.h> // To take control over the terminal
#include <list>
#ifndef DRAW 
#define DRAW
#include "drawing.h" 
#endif 
using namespace std;


void gotoxy(int x, int y)
{ // Allows to move inside the terminal using coordinates
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x; // Starts from 0
	dwPos.Y = y; // Starts from 0
	SetConsoleCursorPosition(hCon, dwPos);
}


void HideCursor()
{ // Hides the cursor :3
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cci);
}


void DrawWhiteSpace(int a_x, int a_y, int b_x, int b_y)
{ // To clean a certain space in the terminal
	for(int i = a_x; i < b_x; i++)
	{
		for(int j = a_y; j < b_y; j++)
		{
			gotoxy(i,j); printf(" ");
		}
	}
}


void DrawWindowFrame(int a_x, int a_y, int b_x, int b_y)
{ // This will draw a rectangular frame defined by two points
	DrawWhiteSpace(a_x,a_y,b_x,b_y);
	for(int i = a_x; i < b_x; i++)
	{
		gotoxy(i, a_y); printf("%c", 97);
		gotoxy(i, b_y); printf("%c", 97);
	}
	for(int i = a_y; i < b_y; i++)
	{
		gotoxy(a_x, i); printf("%c", 97);
		gotoxy(b_x, i); printf("%c", 97);
	}
	gotoxy(a_x, a_y); printf("%c", 97);
	gotoxy(b_x, a_y); printf("%c", 97);
	gotoxy(a_x, b_y); printf("%c", 97);
	gotoxy(b_x, b_y); printf("%c", 97);
}


void DrawGameLimits()
{ // Draws the game limits, and information that doesn't have to be printed repeatedly
	DrawWindowFrame(1,2,79,23); // The default size of the Windows terminal is 25 rows x 80 columns
	gotoxy( 2,1); printf("HP:");
	gotoxy(16,1); printf("ENERGY:");
	gotoxy(50,1); printf("SCORE:");
}
void WelcomeMessage()
{ // The main title, I tried to center it as best as I could
	int x = 13;
	int y = 6;
	gotoxy(x, y  ); printf(" _____                    _____ _           _           ");
	gotoxy(x, y+1); printf("|   __|___ ___ ___ ___   |   __| |_ ___ ___| |_ ___ ___ ");
	gotoxy(x, y+2); printf("|__   | . | .'|  _| -_|  |__   |   | . | . |  _| -_|  _|");
	gotoxy(x, y+3); printf("|_____|  _|__,|___|___|  |_____|_|_|___|___|_| |___|_|  ");
	gotoxy(x, y+4); printf("      |_|");
	gotoxy(x, y+6); printf("                 Press any key to play");
	gotoxy(x, y+7); printf("         developed by Carlos Hernandez C. - 2016");
}


void GameOverDefeatMessage()
{ // When you lose the game you see this in screen
	int a_x = 30;
	int a_y = 11;
	int b_x = a_x + 23;
	int b_y = a_y + 4;
	DrawWindowFrame(a_x,a_y,b_x,b_y);
	gotoxy(a_x+1,a_y+2); printf("      DEFEAT!!!");
}


void GameOverVictoryMessage()
{ // When you win the game you see this in screen
	int a_x = 30;
	int a_y = 11;
	int b_x = a_x + 23;
	int b_y = a_y + 4;
	DrawWindowFrame(a_x,a_y,b_x,b_y);
	gotoxy(a_x+1,a_y+2); printf("      VICTORY!!!");
}


void SpecialMessage()
{ // A special message for your special needs
	DrawWhiteSpace(1,1,80,24);
	gotoxy(30,11); printf("Thanks for playing! :3");
}
