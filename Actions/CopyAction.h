#pragma once
#include "action.h"
#include "../ApplicationManager.h"
extern CFigure *FigPtr; //copied fig
extern bool isCopy;
extern GfxInfo info;
//CFigure* getCopied();
class CopyAction : public Action
{
 	private:
	Point P1; //Point of selection


public:

	CopyAction(ApplicationManager *pApp);
	~CopyAction();
	virtual void ReadActionParameters();
	virtual void Execute() ;
	//friend  CFigure* getCopied();
 };
