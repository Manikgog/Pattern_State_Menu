#pragma once
#include "BaseState.h"

class StateD : public BaseState
{
public:
	StateD();
	~StateD();

	// �������� ��������� �� ������
	void HandleDOWN(Context* context)override;
	void HandleUP(Context* context)override;
	void MenuUP();
	void MenuDOWN();
};

#pragma once
