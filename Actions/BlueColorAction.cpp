#include"BlueColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

BlueColorAction::BlueColorAction(ApplicationManager * pApp) :Action(pApp)
{
}

void BlueColorAction::ReadActionParameters()
{
}


void BlueColorAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Blue Color is selected");

	if (UI.CurrentState == 0 && pManager->GetSelectedFig() != 0)
	{
		pManager->GetSelectedFig()->ChngDrawClr(BLUE);
	}
	else if (UI.CurrentState == 1 && pManager->GetSelectedFig() != 0)
	{
		pManager->GetSelectedFig()->ChngFillClr(BLUE);
	}

	if (UI.CurrentState == 0)
	{
		UI.DrawColor = BLUE;
	}
	else if (UI.CurrentState == 1)
	{
		UI.FillColor = BLUE;
	}

	if (pManager->GetSelectedFig() != 0)
	pManager->GetSelectedFig()->SetSelected(false);

	pOut->CreateDrawToolBar();

}
