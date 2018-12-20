#include "CRhombus.h"
#include"../ApplicationManager.h"
CRhombus::CRhombus(Point p1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = p1;
	figtype=4;

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

void CRhombus::Draw(Output * pOut) 
{
	pOut->Draw_poly(center, FigGfxInfo, Selected);
}

bool CRhombus:: SelectArea(int x,int y)
{
	double f=abs(x-(double)center.x)/50+abs(y-(double)center.y)/100;
	if (f<=1) return true;
	return false;

}
void CRhombus :: save (ofstream &OutFile, int n) {
	ID = n;
	OutFile<<"Rhombus "<<"       ";
	OutFile<<ID<<"        "<<center.x<<"      "<<center.y<<"     ";
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


void CRhombus :: load (ifstream &Infile) {
Infile>>ID; 
Infile>>center.x;
Infile>>center.y;
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
fil =y;
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


void CRhombus:: PrintInfo(Output* pOut)
{
	string p="Rhombus ID:  "+to_string(4000+ID)+" Center: ";

	p+=to_string(center.x)+' '+to_string(center.y);
	pOut->PrintMessage(p);


}
