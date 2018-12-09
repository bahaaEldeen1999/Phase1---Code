#pragma once
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
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at the Center");

	pIn->GetPointClicked(P1.x, P1.y);

	EllipseGfxInfo.isFilled = false;

	EllipseGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllipseGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddEllipseAction::Execute()
{
	ReadActionParameters();

	CEllipse* E = new CEllipse(P1, EllipseGfxInfo);

	pManager->AddFigure(E);

}
