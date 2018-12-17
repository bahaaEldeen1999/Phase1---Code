#include "Action.h"
class SwitchToDraw:public Action
{
public:
	private:
	
public:
	SwitchToDraw(ApplicationManager *pApp);

	//Reads  parameters and Prints Info
	void ReadActionParameters();
	// Executes the Algorithm
	virtual void Execute() ;
};