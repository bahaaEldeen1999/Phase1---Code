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

	virtual void Draw(Output* pOut) ;
    virtual bool SelectArea(int x,int y);
	Point getCorner1();
	Point getCorner2();
	//virtual void Draw(Output* pOut) ;


};

#endif