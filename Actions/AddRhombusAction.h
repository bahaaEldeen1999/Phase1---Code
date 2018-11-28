#include "Action.h"

class AddRhombusAction :public Action
{
private:
	Point P1;
	GfxInfo RhombusGfxInfo;
public:
	AddRhombusAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
