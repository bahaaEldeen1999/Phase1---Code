#include "ApplicationManager.h"
#include <Windows.h>
#include <mmsystem.h>
int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;
	PlaySound (TEXT("draw mode.wav"),NULL, SND_SYNC);
	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	

	}while(ActType != EXIT);
	

	
	return 0;
}

