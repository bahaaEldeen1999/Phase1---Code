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
<<<<<<< HEAD
	
}
 void PasteAction::ReadActionParameters() 
{	
=======

}
 void PasteAction::ReadActionParameters()
{
>>>>>>> bahaa_branch1
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
 	pOut->PrintMessage("click a point to paste the figure");
<<<<<<< HEAD
	
=======

>>>>>>> bahaa_branch1
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}
 //Execute the action
<<<<<<< HEAD
void PasteAction::Execute() 
=======
void PasteAction::Execute()
>>>>>>> bahaa_branch1
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
//	std::cout<<"k";

<<<<<<< HEAD
	CFigure *f = copyFigPtr;
	CFigure *g = cutFigPtr;
	
	
=======
	CFigure *f = FigPtr;
	//CFigure *g = cutFigPtr;


>>>>>>> bahaa_branch1
	//f->ChngFillClr(BLUE);
	Point p1;
	Point p2;
	Point p3;
<<<<<<< HEAD
	GfxInfo t;
	t.DrawClr = BLACK;
	t.FillClr = LIGHTGOLDENROD;
	
	t.isFilled = false;
	if(f){
=======
>>>>>>> bahaa_branch1
	CRectangle *k = dynamic_cast<CRectangle*>(f);
	CLine *l = dynamic_cast<CLine*>(f);
	CRhombus *m = dynamic_cast<CRhombus*>(f);
	CEllipse *n = dynamic_cast<CEllipse*>(f);
	CTriangle *o = dynamic_cast<CTriangle*>(f);
	//std::cout<<P1.x<<" ";
	if( k != NULL ){
<<<<<<< HEAD
	
=======

>>>>>>> bahaa_branch1
		p1.x = P1.x  ;
		p1.y = P1.y ;
		p2.x =P1.x + abs(k->getCorner1().x - k->getCorner2().x)   ;
		p2.y = P1.y + abs(k->getCorner2().y -  k->getCorner1().y) ;
<<<<<<< HEAD
=======
		GfxInfo t = k->getInfo();
>>>>>>> bahaa_branch1
		//std::cout<<P1.x<<" ";
		CRectangle *r = new CRectangle(p1,p2,t);
		//std::cout<<" k "<<" ";
		pManager->AddFigure(r);
		//std::cout<<"k";
<<<<<<< HEAD
	
	}else if( l != NULL){
	
=======

	}else if( l != NULL){

>>>>>>> bahaa_branch1
		p1.x = P1.x;
		p1.y = P1.y;
		p2.y = p1.y - l->getPoint1().y + l->getPoint2().y;
		p2.x = p1.x - l->getPoint1().x + l->getPoint2().x;
		std::cout<<p1.x <<" "<<p1.y<<std::endl << p2.x <<" "<<p2.y<< std::endl;
<<<<<<< HEAD
		CLine *r = new CLine(p1,p2,t);
		//r->Draw(pOut);
		pManager->AddFigure(r);
	
	}else if(m  != NULL){
		p1.x = P1.x;
		p1.y = P1.y;
		CRhombus *r = new CRhombus(p1,t);
		//r->Draw(pOut);
		pManager->AddFigure(r);
	
	}else if( n != NULL){
		p1.x = P1.x;
		p1.y = P1.y;
		CEllipse *r = new CEllipse(p1,t);
		//r->Draw(pOut);
		pManager->AddFigure(r);
	
	
	}else if(o  != NULL){
	
=======
		GfxInfo t = l->getInfo();
		CLine *r = new CLine(p1,p2,t);
		//r->Draw(pOut);
		pManager->AddFigure(r);

	}else if(m  != NULL){
		p1.x = P1.x;
		p1.y = P1.y;
		GfxInfo t = m->getInfo();
		CRhombus *r = new CRhombus(p1,t);
		//r->Draw(pOut);

		pManager->AddFigure(r);

	}else if( n != NULL){
		p1.x = P1.x;
		p1.y = P1.y;
		GfxInfo t = n->getInfo();
		CEllipse *r = new CEllipse(p1,t);
		//r->Draw(pOut);
		pManager->AddFigure(r);


	}else if(o  != NULL){

>>>>>>> bahaa_branch1
	p1.x = P1.x;
	p1.y = P1.y;
	p2.x = o->getCorner2().x - o->getCorner1().x + P1.x ;
	p2.y = o->getCorner2().y - o->getCorner1().y + P1.y ;
	p3.x = o->getCorner3().x -  o->getCorner1().x + P1.x ;
	p3.y = o->getCorner3().y -  o->getCorner1().y + P1.y;
	std::cout<<p1.x <<" "<<p1.y<<std::endl << p2.x <<" "<<p2.y<< std::endl<<p3.x << " " <<p3.y<<std::endl;
<<<<<<< HEAD
=======
	GfxInfo t = o->getInfo();
>>>>>>> bahaa_branch1
		CTriangle *r = new CTriangle(p1,p2,p3,t);
		//r->Draw(pOut);
		pManager->AddFigure(r);
	}
<<<<<<< HEAD
 	
	}else if(g){
	
	
	CRectangle *k = dynamic_cast<CRectangle*>(g);
	CLine *l = dynamic_cast<CLine*>(g);
	CRhombus *m = dynamic_cast<CRhombus*>(g);
	CEllipse *n = dynamic_cast<CEllipse*>(g);
	CTriangle *o = dynamic_cast<CTriangle*>(g);
	//std::cout<<P1.x<<" ";
	if( k != NULL ){
	
=======
	i++;

	/*
	if(isCopy == true){


	} else if( isCopy == false ){
		//std::cout<<" k "<<" ";
	CRectangle *k = dynamic_cast<CRectangle*>(f);
	CLine *l = dynamic_cast<CLine*>(f);
	CRhombus *m = dynamic_cast<CRhombus*>(f);
	CEllipse *n = dynamic_cast<CEllipse*>(f);
	CTriangle *o = dynamic_cast<CTriangle*>(f);

		if( k != NULL ){

>>>>>>> bahaa_branch1
		p1.x = P1.x  ;
		p1.y = P1.y ;
		p2.x =P1.x + abs(k->getCorner1().x - k->getCorner2().x)   ;
		p2.y = P1.y + abs(k->getCorner2().y -  k->getCorner1().y) ;
<<<<<<< HEAD
		//std::cout<<P1.x<<" ";
=======
		GfxInfo t = k->getInfo();

		std::cout<<P1.x<<" ";
>>>>>>> bahaa_branch1
		CRectangle *r = new CRectangle(p1,p2,t);
		//std::cout<<" k "<<" ";
		pManager->AddFigure(r);
		//std::cout<<"k";
<<<<<<< HEAD
	
	}else if( l != NULL){
	
=======

	}else if( l != NULL){

>>>>>>> bahaa_branch1
		p1.x = P1.x;
		p1.y = P1.y;
		p2.y = p1.y - l->getPoint1().y + l->getPoint2().y;
		p2.x = p1.x - l->getPoint1().x + l->getPoint2().x;
		std::cout<<p1.x <<" "<<p1.y<<std::endl << p2.x <<" "<<p2.y<< std::endl;
<<<<<<< HEAD
		CLine *r = new CLine(p1,p2,t);
		//r->Draw(pOut);
		pManager->AddFigure(r);
	
	}else if(m  != NULL){
		p1.x = P1.x;
		p1.y = P1.y;
		CRhombus *r = new CRhombus(p1,t);
		//r->Draw(pOut);
		pManager->AddFigure(r);
	
	}else if( n != NULL){
		p1.x = P1.x;
		p1.y = P1.y;
		CEllipse *r = new CEllipse(p1,t);
		//r->Draw(pOut);
		pManager->AddFigure(r);
	
	
	}else if(o  != NULL){
	
=======
		GfxInfo t = l->getInfo();
		CLine *r = new CLine(p1,p2,t);
		//r->Draw(pOut);
		pManager->AddFigure(r);

	}else if(m  != NULL){
		p1.x = P1.x;
		p1.y = P1.y;
		GfxInfo t = m->getInfo();
		CRhombus *r = new CRhombus(p1,t);
		//r->Draw(pOut);

		pManager->AddFigure(r);

	}else if( n != NULL){
		p1.x = P1.x;
		p1.y = P1.y;
		GfxInfo t = n->getInfo();
		CEllipse *r = new CEllipse(p1,t);
		//r->Draw(pOut);
		pManager->AddFigure(r);


	}else if(o  != NULL){

>>>>>>> bahaa_branch1
	p1.x = P1.x;
	p1.y = P1.y;
	p2.x = o->getCorner2().x - o->getCorner1().x + P1.x ;
	p2.y = o->getCorner2().y - o->getCorner1().y + P1.y ;
	p3.x = o->getCorner3().x -  o->getCorner1().x + P1.x ;
	p3.y = o->getCorner3().y -  o->getCorner1().y + P1.y;
	std::cout<<p1.x <<" "<<p1.y<<std::endl << p2.x <<" "<<p2.y<< std::endl<<p3.x << " " <<p3.y<<std::endl;
<<<<<<< HEAD
		CTriangle *r = new CTriangle(p1,p2,p3,t);
		//r->Draw(pOut);
		pManager->AddFigure(r);
	}

	pManager->RearrangeDeleted();
 	
	
	
	
	}
	
	
 	
 	
 }
PasteAction::~PasteAction(){
 //delete c;
}
=======
	GfxInfo t = o->getInfo();
		CTriangle *r = new CTriangle(p1,p2,p3,t);
		//r->Draw(pOut);
		pManager->AddFigure(r);
	}else{
		std::cout<<"g ";
	}



	pManager->RearrangeDeleted();




	}
	*/
	if(!isCopy){
		pManager->RearrangeDeleted();
    isCopy = true;
	}

	//copyFigPtr = NULL;
	// cutFigPtr = NULL;




 }
PasteAction::~PasteAction(){
 //delete c;
	//FigPtr = NULL;
}
>>>>>>> bahaa_branch1
