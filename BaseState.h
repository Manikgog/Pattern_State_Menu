#ifndef _BASESTATE_H_
#define _BASESTATE_H_

#include<string>
#include<Windows.h>
#include<conio.h>
using namespace std;

class Context;

class BaseState
{
public:
	BaseState();
	~BaseState();
	void Col(int bg, int txt)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)((bg << 4) | txt));
	}

	void setcur(int x, int y)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(hConsole, coord);
	}
	virtual void HandleUP(Context* context) = 0;
	virtual void HandleDOWN(Context* context) = 0;
	virtual void MenuUP() = 0;
	virtual void MenuDOWN() = 0;
};


#endif