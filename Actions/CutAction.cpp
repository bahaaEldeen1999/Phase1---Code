//#pragma once
#include "CutAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>

CutAction::CutAction(ApplicationManager * pApp):Action(pApp)
{

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
	pManager->unSetSelectedFig();
	pManager->unSetClip();
	FigPtr = NULL;
	FigPtr->SetSelected(false);
	pManager->SetSelectedFig(pManager->GetFigure(P1.x,P1.y));
	//FigPtr = pManager->GetSelectedFig();
	pManager->setClip( pManager->GetSelectedFig());
	FigPtr = pManager->getClip();
	if(FigPtr){
	isCopy = false;
	info = pManager->GetSelectedFig()->getInfo();
	//pManager->GetSelectedFig()->
	 
	FigPtr->ChngDrawClr(GRAY);
	FigPtr->SetSelected(false);
	pManager->unSetSelectedFig();
	
	}else{
	Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("no figure is selected");
	}
	


	/*
	FigPtr = NULL;
	
	pManager->SetSelectedFig(pManager->GetFigure(P1.x,P1.y));
	FigPtr = pManager->GetFigure(P1.x,P1.y);
	if(FigPtr){
		
		info = FigPtr->getInfo();
		FigPtr->ChngDrawClr(GRAY);
		isCopy = false;
	}else{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("no figure is selected");
	}
	*/


 }
