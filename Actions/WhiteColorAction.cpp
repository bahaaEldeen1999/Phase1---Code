#include"WhiteColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

WhiteColorAction::WhiteColorAction(ApplicationManager * pApp) :Action(pApp)
{
}

void WhiteColorAction::ReadActionParameters()
{
}


void WhiteColorAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("White Color is selected");

	if (UI.CurrentState == 0 && pManager->GetSelectedFig() != 0)
	{
		pManager->GetSelectedFig()->ChngDrawClr(WHITE);
	}
	else if (UI.CurrentState == 1 && pManager->GetSelectedFig() != 0)
	{
		pManager->GetSelectedFig()->ChngFillClr(WHITE);
	}

	if (UI.CurrentState == 0)
	{
		UI.DrawColor = WHITE;
	}
	else if (UI.CurrentState == 1)
	{
		UI.FillColor = WHITE;
	}

	pManager->GetSelectedFig()->SetSelected(false);

	pOut->CreateDrawToolBar();
}
