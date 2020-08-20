#include <string>
#include "GUI.h"
#include "obstacle.h"
#include "enemy.h"
#include "playercell.h"
#include "Goal.h"
#include "empty.h"
#include "cell.h"
#include "Player.h"
#include "grid.h"


GUI::GUI()
{


	MsgColor = DARKRED;		    
	BkGrndColor = DARKSLATEBLUE;	
	StatusBarColor = GREY;       

	GridLineColor = LIGHTGRAY;   
	ObstacleColor = BLACK;       

	
	pWind = new window(WindWidth + 15, WindHeight, 5, 5);

	pWind->ChangeTitle("Game");

	CreateMenu();
	ClearGridArea();
	ClearStatusBar();

	InterfaceMode = MODE_MENU;
}




void GUI::GetPointClicked(int &x, int &y, bool wait) const
{
	

	if (wait)
		pWind->WaitMouseClick(x, y); 
	else
		pWind->GetMouseClick(x, y);	 
}

Cell* GUI::GetClickCell( int &x, int &y )
{
	int row = (y - WindowHeight) / GridCellWidth;
	int col = x / GridCellWidth;
	Cell* arr = new Cell ( int row , int col );
	return arr;
}

;
string GUI::GetSrting() const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	
			return "";	
		if (Key == 13)	
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	
			Label.resize(Label.size() - 1);
		else
			Label += Key;

		PrintMessage(Label);
	}
};
 
ActionType GUI::GetUserAction() const
{
	int x = -1, y = -1;


	if (InterfaceMode == MODE_MENU)
	{
		pWind->WaitMouseClick(x, y);
		if (y >= 0 && y < ToolBarHeight)
		{

			int ClickedItemOrder = (x / MenuItemWidth);


			switch (ClickedItemOrder)
			{
			case ITM_LOAD: return LOAD;
			case ITM_SAVE: return SAVE;
			case ITM_START:
				pWind->FlushKeyQueue();
				pWind->FlushMouseQueue();
				return START;
			case ITM_EXIT: return EXIT;

			case ITM_PlayerCell: return PlayerCell;

			case ITM_EmptyCell: return EmptyCell;

			case ITM_ObstacleCell: return ObstacleCell;

			case ITM_EnemyCell: return EnemyCell;

			case ITM_GoalCell: return GoalCell;

			default: return EMPTY;	
			}
		}

		
		if ((y >= ToolBarHeight) && (y < WindHeight - StatusBarHeight))
		{
			return GRID_AREA;
		}

		
		return STATUS;
	}
	
	else
	{

		char keyData;
		keytype Ktype = pWind->GetKeyPress(keyData);

		if (Ktype == ESCAPE)
		{
			pWind->FlushKeyQueue();
			pWind->FlushMouseQueue();
			return PAUSE;
		}

		if (Ktype == ARROW)		
			switch (keyData)
			{
			case 2:	return MOVE_DOWN;
			case 4:	return MOVE_LEFT;
			case 6:	return MOVE_RIGHT;
			case 8:	return MOVE_UP;
			}


		return NO_MOVE; 

		
	}

}

GUI_MODE GUI::getInterfaceMode() const
{
	return InterfaceMode;
}


void GUI::setInterfaceMode(GUI_MODE mode)
{
	InterfaceMode = mode;
}


void GUI::ClearStatusBar() const
{

	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, WindHeight - StatusBarHeight, WindWidth, WindHeight);
}


void GUI::ClearGridArea() const
{
	
	pWind->SetPen(GridLineColor, 1);
	int x1, y1, x2, y2;

	y1 = ToolBarHeight;
	y2 = WindHeight - StatusBarHeight;
	for (int i = 0; i < NumColumnCells; i++)
	{
		x1 = x2 = i * GridCellWidth;
		pWind->DrawLine(x1, y1, x2, y2);
	}

	x1 = 0;
	x2 = WindWidth;
	for (int i = 0; i < NumRowCells; i++)
	{
		y1 = y2 = ToolBarHeight + i * GridCellWidth;
		pWind->DrawLine(x1, y1, x2, y2);
	}

}

void GUI::CreateMenu()
{
	InterfaceMode = MODE_MENU;

	
	string MenuItemImages[MENU_ITM_COUNT];
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Load.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Save.jpg";
	MenuItemImages[ITM_START] = "images\\MenuItems\\Start.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Exit.jpg";
	MenuItemImages[ITM_PlayerCell]= "images\\Cells\\PlayerCell.jpg";
	MenuItemImages[ITM_EmptyCell]= "images\\Cells\\EmptyCell.jpg";
	MenuItemImages[ITM_ObstacleCell]= "images\\Cells\\ObstacleCell.jpg";
	MenuItemImages[ITM_EnemyCell] = "images\\Cells\\EnemyCell.jpg";
	MenuItemImages[ITM_GoalCell] = "images\\Cells\\GoalCell.jpg";


	for (int i = 0; i < MENU_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*MenuItemWidth, 0, MenuItemWidth, ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, WindWidth, ToolBarHeight);

}


void GUI::PrintMessage(string msg) const	
{
	ClearStatusBar();	

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(18, BOLD, BY_NAME, "Verdana");
	pWind->DrawString(10, WindHeight - (int)(StatusBarHeight / 1.3), msg);
}



void GUI::DrawCell(const Cell * cell) const
{
	pWind->SetPen(ObstacleColor, 1);
	pWind->SetBrush(ObstacleColor);
	drawstyle style = FILLED;

	int x = cell->getCol() * GridCellWidth;
	int y = ToolBarHeight + (cell->getRow() * GridCellWidth);
	pWind->DrawImage(cell->getImage(), x + 1, y + 1, GridCellWidth - 1, GridCellWidth - 1);
}



GUI::~GUI()
{
	delete pWind;
}
