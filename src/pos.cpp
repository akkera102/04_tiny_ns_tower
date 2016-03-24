#include "pos.h"
#include "lib/rnd.h"

//---------------------------------------------------------------------------
ST_POS Pos;


//---------------------------------------------------------------------------
void PosInit(void)
{
	_Memset(&Pos, 0x00, sizeof(ST_POS));
}
//---------------------------------------------------------------------------
void PosAddX(s8 x)
{
	u8 d;

	if(x <= 12 + 8)
	{
		d = POS_LEFT;
	}
	else if(x >= 68 - 8)
	{
		d = POS_RIGHT;
	}
	else
	{
		d = POS_MID;
	}

	Pos.d[Pos.idx] = d;

	Pos.idx++;
	Pos.idx %= POS_MAX_CNT;
}
//---------------------------------------------------------------------------
// 履歴から不足しているブロックの位置（x座標）を返します
s8 PosGetRndX(void)
{
	u8 i;
	u8 d = 0;

	for(i=0; i<POS_MAX_CNT; i++)
	{
		d |= Pos.d[i];
	}


	if(!(d & POS_LEFT))
	{
		return Rnd(3) * 4 + 4;
	}

	if(!(d & POS_MID))
	{
		return Rnd(3) * 4 + (8 * 4) + 4;
	}

	if(!(d & POS_RIGHT))
	{
		return Rnd(3) * 4 + (16 * 4) + 4;
	}

	return Rnd(18 + 1) * 4 + 4;
}
