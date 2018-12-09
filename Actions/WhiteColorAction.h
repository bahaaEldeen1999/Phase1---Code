#include "Action.h"

class WhiteColorAction :public Action
{
public:
	WhiteColorAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};