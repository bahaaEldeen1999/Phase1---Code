#include "Action.h"

class BlackColorAction :public Action
{
public:
	BlackColorAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};