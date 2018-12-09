#include "Action.h"

class SelectByColAction : public Action{

private :
	Point P1;
public:
	SelectByColAction(ApplicationManager *pApp);
	void ReadActionParameters();
	virtual void Execute() ;
	~SelectByColAction(void);
};