#include "StateA.h"
#include"StateB.h"
#include"StateC.h"
#include"StateD.h"
#include "Context.h"
#include <iostream>

StateC::StateC()
{
}


StateC::~StateC()
{
}

// �������� ��������� �� ������
void StateC::HandleDOWN(Context* context) {
	MenuDOWN();
	context->SetState(new StateD());
}

void StateC::HandleUP(Context* context) {
	MenuUP();
	context->SetState(new StateB());

}

void StateC::HandleENTER(Context* context) {
	//MenuENTER();
	context->SetState(new StateC());
}

void StateC::MenuUP()
{
	Col(0, 15);
	setcur(2, 4); std::cout << "���������� ���";
	Col(0, 9);
	setcur(2, 3); std::cout << "��������� ����";
}

void StateC::MenuDOWN()
{
	Col(0, 15);
	setcur(2, 4); std::cout << "���������� ���";
	Col(0, 9);
	setcur(2, 5); std::cout << "�����";
}

