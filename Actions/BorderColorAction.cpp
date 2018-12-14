#include"BorderColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

BorderColorAction::BorderColorAction(ApplicationManager * pApp) :Action(pApp)
{
}

void BorderColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click On Color Palette to choose draw color");

	UI.CurrentState = 0;
}

void BorderColorAction::Execute()
{
	ReadActionParameters();
}
