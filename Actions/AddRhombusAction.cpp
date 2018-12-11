#include "AddRhombusAction.h"
#include"..\ApplicationManager.h"
#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
#include"..\Figures\CRhombus.h"

AddRhombusAction::AddRhombusAction(ApplicationManager * pApp):Action(pApp)
{
}

void AddRhombusAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at the Center");

	pIn->GetPointClicked(P1.x, P1.y);

	RhombusGfxInfo.isFilled = false;

	RhombusGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhombusGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddRhombusAction::Execute()
{
	ReadActionParameters();
	
	CRhombus* Rh = new CRhombus(P1, RhombusGfxInfo);

	pManager->AddFigure(Rh);
}

