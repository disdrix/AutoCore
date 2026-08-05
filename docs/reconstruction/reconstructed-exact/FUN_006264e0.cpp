// =============================================================================
// FUN_006264e0  (alias → CVOGHBActivatePlayer_ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_006264e0
// Address:   0x006264e0–0x0062652a  (autoassault.exe, image base 0x400000)
// System:    heartbeat / timed-actions / player activate
// Generated: 2026-07-29 W28-G dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// See: CVOGHBActivatePlayer_ctor_Inferred.cpp (named clean twin).

#include <stdint.h>

void *__thiscall FUN_006264e0(
    void *param_1,
    void *param_2,
    void *param_3,
    void *param_4)
{
  int nPeriodSentinel;

  CVOGHBBase_ctor(param_1);
  *(uint32_t *)param_1 = 0x009e3168u;
  CVOGHBBase_AttachOwnerObject(param_1, param_3);
  *((uint8_t *)param_1 + 0x28) = 0;
  *(uint32_t *)((char *)param_1 + 0x08) =
      *(uint32_t *)((char *)param_2 + 0x1c);
  nPeriodSentinel = *(int *)((char *)param_2 + 0x18);
  if (nPeriodSentinel == 0) {
    nPeriodSentinel = 1;
  }
  CVOGHBBase_SetPeriodAndCounter(param_1, nPeriodSentinel, 1);
  *(void **)((char *)param_1 + 0x24) = param_4;
  return param_1;
}
