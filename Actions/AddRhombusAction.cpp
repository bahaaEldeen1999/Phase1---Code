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

	pIn->GetPointClicked(P1.x, P1.y);			//read point from user

	if (UI.CurrentState == 0)
		RhombusGfxInfo.isFilled = false;	//default is not filled
	else if (UI.CurrentState == 1)
	{
		RhombusGfxInfo.isFilled = true;
	}

	RhombusGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhombusGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddRhombusAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rhombus with the parameters read from the user
	CRhombus* Rh = new CRhombus(P1, RhombusGfxInfo);

	//Add the rhombus to the list of figures
	pManager->AddFigure(Rh);
}

