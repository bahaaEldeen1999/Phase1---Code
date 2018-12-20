#include "SwitchToDraw.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


SwitchToDraw::SwitchToDraw(ApplicationManager * pApp):Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->Loadme();
	ifstream Input; 
	Input.open ("stm.txt");
	pManager->load (Input);
	Input.close();
	pManager->UpdateInterface();
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