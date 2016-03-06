#ifndef CHR_H
#define CHR_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lib/common.h"

//---------------------------------------------------------------------------
#define CHR_MAX_POW_CNT				6
#define CHR_SCROLL_Y				16

enum {
	CHR_STATE_MOVE,
	CHR_STATE_JUMP,
	CHR_STATE_FALL,
};

//---------------------------------------------------------------------------
typedef struct {
	u8  state;
	s16 fx;
	s16 fy;
	s16 fmx;
	s16 fmy;
	s8  cx;
	s8  cy;
	s8  dir;
	u8  pow;
	u8  plateNo;

	u8  animeCnt;

} ST_CHR;

//---------------------------------------------------------------------------
void ChrInit(void);
void ChrExec(void);
void ChrExecCalcX(void);
void ChrExecCalcY(void);

void ChrExecMove(void);
void ChrExecJump(void);
void ChrExecFall(void);
void ChrExecFmx(void);

void ChrDraw(void);
void ChrDrawUnit(void);
void ChrDrawGauge(void);

bool ChrIsEnd(void);
void ChrGetFmx(void);


#ifdef __cplusplus
}
#endif
#endif
