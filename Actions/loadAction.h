#ifndef loadAct_HEADER
#define loadAct_HEADER
#include "Action.h"
#include <string>

class loadAct :public Action
{
private:

string file_name;
public:
	loadAct(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	void load (ifstream &Input) ;
};

#endif