//#pragma once
#include "CutAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
 
CutAction::CutAction(ApplicationManager * pApp):CopyAction(pApp)
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
	CFigure* C=pManager->GetFigure(P1.x,P1.y);
	//Check for selected figure
	pManager->SetSelectedFig(C); //select fig
	
	
	pManager->setClip(NULL); //set clip to null
	pManager->setClip(pManager->GetSelectedFig()); //set select to clip
	CFigure *h =  pManager->getClip(); // store the clip to ptr
	if(h){
		
		pManager->setInfo( h->getInfo() ); //set info
		h->ChngFillClr(GRAY); // make fill color gray 
		pManager->setIsCopy(false); //set copy to false
	}
	

 }

