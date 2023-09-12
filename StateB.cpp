#include "StateB.h"
#include "StateA.h"
#include "StateC.h"
#include "StateD.h"
#include "Context.h"
#include <iostream>

StateB::StateB()
{
}


StateB::~StateB()
{
}

// изменяем состояние на другое
void StateB::HandleDOWN(Context* context) {
	MenuDOWN();
	context->SetState(new StateC());

}

void StateB::HandleUP(Context* context) {
	MenuUP();
	context->SetState(new StateA());

}

void StateB::MenuUP()
{
	Col(0, 15);
	setcur(2, 3); std::cout << "Изменение дела";
	Col(0, 9);
	setcur(2, 2); std::cout << "Добавление нового дела";
}

void StateB::MenuDOWN()
{
	Col(0, 15);
	setcur(2, 3); std::cout << "Изменение дела";
	Col(0, 9);
	setcur(2, 4); std::cout << "Сортировка дел";
}