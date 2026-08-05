// =============================================================================
// FUN_005cc450  →  CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1
// -----------------------------------------------------------------------------
// Stable ID: aa_005cc450
// Address:   0x005cc450 – 0x005cc45b  (autoassault.exe, image base 0x400000)
// System:    npc-ai / HBAI / aim-offset dispatch
// Generated: 2026-07-23 scaffold; sealed 2026-07-29 W28-L
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Twin of CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1.cpp (same body).

#include <stdint.h>

void __thiscall FUN_005cc450(void *self)
{
  void **vtbl = *(void ***)self;
  typedef void (__thiscall *Vtbl4c_t)(void *self, void *aimAt40, int flag);
  Vtbl4c_t fn = (Vtbl4c_t)vtbl[0x4c / 4];
  fn(self, (char *)self + 0x40, 1);
}
