//#pragma once
#include "CutAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
<<<<<<< HEAD
  CFigure *cutFigPtr = NULL;
=======
  //CFigure *FigPtr = NULL;
>>>>>>> bahaa_branch1
CutAction::CutAction(ApplicationManager * pApp):Action(pApp)
{
	//fig = NULL;
}
 void CutAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
<<<<<<< HEAD
 	pOut->PrintMessage("Select a Figure to copy");
=======
 	pOut->PrintMessage("Select a Figure to cut");
>>>>>>> bahaa_branch1
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}
 //Execute the action
void CutAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Check for selected figure
	pManager->SetSelectedFig(pManager->GetFigure(P1.x,P1.y));
<<<<<<< HEAD
	cutFigPtr = pManager->GetFigure(P1.x,P1.y);
	//fig->ChngDrawClr(GRAY);
	//Output* pOut = pManager->GetOutput();
	//fig->Draw(pOut);
=======
	FigPtr = NULL;
	FigPtr = pManager->GetFigure(P1.x,P1.y);
	isCopy = false;
	//FigPtr->ChngDrawClr(GRAY);
	//cutFigPtr->ChngDrawClr(GRAY);
	//Output* pOut = pManager->GetOutput();
	//cutFigPtr->Draw(pOut);
	
>>>>>>> bahaa_branch1
	
	//pOut->DrawRect(fig->getInfo);
	//std::cout<<"h ";
	
 }