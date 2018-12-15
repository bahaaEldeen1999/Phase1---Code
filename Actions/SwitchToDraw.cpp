#include "SwitchToDraw.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


SwitchToDraw::SwitchToDraw(ApplicationManager * pApp):Action(pApp)
{
}

void SwitchToDraw::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
	//load figures here
}
void SwitchToDraw::ReadActionParameters()
{



}