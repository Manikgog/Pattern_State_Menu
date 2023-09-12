#pragma once

#include<Windows.h>
#include<conio.h>
#include<iostream>

#include "BaseState.h"
#include "Menu.h"

// ����� ���������
// ��� ���������� ��������� ����� ��������
class Context
{
private:

	BaseState* pCurrent = nullptr;

	// ��������� �� ������ ����
	Menu* mainMenu = nullptr;

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

	

public:

	Context(BaseState* pTemp)
	{
		pCurrent = pTemp;
		mainMenu = new MainMenu();
		mainMenu->Menu_();
	}

	~Context()
	{
		if (pCurrent)
			delete pCurrent;
		if (mainMenu)
			delete mainMenu;
	}


	// ���������� ���������� ���������
	BaseState* GetState()
	{
		return pCurrent;
	}
	// �������� ���������� ���������
	void SetState(BaseState* pTemp)
	{
		if (pCurrent)
			delete pCurrent;

		pCurrent = pTemp;
	}
	// ��������� ��������� �������� � ����������, �������� �������� ��������� ���������
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
			{
				pCurrent->HandleENTER(this);
				Menu* addCaseMenu = new AddCaseMenu();
				addCaseMenu->Menu_();
			}
		}


	}
};




