
#include "Action.h"
#include <string>

class loadAct :public Action
{
private:
string file_name;
public:
	loadAct (ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};
