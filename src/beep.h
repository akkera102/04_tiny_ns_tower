#ifndef BEEP_H
#define BEEP_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lib/common.h"

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
typedef struct {
	bool isOn;
} ST_BEEP;


//---------------------------------------------------------------------------
void BeepInit(void);

void BeepPlay(u16 freq, u32 duration);
void BeepPlayJump(void);
void BeepPlayJumpSpring(void);
void BeepPlayLand(void);

void BeepSetOnOff(void);


#ifdef __cplusplus
}
#endif
#endif
