#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point corner1, corner2, corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
<<<<<<< HEAD
	virtual void Draw(Output* pOut) const;
	 virtual bool SelectArea(int x,int y);
=======
	virtual void Draw(Output* pOut) ;
>>>>>>> 37869b2725815d32942bad04df1d8c4413e1e3ee
};