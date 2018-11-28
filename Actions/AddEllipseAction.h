#include "Action.h"

class AddEllipseAction :public Action
{
private:
	Point P1;
	GfxInfo EllipseGfxInfo;
public:
	AddEllipseAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};