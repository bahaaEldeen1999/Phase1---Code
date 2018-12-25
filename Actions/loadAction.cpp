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
	file_name = pIn->GetSrting(pOut); // Getting the file that will be loaded from . 
	pOut->PrintMessage("You will load from  : "+ file_name); // Display the name for the user
}

void  loadAct::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	ifstream Input;
	Input.open(file_name+".txt");
	if (Input.fail()) { // incase the user enter an invlaid file or an unexisting file the program will give another one  chance for user to enter the name 
	pOut->PrintMessage("please enter an existing file name in order the load operation  occurs correclty or save first");
	PlaySound (TEXT("files.wav"),NULL, SND_SYNC);
	pOut->PrintMessage("Load graphs: Please enter the file name you want to save from");
	file_name = pIn->GetSrting(pOut);
	Input.open(file_name+".txt");
	}
	pOut->ClearDrawArea();
	pManager ->Loadme();
	//pManager->load (Input);
	load (Input);
	Input.close();
	pManager->UpdateInterface();
}





void loadAct :: load (ifstream &Input) {
	string fclr , dclry;
	Input>>dclry>>fclr;
	if (dclry == "BLACK") {
		UI.DrawColor = BLACK;
	}
	else if (dclry == "RED") {
		UI.DrawColor = RED;
	}
	else if (dclry == "BLUE") {
		UI.DrawColor = BLUE;
	}
	else if  (dclry == "GREEN") {
		UI.DrawColor = GREEN;
	}
	else if (dclry == "WHITE") {
	UI.DrawColor = WHITE;
	}
	if (fclr == "BLACK") {
		UI.FillColor = BLACK;
	}
	else if (fclr == "RED") {
		UI.FillColor = RED;
	}
	else if (fclr == "BLUE") {
		UI.FillColor = BLUE;
	}
	else if  (fclr == "GREEN") {
		UI.FillColor = GREEN;
	}
	else if (fclr == "WHITE") {
	UI.FillColor = WHITE;
	}
	int x;
	string y;
	Input>>x;
	for (int i = 0 ; i<x; i++) {
		Input>>y;
	if (y=="Elipse"){
		Point p;
		p.x = 100; 
		p.y = 100;
		GfxInfo GP;
		CEllipse *C = new CEllipse (p,GP);
		C->load (Input);
		pManager->AddFigure (C);
	}
		else if (y=="Rectangle"){
		Point p,y ;
		y.x = 200;
		y.y = 150; 
		p.x = 609; 
		p.y = 578;
		GfxInfo GP;
		CRectangle *C = new CRectangle (p,y,GP);
		C->load (Input);
		pManager->AddFigure (C);
	}
else if (y=="Line"){
		Point p,y ;
		y.x = 567;
		y.y = 126; 
		p.x = 567; 
		p.y = 546;
		GfxInfo GP;
		CLine *C = new CLine (p,y,GP);
		C->load (Input);
		pManager->AddFigure (C);
	}
else if (y=="Rhombus"){
		Point p,y ;
		y.x = 123;
		y.y = 415; 
		p.x = 514; 
		p.y = 606;
		GfxInfo GP;
		CRhombus *C = new CRhombus (p,GP);
		C->load (Input);
		pManager->AddFigure (C);
}
else if (y== "Triangle") {
		Point p,y ,m;
		m.x = 108; 
		m.y = 199; 
		y.x = 178;
		y.y = 195; 
		p.x = 205; 
		p.y = 423;
		GfxInfo GP;
		CTriangle *C = new CTriangle (p,y,m,GP);
		C->load (Input);
	pManager->AddFigure (C);
}
	//Here call laod function from CFigures 
	// then call the appMGr to make add list figures; 
	
//	pManager->SavebyType(OutFile,x);
	//Input.close();
	//pManager->UpdateInterface();

}

}