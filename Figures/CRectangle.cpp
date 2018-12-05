#include "CRectangle.h"
#include"../ApplicationManager.h"
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
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
}