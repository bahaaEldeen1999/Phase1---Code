#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions/AddLineAction.h"
#include"Actions/AddTriAction.h"
#include"Actions/AddEllipseAction.h"
#include"Actions/AddRhombusAction.h"
#include "Actions\SelectAction.h"
#include "Actions\PlayAction.h"
#include "Actions\SelectByColAction.h"
#include "Actions\SelectByFigAction.h"
#include "Actions\CopyAction.h"
#include "Actions\PasteAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			///create AddLineAction here
			pAct = new AddLineAction(this);

			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);

			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhombusAction(this);

			break;
		case SELECT:
			pAct = new SelectAction(this);
			
			break;
		case EXIT:
			///create ExitAction here
			
			break;
		case TO_PLAY:
			pOut->CreatePlayToolBar();

			break;
		case SELECTBYCOLOR:
			pAct = new SelectByColAction(this);

			break;
		case SELECTBYFIGURE:
			pAct = new SelectByFigAction(this);

			break;
		case TO_DRAW:
			pOut->CreateDrawToolBar();
			break;
		case COPY:
			pAct = new CopyAction(this);
			break;
		case PASTE:
			pAct = new PasteAction(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	
	for (int i=FigCount-1;i>=0;i--) 
	{
	if (FigList[i]->SelectArea(x,y)) 
	{
	FigList[i]->SetSelected(true);
	return FigList[i];
	}

	}
	


	
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//select all figures
CFigure *ApplicationManager::GetFigures(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	
	for (int i=FigCount-1;i>=0;i--) 
	{
	
	FigList[i]->SetSelected(true);
	//return FigList[i];
	

	}
	


	
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//get figures list

CFigure* ApplicationManager::getFigList(){

	return *FigList;
}
int ApplicationManager::getFigCount(){
	return FigCount;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//sets selected fig
void ApplicationManager:: SetSelectedFig(CFigure*fig) {
	SelectedFig=fig;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
