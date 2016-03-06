#ifndef POS_H
#define POS_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lib/common.h"

//---------------------------------------------------------------------------
#define POS_MAX_CNT					4

enum {
	POS_NONE  = 0x00,
	POS_LEFT  = (1 << 0),
	POS_MID   = (1 << 1),
	POS_RIGHT = (1 << 2),
};

//---------------------------------------------------------------------------

typedef struct {

	u8 idx;
	u8 d[POS_MAX_CNT];

} ST_POS;

//---------------------------------------------------------------------------
void PosInit(void);
void PosAddX(s8 x);
s8   PosGetRndX(void);


#ifdef __cplusplus
}
#endif
#endif
