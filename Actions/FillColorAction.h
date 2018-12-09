#include "Action.h"

class FillColorAction :public Action
{
private:
	Point P1; //Point of selection
public:
	FillColorAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};