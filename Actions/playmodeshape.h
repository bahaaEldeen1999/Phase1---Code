#include "Action.h"
class playmodeshape:public Action
{
public:
	private:
	Point P1; //Point of selection
	int countcorrect,countincorrect; //counters
	int randomfigtype;//randomfigtype (0:rectangle,1:line,2:ellipse,3:triangle,4:rhombus)
	int randomfigurecount;
public:
	playmodeshape(ApplicationManager *pApp);

	//Reads  parameters and Prints Info
	virtual void ReadActionParameters();
	string FigType(int x);
	// Executes the Algorithm
	virtual void Execute();
};
