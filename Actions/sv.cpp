#include "sv.h"
#include"../ApplicationManager.h"
#include <fstream>
int x;
Svt  :: Svt  (ApplicationManager * pApp):Action(pApp)
{
}

void  Svt  ::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	here:
	pOut->PrintMessage("Save graphs: Please select the type which will be only saved");
    x=	pIn->GetUserAction();
	if (x>=0 && x<=4) {
	}
	else {
    pOut->PrintMessage("Please select a type from statuse bar");
	goto here;
	}
	pOut->PrintMessage("Save graphs: Please enter the file name");
	file_name = pIn->GetSrting(pOut);
	pOut->PrintMessage("Your file name is : "+ file_name);
}

void  Svt  ::Execute()
{
	ReadActionParameters();
	ofstream OutFile;
	OutFile.open(file_name+".txt");
	pManager->SavebyType(OutFile,x);
	OutFile.close();


}
