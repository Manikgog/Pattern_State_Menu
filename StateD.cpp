#include <iostream>

#include "StateA.h"
#include"StateB.h"
#include"StateC.h"
#include"StateD.h"
#include "Context.h"

StateD::StateD()
{
}


StateD::~StateD()
{
}

// �������� ��������� �� ������
void StateD::HandleDOWN(Context* context) {
	MenuDOWN();
	context->SetState(new StateA());
}

void StateD::HandleUP(Context* context) {
	MenuUP();
	context->SetState(new StateC());
}

void StateD::HandleENTER(Context* context) {
	Col(0, 15);
	exit(0);
}

void StateD::MenuUP()
{
	Col(0, 15);
	setcur(2, 5); std::cout << "�����";
	Col(0, 9);
	setcur(2, 4); std::cout << "���������� ���";
}

void StateD::MenuDOWN()
{
	Col(0, 15);
	setcur(2, 5); std::cout << "�����";
	Col(0, 9);
	setcur(2, 2); std::cout << "���������� ������ ����";
}

