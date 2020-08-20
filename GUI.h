#pragma once

#include "DEFS.h"
#include "CMUgraphicsLib\CMUgraphics.h"
#include "cell.h"
#include "player.h"



#define WindowWidth		1100
#define WindowHeight	660
#define GridCellWidth	50		
#define ToolBarHeight	50		
#define StatusBarHeight	60		
#define NumColumnCells	WindowWidth/ GridCellWidth	
#define NumRowCells	(WindowHeight-ToolBarHeight-StatusBarHeight)/GridCellWidth			

enum GUI_MODE	
{
	MODE_MENU,	
	MODE_GAME   
};

enum MENU_ITEMS 
{
	

	ITM_LOAD,
	ITM_SAVE,
	ITM_START,
	ITM_EXIT,
	ITM_PlayerCell,
	ITM_EmptyCell,
	ITM_ObstacleCell,
	ITM_EnemyCell,
	ITM_GoalCell,

	MENU_ITM_COUNT		
};

enum GAME_ITEMS 
{
	

	ITM_CHOOSE_GRID,

	

	PLAY_ITM_COUNT		
};





class GUI
{

private:
	window *pWind;	

	GUI_MODE InterfaceMode;




	static const int

		MenuItemWidth = 50,		

		WindWidth = WindowWidth,		
		WindHeight = WindowHeight; 

	color MsgColor;			
	color BkGrndColor;		
	color StatusBarColor;	

	color GridLineColor;	
	color ObstacleColor;	



public:
	GUI();

	Cell* GetClickCell(int &x, int &y);

	void GetPointClicked(int &x, int &y, bool wait = true) const; 


	string GetSrting() const; 

	ActionType GetUserAction() const;	 

	GUI_MODE getInterfaceMode() const;
	void setInterfaceMode(GUI_MODE);

	void ClearStatusBar() const;	
	void ClearGridArea() const;	    

	void CreateMenu(); 	
	void CreateGameModeToolBar(); 	

	void PrintMessage(string msg) const;	

	

	void DrawCell(const Cell *cell) const;		
																  
	void ClearCell(const Cell & cell) const; 

	~GUI();
};