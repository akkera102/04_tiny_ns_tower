#include "score.h"
#include "lib/eep.h"
#include "lib/rnd.h"
#include "lib/oled.h"

//---------------------------------------------------------------------------
ST_SCORE Score;


//---------------------------------------------------------------------------
void ScoreInit(void)
{
	_Memset(&Score, 0x00, sizeof(ST_SCORE));

	ScoreInitRnd();
	ScoreLoadBest();
}
//---------------------------------------------------------------------------
void ScoreInitRnd(void)
{
	EepSeek(0x10);
	u32 r = EepRead32();

	if(r != 0)
	{
		RndInitSeed(r);
	}

	EepSeek(0x10);
	EepWrite32(Rnd32());
}
//---------------------------------------------------------------------------
void ScoreDraw(void)
{
	OledDrawStr(21, 0, "Best");
	OledDrawStr(21, 2, " Rec");
	OledDrawStr(21, 4, "Jump");

	OledDrawStr(21, 1, "%4d", Score.best);
	OledDrawStr(21, 3, "%4d", Score.floor);
	OledDrawStr(21, 5, "%4d", Score.jump);
}
//---------------------------------------------------------------------------
void ScoreSaveBest(void)
{
	if(Score.best > Score.floor)
	{
		return;
	}
	Score.best = Score.floor;


	EepSeek(0);

	EepWrite8('N');
	EepWrite8('S');
	EepWrite8('-');
	EepWrite8('T');

	EepWrite16(Score.best);
}
//---------------------------------------------------------------------------
void ScoreLoadBest(void)
{
	Score.best = 0;


	EepSeek(0);

	if(EepRead8() != 'N') return;
	if(EepRead8() != 'S') return;
	if(EepRead8() != '-') return;
	if(EepRead8() != 'T') return;

	Score.best = EepRead16();
}
//---------------------------------------------------------------------------
void ScoreAddFloor(void)
{
	Score.floor++;
}
//---------------------------------------------------------------------------
void ScoreAddJump(void)
{
	Score.jump++;
}
//---------------------------------------------------------------------------
bool ScoreIsEndFloor(void)
{
	return (Score.floor >= 30) ? TRUE : FALSE;
}
//---------------------------------------------------------------------------
void ScoreDebug(void)
{
	EepSeek(0);
	EepWrite32(0);
	EepWrite16(0);

	EepSeek(0x10);
	EepWrite32(0);
}
