#pragma once

#include <string>
#include "BaseState.h"
using namespace std;

class StateB :public BaseState
{
public:
	StateB();
	~StateB();
	// �������� ��������� �� ������
	void HandleDOWN(Context* context)override;
	void HandleUP(Context* context)override;
	void HandleENTER(Context* context)override;
	void MenuUP();
	void MenuDOWN();
};

