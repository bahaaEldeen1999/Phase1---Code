#include "CEllipse.h"
#include"../ApplicationManager.h"
CEllipse::CEllipse(Point P1, GfxInfo FigGfxInfo):CFigure(FigGfxInfo)
{
	center = P1;
}

void CEllipse::Draw(Output * pOut) 
{
	pOut->Drawelipse(center, FigGfxInfo, Selected);
}
bool CEllipse:: SelectArea(int x,int y)
{
	double f =(x-center.x)*(x-(double)center.x)/(100*100)+(y-center.y)*((double)y-center.y)/(50*50);
	if (f<=1) return true;
	return false;

}

void CEllipse:: PrintInfo(Output* pOut)
{
	string p="Ellipse ID:   Center: ";
	p+=to_string(center.x)+' '+to_string(center.y);
	pOut->PrintMessage(p);


}
void CEllipse :: save (ofstream &OutFile, int n) {
	ID = n;
	OutFile<<"Elipse"<<"       ";
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
void CEllipse:: load (ifstream &Infile) {
}
