#pragma once

#include "GUI.h"
#include "DEFS.h"
#include "cell.h"
class Player;	

class Grid
{
	GUI * pGUI;   
	Cell*	GameCells[NumRowCells][NumColumnCells];	
	Player* player;

public:

	Grid();

	
	ActionType GetUserAction() const; 

	void ExecuteAction(ActionType);  

	void setCell(int r, int c, Cell* pCell);	

	bool MoveIfPossible(Cell * pCurrentCell, ActionType dir); 


	bool IsValidCell(int r, int c) const;

	void DrawAllCells() const; 


	GUI * getGUI() const;	

	~Grid();
	void RunApp();	
};
