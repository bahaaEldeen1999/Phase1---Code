#include "Action.h"

class ColorIconAction :public Action
{

private:
	Point P1; //Point of selection
public:
	ColorIconAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	void SwitchToColorBar();
	virtual void Execute();

};
