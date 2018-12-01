#include "CRhombus.h"

CRhombus::CRhombus(Point p1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = p1;
}

void CRhombus::Draw(Output * pOut) 
{
	pOut->Draw_poly(center, FigGfxInfo, Selected);
}
