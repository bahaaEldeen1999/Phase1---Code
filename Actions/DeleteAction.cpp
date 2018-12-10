#include "DeleteAction.h"
#include "..\ApplicationManager.h"

DeleteAction::DeleteAction(ApplicationManager * pApp):Action(pApp)
{
}

void DeleteAction::ReadActionParameters() 
{



}

void DeleteAction::Execute() 
{
	
	if (pManager->GetSelectedFig()!=NULL)
	{
		pManager->RearrangeDeleted();
	}
	
	pManager->GetOutput()->ClearStatusBar();
}

DeleteAction::~DeleteAction(void)
{
}

