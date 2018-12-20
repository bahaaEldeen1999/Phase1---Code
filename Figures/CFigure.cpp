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

bool CFigure ::SelectArea(int x,int y) {

	return true;
}
GfxInfo CFigure::getInfo(){
	return FigGfxInfo;
}