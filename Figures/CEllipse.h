#pragma once
#include "CFigure.h"

class CEllipse : public  CFigure
{
private:
	Point center;
public:
	CEllipse(Point, GfxInfo FigGfxInfo);

	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);
	 virtual void figinfo();
	 Point getCenter(){
	 return center;
	 }
//	virtual void Draw(Output* pOut) ;

};