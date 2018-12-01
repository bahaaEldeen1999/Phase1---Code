#include "CEllipse.h"

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
	if ((x*x)/(center.x*center.x)+(y*y)/(center.y*center.y)<=1) return true;
	return false;

}

void CEllipse:: figinfo()
{



}