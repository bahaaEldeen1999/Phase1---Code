#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>
#include <string.h>
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	int figtype; //figtype (0:rectangle,1:line,2:ellipse,3:triangle,4:rhombus)
	int figcolor; //figcolor (0:red,1:blue,2:green,3:white,4:black)

	/// Add more parameters if needed.
	
public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut)   = 0 ;		//Draw the figure
	int getfigtype(); //returns figtype
	int getfigcolor(); //returns figcolor
	bool IsFilled();
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual bool SelectArea(int x,int y); //Checks if clicked point is inside Figure
	
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual void save (ofstream &OutFile, int ) = 0; 
	virtual void load (ifstream &InFile) = 0;
	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	virtual void PrintInfo(Output* pOut) = 0;
	GfxInfo getInfo();
};

#endif