#include "game.h"
#include "lib/oled.h"
#include "lib/key.h"
#include "score.h"
#include "stage.h"
#include "chr.h"
#include "res.h"
#include "pos.h"
#include "beep.h"

//---------------------------------------------------------------------------
ST_GAME Game;


//---------------------------------------------------------------------------
void GameInit(void)
{
	_Memset(&Game, 0x00, sizeof(ST_GAME));
}
//---------------------------------------------------------------------------
void GameLoop(void)
{
	switch(Game.act)
	{
		case GAME_EXEC_RESET: GameExecReset(); break;
		case GAME_EXEC_PLAY:  GameExecPlay();  break;
		case GAME_EXEC_OVER:  GameExecOver();  break;

		default:
			_SystemError("%x", Game.act);
			break;
	}
}
//---------------------------------------------------------------------------
void GameExecReset(void)
{
	ScoreInit();
	StageInit();
	ChrInit();
	ResInit();
	PosInit();
	BeepInit();

	GameSetAct(GAME_EXEC_PLAY);
}
//---------------------------------------------------------------------------
void GameExecPlay(void)
{
	StageDraw();
	ScoreDraw();
	ChrDraw();

	StageExec();
	ChrExec();

	if(KeyGetTrg() & KEY_U)
	{
		GameSetAct(GAME_EXEC_RESET);
	}


	if(ChrIsEnd() == TRUE || ScoreIsEndFloor() == TRUE)
	{
		GameSetAct(GAME_EXEC_OVER);
	}
}
//---------------------------------------------------------------------------
void GameExecOver(void)
{
	StageDraw();
	ScoreDraw();
	ChrDraw();

	if(ChrIsEnd() == TRUE)
	{
		OledDrawStr(6, 4, "GAME OVER");
	}
	else
	{
		OledDrawStr(6, 4, "COMPLETE!");
	}


	if(KeyGetTrg() & KEY_RESET)
	{
		ScoreSaveBest();
		GameSetAct(GAME_EXEC_RESET);
	}
}
//---------------------------------------------------------------------------
void GameSetAct(u8 act)
{
	Game.act = act;
}
