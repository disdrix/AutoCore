// =============================================================================
// FUN_00418700  (machine alias of StdList_BuyNode_Dword_Seh)
// -----------------------------------------------------------------------------
// Stable ID: aa_00418700
// Address:   0x00418700  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list node helper (SEH-framed)
// Generated: 2026-08-05 MEGA-081 dual seal (prior scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: StdList_BuyNode_Dword_Seh.cpp
// =============================================================================

#include <cstdint>

// Prefer StdList_BuyNode_Dword_Seh for ports. This file keeps the Ghidra symbol.
// ABI: __stdcall RET 0xC; return node* in EAX (decompiler void is incorrect).

void *FUN_00418700(void *param_1, void *param_2, uint32_t *param_3)
{
  uint32_t *puVar1;

  puVar1 = (uint32_t *)operator_new(0xC);
  if (puVar1 != nullptr) {
    *puVar1 = (uint32_t)(uintptr_t)param_1;
    puVar1[1] = (uint32_t)(uintptr_t)param_2;
    puVar1[2] = *param_3;
  }
  return puVar1;
}
