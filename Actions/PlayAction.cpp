#pragma once
#include "PlayAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


PlayAction::PlayAction(ApplicationManager *pApp):Action(pApp)
{
}
void PlayAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//pOut->PrintMessage("Select a Figure");
	
	//Read 1st corner and store in point P1
	//pIn->GetPointClicked(P1.x, P1.y);
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();
}
void PlayAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Check for selected figure
	//pManager->SetSelectedFig(pManager->GetFigure(P1.x,P1.y));
}


PlayAction::~PlayAction(void)
{
}
