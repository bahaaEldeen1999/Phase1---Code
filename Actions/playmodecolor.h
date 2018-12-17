#include "Action.h"

class playmodecolor :public Action
{
private:
	Point P1; //Point of selection
	int countcorrect, countincorrect; //counters
	int randomfigcolor;//randomfigcolor (0:red,1:blue,2:green,3:white,4:black)
	int randomfigurecount;
public:
	playmodecolor(ApplicationManager* pApp);

	//Reads  parameters and Prints Info
	virtual void ReadActionParameters();

	string FigColor(int x);

	virtual void Execute();

};