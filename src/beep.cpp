#include "beep.h"
#include "lib/snd.h"


//---------------------------------------------------------------------------
ST_BEEP Beep;


//---------------------------------------------------------------------------
void BeepInit(void)
{
	_Memset(&Beep, 0x00, sizeof(ST_BEEP));

	Beep.isOn = TRUE;
}
//---------------------------------------------------------------------------
void BeepPlay(u16 freq, u32 duration)
{
	if(Beep.isOn == FALSE)
	{
		return;
	}

	SndPlayTone(freq, duration);
}
//---------------------------------------------------------------------------
void BeepPlayJump(void)
{
	BeepPlay(330, 50);
}
//---------------------------------------------------------------------------
void BeepPlayJumpSpring(void)
{
	BeepPlay(1319, 50);
}
//---------------------------------------------------------------------------
void BeepPlayLand(void)
{
	BeepPlay(175, 50);
}
//---------------------------------------------------------------------------
void BeepSetOnOff(void)
{
	if(Beep.isOn == TRUE)
	{
		Beep.isOn = FALSE;
	}
	else
	{
		Beep.isOn = TRUE;
	}
}
