#pragma once
#include "CFigure.h"

class CEllipse : public  CFigure
{
private:
	Point center;
public:
	CEllipse(Point, GfxInfo FigGfxInfo);
<<<<<<< HEAD
	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);
	 virtual void figinfo();
};
=======

	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);
	 virtual void figinfo();

//	virtual void Draw(Output* pOut) ;

};
>>>>>>> db46d93509c2ce146a4e9203fd87cfe2f0cc7b22
