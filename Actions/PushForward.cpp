#include"PushForward.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PushForward::PushForward(ApplicationManager * pApp):Action(pApp)
{
}

void PushForward::ReadActionParameters()
{
}

void PushForward::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->GetSelectedFig() == 0)
	{
		pOut->PrintMessage("Please Select A figure to be pushed forward");
	}
	else
	{
		pManager->RearrangeForward();
	}
}
