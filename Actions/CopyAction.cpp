//#pragma once
#include "CopyAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
#include "SelectAction.h"



  CFigure *FigPtr = NULL;
  bool isCopy;
   GfxInfo info;

CopyAction::CopyAction(ApplicationManager * pApp):Action(pApp)
{
	
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
	pManager->unSetSelectedFig();
	pManager->unSetClip();
	FigPtr = NULL;
	FigPtr->SetSelected(false);
	pManager->SetSelectedFig(pManager->GetFigure(P1.x,P1.y));
	pManager->setClip( pManager->GetSelectedFig());
	FigPtr = pManager->getClip();
	if(FigPtr){
		info =  pManager->GetSelectedFig()->getInfo();
	isCopy = true;
	}else{
		Output* pOut = pManager->GetOutput();

		pOut->PrintMessage("no figure is selected");
	}
	
	/*
	pManager->SetSelectedFig(pManager->GetFigure(P1.x,P1.y));
	
	FigPtr = pManager->GetFigure(P1.x,P1.y);
	if(FigPtr){
	isCopy = true;
	info = FigPtr->getInfo();
	}else{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("no figure is selected");
	}
	*/
	

	

 }
