#include "stage.h"
#include <avr/pgmspace.h>
#include "lib/oled.h"
#include "lib/frame.h"
#include "lib/rnd.h"
#include "pos.h"
#include "res.h"
#include "score.h"

//---------------------------------------------------------------------------
PROGMEM const s8 StageMoveList[] = {
	 1,  1,  1,
	 3,  3,
	 5,
	 7,  7,
	 8,  8,  8,

	 8,  8,  8,
	 7,  7,
	 5,
	 3,  3,
	 1,  1,  1,

	-1, -1, -1,
	-3, -3,
	-5,
	-7, -7,
	-8, -8, -8,

	-8, -8, -8,
	-7, -7,
	-5,
	-3, -3,
	-1, -1, -1,
};

//---------------------------------------------------------------------------
ST_STAGE Stage;


//---------------------------------------------------------------------------
void StageInit(void)
{
	_Memset(&Stage, 0x00, sizeof(ST_STAGE));


	StageAddPlate( 4, 60, STAGE_TYPE_PLATE);
	StageAddPlate(28, 60, STAGE_TYPE_PLATE);
	StageAddPlate(52, 60, STAGE_TYPE_PLATE);
	StageAddPlate(76, 60, STAGE_TYPE_PLATE);

	s8 y;

	for(y=13; y>=-2; y-=2)
	{
		StageAddPlate(PosGetRndX(), y * 4, StageGetRndType());
	}
}
//---------------------------------------------------------------------------
void StageExec(void)
{
	StageExecPlate();
	StageExecCnt();
}
//---------------------------------------------------------------------------
void StageExecPlate(void)
{
	u8 i;

	for(i=0; i<STAGE_DATA_MAX_CNT; i++)
	{
		ST_STAGE_DATA* p = &Stage.d[i];

		if(p->isUse == FALSE)
		{
			continue;
		}

		if(p->type == STAGE_TYPE_MOVE_LR)
		{
			p->x = p->ix + __LPM(StageMoveList + Stage.moveCnt);
		}

		if(p->type == STAGE_TYPE_MOVE_UD)
		{
			p->y = p->iy + __LPM(StageMoveList + Stage.moveCnt);
		}

		if(Stage.d[i].y >= OLED_SCREEN_CY+8)
		{
			Stage.d[i].isUse = FALSE;
		}
	}
}
//---------------------------------------------------------------------------
void StageExecCnt(void)
{
	if(FrameIsMod(6) == FALSE)
	{
		return;
	}

	Stage.beltCnt++;
	Stage.beltCnt %= 3;

	Stage.moveCnt++;
	Stage.moveCnt %= 44;
}
//---------------------------------------------------------------------------
void StageAddPlate(s8 x, s8 y, u8 type)
{
	PosAddX(x);


	ST_STAGE_DATA* p = &Stage.d[Stage.idx];

	p->isUse = TRUE;
	p->type  = type;
	p->x     = x;
	p->ix    = x;
	p->y     = y;
	p->iy    = y;

	Stage.idx++;
	Stage.idx %= STAGE_DATA_MAX_CNT;
}
//---------------------------------------------------------------------------
void StageAddScroll(s8 y)
{
	u8 i;

	for(i=0; i<STAGE_DATA_MAX_CNT; i++)
	{
		if(Stage.d[i].isUse == FALSE)
		{
			continue;
		}

		Stage.d[i].y  += y;
		Stage.d[i].iy += y;
	}

	s8 prev = (Stage.wallSy);
	s8 next = (Stage.wallSy + y) % 8;

	if(prev - next >= 0)
	{
		StageAddPlate(PosGetRndX(), -4 + y, StageGetRndType());
	}

	Stage.wallSy = next;


	Stage.floorCnt += y;

	if(Stage.floorCnt >= 32)
	{
		Stage.floorCnt -= 32;
		ScoreAddFloor();
	}
}
//---------------------------------------------------------------------------
void StageDraw(void)
{
	StageDrawWall();
	StageDrawPlate();
}
//---------------------------------------------------------------------------
void StageDrawWall(void)
{
	s8 y;

	for(y=-8+Stage.wallSy; y<OLED_SCREEN_CY; y+=8)
	{
		ResDrawWall(  0, y);
		ResDrawWall(100, y);
	}
}
//---------------------------------------------------------------------------
void StageDrawPlate(void)
{
	u8 i;

	for(i=0; i<STAGE_DATA_MAX_CNT; i++)
	{
		ST_STAGE_DATA* p = &Stage.d[i];

		if(p->isUse == FALSE)
		{
			continue;
		}

		switch(p->type)
		{
		case STAGE_TYPE_PLATE:
		case STAGE_TYPE_MOVE_LR:
		case STAGE_TYPE_MOVE_UD:
			ResDrawPlate(p->x, p->y);
			break;

		case STAGE_TYPE_BELT_L:
			ResDrawPlateBeltL(p->x, p->y, Stage.beltCnt);
			break;

		case STAGE_TYPE_BELT_R:
			ResDrawPlateBeltR(p->x, p->y, Stage.beltCnt);
			break;

		case STAGE_TYPE_SPRING:
			ResDrawSpring(p->x, p->y, 0);
			break;

		default:
			_SystemError("%x %x", Stage.idx, p->type);
			break;
		}
	}
}
//---------------------------------------------------------------------------
bool StageIsHit(s8 sx, s8 sy, s8 scx, s8 scy, s8 dx, s8 dy, s8 dcx, s8 dcy)
{
	if((sy < dy + dcy) && (dy < sy + scy))
	{
		if((sx < dx + dcx) && (dx < sx + scx))
		{
			return TRUE;
		}
	}

	return FALSE;
}
//---------------------------------------------------------------------------
bool StageIsHitX(s8 sx, s8 scx, u8 num)
{
	s8 dx  = Stage.d[num].x;
	s8 dcx = 24;

	if((sx < dx + dcx) && (dx < sx + scx))
	{
		return TRUE;
	}

	return FALSE;
}
//---------------------------------------------------------------------------
bool StageIsHitPlate(s8 x, s8 y, s8 cx, s8 cy, s8 my)
{
	return (StageGetHitPlateNo(x, y, cx, cy, my) != STAGE_DATA_MAX_CNT) ? TRUE : FALSE;
}
//---------------------------------------------------------------------------
bool StageIsPlateTypeBeltL(u8 num)
{
	return (Stage.d[num].type == STAGE_TYPE_BELT_L) ? TRUE : FALSE;
}
//---------------------------------------------------------------------------
bool StageIsPlateTypeBeltR(u8 num)
{
	return (Stage.d[num].type == STAGE_TYPE_BELT_R) ? TRUE : FALSE;
}
//---------------------------------------------------------------------------
bool StageIsPlateTypeMoveUD(u8 num)
{
	return (Stage.d[num].type == STAGE_TYPE_MOVE_UD) ? TRUE : FALSE;
}
//---------------------------------------------------------------------------
bool StageIsPlateTypeSpring(u8 num)
{
	return (Stage.d[num].type == STAGE_TYPE_SPRING) ? TRUE : FALSE;
}
//---------------------------------------------------------------------------
// ヒットしたブロック番号を返します。この関数を実行する前にStageIsHitPlateを実行してください
// ブロックが複数あった場合、出現が後の方（上層階）を優先します
u8 StageGetHitPlateNo(s8 x, s8 y, s8 cx, s8 cy, s8 my)
{
	ASSERT(my != 0);


	u8 i, j;
	u8 r = STAGE_DATA_MAX_CNT;
	u8 idx = Stage.idx;

	for(i=0; i<my; i++)
	{
		for(j=0; j<STAGE_DATA_MAX_CNT; j++)
		{
			if(Stage.d[idx].isUse == TRUE)
			{
				if(StageIsHit(x, y + i, cx, cy, Stage.d[idx].x, Stage.d[idx].y, 24, 4) == TRUE)
				{
					r  = idx;
				}
			}

			idx++;
			idx %= STAGE_DATA_MAX_CNT;
		}
	}

	return r;
}
//---------------------------------------------------------------------------
s8 StageGetPlateY(u8 num)
{
	return Stage.d[num].y;
}
//---------------------------------------------------------------------------
u8 StageGetRndType(void)
{
	switch(Rnd(20))
	{
	case 0:
	case 1:
		return STAGE_TYPE_MOVE_LR;

	case 2:
	case 3:
		return STAGE_TYPE_MOVE_UD;

	case 4:
	case 5:
		return STAGE_TYPE_BELT_L;

	case 6:
	case 7:
		return STAGE_TYPE_BELT_R;

	case 8:
	case 9:
	case 10:
		return STAGE_TYPE_SPRING;
	}

	return STAGE_TYPE_PLATE;
}
