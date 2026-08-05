// =============================================================================
// FUN_00437150 — alias of RefCountedSlot_ReleaseAndClear
// -----------------------------------------------------------------------------
// Stable ID: aa_00437150
// Address:   0x00437150  (autoassault.exe, image base 0x400000)
// Canonical: RefCountedSlot_ReleaseAndClear
// See:       reconstructed-exact/RefCountedSlot_ReleaseAndClear.cpp
// Generated: 2026-07-29 W23-A dual A/B seal
// =============================================================================

#include <stdint.h>

typedef void (__thiscall *RefCounted_ReleaseFn)(void *self);

void __stdcall FUN_00437150(void **param_1 /* slot */)
{
  void *obj;
  int32_t *p_ref;
  void **vtbl;

  obj = *param_1;
  if (obj != 0) {
    p_ref = (int32_t *)((uint8_t *)obj + 4);
    *p_ref = *p_ref - 1;
    if (*p_ref == 0) {
      vtbl = *(void ***)obj;
      ((RefCounted_ReleaseFn)vtbl[2])(obj);
    }
    *param_1 = 0;
  }

  obj = *param_1;
  if (obj != 0) {
    p_ref = (int32_t *)((uint8_t *)obj + 4);
    *p_ref = *p_ref - 1;
    if (*p_ref == 0) {
      vtbl = *(void ***)obj;
      ((RefCounted_ReleaseFn)vtbl[2])(obj);
    }
  }
}
