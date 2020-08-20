#include "PlayerCell.h"
#include "player.h"


PlayerCell::PlayerCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\PlayerCell.jpg";
}


PlayerCell::~PlayerCell()
{
}

bool PlayerCell::ActOn(Player* p)
{
	
	return true;
}
PlayerCell::PlayerCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\PlayerCell.jpg";
}


PlayerCell::~PlayerCell(void)
{
}

bool PlayerCell::ActOn(Player* p)
{
	return true;
}