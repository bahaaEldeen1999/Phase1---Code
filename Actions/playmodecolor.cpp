#include"playmodecolor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

playmodecolor::playmodecolor(ApplicationManager * pApp):Action(pApp)
{
	countcorrect = 0;
	countincorrect = 0;
	randomfigcolor = rand() % 5;       //random number generator
	randomfigurecount = 0;
	while (randomfigurecount == 0)
	{
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
		//reading parameters and printing info of the game
		ReadActionParameters();

		if (P1.y > 1250 || P1.y < 50) { break; }

		pManager->SetSelectedFig(pManager->GetFigure(P1.x, P1.y));     //gets selected figures and puts it in selected pointer

		//add code to check if NULL
		if (pManager->GetSelectedFig() != NULL) {
			if (pManager->GetSelectedFig()->getfigcolor() == randomfigcolor)        //gets figolor of the selected fig
			{
				countcorrect++; pManager->RearrangeDeleted(); pManager->UpdateInterface();
			}
			else { countincorrect++; pManager->RearrangeDeleted(); pManager->UpdateInterface(); }
		}
		else { countincorrect++; }
	} while (countcorrect != randomfigurecount);

	string c1 = to_string(countcorrect);
	string c2 = to_string(countincorrect);
	string c3;
	if (countcorrect != 0) { c3 = to_string(countcorrect / (float)(countcorrect + countincorrect) * 100); }
	else { c3 = "0"; }
	pOut->ClearDrawArea();
	pOut->PrintMessage("Correct Figures:" + c1 + "        InCorrect Figures:" + c2 + "      Percentage: " + c3);

}

