#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point corner1, corner2, corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);

	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);
	 Point getCorner1(){
		 return corner1;
	 }
	 	 Point getCorner2(){
		 return corner2;
	 }
		 	 Point getCorner3(){
		 return corner3;
	 }
	//virtual void Draw(Output* pOut) ;

};