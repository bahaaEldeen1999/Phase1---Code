#include"FillColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillColorAction::FillColorAction(ApplicationManager * pApp) :Action(pApp)
{
}

void FillColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click On Color Palette to choose fill color");

	pManager->SetStateNum(1);
}

void FillColorAction::Execute()
{
	ReadActionParameters();
}

