#pragma once
#include "cell.h"
#include "player.h"
class ObstacleCell : public Cell
{
public:
	ObstacleCell(int row, int col);
	virtual ~ObstacleCell();

	virtual bool ActOn(Player* p);
};
