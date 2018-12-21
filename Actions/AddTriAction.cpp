#include "AddTriAction.h"
#include"../ApplicationManager.h"
#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
#include"..\Figures\CTriangle.h"


AddTriAction::AddTriAction(ApplicationManager * pApp):Action(pApp)
{
}

void AddTriAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first Vertix");		//read frist point

	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second Vertix");		//read second point

	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third Vertix");		//read third point

	pIn->GetPointClicked(P3.x, P3.y);

	if (UI.CurrentState == 0)
		TriGfxInfo.isFilled = false;	//default is not filled
	else if (UI.CurrentState == 1)
	{
		TriGfxInfo.isFilled = true;
	}

	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddTriAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	CTriangle *T = new CTriangle(P1, P2, P3, TriGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(T);
}

