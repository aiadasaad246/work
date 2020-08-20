#pragma once
#include "cell.h"
class GoalCell : public Cell
{
public:
	GoalCell(int row, int col);
	virtual ~GoalCell();

	virtual bool ActOn(Player* p);
};
