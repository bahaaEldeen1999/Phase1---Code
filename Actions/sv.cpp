#include "sv.h"
#include"../ApplicationManager.h"
#include <fstream>
// Save by type class 
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
    pOut->PrintMessage("Please select a type from statues bar");
	goto here; // enforce the user to select a valid shape 
	}
	pOut->PrintMessage("Save graphs: Please enter the file name");
	file_name = pIn->GetSrting(pOut); // Reading the name of the file 
	pOut->PrintMessage("Your file name is : "+ file_name);
}

void  Svt  ::Execute()
{  Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	ofstream OutFile;
	OutFile.open(file_name+".txt");
	color y = pOut->getCrntDrawColor();
	color x1 = pOut->getCrntFillColor();
	if (y== BLACK){
		OutFile<<"BLACK"<<"         ";
	}
	else if (y== GREEN) {
		OutFile<<"GREEN"<<"         ";
	}
	else if (y== BLUE) {
		OutFile<<"BLUE"<<"         ";
	}
	else if (y== RED) {
		OutFile<<"RED"<<"         ";
	}
	else if (y== WHITE) {
		OutFile<<"WHITE"<<"         ";
	}
	if (x1== BLACK){
		OutFile<<"BLACK"<<"         ";
	}
	else if (x1== GREEN) {
		OutFile<<"GREEN"<<"         ";
	}
	else if (x1== BLUE) {
		OutFile<<"BLUE"<<"         ";
	}
	else if (x1== RED) {
		OutFile<<"RED"<<"         ";
	}
	else if (x1== WHITE) {
		OutFile<<"WHITE"<<"         ";
	}
	OutFile<<endl; 
	pManager->SavebyType(OutFile,x); // calling save by type action from the application manager.  
	OutFile.close();


}
