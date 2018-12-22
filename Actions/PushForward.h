#include "Action.h"

class PushForward :public Action
{
public:
	PushForward(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};