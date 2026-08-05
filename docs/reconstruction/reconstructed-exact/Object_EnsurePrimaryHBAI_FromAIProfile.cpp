// =============================================================================
// Object_EnsurePrimaryHBAI_FromAIProfile
// -----------------------------------------------------------------------------
// Purpose:  Ensure host object has a primary HBAI/HB at +0x1fc by looking up
//           the AI profile map (key param_3 or def+0x4dc), allocating the
//           profile-type-specific subclass, enqueuing on CVOGHBList, and
//           Start (or Stop when deferred + host flag). Optional secondary
//           period--1000 HB when def+0x4e8==1. Skill-effect refresh when
//           clone type != 0x14.
//
// Address:  0x004c9430  (autoassault.exe, image base 0x400000)
// Body:     0x004c9430 – 0x004c96a9 (634 B, RET 8)
// Stable:   aa_004c9430
// System:   npc-ai / host HB list / AI profile map
// Ghidra:   FUN_004c9430
//
// Convention: MSVC __thiscall + SEH
//   this   host object*
//   stack  char deferStopIfHostFlag, char profileKeyOrMinus1
//   ret    this+mi (or skill-refresh surface); RET 8
//
// Dual A/B: 2026-07-29 W27-I accept-with-gaps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// =============================================================================

#include <stdint.h>

struct CVOGHBBase {
  void **pVTable;
  // ...
  char cStopped;  // used at +0x20 in decompiler field access
};

extern void *ExceptionList;
extern void *DAT_00b041fc;  // host for AI profile map
extern void *operator_new(uint32_t size);

extern uint32_t __thiscall Host_AIProfileMap_GetOrReset(void *host, char forceReset); // FUN_00540890
extern void __thiscall Map_LowerBoundFindByIntKey_Isnil65(void *map, void **pOutIt, void *pKey); // FUN_004cbd50
extern uint32_t __thiscall CVOGHBList_Enqueue(void *list, CVOGHBBase *hb); // FUN_005078f0
extern void __thiscall CVOGHBBase_Start(CVOGHBBase *hb); // FUN_005081c0
extern void __thiscall CVOGHBBase_Stop(CVOGHBBase *hb);  // FUN_005081d0
extern void *__thiscall Object_RefreshActiveSkillEffects_Inferred(void *obj, char includeZeroRank); // FUN_00516a00

extern CVOGHBBase *__thiscall FUN_005d8330(void *owner); // profile type 2
extern CVOGHBBase *__thiscall FUN_005d7f50(void *owner); // type 3
extern CVOGHBBase *__thiscall FUN_005d7de0(void *owner); // type 4
extern CVOGHBBase *__thiscall FUN_005d7bb0(void *owner); // type 5
extern CVOGHBBase *__thiscall FUN_005d6da0(void *owner); // default
extern CVOGHBBase *__thiscall FUN_005d6b80(void *owner); // secondary 0x28

void *__thiscall Object_EnsurePrimaryHBAI_FromAIProfile(
    void *self,
    char deferStopIfHostFlag,
    char profileKeyOrMinus1)
{
  void *local_10; // map iterator / node*
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  CVOGHBBase *hb;
  void *ret;
  int mi;
  int map;
  void **ppIt;
  uint8_t *pKey;

  local_4 = 0xffffffff;
  puStack_8 = (uint8_t *)0x009a1c71; // LAB_009a1c71
  local_c = ExceptionList;

  if (*(int *)((char *)self + 0x1fc) != 0) {
    // Early shared epilogue (decompiler ExceptionList residual)
    return ExceptionList;
  }

  if (profileKeyOrMinus1 == -1) {
    profileKeyOrMinus1 = *(char *)(
        *(int *)(*(int *)(*(int *)(*(int *)((char *)self + 4) + 4) + 0xac + (int)self) + 0x3c) +
        0x4dc);
  }

  pKey = (uint8_t *)&profileKeyOrMinus1;
  ppIt = &local_10;
  ExceptionList = &local_c;
  local_10 = self;

  Host_AIProfileMap_GetOrReset(DAT_00b041fc, 0);
  Map_LowerBoundFindByIntKey_Isnil65(/*map this from prior*/, ppIt, pKey);
  map = (int)Host_AIProfileMap_GetOrReset(DAT_00b041fc, 0);
  if (local_10 == *(void **)(map + 4)) {
    ExceptionList = local_c;
    return local_10;
  }

  *(int *)((char *)self + 0x200) =
      1 << (*(uint8_t *)((char *)local_10 + 0x10) & 0x1f);

  switch (*(uint16_t *)((char *)local_10 + 0x10)) {
  case 2:
    local_4 = 0;
    hb = (operator_new(0xC0) != 0) ? FUN_005d8330(self) : 0;
    break;
  case 3:
    local_4 = 1;
    hb = (operator_new(0xB0) != 0) ? FUN_005d7f50(self) : 0;
    break;
  case 4:
    local_4 = 2;
    hb = (operator_new(0xC0) != 0) ? FUN_005d7de0(self) : 0;
    break;
  case 5:
    local_4 = 3;
    hb = (operator_new(0xC0) != 0) ? FUN_005d7bb0(self) : 0;
    break;
  default:
    local_4 = 4;
    hb = (operator_new(0xB0) != 0) ? FUN_005d6da0(self) : 0;
    break;
  }

  local_4 = 0xffffffff;
  if (hb != 0) {
    if (hb->cStopped == 0) {
      *(CVOGHBBase **)((char *)self + 0x1fc) = hb;
      CVOGHBList_Enqueue(
          *(void **)(*(int *)(*(int *)(*(int *)((char *)self + 4) + 4) + 0xa8 + (int)self) +
                     0xe4ec),
          hb);
      if (deferStopIfHostFlag == 0 &&
          *(char *)(*(int *)(*(int *)(*(int *)((char *)self + 4) + 4) + 0xa8 + (int)self) + 0x7e) !=
              0) {
        CVOGHBBase_Stop(hb);
      } else {
        CVOGHBBase_Start(hb);
      }
    } else {
      ((void(__thiscall *)(CVOGHBBase *, int))hb->pVTable[0])(hb, 1);
    }
  }

  if (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)((char *)self + 4) + 4) + 0xac + (int)self) +
                       0x3c) +
               0x4e8) == 1) {
    local_4 = 5;
    hb = (operator_new(0x28) != 0) ? FUN_005d6b80(self) : 0;
    local_4 = 0xffffffff;
    CVOGHBList_Enqueue(
        *(void **)(*(int *)(*(int *)(*(int *)((char *)self + 4) + 4) + 0xa8 + (int)self) + 0xe4ec),
        hb);
    CVOGHBBase_Start(hb);
  }

  mi = *(int *)(*(int *)((char *)self + 4) + 4);
  ret = (void *)(mi + (int)self);
  if (*(int *)(*(int *)(mi + 0xac + (int)self) + 0x38) != 0x14) {
    // Bytes: LEA ECX,[eax+4]; PUSH 0; CALL FUN_00516a00
    ret = Object_RefreshActiveSkillEffects_Inferred((char *)ret + 4, 0);
  }

  ExceptionList = local_c;
  return ret;
}
