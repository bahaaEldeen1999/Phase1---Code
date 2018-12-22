//#pragma once
#include "CopyAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>

 // CFigure *copyFigPtr = NULL;

//  CFigure *FigPtr = NULL;
  
//   GfxInfo info;

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
	//std::cout<<"l";
}
 //Execute the action
void CopyAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Check for selected figure
	pManager->SetSelectedFig(pManager->GetFigure(P1.x,P1.y)); //select fig

	pManager->setClip(NULL); //null the ptr
	pManager->setClip(pManager->GetSelectedFig()); //set clip 
	CFigure *h =  pManager->getClip(); //store clip to ptr
	
	if(h){
		
		pManager->setIsCopy(true); // copy is true
		pManager->setInfo( h->getInfo() ); //store info
		
	}else{
			Output* pOut = pManager->GetOutput();

 	pOut->PrintMessage("no figure is selected");
	}
	
	

 }

