#pragma once
#include "cell.h"
class EnemyCell : public Cell
{
public:
	EnemyCell(int row, int col);
	virtual ~EnemyCell();

	virtual bool ActOn(Player* p);
};
