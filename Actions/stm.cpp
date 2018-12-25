#include "stm.h"
#include"../ApplicationManager.h"
#include <fstream> 
// Switch to play mode action 
stm  :: stm (ApplicationManager * pApp):Action(pApp)
{
}

void  stm  ::ReadActionParameters()
{
}

void  stm  ::Execute()
{
ReadActionParameters();
Output* pOut = pManager->GetOutput();
Input* pIn = pManager->GetInput();
pOut->CreatePlayToolBar();
ofstream OutFile;
OutFile.open("stm.txt"); // you should load from switch to draw mode from this file name; 
color y = pOut->getCrntDrawColor();
color x = pOut->getCrntFillColor();
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
	if (x== BLACK){
		OutFile<<"BLACK"<<"         ";
	}
	else if (x== GREEN) {
		OutFile<<"GREEN"<<"         ";
	}
	else if (x== BLUE) {
		OutFile<<"BLUE"<<"         ";
	}
	else if (x== RED) {
		OutFile<<"RED"<<"         ";
	}
	else if (x== WHITE) {
		OutFile<<"WHITE"<<"         ";
	}
	OutFile<<endl; 
pManager->saveall(OutFile);
OutFile.close();
}
