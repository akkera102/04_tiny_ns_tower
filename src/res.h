#ifndef RES_H
#define RES_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lib/common.h"

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void ResInit(void);

void ResDrawWall(s8 x, s8 y);
void ResDrawPlate(s8 x, s8 y);
void ResDrawPlateBeltL(s8 x, s8 y, u8 num);
void ResDrawPlateBeltR(s8 x, s8 y, u8 num);
void ResDrawSpring(s8 x, s8 y, u8 num);
void ResDrawChr(s8 x, s8 y, u8 num, s8 dir);
void ResDrawGauge(u8 num);


#ifdef __cplusplus
}
#endif
#endif
