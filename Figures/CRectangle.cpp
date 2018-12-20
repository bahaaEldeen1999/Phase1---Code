#include "CRectangle.h"
#include"../ApplicationManager.h"
#include <iostream>
using namespace std;
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	figtype=0;

	if (FigGfxInfo.FillClr == RED)					//figcolor (0:red,1:blue,2:green,3:white,4:black)
	{
		figcolor = 0;
	}
	else if (FigGfxInfo.FillClr == BLUE)
	{
		figcolor = 1;
	}
	else if (FigGfxInfo.FillClr == GREEN)
	{
		figcolor = 2;
	}
	else if (FigGfxInfo.FillClr == WHITE)
	{
		figcolor = 3;
	}
	else if (FigGfxInfo.FillClr == BLACK)
	{
		figcolor = 4;
	}
}
	

void CRectangle::Draw(Output* pOut) 
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle:: SelectArea(int x,int y)
{
	if (x>=Corner1.x&&x<=Corner2.x&&y>=Corner1.y&&y<=Corner2.y) return true;
	return false;

}
void CRectangle :: save (ofstream &OutFile, int n) {
	ID = n;
	OutFile<<"Rectangle "<<"       ";
	OutFile<<ID<<"        "<<Corner1.x<<"      "<<Corner1.y<<"     "<<Corner2.x<<"      "<<Corner2.y<<"     ";
	if (FigGfxInfo.isFilled){
		if (FigGfxInfo.FillClr == BLACK) {
		OutFile<<"BLACK"<<"   ";
		}
		else if (FigGfxInfo.FillClr == RED) {
		OutFile<<"RED"<<"   ";
	}
		else if (FigGfxInfo.FillClr == BLUE) {
		OutFile<<"BLUE"<<"   ";
	}
		else if (FigGfxInfo.FillClr == GREEN) {
		OutFile<<"GREEN"<<"   ";
	}
		else {
		OutFile<<"WHITE"<<"   ";
		}
}
	else {
	OutFile<<"NON_FILL"<<"      ";
	}
	if (FigGfxInfo.DrawClr == BLACK) {
		OutFile<<"BLACK"<<"   ";
		}
	else if (FigGfxInfo.DrawClr == RED) {
		OutFile<<"RED"<<"   ";
	}
	else if (FigGfxInfo.DrawClr == BLUE) {
		OutFile<<"BLUE"<<"   ";
	}
	else if (FigGfxInfo.DrawClr== GREEN) {
		OutFile<<"GREEN"<<"   ";
	}
		else {
		OutFile<<"WHITE"<<"   ";
		}
}

void CRectangle :: load (ifstream &Infile) {
Infile>>ID; 
Infile>>Corner1.x;
Infile>>Corner1.y;
Infile>>Corner2.x;
Infile>>Corner2.y;
string y;
string fil;
Infile>>y;
string  Clr;
Infile>>Clr;
if (Clr=="BLACK") {
	FigGfxInfo.DrawClr = BLACK;
}
else if (Clr=="RED") {
	FigGfxInfo.DrawClr = RED;
}
else if (Clr=="BLUE") {
	FigGfxInfo.DrawClr = BLUE;
}
else if (Clr=="GREEN") {
	FigGfxInfo.DrawClr = GREEN;
}
else   {
	FigGfxInfo.DrawClr = WHITE;
}
if (y== "NON_FILL") {
	FigGfxInfo.isFilled = false;
}
else {
	FigGfxInfo.isFilled = true;
	fil = y; 
	if (fil=="BLACK") {
		FigGfxInfo.FillClr= BLACK;
}
else if (fil=="RED") {
	FigGfxInfo.FillClr = RED;
}
else if (fil=="BLUE") {
	FigGfxInfo.FillClr = BLUE;
}
else if (fil=="GREEN") {
	FigGfxInfo.FillClr = GREEN;
}
else   {
	FigGfxInfo.FillClr = WHITE;
}
}
}
void CRectangle:: PrintInfo(Output* pOut)
{
	string p="Rectangle ID: " +to_string(2000+ID);
	p+="  Point 1: "+to_string(Corner1.x)+' '+to_string(Corner1.y)+' '+"Point 2:"+to_string(Corner2.x)+' '+to_string(Corner2.y) ;
	pOut->PrintMessage(p);


}