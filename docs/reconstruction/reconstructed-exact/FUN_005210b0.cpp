// =============================================================================
// FUN_005210b0 — scaffold alias for Character_ClearEquippedRaceItemTfId_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005210b0
// Address:   0x005210b0  (autoassault.exe, image base 0x400000)
// Canonical: Character_ClearEquippedRaceItemTfId_Inferred
// Dual A/B:  accept (2026-07-29 W21-E)
// =============================================================================

/* Prefer Character_ClearEquippedRaceItemTfId_Inferred.cpp for the sealed body.
   This scaffold keeps Ghidra FUN_* naming stable for coverage tooling. */

#include <stdint.h>

struct TFID_16 {
  uint32_t dwCoidLo;
  uint32_t dwCoidHi;
  uint32_t field_08;
  uint32_t field_0C;
};

extern void *Object_ResolveFromTFID(TFID_16 *tfid);
extern void __thiscall Object_EnqueueDeferredOnce(void *host, void *obj);

static const uint32_t kNullTfidTemplate[4] = {
    0xffffffffu, 0xffffffffu, 0x00000000u, 0x00000000u
};

void __fastcall FUN_005210b0(int param_1)
{
  uint32_t *tfid_dwords = (uint32_t *)((uint8_t *)(uintptr_t)param_1 + 0x518);
  TFID_16 *tfid = (TFID_16 *)tfid_dwords;

  if (((tfid_dwords[0] & tfid_dwords[1]) == 0xffffffffu) &&
      (*(int8_t *)((uint8_t *)(uintptr_t)param_1 + 0x520) == 0)) {
    return;
  }

  int *vt_adj = *(int **)((uint8_t *)(uintptr_t)param_1 + 4);
  void *host = *(void **)((uint8_t *)vt_adj[1] + (uintptr_t)param_1 + 0xa8);
  if (host == 0) {
    return;
  }

  (void)*(void **)((uint8_t *)host + 0xe4e8);
  void *obj = Object_ResolveFromTFID(tfid);
  if (obj != 0) {
    Object_EnqueueDeferredOnce(host, obj);
  }

  tfid_dwords[0] = kNullTfidTemplate[0];
  tfid_dwords[1] = kNullTfidTemplate[1];
  tfid_dwords[2] = kNullTfidTemplate[2];
  tfid_dwords[3] = kNullTfidTemplate[3];
}
