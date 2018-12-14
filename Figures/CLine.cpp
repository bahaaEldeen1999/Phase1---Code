
#include "CLine.h"
#include"../ApplicationManager.h"
CLine::CLine(Point p1 , Point p2 , GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	fPoint = p1;
	sPoint = p2;
}

void CLine::Draw(Output * pOut) 
{
	pOut->DrawLine(fPoint, sPoint, FigGfxInfo, Selected);
}

bool CLine:: SelectArea(int x,int y)
{
	int maxx ,minx,miny,maxy;

	if(fPoint.x>sPoint.x) 
	{maxx=fPoint.x;minx =sPoint.x;}
	else {maxx=sPoint.x;minx=fPoint.x;}

	if(fPoint.y>sPoint.y) 
	{maxy=fPoint.y;miny =sPoint.y;}
	else {maxy=sPoint.y;miny=fPoint.y;}

	float slope= ((float)fPoint.y-sPoint.y)/(fPoint.x-sPoint.x);
	float test=((float)fPoint.y-y)/(fPoint.x-x);
	bool A=slope+0.05>=test&&slope-0.05<test;
	if (A&&x>minx&&x<maxx&&y>miny&&y<maxy) return true;
	return false;

}
void CLine :: save (ofstream &OutFile, int n ) {
	ID =n;
	OutFile<<"Line "<<"       ";
	OutFile<<ID<<"        "<<fPoint.x<<"      "<<fPoint.y<<"     "<<sPoint.x<<"      "<<sPoint.y<<"     ";
	
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

void CLine:: load (ifstream &Infile) {
Infile>>ID; 
Infile>>fPoint.x;
Infile>>fPoint.y;
Infile>>sPoint.x;
Infile>>sPoint.y;
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
FigGfxInfo.isFilled = false;
}

void CLine:: PrintInfo(Output* pOut)
{
	string p="Line ID:   Point 1: ";
	p+=to_string(fPoint.x)+' '+to_string(fPoint.y)+"Point 2:"+to_string(sPoint.x)+' '+to_string(sPoint.y) ;
	pOut->PrintMessage(p);


}