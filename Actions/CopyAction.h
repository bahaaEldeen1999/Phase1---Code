#pragma once
#include "action.h"
#include "../ApplicationManager.h"

class CopyAction : public Action
{
 	private:
	Point P1; //Point of selection
protected:
	GfxInfo info;
	

public:
	
	CopyAction(ApplicationManager *pApp);
	~CopyAction();
	virtual void ReadActionParameters();
	virtual void Execute() ;
	
	
 };
