#pragma once
#include "SelectByFigAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include "SelectAction.h"


SelectByFigAction::SelectByFigAction(ApplicationManager *pApp):Action(pApp)
{
}
void SelectByFigAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure by figure shape");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();
}
void SelectByFigAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Check for selected figure
	pManager->SetSelectedFig(pManager->GetFigure(P1.x,P1.y));
}


SelectByFigAction::~SelectByFigAction(void)
{
}
