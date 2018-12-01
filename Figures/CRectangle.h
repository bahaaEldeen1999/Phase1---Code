#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo);
<<<<<<< HEAD
	virtual void Draw(Output* pOut) ;
    virtual bool SelectArea(int x,int y);
=======

	virtual void Draw(Output* pOut) ;
    virtual bool SelectArea(int x,int y);

	//virtual void Draw(Output* pOut) ;


>>>>>>> db46d93509c2ce146a4e9203fd87cfe2f0cc7b22
};

#endif
