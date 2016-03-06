#ifndef STAGE_H
#define STAGE_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lib/common.h"

//---------------------------------------------------------------------------
#define STAGE_DATA_MAX_CNT			16

enum {
	STAGE_TYPE_PLATE,
	STAGE_TYPE_MOVE_LR,
	STAGE_TYPE_MOVE_UD,
	STAGE_TYPE_BELT_L,
	STAGE_TYPE_BELT_R,
	STAGE_TYPE_SPRING,
};

//---------------------------------------------------------------------------

typedef struct {
	bool isUse;
	u8   type;
	s8   x;
	s8   y;
	s8   ix;
	s8   iy;

} ST_STAGE_DATA;


typedef struct {

	u8 idx;
	ST_STAGE_DATA d[STAGE_DATA_MAX_CNT];

	s8 wallSy;

	u8 beltCnt;
	u8 moveCnt;
	u8 floorCnt;

} ST_STAGE;

//---------------------------------------------------------------------------
void StageInit(void);
void StageExec(void);
void StageExecPlate(void);
void StageExecCnt(void);

void StageAddPlate(s8 bx, s8 by, u8 type);
void StageAddScroll(s8 y);

void StageDraw(void);
void StageDrawWall(void);
void StageDrawPlate(void);

bool StageIsHit(s8 sx, s8 sy, s8 scx, s8 scy, s8 dx, s8 dy, s8 dcx, s8 dcy);
bool StageIsHitPlateX(s8 sx, s8 scx, u8 num);
bool StageIsHitPlate(s8 x, s8 y, s8 cx, s8 cy, s8 my);
bool StageIsPlateTypeBeltL(u8 num);
bool StageIsPlateTypeBeltR(u8 num);
bool StageIsPlateTypeMoveUD(u8 num);
bool StageIsPlateTypeSpring(u8 num);

u8   StageGetHitPlateNo(s8 x, s8 y, s8 cx, s8 cy, s8 my);
s8   StageGetPlateY(u8 num);
u8   StageGetRndType(void);


#ifdef __cplusplus
}
#endif
#endif
