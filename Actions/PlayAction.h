#pragma once
#include "Action.h"
class PlayAction :
	public Action
{
public:
	PlayAction(ApplicationManager *pApp);
	void ReadActionParameters();
	virtual void Execute() ;
	~PlayAction(void);
};

