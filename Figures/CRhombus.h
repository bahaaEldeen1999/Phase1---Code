#include "CFigure.h"

class CRhombus :public CFigure
{
private:
	Point center;
public:
	CRhombus(Point, GfxInfo FigureGfxInfo);
<<<<<<< HEAD
	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);
};
=======

	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);

	//virtual void Draw(Output* pOut) ;

};
>>>>>>> db46d93509c2ce146a4e9203fd87cfe2f0cc7b22
