#include "Goal.h"
#include "player.h"

GoalCell::GoalCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\EmptyCell.jpg";
}


GoalCell::~GoalCell(void)
{
}

bool GoalCell::ActOn(Player* p)
{
	return true;
}