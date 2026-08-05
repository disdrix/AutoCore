// =============================================================================
// RefCountedSlot_ReleaseAndClear
// -----------------------------------------------------------------------------
// Stable ID: aa_00437150
// Address:   0x00437150  (autoassault.exe, image base 0x400000)
// System:    shared intrusive-refcount smart slot / SEH cleanup
// Generated: 2026-07-29 W23-A dual A/B seal
// Exactness: Behavior-preserving (SEH frame represented as comments).
// Bit-for-bit vs retail EXE: DEFERRED.
// Prior scaffold: FUN_00437150
// =============================================================================

// PURPOSE:
// Release one intrusive-refcount object held in a pointer slot and clear the slot.
// Object layout: +0 vtbl, +4 int32 refcount. Destroy via vtbl[+8] when count hits 0.
//
// ABI:
//   void __stdcall RefCountedSlot_ReleaseAndClear(void **slot);
//   RET 4
//
// Callers: Phy_CPConnectionPair_ReleaseClear, FUN_00439f00, SEH Unwind@*, etc.
// Phase2 after *slot=0 is residual (always null under successful phase1).

#include <stdint.h>

typedef void (__thiscall *RefCounted_ReleaseFn)(void *self);

void __stdcall RefCountedSlot_ReleaseAndClear(void **slot)
{
  void *obj;
  int32_t *p_ref;
  void **vtbl;

  /* Retail: FS:[0] SEH install; handler LAB_009bc278; state 0 then -1. */

  obj = *slot;
  if (obj != 0) {
    p_ref = (int32_t *)((uint8_t *)obj + 4);
    *p_ref = *p_ref - 1;
    if (*p_ref == 0) {
      vtbl = *(void ***)obj;
      ((RefCounted_ReleaseFn)vtbl[2])(obj); /* +8 */
    }
    *slot = 0;
  }

  /* Phase2 residual — re-read slot (null after clear). */
  obj = *slot;
  if (obj != 0) {
    p_ref = (int32_t *)((uint8_t *)obj + 4);
    *p_ref = *p_ref - 1;
    if (*p_ref == 0) {
      vtbl = *(void ***)obj;
      ((RefCounted_ReleaseFn)vtbl[2])(obj);
    }
  }

  /* Retail: restore FS:[0]; pop esi; add esp, 0xC; ret 4 */
}
