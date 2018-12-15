
#include "Action.h"
class stm :public Action
{
public:
	stm(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};

