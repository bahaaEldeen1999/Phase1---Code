#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point fPoint;
	Point sPoint;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
<<<<<<< HEAD
	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);
=======

	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);

//	virtual void Draw(Output* pOut) ;

>>>>>>> db46d93509c2ce146a4e9203fd87cfe2f0cc7b22
};
#endif
