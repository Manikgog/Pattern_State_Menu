#pragma once

#include<Windows.h>
#include<conio.h>
#include<iostream>

#include "BaseState.h"

// класс контекста
// его внутреннее состояние будет меняться
class Context
{
	// переменная для внутреннего состояния
	BaseState* pCurrent = nullptr;

	char input_menu(int low, int hi, size_t& numAcion) {
		int c1 = 0;
		int c2 = 0;
		int c = c1 + c2;
		do {
			bool f = false;
			if (_kbhit()) {
				c1 = _getch();
				if (c1 == 13) {
					f = true;
					c = c1 + c2;
					break;
				}
				c2 = _getch();
				c = c1 + c2;
				switch (c) {
				case 296:
					--numAcion;
					break;
				case 304:
					++numAcion;
					break;
				}
			}

		} while (c1 != 13 && c != 296 && c != 304);
		if (numAcion < low)
			numAcion = hi;
		else if (numAcion > hi)
			numAcion = low;
		return (char)c;
	}

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


	void Menu()
	{
		Col(0, 15);
		setcur(2, 2); std::cout << "Добавление нового дела";
		setcur(2, 3); std::cout << "Изменение дела";
		setcur(2, 4); std::cout << "Сортировка дел";
		setcur(2, 5); std::cout << "Выход";
	}

public:

	Context(BaseState* pTemp)
	{
		pCurrent = pTemp;
		Menu();
	}

	~Context()
	{
		if (pCurrent)
			delete pCurrent;
	}


	// возвращаем внутреннее состояние
	BaseState* GetState()
	{
		return pCurrent;
	}
	// изменяем внутреннее состояние
	void SetState(BaseState* pTemp)
	{
		if (pCurrent)
			delete pCurrent;

		pCurrent = pTemp;
	}
	// выполняем некоторое действие в результате, которого меняется внутренее состояние
	void Request()
	{
		size_t nCase = 1;
		while (1) {
			int n = (int)input_menu(1, 4, nCase);
			if (n == 40)
				pCurrent->HandleUP(this);
			if (n == 48)
				pCurrent->HandleDOWN(this);
			if (n == 13)
				break;
		}

	}
};




