#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"ColorIconAction.h"


ColorIconAction::ColorIconAction(ApplicationManager * pApp) :Action(pApp)
{
}

void ColorIconAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a Color");

}

void ColorIconAction::SwitchToColorBar()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->CreateColorBar();
}

void ColorIconAction::Execute()
{
	ReadActionParameters();
	SwitchToColorBar();

}