#pragma once
#include "BaseState.h"

class StateA : public BaseState
{
public:
	StateA();
	~StateA();

	// �������� ��������� �� ������
	void HandleDOWN(Context* context)override;
	void HandleUP(Context* context)override;
	void MenuUP()override;
	void MenuDOWN()override;
};

#pragma once
