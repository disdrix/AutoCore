// =============================================================================
// FUN_00925670  — scaffold twin of Client_ItemPickup_AutoGatherTick
// -----------------------------------------------------------------------------
// Stable ID: aa_00925670
// Address:   0x00925670 – 0x00925712  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer / client input auto gather
// Generated: 2026-07-29 W24-T (twin of Client_ItemPickup_AutoGatherTick.cpp)
// Exactness: Ghidra-name plate; CF matches raw + live re-seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>

extern uint32_t __stdcall GetTickCount(void);
extern void FUN_0058cd60(void *pairOut, ...);
extern void FUN_00925580(void);

extern uint32_t DAT_00d1f0d4;
extern uint32_t DAT_00d218d4;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00925670(void)
{
  int iVar1;
  int iVar2;
  uint32_t uVar3;
  int in_EAX; /* sealed: client* from EAX at call site */
  uint32_t uVar4;
  uint32_t local_30;
  uint32_t local_2c;

  if (*(int *)(in_EAX + 0xcd0) == 0) {
    DAT_00d218d4 = GetTickCount();
    if (99 < (int)(DAT_00d218d4 - DAT_00d1f0d4)) {
      local_30 = 0xffffffff;
      local_2c = 0xffffffff;
      iVar2 = *(int *)(*(int *)(in_EAX + 4) + 4);
      iVar1 = *(int *)(*(int *)(in_EAX + 4) + 4) + in_EAX;
      uVar3 = *(uint32_t *)(iVar1 + 0xa8);
      DAT_00d1f0d4 = DAT_00d218d4;
      uVar4 = (**(uint32_t(**)(uint32_t, int, int, int, int, int))(
                 *(int *)(iVar1 + 4) + 0x1a0))(0x41a00000, 1, 6, 0, 0, 1);
      FUN_0058cd60(&local_30, 0, uVar3, (void *)(iVar2 + 4 + in_EAX), uVar4);
      if ((local_30 & local_2c) != 0xffffffff) {
        FUN_00925580();
      }
    }
  }
  return;
}
