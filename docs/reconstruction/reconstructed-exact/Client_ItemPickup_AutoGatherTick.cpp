// =============================================================================
// Client_ItemPickup_AutoGatherTick  (Ghidra: FUN_00925670)
// -----------------------------------------------------------------------------
// Stable ID: aa_00925670
// Address:   0x00925670 – 0x00925712  (163 B; autoassault.exe base 0x400000)
// System:    inventory-transfer / client input auto gather
// Generated: 2026-07-29 W24-T OWN-ONLY dual (decompile + read_memory)
// Exactness: Behavior-preserving CF. ABI sealed from bytes + sole call site.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Periodic auto item-pickup gather tick (~100 ms), always invoked from
 * Client_Input_PollBoundActions (not Activate-edge gated).
 *
 * On throttle hit: Skill_GatherTargetsRadiusMap family @ 20.0f / mode 6;
 * if TFID pair valid, Client_SendItemPickup (C2S 0x2055 size 0x30).
 *
 * ABI: EAX = client* (DAT_00d1b6d8 at call site); stack formal cleaned (RET 4)
 * but unused in body; ESI = &pair before SendItemPickup.
 */

#include <stdint.h>

extern uint32_t __stdcall GetTickCount(void);
extern void FUN_0058cd60(void *pairOut, ...);
extern void FUN_00925580(void); /* Client_SendItemPickup; ESI = uint32_t pair[2] */

extern uint32_t DAT_00d1f0d4; /* throttle stamp */
extern uint32_t DAT_00d218d4; /* last GetTickCount sample */

void Client_ItemPickup_AutoGatherTick(void * /*unused_stack*/)
{
  /* client arrives in EAX — model as first logical input */
  int client;
  __asm { mov client, eax }

  uint32_t pair_lo;
  uint32_t pair_hi;
  int adj;
  int host;
  uint32_t world_ctx;
  uint32_t helper;
  uint32_t now;

  if (*(int *)(client + 0xcd0) != 0) {
    return;
  }

  now = GetTickCount();
  DAT_00d218d4 = now;
  if ((int)(now - DAT_00d1f0d4) <= 99) {
    return;
  }

  pair_lo = 0xffffffffu;
  pair_hi = 0xffffffffu;
  adj = *(int *)(*(int *)(client + 4) + 4);
  host = client + adj;
  world_ctx = *(uint32_t *)(host + 0xa8);
  DAT_00d1f0d4 = now;

  /* vtbl +0x1a0 on *(host+4); formals: 20.0f, 1, 6, 0, 0, 1 */
  helper = (**(uint32_t(**)(float, int, int, int, int, int))(
              *(int *)(host + 4) + 0x1a0))(20.0f, 1, 6, 0, 0, 1);

  /* Skill_GatherTargetsRadiusMap — formal list residual at call site */
  {
    uint32_t pair[2];
    pair[0] = pair_lo;
    pair[1] = pair_hi;
    FUN_0058cd60(pair, 0, world_ctx, (void *)(client + adj + 4), helper);
    pair_lo = pair[0];
    pair_hi = pair[1];
  }

  if ((pair_lo & pair_hi) != 0xffffffffu) {
    /* call site of SendItemPickup: LEA ESI, pair */
    FUN_00925580();
  }
}
