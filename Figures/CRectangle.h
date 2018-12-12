#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"
#include"../ApplicationManager.h"
class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo);

	virtual void Draw(Output* pOut) ;
    virtual bool SelectArea(int x,int y);
	void save (ofstream &OutFile , int );
	void load (ifstream &Infile ); 
	void PrintInfo(Output* pOut);
	Point getCorner1(){
	return Corner1;
	}
	Point getCorner2(){
		return Corner2;
	}
};

#endif
