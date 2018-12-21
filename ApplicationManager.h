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
	bool is_mute;
	static bool ApplicationManager::is_copy ; //check if clipboard from copy/cut
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	static GfxInfo ApplicationManager::figInfo;
	CFigure* SelectedFig; //Pointer to the selected figure
	int Fignum;  //Number of Selected figure
	static CFigure* ApplicationManager::Clipboard;   //Pointer to the copied/cut figure

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
	int GetFigNum();               //Gets Selected Figure number
	int GetFigCount();              //Gets Figure Count
	void RearrangeDeleted();               //Rearranges figures after delete
	int FigureCounter(int x);  //counts number of x type fig x from 0 to 4
	int FigureColorCounter(int x); ////counts number of x color fig x from 0 to 4
	bool IsAllFilled();			//return true if all figures are filled
	bool IsAlllines();			//return false if all figures are lines
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void saveall (ofstream &);
	void load (ifstream & );
	void SavebyType(ofstream &, int);
	void Loadme () ;
	int getFigCount();      //returns the Count of figures that are in the FigList
	static bool getIsCopy(); // get the is copy
	static void setIsCopy(bool v); //set the value of is copy
	static void setClip(CFigure* c) ; //set the clipboard
	static CFigure* getClip(); // get the clip
	static void setInfo(GfxInfo f) ; //set the info
	static GfxInfo getInfo(); // get the info

};

#endif
