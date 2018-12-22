#pragma once
#include "Action.h"
class ResizeAction : public Action
{

	private:
	Point P1; //Point of selection
public:
	ResizeAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	void SwitchToResizeBar();
	virtual void Execute();
};

