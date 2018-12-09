#include"WhiteColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

WhiteColorAction::WhiteColorAction(ApplicationManager * pApp) :Action(pApp)
{
}

void WhiteColorAction::ReadActionParameters()
{
}


void WhiteColorAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	color mycolor = pOut->getCrntFillColor();

	if (pManager->GetStateNum() == 0)
	{
		pManager->GetSelectedFig()->ChngDrawClr(WHITE);

	}
	else
	{
		pManager->GetSelectedFig()->ChngFillClr(WHITE);
	}


	pOut->CreateDrawToolBar();
}
