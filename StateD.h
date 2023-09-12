#pragma once
#include "BaseState.h"

class StateD : public BaseState
{
public:
	StateD();
	~StateD();

	// изменяем состояние на другое
	void HandleDOWN(Context* context)override;
	void HandleUP(Context* context)override;
	void MenuUP();
	void MenuDOWN();
};

#pragma once
