#include "StateA.h"
#include"StateB.h"
#include"StateC.h"
#include"StateD.h"
#include"BaseState.h"
#include "Context.h"
#include <iostream>

StateA::StateA()
{
}


StateA::~StateA()
{
}

// изменяем состояние на другое
void StateA::HandleDOWN(Context* context) {
	MenuDOWN();
	context->SetState(new StateB());
}

void StateA::HandleUP(Context* context) {
	MenuUP();
	context->SetState(new StateD());

}

void StateA::MenuUP() 
{
	Col(0, 15);
	setcur(2, 2); std::cout << "Добавление нового дела";
	Col(0, 9);
	setcur(2, 5); std::cout << "Выход";
}

void StateA::MenuDOWN()
{
	Col(0, 15);
	setcur(2, 2); std::cout << "Добавление нового дела";
	Col(0, 9);
	setcur(2, 3); std::cout << "Изменение дела";
}

