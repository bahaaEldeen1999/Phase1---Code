#pragma once
#include "CFigure.h"
#include"../ApplicationManager.h"
class CEllipse : public  CFigure
{
private:
	Point center;
public:
	CEllipse(Point, GfxInfo FigGfxInfo);

	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);
	void save (ofstream &OutFile , int );
	void load (ifstream &Infile ); 
	void PrintInfo(Output* pOut);
	 Point getCenter(){
	 return center;
	 }
};
