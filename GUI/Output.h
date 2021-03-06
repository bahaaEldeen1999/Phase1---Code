#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		
	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar()   const;	//create the status bar
	void CreateResizeBar()   const;	//create the resize bar
	Input* CreateInput()     const; //creates a pointer to the Input object	
	void ClearStatusBar()    const;	//Clears the status bar
	void ClearDrawArea()     const;	//Clears the drawing area
	void ClearToolBar() const;
	//check if point on toolbar
	bool isChecked(Point p) const;
	// -- Figures Drawing functions
	void DrawRect(Point &P1, Point &P2, GfxInfo RectGfxInfo, bool selected=false) ;  //Draw a 
	void DRAWTri (Point &P1, Point &P2, Point &p3, GfxInfo RectGfxInfo, bool selected=false) ;
	void Drawelipse (Point &P1, GfxInfo RectGfxInfo, bool selected=false) ; 
	void Draw_poly (Point &P1, GfxInfo RectGfxInfo, bool selected=false) ; 
	void DrawLine(Point &P1, Point &P2, GfxInfo RectGfxInfo, bool selected = false) ;  
	///Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	void Output::CreateColorBar() const; //Creates ColorBar
	~Output();
};

#endif