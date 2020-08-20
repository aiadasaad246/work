#include "enemy.h"
#include "player.h"

EnemyCell::EnemyCell(int row, int col) :Cell(row, col)
{
	ImagePath = "images\\Cells\\EmptyCell.jpg";
}


EnemyCell::~EnemyCell(void)
{
}

bool EnemyCell::ActOn(Player* p)
{
	return false;
}