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
		pManager->SetSelectedFig(NULL);
		pManager->GetOutput()->ClearStatusBar();
	}
	else pManager->GetOutput()->PrintMessage("Please Select a Figure To Delete");
	
	
}

DeleteAction::~DeleteAction(void)
{
}

