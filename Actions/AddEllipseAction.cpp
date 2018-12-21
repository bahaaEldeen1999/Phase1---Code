#include "AddEllipseAction.h"
#include"..\ApplicationManager.h"
#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
#include"..\Figures\CEllipse.h"

AddEllipseAction::AddEllipseAction(ApplicationManager * pApp) :Action(pApp)
{
}

void AddEllipseAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at the Center");

	pIn->GetPointClicked(P1.x, P1.y);		//get point from user

	if (UI.CurrentState == 0)
		EllipseGfxInfo.isFilled = false;	//default is not filled
	else if (UI.CurrentState == 1)
	{
		EllipseGfxInfo.isFilled = true;
	}

	EllipseGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllipseGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddEllipseAction::Execute()
{
	ReadActionParameters();		//read actions from user

	CEllipse* E = new CEllipse(P1, EllipseGfxInfo);

	pManager->AddFigure(E);

}
