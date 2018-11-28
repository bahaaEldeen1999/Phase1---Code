#include "CFigure.h"

class CRhombus :public CFigure
{
private:
	Point center;
public:
	CRhombus(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};