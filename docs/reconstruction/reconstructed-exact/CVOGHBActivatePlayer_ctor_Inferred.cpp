// =============================================================================
// CVOGHBActivatePlayer_ctor_Inferred  (FUN_006264e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_006264e0
// Address:   0x006264e0–0x0062652a  (autoassault.exe, image base 0x400000)
// System:    heartbeat / timed-actions / player activate
// Generated: 2026-07-29 W28-G dual seal (from raw 2026-07-23 + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Construct the HB action used exclusively by Object_ActivatePlayerEnqueueHB_Inferred.
//   Base ctor → subclass vtbl 0x009e3168 → attach owner → flag@+0x28=0 →
//   copy periodSrc fields → SetPeriod (min 1) → store host@+0x24 → return this.
//   Object size at sole call site: 0x2c.

// ABI (image-sealed):
//   __thiscall  ECX = this
//   stack: void *periodSrc, void *pOwner, void *pHost
//   ret 0xC
//   returns this*

#include <stdint.h>

// External (sealed elsewhere):
// void __thiscall CVOGHBBase_ctor(void *this);
// void __thiscall CVOGHBBase_AttachOwnerObject(void *this, void *pOwner);
// void __thiscall CVOGHBBase_SetPeriodAndCounter(void *this, int period, int fTrue);

void *__thiscall CVOGHBActivatePlayer_ctor_Inferred(
    void *self,
    void *periodSrc,
    void *pOwner,
    void *pHost)
{
  int nPeriod;

  CVOGHBBase_ctor(self);
  *(uint32_t *)self = 0x009e3168u;
  CVOGHBBase_AttachOwnerObject(self, pOwner);
  *((uint8_t *)self + 0x28) = 0;
  *(uint32_t *)((char *)self + 0x08) =
      *(uint32_t *)((char *)periodSrc + 0x1c);
  nPeriod = *(int *)((char *)periodSrc + 0x18);
  if (nPeriod == 0) {
    nPeriod = 1;
  }
  CVOGHBBase_SetPeriodAndCounter(self, nPeriod, 1);
  *(void **)((char *)self + 0x24) = pHost;
  return self;
}
