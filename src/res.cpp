#include "res.h"
#include "res/img.h"
#include "lib/oled.h"


//---------------------------------------------------------------------------
const unsigned char* ResChrRList[] = {
	bitmapChr1_1,
	bitmapChr1_2,
	bitmapChr1_3,
};

const unsigned char* ResChrLList[] = {
	bitmapChr2_1,
	bitmapChr2_2,
	bitmapChr2_3,
};

const unsigned char* ResBeltRList[] = {
	bitmapBelt1_1,
	bitmapBelt1_2,
	bitmapBelt1_3,
};

const unsigned char* ResBeltLList[] = {
	bitmapBelt2_1,
	bitmapBelt2_2,
	bitmapBelt2_3,
};

const unsigned char* ResSpringList[] = {
	bitmapSpring1_1,	// í èÌ
	bitmapSpring1_2,	// Ç÷Ç±Çﬁ
	bitmapSpring1_3,	// íµÇÀÇÈ
};

const unsigned char* ResGaugeList[] = {
	bitmapGauge1_1,
	bitmapGauge1_2,
	bitmapGauge1_3,
	bitmapGauge1_4,
	bitmapGauge1_5,
	bitmapGauge1_6,
	bitmapGauge1_7,
};

//---------------------------------------------------------------------------
void ResInit(void)
{
	// EMPTY
}
//---------------------------------------------------------------------------
void ResDrawWall(s8 x, s8 y)
{
	OledDrawBmp(x, y, (u8*)bitmapWall);
}
//---------------------------------------------------------------------------
void ResDrawPlate(s8 x, s8 y)
{
	OledDrawBmpPlate(x, y, (u8*)bitmapPlate);
}
//---------------------------------------------------------------------------
void ResDrawPlateBeltL(s8 x, s8 y, u8 num)
{
	ASSERT(num < 3);

	OledDrawBmpPlate(x, y, (u8*)ResBeltLList[num]);
}
//---------------------------------------------------------------------------
void ResDrawPlateBeltR(s8 x, s8 y, u8 num)
{
	ASSERT(num < 3);

	OledDrawBmpPlate(x, y, (u8*)ResBeltRList[num]);
}
//---------------------------------------------------------------------------
void ResDrawSpring(s8 x, s8 y, u8 num)
{
	ASSERT(num < 3);

	OledDrawBmpPlate(x, y, (u8*)ResSpringList[num]);
}
//---------------------------------------------------------------------------
void ResDrawChr(s8 x, s8 y, u8 num, s8 dir)
{
	ASSERT(num < 3);

	if(dir > 0)
	{
		OledDrawBmpPlate(x, y, (u8*)ResChrRList[num]);
	}
	else
	{
		OledDrawBmpPlate(x, y, (u8*)ResChrLList[num]);
	}
}
//---------------------------------------------------------------------------
void ResDrawGauge(u8 num)
{
	ASSERT(num < 7);

	OledDrawBmp(106, 64-8, (u8*)ResGaugeList[num]);
}
