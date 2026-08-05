// =============================================================================
// FUN_004bd1b0  (scaffold twin → COList_ScalarDeletingDestructor)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bd1b0
// Address:   0x004bd1b0–0x004bd1cd  (30 B, autoassault.exe base 0x400000)
// System:    client / COList
// Generated: 2026-07-29 W27-L dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: docs/reconstruction/reconstructed-exact/COList_ScalarDeletingDestructor.cpp
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_004bbc70(void* self);
extern "C" void operator_delete(void* p);

// __thiscall; ECX=this; stack flags; ret 4; returns this*
extern "C" void* __thiscall FUN_004bd1b0(void* param_1, uint8_t param_2)
{
  FUN_004bbc70(param_1);

  if ((param_2 & 1u) != 0u) {
    // Decompiler WARNING "does not return" is a Ghidra artifact.
    operator_delete(param_1);
  }

  return param_1;
}
