#include "Action.h"

class BlueColorAction :public Action
{
public:
	BlueColorAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};