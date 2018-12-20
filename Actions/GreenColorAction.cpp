#include"GreenColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

GreenColorAction::GreenColorAction(ApplicationManager * pApp) :Action(pApp)
{
}

void GreenColorAction::ReadActionParameters()
{
}


void GreenColorAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Green Color is selected");

	if (UI.CurrentState == 0 && pManager->GetSelectedFig() != 0)
	{
		pManager->GetSelectedFig()->ChngDrawClr(GREEN);
	}
	else if (UI.CurrentState == 1 && pManager->GetSelectedFig() != 0)
	{
		pManager->GetSelectedFig()->ChngFillClr(GREEN);
	}

	if (UI.CurrentState == 0)
	{
		UI.DrawColor = GREEN;
	}
	else if (UI.CurrentState == 1)
	{
		UI.FillColor = GREEN;
	}

	pManager->GetSelectedFig()->SetSelected(false);

	pOut->CreateDrawToolBar();
}
