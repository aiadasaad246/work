#pragma once

#include "cell.h"
#include "GUI.h"
class Grid;

class Player
{
	int lives;    
	float health; 
	float score;  
	Cell PositionCell;

public:

	Player(Cell pos); 

	void setPosition(Cell);
	void Move(Grid* pGrid, ActionType MoveAction); 
};
