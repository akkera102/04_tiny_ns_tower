#include "chr.h"
#include "lib/oled.h"
#include "lib/key.h"
#include "lib/frame.h"
#include "res.h"
#include "stage.h"
#include "score.h"
#include "beep.h"


//---------------------------------------------------------------------------
ST_CHR Chr;


//---------------------------------------------------------------------------
void ChrInit(void)
{
	_Memset(&Chr, 0x00, sizeof(ST_CHR));

	Chr.fx  = NUM2FIX(4);
	Chr.fy  = NUM2FIX(52);
	Chr.fmx = 120;
	Chr.fmy = 0;
	Chr.cx  = 8;
	Chr.cy  = 8;
	Chr.dir = 1;
}
//---------------------------------------------------------------------------
void ChrExec(void)
{
	ChrExecCalcX();
	ChrExecCalcY();
}
//---------------------------------------------------------------------------
void ChrExecCalcX(void)
{
	Chr.fx += Chr.fmx * Chr.dir;

	if(Chr.fx < NUM2FIX(4+1))
	{
		Chr.fx = NUM2FIX(4+1);
		Chr.dir *= -1;
	}

	if(Chr.fx >= NUM2FIX(100 - Chr.cx - 1))
	{
		Chr.fx = NUM2FIX(100 - Chr.cx - 1);
		Chr.dir *= -1;
	}

	ChrExecFmx();
}
//---------------------------------------------------------------------------
void ChrExecCalcY(void)
{
	switch(Chr.state)
	{
	case CHR_STATE_MOVE: ChrExecMove(); break;
	case CHR_STATE_JUMP: ChrExecJump(); break;
	case CHR_STATE_FALL: ChrExecFall(); break;

	default:
		_SystemError("%x", Chr.state);
		break;
	}
}
//---------------------------------------------------------------------------
void ChrExecMove(void)
{
	// プレートの上に乗っているか、x座標分のみ判定を行います
	if(StageIsHitX(FIX2NUM(Chr.fx), Chr.cx, Chr.plateNo) == FALSE)
	{
		Chr.state = CHR_STATE_FALL;
		ChrExecFall();

		return;
	}


	// 上下プレートの場合、y座標の補正とスクロール処理をします
	if(StageIsPlateTypeMoveUD(Chr.plateNo) == TRUE)
	{
		s8 by  = StageGetPlateY(Chr.plateNo);
		Chr.fy = NUM2FIX(by - 8);

		if(FIX2NUM(Chr.fy) < CHR_SCROLL_Y)
		{
			s8 sy = CHR_SCROLL_Y - FIX2NUM(Chr.fy);

			StageAddScroll(sy);
			Chr.fy += NUM2FIX(sy);
		}
	}


	if(KeyGetCnt() & KEY_JUMP)
	{
		if(FrameIsMod(3) == TRUE)
		{
			Chr.pow++;
			Chr.pow %= 7;
		}

		return;
	}

	if(KeyGetOff() & KEY_JUMP)
	{
		if(StageIsPlateTypeSpring(Chr.plateNo) == TRUE)
		{
			Chr.fmy = (Chr.pow * 200 + 200) * -1;
			BeepPlayJumpSpring();
		}
		else
		{
			Chr.fmy = (Chr.pow * 150 + 200) * -1;
			BeepPlayJump();
		}

		ScoreAddJump();

		Chr.state = CHR_STATE_JUMP;
		ChrExecJump();

		return;
	}
}
//---------------------------------------------------------------------------
void ChrExecJump(void)
{
	if(Chr.fmy > 0)
	{
		Chr.state = CHR_STATE_FALL;
		ChrExecFall();

		return;
	}

	Chr.fmy += 50;
	Chr.fy  += Chr.fmy;

	// 画面スクロール判定
	if(FIX2NUM(Chr.fy) < CHR_SCROLL_Y)
	{
		s8 sy = CHR_SCROLL_Y - FIX2NUM(Chr.fy);

		StageAddScroll(sy);
		Chr.fy += NUM2FIX(sy);

		return;
	}
}
//---------------------------------------------------------------------------
void ChrExecFall(void)
{
	s8 x  = FIX2NUM(Chr.fx);
	s8 y  = FIX2NUM(Chr.fy);
	s8 my = FIX2NUM(Chr.fmy);


	// 落下先にプレートがあるかチェックします
	if(StageIsHitPlate(x, y + Chr.cy, Chr.cx, 1, my + 1) == FALSE)
	{
		Chr.fmy += 50;
		Chr.fy  += Chr.fmy;

		return;
	}

	Chr.plateNo = StageGetHitPlateNo(x, y + Chr.cy, Chr.cx, 1, my + 1);
	ChrExecFmx();

	if(Chr.fmy != 0)
	{
		BeepPlayLand();
	}

	Chr.fy  = NUM2FIX(StageGetPlateY(Chr.plateNo) - Chr.cy);
	Chr.fmy = 0;
	Chr.pow = 0;

	Chr.state = CHR_STATE_MOVE;
}
//---------------------------------------------------------------------------
void ChrExecFmx(void)
{
	if(StageIsPlateTypeBeltL(Chr.plateNo) == TRUE)
	{
		if(Chr.dir > 0) Chr.fmx = 100;
		else            Chr.fmx = 140;

		return;
	}

	if(StageIsPlateTypeBeltR(Chr.plateNo) == TRUE)
	{
		if(Chr.dir > 0) Chr.fmx = 140;
		else            Chr.fmx = 100;

		return;
	}

	Chr.fmx = 120;
}
//---------------------------------------------------------------------------
void ChrDraw(void)
{
	ChrDrawUnit();
	ChrDrawGauge();
}
//---------------------------------------------------------------------------
void ChrDrawUnit(void)
{
	if(ChrIsEnd() == TRUE)
	{
		return;
	}

	if(Chr.state == CHR_STATE_MOVE && FrameIsMod(10) == TRUE)
	{
		Chr.animeCnt++;
		Chr.animeCnt %= 3;
	}

	ResDrawChr(FIX2NUM(Chr.fx), FIX2NUM(Chr.fy), Chr.animeCnt, Chr.dir);
}
//---------------------------------------------------------------------------
void ChrDrawGauge(void)
{
	ResDrawGauge(Chr.pow);
}
//---------------------------------------------------------------------------
bool ChrIsEnd(void)
{
	return (FIX2NUM(Chr.fy) >= OLED_SCREEN_CY) ? TRUE : FALSE;
}
