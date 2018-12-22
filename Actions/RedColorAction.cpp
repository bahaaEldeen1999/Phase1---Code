#include"RedColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RedColorAction::RedColorAction(ApplicationManager * pApp) :Action(pApp)
{
}

void RedColorAction::ReadActionParameters()
{
}


void RedColorAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("Red Color is selected");

	if (UI.CurrentState == 0 && pManager->GetSelectedFig() != 0)
	{
		pManager->GetSelectedFig()->ChngDrawClr(RED);
	}
	else if (UI.CurrentState == 1 && pManager->GetSelectedFig() != 0)
	{
		pManager->GetSelectedFig()->ChngFillClr(RED);
	}
	
	if (UI.CurrentState == 0)
	{
		UI.DrawColor = RED;
	}
	else if (UI.CurrentState == 1)
	{
		UI.FillColor = RED;
	}

	if (pManager->GetSelectedFig() != 0)
	{
		pManager->GetSelectedFig()->SetSelected(false);
		pManager->SetSelectedFig(NULL);
	}

	pOut->CreateDrawToolBar();
}
