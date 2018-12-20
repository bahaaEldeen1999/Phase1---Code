#include "CFigure.h"

static int countoffigures; //Number of Figures created to Declare ID's
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID=++countoffigures;


	if (FigGfxInfo.FillClr == RED)					//figcolor (0:red,1:blue,2:green,3:white,4:black)
	{
		figcolor = 0;
	}
	else if (FigGfxInfo.FillClr == BLUE)
	{
		figcolor = 1;
	}
	else if (FigGfxInfo.FillClr == GREEN)
	{
		figcolor = 2;
	}
	else if (FigGfxInfo.FillClr == WHITE)
	{
		figcolor = 3;
	}
	else if (FigGfxInfo.FillClr == BLACK)
	{
		figcolor = 4;
	}
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