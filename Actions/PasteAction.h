#pragma once
#include "action.h"
#include "CopyAction.h"
class PasteAction :
	public Action
{
public:
	private:
	Point P1; //Point of selection
	
	
	
	
public:
	PasteAction(ApplicationManager *pApp);
	~PasteAction();

	
	virtual void ReadActionParameters();
	
	
	virtual void Execute() ;
};