#include"GreenColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

GreenColorAction::GreenColorAction(ApplicationManager * pApp) :Action(pApp)
{
}

void GreenColorAction::ReadActionParameters()
{
}


void GreenColorAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	color mycolor = pOut->getCrntFillColor();

	if (pManager->GetStateNum() == 0)
	{
		pManager->GetSelectedFig()->ChngDrawClr(GREEN);

	}
	else
	{
		pManager->GetSelectedFig()->ChngFillClr(GREEN);
	}


	pOut->CreateDrawToolBar();
}
