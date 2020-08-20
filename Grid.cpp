#include <string>
#include "grid.h"
#include "obstacle.h"
#include "player.h"
#include "empty.h"
#include "playerCell.h"
#include "cell.h"
#include "Goal.h"
#include "enemy.h"
#include "GUI.h"
#include "WinUser.h"

Grid::Grid()
{
	
	for (int i = 0; i < NumRowCells; i++)
	{
		for (int j = 0; j < NumColumnCells; j++) {

			GameCells[i][j] = new EmptyCell(i, j);

		}
	}
	int r1 = 1 + rand() % (NumRowCells - 1);
	int c1 = 1 + rand() % (NumColumnCells - 1);
	GameCells[r1][c1] = new ObstacleCell(r1 , c1);

	GameCells[NumRowCells / 2][1] = new PlayerCell(NumColumnCells / 2 , 1);

	int r2 = 1 + rand() % (NumRowCells - 1);
	int c2 = 1 + rand() % (NumColumnCells - 1);
	GameCells[r2][c2] = new EnemyCell(r2 , c2 );

	int r3 = 1 + rand() % (NumRowCells - 1);
	GameCells[r3][NumColumnCells - 1] = new GoalCell(r3 , NumColumnCells - 1 );

	pGUI = new GUI;
	DrawAllCells();

}




bool Grid::MoveIfPossible(Cell* pCurrentCell, ActionType dir)
{

	
	int playerOldRow = pCurrentCell->getRow();
	int playerOldCol = pCurrentCell->getCol();

	int TargetRow = playerOldRow;
	int TargetCol = playerOldCol;


	switch (dir)
	{
	case MOVE_UP:
		TargetRow--;
		break;
	case MOVE_DOWN:
		TargetRow++;
		break;
	case MOVE_LEFT:
		TargetCol--;
		break;
	case MOVE_RIGHT:
		TargetCol++;;
		break;
	}

	if (!IsValidCell(TargetRow, TargetCol))
		return false;

	
	Cell *pTargetCell = GameCells[TargetRow][TargetCol];

	if (!pTargetCell->ActOn(player))	
		return false;

	

	setCell(TargetRow, TargetCol, pCurrentCell);

	pCurrentCell->SetRow(TargetRow);
	pCurrentCell->SetCol(TargetCol);

	
	GameCells[playerOldRow][playerOldCol] = new EmptyCell(playerOldRow, playerOldCol);

	
	pGUI->DrawCell(GameCells[TargetRow][TargetCol]);
	pGUI->DrawCell(GameCells[playerOldRow][playerOldCol]);

	return true;
}

void Grid::DrawAllCells() const
{
	pGUI->ClearGridArea();

	for (int i = 0; i < NumRowCells; i++)
		for (int j = 0; j < NumColumnCells; j++)
			pGUI->DrawCell(GameCells[i][j]);
}

void Grid::setCell(int row, int col, Cell* pCell)
{
	if (GameCells[row][col])
		delete GameCells[row][col];	

	GameCells[row][col] = pCell;

}


GUI * Grid::getGUI() const
{
	return pGUI;
}
ActionType Grid::GetUserAction() const
{
	return pGUI->GetUserAction();
}
void GUI::GetPointClicked(int &x, int &y, bool wait) const
{


	if (wait)
		pWind->WaitMouseClick(x, y);
	else
		pWind->GetMouseClick(x, y);
}

Cell *p = GUI::GetClickCell( &x , &y);

void Grid::setCell(int p.GetRow, int p.GetColumn, Cell* pCell);

void Grid::ExecuteAction(ActionType ActType)
{
	switch (ActType)
	{
	case LOAD:
		break;

	case SAVE:
	
		break;

	case START:
		pGUI->setInterfaceMode(MODE_GAME);
		break;

	case PAUSE:
		pGUI->setInterfaceMode(MODE_MENU);
		break;
	

	
	case MOVE_UP:
	case MOVE_DOWN:
	case MOVE_RIGHT:
	case MOVE_LEFT:
		player->Move(this, ActType);
		break;

	case STATUS:	
		return;
	}

}


Grid::~Grid()
{
	delete pGUI;
}




void Grid::RunApp()
{

	int row = 7, col = 12;
	PlayerCell* pCell = new PlayerCell(row, col);
	setCell(row, col, pCell);
	player = new Player(*pCell);
	pGUI->DrawCell(pCell);

	while (1)
	{
		ActionType act = GetUserAction();
		if (act == EXIT)
			return;

		ExecuteAction(act);

		Sleep(100);
	}

}

bool Grid::IsValidCell(int row, int col) const
{
	return (row >= 0 && row < NumRowCells)
		&& (col >= 0 && col < NumColumnCells);
}
