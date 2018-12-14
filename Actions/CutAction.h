#pragma once
#include "action.h"
#include "../ApplicationManager.h"
<<<<<<< HEAD
extern CFigure *cutFigPtr ; //copied fig
=======
#include "CopyAction.h"
//extern CFigure *FigPtr ; //copied fig
>>>>>>> bahaa_branch1
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
