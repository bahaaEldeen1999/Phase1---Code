#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	int Fignum;  //Number of Selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure

	int stateNum; //if statenum=0 --> non-filled , if statenum=1 --> filled

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) ; //Search for a figure given a point inside the figure
	void SetSelectedFig(CFigure*);   //Sets Selected Figure
	void SetFigCount(int);           //Sets Figure Count
	CFigure* GetSelectedFig();     //Gets Selected Figure
	CFigure** GetFigList();          //Gets Figure List
	int GetFigNum();               //Gets Selected Figure number
	int GetStateNum();				//gets whether figure is filled or non-filled
	void SetStateNum(int);			//sets statenum(whether figure is filled or non-filled)
	int GetFigCount();              //Gets Figure Count
	void RearrangeDeleted();               //Rearranges figures after delete
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void saveall (ofstream &);
	void SavebyType(ofstream &, int);
	void Loadme () ;
};

#endif