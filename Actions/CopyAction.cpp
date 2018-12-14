//#pragma once
#include "CopyAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>

  CFigure *copyFigPtr = NULL;

  CFigure *FigPtr = NULL;
  bool isCopy;

CopyAction::CopyAction(ApplicationManager * pApp):Action(pApp)
{
	//fig = NULL;
}
 void CopyAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
 	pOut->PrintMessage("Select a Figure to copy");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}
 //Execute the action
void CopyAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Check for selected figure
	pManager->SetSelectedFig(pManager->GetFigure(P1.x,P1.y));

	copyFigPtr = pManager->GetFigure(P1.x,P1.y);

	FigPtr = NULL;
	FigPtr = pManager->GetFigure(P1.x,P1.y);
	isCopy = true;

	//fig->ChngDrawClr(GRAY);
	//Output* pOut = pManager->GetOutput();
	//fig->Draw(pOut);

	//pOut->DrawRect(fig->getInfo);
	//std::cout<<"h ";

 }
