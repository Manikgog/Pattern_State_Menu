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

// �������� ��������� �� ������
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
	setcur(2, 2); std::cout << "���������� ������ ����";
	Col(0, 9);
	setcur(2, 5); std::cout << "�����";
}

void StateA::MenuDOWN()
{
	Col(0, 15);
	setcur(2, 2); std::cout << "���������� ������ ����";
	Col(0, 9);
	setcur(2, 3); std::cout << "��������� ����";
}

