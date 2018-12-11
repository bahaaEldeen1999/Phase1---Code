#include"RedColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RedColorAction::RedColorAction(ApplicationManager * pApp) :Action(pApp)
{
}

void RedColorAction::ReadActionParameters()
{
}


void RedColorAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	color mycolor = pOut->getCrntFillColor();

	if (pManager->GetStateNum() == 0)
	{
		pManager->GetSelectedFig()->ChngDrawClr(RED);

	}
	else
	{
		pManager->GetSelectedFig()->ChngFillClr(RED);
	}


	pOut->CreateDrawToolBar();
}
