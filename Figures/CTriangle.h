#include "CFigure.h"
#include"../ApplicationManager.h"
class CTriangle : public CFigure
{
private:
	Point corner1, corner2, corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);

	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);
	 float area(int x1, int y1, int x2, int y2, int x3, int y3) ;
	 void save (ofstream &OutFile , int );
	void load (ifstream &Infile ); 
};

