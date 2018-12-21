#include "stm.h"
#include"../ApplicationManager.h"
#include <fstream> 
// Switch to play mode action 
stm  :: stm (ApplicationManager * pApp):Action(pApp)
{
}

void  stm  ::ReadActionParameters()
{
}

void  stm  ::Execute()
{
ReadActionParameters();
Output* pOut = pManager->GetOutput();
Input* pIn = pManager->GetInput();
pOut->CreatePlayToolBar();
ofstream OutFile;
OutFile.open("stm.txt"); // you should load from switch to draw mode from this file name; 
pManager->saveall(OutFile);
OutFile.close();
}
