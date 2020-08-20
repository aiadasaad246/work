#include "cell.h"
#include "obstacle.h"
#include "player.h"


ObstacleCell::ObstacleCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\ObstacleCell.jpg";
}


ObstacleCell::~ObstacleCell(void)
{
}

bool ObstacleCell::ActOn(Player* p)
{
	return false;
}