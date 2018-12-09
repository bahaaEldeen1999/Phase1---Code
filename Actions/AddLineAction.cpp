#pragma once
#include "..\ApplicationManager.h"
#include "..\Figures\CLine.h"
#include "..\GUI\Output.h"
#include "..\GUI\input.h"
#include "AddLineAction.h"

AddLineAction::AddLineAction(ApplicationManager * pApp):Action(pApp)
{
}

void AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New line: Click at first point");

	//Read 1st point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at second point");

	//Read 2nd point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	LineGfxInfo.isFilled = false;	//default is not filled
	//get drawing color from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}


void AddLineAction::Execute()
{
	ReadActionParameters();

	CLine* L = new CLine(P1, P2, LineGfxInfo);

	pManager->AddFigure(L);
}


