#pragma once
#include "SelectByColAction.h"
#include "..\ApplicationManager.h"
#include "..\DEFS.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include "SelectAction.h"
#include <iostream>


SelectByColAction::SelectByColAction(ApplicationManager *pApp):Action(pApp)
{
}
void SelectByColAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure by color");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();
}
void SelectByColAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Check for selected figure
	pManager->SetSelectedFig(pManager->GetFigure(P1.x,P1.y));
	color selectedColor = pManager->GetFigure(P1.x,P1.y)->getInfo().FillClr ;
	//pManager->GetFigures( 1300,650 );
	int count = pManager->getFigCount() ;
	CFigure *figures = pManager->getFigList();
	std::cout<< count <<std::endl;
	for( int i=0;i<count;i++ ){
		
		if( selectedColor.isSameColor(figures[i].getInfo().FillClr)  ){
			
			figures[i].SetSelected(true);
			//std::cout<<"y"<<std::endl;
		}
	
	}

}


SelectByColAction::~SelectByColAction(void)
{
}
