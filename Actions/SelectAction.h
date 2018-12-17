#include "Action.h"
class SelectAction:public Action
{
public:
	private:
	Point P1; //Point of selection
	
	
public:
	SelectAction(ApplicationManager *pApp);

	//Reads parameters
	virtual void ReadActionParameters();
	
	//Executes the Action
	virtual void Execute() ;
	
};
