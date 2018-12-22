#include"PushBackward.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PushBackward::PushBackward(ApplicationManager * pApp):Action(pApp)
{
}

void PushBackward::ReadActionParameters()
{
}

void PushBackward::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->GetSelectedFig() == 0)
	{
		pOut->PrintMessage("Please Select A figure to be pushed Backward");
	}
	else
	{
		pManager->RearrangeBackward();
	}
}
