// =============================================================================
// FUN_004c3c80  →  Object_SetMode278_SelectFromTFID228_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3c80
// Address:   0x004c3c80 – 0x004c3d17  (autoassault.exe, image base 0x400000)
// System:    object / AI owner mode / selected-target apply
// Generated: 2026-07-23 scaffold; sealed 2026-07-29 W28-L
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Twin of Object_SetMode278_SelectFromTFID228_Inferred.cpp (same body).

#include <stdint.h>
#include <string.h>

struct TFID_16 {
  uint32_t dwCoidLo;
  uint32_t dwCoidHi;
  uint32_t w2;
  uint32_t w3;
};

extern void *Object_ResolveFromTFID(TFID_16 *tfid);
extern void __thiscall Object_SetSelectedTarget(void *entity, void *pNewTarget);

void __thiscall FUN_004c3c80(void *self, char mode)
{
  *(char *)((char *)self + 0x278) = mode;
  if (mode != 1) {
    return;
  }

  TFID_16 local;
  memcpy(&local, (char *)self + 0x228, sizeof(local));

  void *resolved = Object_ResolveFromTFID(&local);
  if (resolved == 0) {
    return;
  }

  void *candidate = *(void **)((char *)resolved + 0xa0);
  if (candidate == 0) {
    return;
  }

  int baseAdj = *(int *)(*(int *)((char *)self + 4) + 4);
  void *mi = (char *)self + baseAdj + 4;
  char ok = (*(char (__thiscall **)(void *, void *))(*(int *)mi + 0x298))(mi, candidate);
  if (ok == 0) {
    return;
  }

  Object_SetSelectedTarget(mi, candidate);
}
