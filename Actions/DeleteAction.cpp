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
		CFigure** List =new CFigure*;
		List =pManager->GetFigList();
		for (int i=pManager->GetFigNum();i<pManager->GetFigCount()-1;i++) 
		{
			List[i]=List[i+1];
		}
		List[pManager->GetFigCount()]=NULL;
		pManager->SetFigCount(pManager->GetFigCount()-1);
	}
	
	pManager->GetOutput()->ClearStatusBar();
}

DeleteAction::~DeleteAction(void)
{
}
