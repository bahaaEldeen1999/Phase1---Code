#include "CFigure.h"
#include"../ApplicationManager.h"
class CRhombus :public CFigure
{
private:
	Point center;
public:
	CRhombus(Point, GfxInfo FigureGfxInfo);

	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);
	 void save (ofstream &OutFile , int );
	void load (ifstream &Infile ); 
	void PrintInfo(Output* pOut);
};
