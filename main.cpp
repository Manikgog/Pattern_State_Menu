#include<iostream>
#include<Windows.h>
#include<conio.h>
#include "Context.h"
#include "StateA.h"

using namespace std;


//void NewMenu(int numCase, int prevCase)
//{
//	if (prevCase == 1)
//	{
//		Col(0, 15);
//		setcur(2, prevCase * 2); std::cout << "начальные пок.:";
//	}
//	else if (prevCase == 2)
//	{
//		Col(0, 15);
//		setcur(2, prevCase * 2); std::cout << "последние пок.:";
//	}
//	else if (prevCase == 3)
//	{
//		Col(0, 15);
//		setcur(2, prevCase * 2); std::cout << "тариф:";
//	}
//	else if (prevCase == 4)
//	{
//		Col(0, 15);
//		setcur(2, prevCase * 2); std::cout << "сумма:";
//	}
//
//	if (numCase == 1)
//	{
//		Col(0, 9);
//		setcur(2, numCase * 2); std::cout << "начальные пок.:";
//	}
//	else if (numCase == 2)
//	{
//		Col(0, 9);
//		setcur(2, numCase * 2); std::cout << "последние пок.:";
//	}
//	else if (numCase == 3)
//	{
//		Col(0, 9);
//		setcur(2, numCase * 2); std::cout << "тариф:";
//	}
//	else if (numCase == 4)
//	{
//		Col(0, 9);
//		setcur(2, numCase * 2); std::cout << "сумма:";
//	}
//
//
//}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Context obj(new StateA());

	obj.Request();


	return 0;
}

