
#include "Action.h"
#include <string>

class Svt :public Action
{
private:
string file_name; 
public:
	Svt(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};

