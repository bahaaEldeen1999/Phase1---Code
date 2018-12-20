#include "playmodeshape.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
playmodeshape::playmodeshape(ApplicationManager * pApp):Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->Loadme();
	ifstream Input; 
	Input.open ("stm.txt");
	pManager->load (Input);
	Input.close();    //Load Figures 
	pManager->UpdateInterface();
	countcorrect=0;
	countincorrect=0;
	randomfigurecount=0;
	bool figureexist=pManager->GetFigCount()!=0;     //checks if there are figures to not go into an infinite loop
	while(randomfigurecount==0&&figureexist){
		randomfigtype=rand()%5;       //random number generator
	    randomfigurecount=pManager->FigureCounter(randomfigtype); //counting the figures  
	}
}

string playmodeshape:: FigType(int x)
{
	if (x==0) {return "Rectangle";}
	else if(x==1) {return "Line";}
    else if(x==2) {return "Ellipse";}
	else if(x==3) {return "Triangle";}
	else if(x==4) {return "Rhombus";}
}

void playmodeshape::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string c1=to_string(countcorrect);
	string c2=to_string(countincorrect);
	string type=FigType(randomfigtype);
	pOut->PrintMessage("Choose "+ type+" Correct Figures:"+c1+"        InCorrect Figures:"+c2);
	pIn->GetPointClicked(P1.x,P1.y);
	
}

void playmodeshape::Execute() 
{
	Output* pOut = pManager->GetOutput();
	
	do {
	if (pManager->GetFigCount()==0) break; //breaks if there are no figures
	//reading parameters and printing info of the game
	ReadActionParameters();
	if (P1.y>1250||P1.y<50) {break;}
	//choosing a figure
	pManager->SetSelectedFig(pManager->GetFigure(P1.x,P1.y));     //gets selected figures and puts it in selected pointer
	
	//Checks if the Figure is correct or not
	if (pManager->GetSelectedFig()!=NULL) {
	  if (pManager->GetSelectedFig()->getfigtype()==randomfigtype)        //gets figtype of the selected fig
	      { countcorrect++;pManager->RearrangeDeleted();pManager->UpdateInterface(); }
	  else {countincorrect++;pManager->RearrangeDeleted();pManager->UpdateInterface(); }
	  }
	else {countincorrect++;}
	}
	while (countcorrect!=randomfigurecount);

	//print info of the game 
	
	string c1=to_string(countcorrect);
	string c2=to_string(countincorrect);
	string c3;
	if (countcorrect!=0) { c3=to_string(countcorrect/(float)(countcorrect+countincorrect)*100);}
	else { c3="0";}
	pOut->ClearDrawArea();
	pOut->PrintMessage("Correct Figures:"+c1+"        InCorrect Figures:"+c2+"      Percentage: "+c3);
}