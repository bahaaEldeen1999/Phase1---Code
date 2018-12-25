#include "SwitchToDraw.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "loadAction.h"

SwitchToDraw::SwitchToDraw(ApplicationManager * pApp):Action(pApp)
{
	// When clicking on switch to draw mode all figures that was drawn in the draw mode will be implicltly loaded from stm.txt file 
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->Loadme();
	ifstream Input; 
	Input.open ("stm.txt");
	loadAct* pAct = NULL;
	pAct = new loadAct(pManager);
	pAct->load(Input);
	//pManager->load (Input);
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