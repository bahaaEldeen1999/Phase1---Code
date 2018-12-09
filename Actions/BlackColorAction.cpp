#include"BlackColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

BlackColorAction::BlackColorAction(ApplicationManager * pApp) :Action(pApp)
{
}

void BlackColorAction::ReadActionParameters()
{
}


void BlackColorAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	color mycolor = pOut->getCrntFillColor();

	if (pManager->GetStateNum() == 0)
	{
		pManager->GetSelectedFig()->ChngDrawClr(BLACK);

	}
	else
	{
		pManager->GetSelectedFig()->ChngFillClr(BLACK);
	}


	pOut->CreateDrawToolBar();
}
