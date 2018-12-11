#include"BlueColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

BlueColorAction::BlueColorAction(ApplicationManager * pApp) :Action(pApp)
{
}

void BlueColorAction::ReadActionParameters()
{
}


void BlueColorAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	color mycolor = pOut->getCrntFillColor();

	if (pManager->GetStateNum() == 0)
	{
		pManager->GetSelectedFig()->ChngDrawClr(BLUE);

	}
	else
	{
		pManager->GetSelectedFig()->ChngFillClr(BLUE);
	}


	pOut->CreateDrawToolBar();
}
