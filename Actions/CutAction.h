#pragma once
#include "action.h"
#include "../ApplicationManager.h"
#include "CopyAction.h"

class CutAction  : public CopyAction
{
 	private:
	Point P1; //Point of selection
	

public:

	CutAction(ApplicationManager *pApp);
	~CutAction();
	virtual void ReadActionParameters();
	virtual void Execute() ;
	
	
 };
