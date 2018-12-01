#pragma once
#include "CFigure.h"

class CEllipse : public  CFigure
{
private:
	Point center;
public:
	CEllipse(Point, GfxInfo FigGfxInfo);
<<<<<<< HEAD
	virtual void Draw(Output* pOut) const;
	 virtual bool SelectArea(int x,int y);
	 virtual void figinfo();
=======
	virtual void Draw(Output* pOut) ;
>>>>>>> 37869b2725815d32942bad04df1d8c4413e1e3ee
};