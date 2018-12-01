#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	corner1 = P1;
	corner2 = P2;
	corner3 = P3;
}

void CTriangle::Draw(Output * pOut) const
{
	pOut->DRAWTri(corner1, corner2, corner3, FigGfxInfo, Selected);
}
bool CTriangle:: SelectArea(int x,int y)
{
	if (x>=corner1.x&&x<=corner2.x&&y>=corner1.y&&y<=corner2.y) return true;
	return false;

}