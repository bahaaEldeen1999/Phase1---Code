#include "Action.h"
class SelectAction:public Action
{
public:
	private:
	Point P1; //Point of selection
	
public:
	SelectAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
};
