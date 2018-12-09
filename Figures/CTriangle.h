#include "CFigure.h"
#include"../ApplicationManager.h"
class CTriangle : public CFigure
{
private:
	Point corner1, corner2, corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	bool sameside(int p1x,int p1y,int p2x,int p2y,int p3x,int p3y,int ax,int ay);
	bool dotproduct(int a,int b);
	int crossproduct (int p1x,int p1y,int p2x,int p2y) ;
	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int ax,int ay);
	 float area(int x1, int y1, int x2, int y2, int x3, int y3) ;
	 void save (ofstream &OutFile , int );
	void load (ifstream &Infile ); 
	void PrintInfo(Output* pOut);
};

