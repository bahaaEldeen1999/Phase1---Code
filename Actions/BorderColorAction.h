#include "Action.h"

class BorderColorAction :public Action
{
private:
	Point P1; //Point of selection
public:
	BorderColorAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};