//#pragma once
#include "CutAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
  //CFigure *FigPtr = NULL;
CutAction::CutAction(ApplicationManager * pApp):Action(pApp)
{
	//fig = NULL;
}
 void CutAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
 	pOut->PrintMessage("Select a Figure to cut");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}
 //Execute the action
void CutAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	CFigure* C=pManager->GetFigure(P1.x,P1.y);
	//Check for selected figure
	pManager->SetSelectedFig(C);
	FigPtr = NULL;
	FigPtr =C;
	
	if(FigPtr){
		//std::cout<<"cut found";
		info = FigPtr->getInfo();
		FigPtr->ChngDrawClr(GRAY);
		isCopy = false;
	}
	//FigPtr->ChngDrawClr(GRAY);
	//cutFigPtr->ChngDrawClr(GRAY);
	//Output* pOut = pManager->GetOutput();
	//cutFigPtr->Draw(pOut);


	//pOut->DrawRect(fig->getInfo);
	//std::cout<<"h ";

 }
