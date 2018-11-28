

#include "CLine.h"

CLine::CLine(Point p1 , Point p2 , GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	fPoint = p1;
	sPoint = p2;
}

void CLine::Draw(Output * pOut) const
{
	pOut->DrawLine(fPoint, sPoint, FigGfxInfo, Selected);
}
