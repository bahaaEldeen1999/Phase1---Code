#pragma once
#include "CFigure.h"

class CEllipse : public  CFigure
{
private:
	Point center;
public:
	CEllipse(Point, GfxInfo FigGfxInfo);
	virtual void Draw(Output* pOut) const;
	 virtual bool SelectArea(int x,int y);
	 virtual void figinfo();
};