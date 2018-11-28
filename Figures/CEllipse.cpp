#include "CEllipse.h"

CEllipse::CEllipse(Point P1, GfxInfo FigGfxInfo):CFigure(FigGfxInfo)
{
	center = P1;
}

void CEllipse::Draw(Output * pOut) const
{
	pOut->Drawelipse(center, FigGfxInfo, Selected);
}
