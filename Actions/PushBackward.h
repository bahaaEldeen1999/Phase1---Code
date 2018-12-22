#include "Action.h"

class PushBackward :public Action
{
public:
	PushBackward(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};