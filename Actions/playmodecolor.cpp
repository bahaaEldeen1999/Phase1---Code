#include "playmodecolor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

playmodecolor::playmodecolor(ApplicationManager * pApp):Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->Loadme();
	ifstream Input;
	Input.open("stm.txt");
	pManager->load(Input);
	Input.close();
	pManager->UpdateInterface();

	countcorrect = 0;
	countincorrect = 0;
	randomfigurecount = 0;
	bool figureexist = pManager->GetFigCount() != 0;     //checks if there are figures to not go into an infinite loop
	bool allfilled = pManager->IsAllFilled();
	bool alllines = pManager->IsAlllines();
	while (randomfigurecount == 0 && figureexist && allfilled == true && alllines == false) {
		randomfigcolor = rand() % 5;       //random number generator
		randomfigurecount = pManager->FigureColorCounter(randomfigcolor); //counting the figures  
	}
	
}

void playmodecolor::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	string c1 = to_string(countcorrect);

	string c2 = to_string(countincorrect);

	string type = FigColor(randomfigcolor);

	pOut->PrintMessage("Choose " + type + " Correct Figures:" + c1 + "        InCorrect Figures:" + c2);

	pIn->GetPointClicked(P1.x, P1.y);
}

string playmodecolor::FigColor(int x)
{
	if (x == 0) { return "Red"; }
	else if (x == 1) { return "Blue"; }
	else if (x == 2) { return "Green"; }
	else if (x == 3) { return "White"; }
	else if (x == 4) { return "Black"; }
}

void playmodecolor::Execute()
{
	Output* pOut = pManager->GetOutput();

	do
	{
		if (pManager->GetFigCount() == 0 || pManager->IsAllFilled() == false || pManager->IsAlllines() == true)
		{
			pOut->PrintMessage("Please make sure there are figures drawn and all figures are filled");
			break; //breaks if there are no figures
		}
		//reading parameters and printing info of the game
		ReadActionParameters();

		if (P1.y > 1250 || P1.y < 50) { break; }

		//choosing a figure
		pManager->SetSelectedFig(pManager->GetFigure(P1.x, P1.y));     //gets selected figures and puts it in selected pointer

		//add code to check if NULL
		if (pManager->GetSelectedFig() != NULL) {
			if (pManager->GetSelectedFig()->getfigcolor() == randomfigcolor)        //gets figtype of the selected fig
			{
				countcorrect++; pManager->RearrangeDeleted(); pManager->UpdateInterface();
			}
			else { countincorrect++; pManager->RearrangeDeleted(); pManager->UpdateInterface(); }
		}
		else { countincorrect++; }
	} while (countcorrect != randomfigurecount);

	if (pManager->GetFigCount() != 0 && pManager->IsAllFilled() == true && pManager->IsAlllines() == false)
	{
		string c1 = to_string(countcorrect);
		string c2 = to_string(countincorrect);
		string c3;
		if (countcorrect != 0) { c3 = to_string(countcorrect / (float)(countcorrect + countincorrect) * 100); }
		else { c3 = "0"; }
		pOut->ClearDrawArea();
		pOut->PrintMessage("Correct Figures:" + c1 + "        InCorrect Figures:" + c2 + "      Percentage: " + c3);
	}
}
