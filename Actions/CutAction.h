#pragma once
#include "action.h"
#include "../ApplicationManager.h"
extern CFigure *cutFigPtr ; //copied fig
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
