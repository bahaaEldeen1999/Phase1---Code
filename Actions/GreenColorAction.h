#include "Action.h"

class GreenColorAction :public Action
{
public:
	GreenColorAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};