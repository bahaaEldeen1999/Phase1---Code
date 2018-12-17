#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
	if (Fclr == RED)					//figcolor (0:red,1:blue,2:green,3:white,4:black)
	{
		figcolor = 0;
	}
	else if (Fclr == BLUE)
	{
		figcolor = 1;
	}
	else if (Fclr == GREEN)
	{
		figcolor = 2;
	}
	else if (Fclr == WHITE)
	{
		figcolor = 3;
	}
	else if (Fclr == BLACK)
	{
		figcolor = 4;
	}
}
int CFigure:: getfigtype() 
{
	return figtype;

}

int CFigure::getfigcolor()
{
	return figcolor;
}

bool CFigure ::SelectArea(int x,int y) {

	return true;
}
GfxInfo CFigure::getInfo(){
	return FigGfxInfo;
}