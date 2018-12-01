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
	virtual void Draw(Output* pOut) const;
    virtual bool SelectArea(int x,int y);
=======
	virtual void Draw(Output* pOut) ;

>>>>>>> 37869b2725815d32942bad04df1d8c4413e1e3ee
};

#endif