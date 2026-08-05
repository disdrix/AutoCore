// =============================================================================
// CVOGHB_FixedPeriod1_ctor_Inferred  (FUN_00626530)
// -----------------------------------------------------------------------------
// Stable ID: aa_00626530
// Address:   0x00626530–0x00626561  (50 B / 0x32; pad CC after)
// System:    heartbeat / timed-actions
// Generated: 2026-07-29 W29-O dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   HB subclass constructor: base ctor → install vtbl 0x009e3188 → attach owner →
//   seed dword at +0x08 from arg5 → SetPeriodAndCounter(period=1, true) → return this.
//   Object size at sole call site: 0x50. Does not Enqueue/Start; does not write +0x24/+0x28.

// ABI (image-sealed):
//   __thiscall  ECX = this
//   stack: void *pOwner, uint32_t arg3, uint32_t arg4, uint32_t arg5
//   ret 0x10
//   returns this*
//   arg3/arg4 unused in body (still formals for ret 0x10)

#include <stdint.h>

// External (sealed elsewhere):
// void __thiscall CVOGHBBase_ctor(void *this);
// void __thiscall CVOGHBBase_AttachOwnerObject(void *this, void *pOwner);
// void __thiscall CVOGHBBase_SetPeriodAndCounter(void *this, int period, int fTrue);

void *__thiscall CVOGHB_FixedPeriod1_ctor_Inferred(
    void *self,
    void *pOwner,
    uint32_t arg3,
    uint32_t arg4,
    uint32_t arg5)
{
  (void)arg3;
  (void)arg4;

  CVOGHBBase_ctor(self);
  *(uint32_t *)self = 0x009e3188u;
  CVOGHBBase_AttachOwnerObject(self, pOwner);
  *(uint32_t *)((char *)self + 0x08) = arg5;
  CVOGHBBase_SetPeriodAndCounter(self, 1, 1);
  return self;
}
