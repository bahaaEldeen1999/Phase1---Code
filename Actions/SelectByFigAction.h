#include "Action.h"

class SelectByFigAction : public Action{

private :
	Point P1;
public:
	SelectByFigAction(ApplicationManager *pApp);
	void ReadActionParameters();
	virtual void Execute() ;
	~SelectByFigAction(void);
};