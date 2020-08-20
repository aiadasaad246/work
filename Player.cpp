#include "player.h"
#include "grid.h"
#include "GUI.h"
#include "cell.h"

Player::Player(Cell pos)
{
	PositionCell = pos;
	lives = 4;
	health = 100;
	score = 0;
	
}

void Player::Move(Grid* pGrid, ActionType dir)
{
	
	Cell oldPosition = PositionCell;

	GUI* pGUI = pGrid->getGUI();

	pGrid->MoveIfPossible(&PositionCell, dir); 

}

void Player::setPosition(Cell pos)
{
	PositionCell = pos;
}

