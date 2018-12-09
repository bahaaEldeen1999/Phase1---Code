#include "Action.h"

class RedColorAction :public Action
{
public:
	RedColorAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};