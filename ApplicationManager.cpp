#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions/AddLineAction.h"
#include"Actions/AddTriAction.h"
#include"Actions/AddEllipseAction.h"
#include"Actions/AddRhombusAction.h"
#include "Actions\SelectAction.h"
#include "Actions\DeleteAction.h"
#include "Actions/SaveAction.h"
#include "Actions\Action.h"
#include "Figures\CEllipse.h"
#include "Figures\CLine.h"
#include "Figures\CRectangle.h"
#include "Figures\CRhombus.h"
#include "Figures\CTriangle.h"
#include "Actions\sv.h"
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
			case SAVE: 
           pAct = new SaveAction(this);
		break;
		case SAVE_BY_TYPE:
			pAct = new Svt(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			
			break;
		case DEL:
			pAct = new DeleteAction(this);
			
			break;
		case EXIT:
			///create ExitAction here
			
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
CFigure *ApplicationManager::GetFigure(int x, int y) 
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	
	for (int i=FigCount-1;i>=0;i--) 
	{
	if (FigList[i]->SelectArea(x,y)) 
	{ FigList[i]->SetSelected(true);
	Fignum=i;
	return FigList[i];}

	}
	


	
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
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
CFigure* ApplicationManager::GetSelectedFig() 
{
	return SelectedFig;

}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SetFigCount(int x)
{

	FigCount=x;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure** ApplicationManager::GetFigList()
{
	return FigList;

}
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetFigCount() 
{
	return FigCount;
}
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetFigNum()
{
	return Fignum;
}
void ApplicationManager :: saveall(ofstream &Outfile) {
	Outfile<<FigCount<<endl; 
	for (int i = 0; i < FigCount; i++) {
	FigList [i]->save(Outfile,i);
	Outfile<<endl;
}
}
void ApplicationManager :: SavebyType (ofstream &Outfile,int x) {
if (x==0) {
	int count=0;
	for (int i = 0; i < FigCount; i++) {
	CLine *C = dynamic_cast <CLine*> (FigList[i]);
	if (C!=NULL) {
	count++;
	}}
	if (count!=0)
	{Outfile<<count<<endl;
for (int i = 0; i < FigCount; i++) {
	CLine *C = dynamic_cast <CLine*> (FigList[i]);
	if (C!=NULL) {
		C->save(Outfile,i);
        Outfile<<endl;
	}
}
}
}
else if (x==1) {
	int count=0;
	for (int i = 0; i < FigCount; i++) {
	CRectangle*C = dynamic_cast <CRectangle*> (FigList[i]);
	if (C!=NULL) {
	count++;
	}}
	if (count!=0){
		Outfile<<count<<endl;
	
for (int i = 0; i < FigCount; i++) {
	CRectangle *C = dynamic_cast <CRectangle*> (FigList[i]);
	if (C!=NULL) {
		C->save(Outfile,i);
		Outfile<<endl;
	}
}
}
}
else if (x==2) {
	int count=0;
	for (int i = 0; i < FigCount; i++) {
	CTriangle*C = dynamic_cast <CTriangle*> (FigList[i]);
	if (C!=NULL) {
	count++;
	}}
	if (count!=0){
		Outfile<<count<<endl;
for (int i = 0; i < FigCount; i++) {
	CTriangle *C = dynamic_cast <CTriangle*> (FigList[i]);
	if (C!=NULL) {
		C->save(Outfile,i);
		Outfile<<endl;
	}
}
}
}
else if (x==3) {
	int count=0;
	for (int i = 0; i < FigCount; i++) {
	CEllipse*C = dynamic_cast <CEllipse*> (FigList[i]);
	if (C!=NULL) {
	count++;
	}}
	if (count!=0){
		Outfile<<count<<endl;
for (int i = 0; i < FigCount; i++) {
	CEllipse *C = dynamic_cast <CEllipse*> (FigList[i]);
	if (C!=NULL) {
		C->save(Outfile,i);
		Outfile<<endl;
	}
}
}
}
else   {
	int count=0;
	for (int i = 0; i < FigCount; i++) {
	CRhombus*C = dynamic_cast <CRhombus*> (FigList[i]);
	if (C!=NULL) {
	count++;
	}}
	if (count!=0){
		Outfile<<count<<endl;
for (int i = 0; i < FigCount; i++) {
	CRhombus*C = dynamic_cast <CRhombus*> (FigList[i]);
	if (C!=NULL) {
		C->save(Outfile,i);
		Outfile<<endl;
	}
}
}
}
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