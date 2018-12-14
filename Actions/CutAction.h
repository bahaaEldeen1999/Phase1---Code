#pragma once
#include "action.h"
#include "../ApplicationManager.h"
#include "CopyAction.h"
//extern CFigure *FigPtr ; //copied fig
//CFigure* getCopied();
class CutAction : public Action
{
 	private:
	Point P1; //Point of selection
	

public:

	CutAction(ApplicationManager *pApp);
	~CutAction();
	virtual void ReadActionParameters();
	virtual void Execute() ;
	//friend  CFigure* getCopied();
 };
