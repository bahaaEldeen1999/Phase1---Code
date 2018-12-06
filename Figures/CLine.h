#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"
#include"../ApplicationManager.h"
class CLine : public CFigure
{
private:
	Point fPoint;
	Point sPoint;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);

	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);
	 void save (ofstream &OutFile , int );
	void load (ifstream &Infile ); 
	void PrintInfo(Output* pOut);
};
#endif
