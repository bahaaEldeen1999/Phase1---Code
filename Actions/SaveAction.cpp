#include "SaveAction.h"
#include"../ApplicationManager.h"
#include <fstream>
SaveAction :: SaveAction (ApplicationManager * pApp):Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Save graphs: Please enter the file name");
	file_name = pIn->GetSrting(pOut);
	pOut->PrintMessage("Your file name is : "+ file_name);
}

void SaveAction::Execute()
{
	ReadActionParameters();
	ofstream OutFile;
	OutFile.open(file_name+".txt");
	pManager->saveall(OutFile);
	OutFile.close();


}
