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
#include"Actions/FillColorAction.h"
#include"Actions/BorderColorAction.h"
#include"Actions/ColorIconAction.h"
#include"Actions/RedColorAction.h"
#include"Actions/BlueColorAction.h"
#include"Actions/GreenColorAction.h"
#include"Actions/BlackColorAction.h"
#include"Actions/WhiteColorAction.h"
#include "Actions\CopyAction.h"
#include "Actions\PasteAction.h"
#include "Actions\CutAction.h"
#include "Actions\stm.h"
#include "Actions\loadAction.h"
#include <Windows.h>
#include <mmsystem.h>
#include "Actions\playmodeshape.h"
#include "Actions\loadAction.h"
#include "Actions\SwitchToDraw.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	is_mute = 0;
	FigCount = 0;
	SelectedFig=NULL;
	UI.FillColor = BLACK;
	//Create an array of figure pointers and set them to NULL
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;
}

//=====//
//								Actions Related Functions							//
//=====//
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
			if (!is_mute)
			PlaySound (TEXT("rectangle.wav"),NULL, SND_SYNC);
			break;

		case DRAW_LINE:
			///create AddLineAction here
			pAct = new AddLineAction(this);
			if (!is_mute)
			PlaySound (TEXT("line.wav"),NULL, SND_SYNC);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			if (!is_mute)
			PlaySound (TEXT("tri.wav"),NULL, SND_SYNC);
			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);
			if (!is_mute)
			PlaySound (TEXT("elipse.wav"),NULL, SND_SYNC);
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhombusAction(this);
			if (!is_mute)
			PlaySound (TEXT("rho.wav"),NULL, SND_SYNC);
			break;
			case SAVE:
           pAct = new SaveAction(this);
		break;

			case DRAW_Colors:
				pAct = new ColorIconAction(this);
				break;
			case CHNG_FILL_CLR:
				pAct = new FillColorAction(this);
				break;

			case CHNG_DRAW_CLR:
				pAct = new BorderColorAction(this);
				break;

			case DRAW_RED:
				pAct = new RedColorAction(this);
				break;

			case DRAW_BLUE:
				pAct = new BlueColorAction(this);
				break;

			case DRAW_BLACK:
				pAct = new BlackColorAction(this);
				break;

			case DRAW_GREEN:
				pAct = new GreenColorAction(this);
				break;

			case DRAW_WHITE:
				pAct = new WhiteColorAction(this);
				break;

		case SAVE_BY_TYPE:
			pAct = new Svt(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);

			break;
		case COPY:
			pAct = new CopyAction(this);
			break;
		case PASTE:
			pAct = new PasteAction(this);
			break;
		case DEL:
			pAct = new DeleteAction(this);

			break;
		case CUT :
			pAct = new CutAction(this);

			break;

		case LOAD:
			pAct = new loadAct(this);
			break;
		case TO_PLAY :
				pAct = new stm (this);
				break;
		case SELECTBYFIGURE :
			pAct=new playmodeshape(this);
			break;
		case TO_DRAW:
			pAct =new SwitchToDraw(this);
			break;
		case EXIT:
				{delete pAct;PlaySound (TEXT("goodbye.wav"),NULL, SND_SYNC);}
			break;
				case MUTE:
			is_mute =1;
			break;
		case UNMUTE: 
			is_mute = 0;
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
//=====//
//						Figures Management Functions								//
//=====//

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
	{
		if (FigList[i]->IsSelected()==false)
			 {FigList[i]->SetSelected(true);
	          Fignum=i;
			if (SelectedFig!=NULL){SelectedFig->SetSelected(false);pOut->ClearStatusBar();}// to unhighlight other figures
	          FigList[i]->PrintInfo(pOut);
	          return FigList[i];
		}
		else
		{FigList[i]->SetSelected(false);return NULL;pOut->ClearStatusBar();}
	}

	}
	if (SelectedFig!=NULL)
	{
		SelectedFig->SetSelected(false);
		pOut->ClearStatusBar();

	}

	//Add your code here to search for a figure given a point x,y
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//=====//
//							Interface Management Functions							//
//=====//

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
int ApplicationManager:: FigureCounter(int x)
{
	int count=0;
	for (int i=0;i<FigCount;i++)
	{
		if (FigList[i]->getfigtype()==x) { 
			count++;
		}
	}
	return count;
}
////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager:: RearrangeDeleted()
{

		for (int i=Fignum;i<FigCount-1;i++)
		{
			FigList[i]=FigList[i+1];
		}
		FigList[FigCount]=NULL;
		SetFigCount(FigCount-1);


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
void ApplicationManager :: saveall(ofstream &OutFile) {
	color y = pOut->getCrntDrawColor();
	color x = pOut->getCrntFillColor();
	if (y== BLACK){
		OutFile<<"BLACK"<<"         ";
	}
	else if (y== GREEN) {
		OutFile<<"GREEN"<<"         ";
	}
	else if (y== BLUE) {
		OutFile<<"BLUE"<<"         ";
	}
	else if (y== RED) {
		OutFile<<"RED"<<"         ";
	}
	else if (y== WHITE) {
		OutFile<<"WHITE"<<"         ";
	}
	if (x== BLACK){
		OutFile<<"BLACK"<<"         ";
	}
	else if (x== GREEN) {
		OutFile<<"GREEN"<<"         ";
	}
	else if (x== BLUE) {
		OutFile<<"BLUE"<<"         ";
	}
	else if (x== RED) {
		OutFile<<"RED"<<"         ";
	}
	else if (x== WHITE) {
		OutFile<<"WHITE"<<"         ";
	}
	OutFile<<endl; 
	OutFile<<FigCount<<endl;
	for (int i = 0; i < FigCount; i++) {
	FigList [i]->save(OutFile,i);
	OutFile<<endl;
}
}
void ApplicationManager :: SavebyType (ofstream &Outfile,int x) {
	color y = pOut->getCrntDrawColor();
	color x1 = pOut->getCrntFillColor();
	if (y== BLACK){
		Outfile<<"BLACK"<<"         ";
	}
	else if (y== GREEN) {
		Outfile<<"GREEN"<<"         ";
	}
	else if (y== BLUE) {
		Outfile<<"BLUE"<<"         ";
	}
	else if (y== RED) {
		Outfile<<"RED"<<"         ";
	}
	else if (y== WHITE) {
		Outfile<<"WHITE"<<"         ";
	}
	if (x1== BLACK){
		Outfile<<"BLACK"<<"         ";
	}
	else if (x1== GREEN) {
		Outfile<<"GREEN"<<"         ";
	}
	else if (x1== BLUE) {
		Outfile<<"BLUE"<<"         ";
	}
	else if (x1== RED) {
		Outfile<<"RED"<<"         ";
	}
	else if (x1== WHITE) {
		Outfile<<"WHITE"<<"         ";
	}
	Outfile<<endl; 
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
void ApplicationManager :: Loadme () {
for(int i=0; i<FigCount; i++){
	delete FigList[i];}
for(int i=0; i<MaxFigCount; i++){
	FigList[i] = NULL;}
FigCount = 0 ;
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
void ApplicationManager ::load (ifstream &Input) {
	string fclr , dclry;
	Input>>dclry>>fclr;
	if (dclry == "BLACK") {
		UI.DrawColor = BLACK;
	}
	else if (dclry == "RED") {
		UI.DrawColor = RED;
	}
	else if (dclry == "BLUE") {
		UI.DrawColor = BLUE;
	}
	else if  (dclry == "GREEN") {
		UI.DrawColor = GREEN;
	}
	else if (dclry == "WHITE") {
	UI.DrawColor = WHITE;
	}
	if (fclr == "BLACK") {
		UI.FillColor = BLACK;
	}
	else if (fclr == "RED") {
		UI.FillColor = RED;
	}
	else if (fclr == "BLUE") {
		UI.FillColor = BLUE;
	}
	else if  (fclr == "GREEN") {
		UI.FillColor = GREEN;
	}
	else if (fclr == "WHITE") {
	UI.FillColor = WHITE;
	}
	int x;
	string y;
	Input>>x;
	for (int i = 0 ; i<x; i++) {
		Input>>y;
	if (y=="Elipse"){
		Point p;
		p.x = 100; 
		p.y = 100;
		GfxInfo GP;
		CEllipse *C = new CEllipse (p,GP);
		C->load (Input);
		AddFigure (C);
	}
		else if (y=="Rectangle"){
		Point p,y ;
		y.x = 200;
		y.y = 150; 
		p.x = 609; 
		p.y = 578;
		GfxInfo GP;
		CRectangle *C = new CRectangle (p,y,GP);
		C->load (Input);
		AddFigure (C);
	}
else if (y=="Line"){
		Point p,y ;
		y.x = 567;
		y.y = 126; 
		p.x = 567; 
		p.y = 546;
		GfxInfo GP;
		CLine *C = new CLine (p,y,GP);
		C->load (Input);
		AddFigure (C);
	}
else if (y=="Rhombus"){
		Point p,y ;
		y.x = 123;
		y.y = 415; 
		p.x = 514; 
		p.y = 606;
		GfxInfo GP;
		CRhombus *C = new CRhombus (p,GP);
		C->load (Input);
		AddFigure (C);
}
else if (y== "Triangle") {
		Point p,y ,m;
		m.x = 108; 
		m.y = 199; 
		y.x = 178;
		y.y = 195; 
		p.x = 205; 
		p.y = 423;
		GfxInfo GP;
		CTriangle *C = new CTriangle (p,y,m,GP);
		C->load (Input);
		AddFigure (C);
}
	//Here call laod function from CFigures 
	// then call the appMGr to make add list figures; 
	
//	pManager->SavebyType(OutFile,x);
	//Input.close();
	//pManager->UpdateInterface();

}
}
 
 
int ApplicationManager::getFigCount(){
	return FigCount;
}
