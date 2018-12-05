
#include "Action.h"
#include <string>

class SaveAction :public Action
{
private:
string file_name; 
public:
	SaveAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};

