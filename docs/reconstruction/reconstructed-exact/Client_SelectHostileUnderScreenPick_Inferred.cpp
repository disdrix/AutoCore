// =============================================================================
// Client_SelectHostileUnderScreenPick_Inferred  (was FUN_00921f70)
// -----------------------------------------------------------------------------
// Stable ID: aa_00921f70
// Address:   0x00921f70–0x009221de  (autoassault.exe, image base 0x400000)
// System:    interaction-activation / client target pick
// Generated: 2026-07-29 W20-Q dual A/B seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual: reviews/A|B_aa_00921f70_Client_SelectHostileUnderScreenPick_Inferred.md
// =============================================================================
//
// PURPOSE:
//   Unproject screen cursor to world ray, intersect height helper, distance-scale
//   gather radius (0.015*25*dist, cap 40), gather one hostile (mode 2), select
//   via Client_SelectTargetObject_Inferred (or clear).
//
// NAME: INFERRED — no product string. Constants byte-sealed.
// =============================================================================

// External
// void GfxView_UnprojectScreenToWorldRay_Inferred(void *this, int *screenXY,
//                                                 float *outOrigin, float *outDir);
// long double FUN_004cd220(float x, float z);
// float *Math_CopyFloat3ToFloat4_Inferred(float *a, float *b);
// void Skill_GatherTargetsInArea(TFID_16 *out, ..., float range, int maxTargets,
//                                int mode, ...);
// int TFID_NotEquals(TFID_16 *a, void *b);
// void *Object_ResolveFromTFID(TFID_16 *id);
// void Client_SelectTargetObject_Inferred(void *objOrNull);
//
// Globals:
//   DAT_00d1b6d8  local character*
//   DAT_00d1d86c / DAT_00d1d870  screen int x/y
//   DAT_00d17944  ref object (+0x228 position)
//   DAT_00a158b8  null TFID sentinel
//   _DAT_00aaacbc = 0.015f
//   DAT_00aaa6fc  = 25.0f
//   DAT_00a1109c  = 40.0f

#include <cmath>
#include <cstdint>

struct TFID_16 {
  uint32_t dwCoidLo;
  uint32_t dwCoidHi;
  uint8_t bGlobal;
  uint8_t bPad0, bPad1, bPad2, bPad3, bPad4, bPad5, bPad6;
};

extern void *DAT_00d1b6d8;
extern int DAT_00d1d86c;
extern int DAT_00d1d870;
extern void *DAT_00d17944;
extern uint32_t DAT_00a158b8, DAT_00a158bc, DAT_00a158c0, DAT_00a158c4;
extern float _DAT_00aaacbc; // 0.015f
extern float DAT_00aaa6fc;  // 25.0f
extern float DAT_00a1109c;  // 40.0f

uint32_t Client_SelectHostileUnderScreenPick_Inferred(void)
{
  float screenXY[2];
  float rayOrigin[3];
  float rayDir[3];
  float hit[3];
  float float4[4];
  float *pf;
  float t;
  float dx, dy, dz;
  float range;
  long double h;
  TFID_16 outTfid;
  void *obj;
  int casterAdj;
  int notEq;
  void *charObj;

  charObj = DAT_00d1b6d8;
  if (charObj == nullptr || *(char *)((char *)charObj + 0x4f1) != '\0') {
    return 0;
  }

  screenXY[0] = (float)DAT_00d1d86c;
  screenXY[1] = (float)DAT_00d1d870;
  // retail: ECX = active gfx view; stack: &screen, &origin, &dir
  GfxView_UnprojectScreenToWorldRay_Inferred(
      /*this*/ nullptr, (int *)screenXY, rayOrigin, rayDir);

  h = FUN_004cd220(rayOrigin[0], rayOrigin[2]);
  t = (float)(((long double)rayOrigin[1] - h) / fabs((long double)rayDir[1]));
  hit[0] = rayDir[0] * t + rayOrigin[0];
  hit[1] = rayDir[1] * t + rayOrigin[1];
  hit[2] = rayDir[2] * t + rayOrigin[2];

  pf = Math_CopyFloat3ToFloat4_Inferred(rayDir, hit);
  float4[0] = pf[0];
  float4[1] = pf[1];
  float4[2] = pf[2];
  float4[3] = pf[3];

  dx = float4[0] - *(float *)((char *)DAT_00d17944 + 0x228);
  dy = float4[1] - *(float *)((char *)DAT_00d17944 + 0x22c);
  dz = float4[2] - *(float *)((char *)DAT_00d17944 + 0x230);
  range = sqrtf(dz * dz + dy * dy + dx * dx) * _DAT_00aaacbc * DAT_00aaa6fc;
  if (DAT_00a1109c <= range) {
    range = DAT_00a1109c;
  }

  // seed null TFID
  outTfid.dwCoidLo = DAT_00a158b8;
  outTfid.dwCoidHi = DAT_00a158bc;
  outTfid.bGlobal = (uint8_t)DAT_00a158c0;
  outTfid.bPad0 = (uint8_t)(DAT_00a158c0 >> 8);
  outTfid.bPad1 = (uint8_t)(DAT_00a158c0 >> 16);
  outTfid.bPad2 = (uint8_t)(DAT_00a158c0 >> 24);
  outTfid.bPad3 = (uint8_t)DAT_00a158c4;
  outTfid.bPad4 = (uint8_t)(DAT_00a158c4 >> 8);
  outTfid.bPad5 = (uint8_t)(DAT_00a158c4 >> 16);
  outTfid.bPad6 = (uint8_t)(DAT_00a158c4 >> 24);

  if (DAT_00d1b6d8 == nullptr) {
    casterAdj = 0;
  } else {
    casterAdj = *(int *)(*(int *)((char *)DAT_00d1b6d8 + 4) + 4) + 4 +
                (int)(intptr_t)DAT_00d1b6d8;
  }

  Skill_GatherTargetsInArea(
      &outTfid, 0,
      *(uint32_t *)(*(int *)(*(int *)((char *)DAT_00d1b6d8 + 4) + 4) + 0xa8 +
                    (int)(intptr_t)DAT_00d1b6d8),
      casterAdj, float4, range,
      /*maxTargets*/ 1,
      /*mode*/ 2,
      /*filterA*/ 0,
      /*chainRefresh*/ 0,
      /*allowSelfMode1*/ 1,
      /*filterB*/ 0,
      /*filterC*/ 1,
      /*sort*/ 0,
      /*scoreArg*/ -1.0f);

  notEq = TFID_NotEquals(&outTfid, &DAT_00a158b8);
  if ((char)notEq == '\0') {
    Client_SelectTargetObject_Inferred(nullptr);
  } else {
    obj = Object_ResolveFromTFID(&outTfid);
    if (obj != nullptr) {
      Client_SelectTargetObject_Inferred(obj);
      return 1;
    }
  }
  return 1;
}
