#pragma once
#include "BaseState.h"

class StateC : public BaseState
{
public:
	StateC();
	~StateC();

	// изменяем состояние на другое
	void HandleDOWN(Context* context)override;
	void HandleUP(Context* context)override;
	void HandleENTER(Context* context)override;
	void MenuUP();
	void MenuDOWN();
};

#pragma once
