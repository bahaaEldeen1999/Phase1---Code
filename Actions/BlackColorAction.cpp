#include"BlackColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

BlackColorAction::BlackColorAction(ApplicationManager * pApp) :Action(pApp)
{
}

void BlackColorAction::ReadActionParameters()
{
}


void BlackColorAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Black Color is selected");

	if (UI.CurrentState == 0 && pManager->GetSelectedFig() != 0)
	{
		pManager->GetSelectedFig()->ChngDrawClr(BLACK);
	}
	else if (UI.CurrentState == 1 && pManager->GetSelectedFig() != 0)
	{
		pManager->GetSelectedFig()->ChngFillClr(BLACK);
	}

	if (UI.CurrentState == 0)
	{
		UI.DrawColor = BLACK;
	}
	else if (UI.CurrentState == 1)
	{
		UI.FillColor = BLACK;
	}


	pOut->CreateDrawToolBar();
}
