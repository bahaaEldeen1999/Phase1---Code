#include "CFigure.h"

static int countoffigures; //Number of Figures created to Declare ID's
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID=++countoffigures;

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

}
int CFigure:: getfigtype() 
{
	return figtype;

}

int CFigure::getfigcolor()
{
	if (FigGfxInfo.FillClr == RED)									//figcolor (0:red,1:blue,2:green,3:white,4:black)
		return 0;
	else if (FigGfxInfo.FillClr == BLUE)
		return 1;
	else if (FigGfxInfo.FillClr == GREEN)
		return 2;
	else if (FigGfxInfo.FillClr == WHITE)
		return 3;
	else if (FigGfxInfo.FillClr == BLACK)
		return 4;
}

bool CFigure::IsFilled()
{
	if (FigGfxInfo.isFilled == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CFigure ::SelectArea(int x,int y) {

	return true;
}
GfxInfo CFigure::getInfo(){
	return FigGfxInfo;
}