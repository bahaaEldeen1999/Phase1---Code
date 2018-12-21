#include "SaveAction.h"
#include"../ApplicationManager.h"
#include <fstream>
SaveAction :: SaveAction (ApplicationManager * pApp):Action(pApp) // constructor of save Action 
{
}

void SaveAction::ReadActionParameters()
{ 
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Save graphs: Please enter the file name");
	file_name = pIn->GetSrting(pOut); //Reading the file name from user 
	pOut->PrintMessage("Your file name is : "+ file_name); // Display the name again for the user 
}

void SaveAction::Execute()
{
	ReadActionParameters(); // first thing when calling the save Action is reading it's parameters 
	Output* pOut = pManager->GetOutput();
	color y = pOut->getCrntDrawColor(); // Getting the current draw colour
	color x = pOut->getCrntFillColor(); // Getting the current fill colour
	ofstream OutFile; // Declaring an instance of file stream 
	OutFile.open(file_name+".txt");
	pManager->saveall(OutFile); // Calling the function save all from the application manager 
	OutFile.close();
}
