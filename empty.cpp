#include "empty.h"
#include "player.h"

EmptyCell::EmptyCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\EmptyCell.jpg";
}


EmptyCell::~EmptyCell(void)
{
}

bool EmptyCell::ActOn(Player* p)
{
	return true;
}