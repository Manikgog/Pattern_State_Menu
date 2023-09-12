#pragma once

#include<Windows.h>
#include<conio.h>


class Menu {
protected:
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

public:
	virtual void Menu_() = 0;
	
};

class MainMenu : public Menu
{
public:
	void Menu_()override
	{
		Col(0, 15);
		setcur(2, 2); std::cout << "���������� ������ ����";
		setcur(2, 3); std::cout << "��������� ����";
		setcur(2, 4); std::cout << "���������� ���";
		setcur(2, 5); std::cout << "�����";
	}
};

class AddCaseMenu : public Menu
{
public:
	void Menu_()override
	{
		Col(0, 15);
		setcur(2, 2); std::cout << "������� �������� ������ ����: ";
		int n;
		std::cin >> n;
	}
};