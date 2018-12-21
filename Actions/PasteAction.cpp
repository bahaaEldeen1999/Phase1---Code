#include "PasteAction.h"
 #include "..\ApplicationManager.h"
 #include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
 #include "../Figures/CFigure.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CLine.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CRhombus.h"
#include "../Figures/CEllipse.h"
#include <cmath>
 PasteAction::PasteAction(ApplicationManager * pApp) :Action(pApp)
{

}
 void PasteAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
 	pOut->PrintMessage("click a point to paste the figure");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}
 //Execute the action
void PasteAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	//store the clip 
	CFigure *f = pManager->getClip();
	
	if( f){
		pManager->GetSelectedFig()->SetSelected(false); //unselect fig
// get the info
	GfxInfo info =pManager->getInfo();
	//points help us to draw figs
	Point p1;
	Point p2;
	Point p3;
	//dynamic cast for figure checking
	CRectangle *k = dynamic_cast<CRectangle*>(f);
	CLine *l = dynamic_cast<CLine*>(f);
	CRhombus *m = dynamic_cast<CRhombus*>(f);
	CEllipse *n = dynamic_cast<CEllipse*>(f);
	CTriangle *o = dynamic_cast<CTriangle*>(f);

	if( k != NULL ){

		p1.x = P1.x  ;
		p1.y = P1.y ;
		p2.x =P1.x + abs(k->getCorner1().x - k->getCorner2().x)   ;
		p2.y = P1.y + abs(k->getCorner2().y -  k->getCorner1().y) ;
		GfxInfo t = k->getInfo();
	
		CRectangle *r = new CRectangle(p1,p2,info);
		
		pManager->AddFigure(r);
		

	}else if( l != NULL){

		p1.x = P1.x;
		p1.y = P1.y;
		p2.y = p1.y - l->getPoint1().y + l->getPoint2().y;
		p2.x = p1.x - l->getPoint1().x + l->getPoint2().x;
		std::cout<<p1.x <<" "<<p1.y<<std::endl << p2.x <<" "<<p2.y<< std::endl;
		GfxInfo t = l->getInfo();
		CLine *r = new CLine(p1,p2,info);
		
		pManager->AddFigure(r);

	}else if(m  != NULL){
		p1.x = P1.x;
		p1.y = P1.y;
		GfxInfo t = m->getInfo();
		CRhombus *r = new CRhombus(p1,info);
		

		pManager->AddFigure(r);

	}else if( n != NULL){
		p1.x = P1.x;
		p1.y = P1.y;
		GfxInfo t = n->getInfo();
		CEllipse *r = new CEllipse(p1,info);
		
		pManager->AddFigure(r);


	}else if(o  != NULL){

	p1.x = P1.x;
	p1.y = P1.y;
	p2.x = o->getCorner2().x - o->getCorner1().x + P1.x ;
	p2.y = o->getCorner2().y - o->getCorner1().y + P1.y ;
	p3.x = o->getCorner3().x -  o->getCorner1().x + P1.x ;
	p3.y = o->getCorner3().y -  o->getCorner1().y + P1.y;
	std::cout<<p1.x <<" "<<p1.y<<std::endl << p2.x <<" "<<p2.y<< std::endl<<p3.x << " " <<p3.y<<std::endl;
	GfxInfo t = o->getInfo();
		CTriangle *r = new CTriangle(p1,p2,p3,info);
		
		pManager->AddFigure(r);
	}


	//if the fig is cut then delete the fig
	if(!pManager->getIsCopy()){
		pManager->RearrangeDeleted();
		//set too true so doesnt delete each one
		pManager->setIsCopy(true);
	}
	
	}
	





 }
PasteAction::~PasteAction(){

}
