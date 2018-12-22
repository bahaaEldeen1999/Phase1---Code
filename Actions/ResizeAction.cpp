#include "ResizeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"ColorIconAction.h"


ResizeAction::ResizeAction(ApplicationManager * pApp) :Action(pApp)
{
}

void ResizeAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a size");

}

void ResizeAction::SwitchToResizeBar()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->CreateColorBar();
}

void ResizeAction::Execute()
{
	ReadActionParameters();
	SwitchToResizeBar();

}
