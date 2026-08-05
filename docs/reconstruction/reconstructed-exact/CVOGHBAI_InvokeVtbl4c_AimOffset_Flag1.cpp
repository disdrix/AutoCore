// =============================================================================
// CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1
// -----------------------------------------------------------------------------
// Purpose:  HBAI leaf thunk — invoke this->vtbl[+0x4c](this+0x40, 1).
//           this+0x40 is aim-offset vec4 (see CVOGHBAI_UpdateAimOffset_Inferred).
//
// Address:  0x005cc450 – 0x005cc45b (12 B)
// Stable:   aa_005cc450
// System:   npc-ai / HBAI / aim-offset dispatch
// Ghidra:   FUN_005cc450
//
// Convention: MSVC __thiscall
//   this  CVOGHBAI* (or HBAI subclass)
//   void  bare ret
//
// Dual A/B: 2026-07-29 W28-L accept.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// =============================================================================

#include <stdint.h>

void __thiscall CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1(void *self)
{
  void **vtbl = *(void ***)self;
  /* slot 0x4c / 4 = index 19 */
  typedef void (__thiscall *Vtbl4c_t)(void *self, void *aimAt40, int flag);
  Vtbl4c_t fn = (Vtbl4c_t)vtbl[0x4c / 4];
  fn(self, (char *)self + 0x40, 1);
}
