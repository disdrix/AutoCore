// =============================================================================
// FUN_004130d0  (scaffold twin of CVOGDialog_ScalarDeletingDtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_004130d0
// Address:   0x004130d0–0x004130ee exclusive (30 B / 0x1E)
// Module:    autoassault.exe (image base 0x400000)
// System:    missions-progression / CVOGDialog
// Wave:      R12-010 OWN-ONLY dual 2026-08-05
// Canonical: CVOGDialog_ScalarDeletingDtor
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false
// =============================================================================
// Prefer named clean: CVOGDialog_ScalarDeletingDtor.cpp
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_0087b7d0(void* self);
extern "C" void operator_delete(void* p);

extern "C" void* __thiscall FUN_004130d0(void* param_1, uint8_t param_2)
{
  FUN_0087b7d0(param_1);
  if ((param_2 & 1u) != 0u) {
    operator_delete(param_1);
  }
  return param_1;
}
