
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
	int slope= (fPoint.y-sPoint.y)/(fPoint.x-sPoint.x);
	if ((fPoint.y-y)/(fPoint.x-x)==slope) return true;
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
}