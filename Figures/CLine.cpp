

#include "CLine.h"

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

