#include "loadAction.h"
#include"../ApplicationManager.h"
#include <fstream>
#include "../Figures/CEllipse.h"
#include "../Figures/CRhombus.h"
#include "../Figures/CLine.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"
#include "../DEFS.h"
#include <iostream>
using namespace std; 
loadAct::loadAct(ApplicationManager * pApp):Action(pApp)
{
}

void  loadAct::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load graphs: Please enter the file name you want to save from");
	file_name = pIn->GetSrting(pOut);
	pOut->PrintMessage("You will load from  : "+ file_name);
}

void  loadAct::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	ifstream Input;
	Input.open(file_name+".txt");
	if (Input.fail()) {
	pOut->PrintMessage("please enter an existing file name in order the load operation  occurs correclty or save first");
	pOut->PrintMessage("Load graphs: Please enter the file name you want to save from");
	file_name = pIn->GetSrting(pOut);
	Input.open(file_name+".txt");
	}
	pOut->ClearDrawArea();
	pManager ->Loadme();
	pManager->load (Input);
	//Here call laod function from CFigures 
	// then call the appMGr to make add list figures; 
	
//	pManager->SavebyType(OutFile,x);
	//Input.close();
	//pManager->UpdateInterface();


	Input.close();
	pManager->UpdateInterface();
}