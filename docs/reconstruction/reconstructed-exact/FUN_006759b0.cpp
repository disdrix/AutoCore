// =============================================================================
// FUN_006759b0  — alias plate for StdList_BuyNode_Dword
// -----------------------------------------------------------------------------
// Stable ID: aa_006759b0
// Address:   0x006759b0  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list node helper
// Generated: 2026-07-29 W20-M dual seal (updates 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Canonical clean: reconstructed-exact/StdList_BuyNode_Dword.cpp
// =============================================================================

#include <cstdint>

// Returns node* in EAX (decompiler void). __stdcall ret 0xC.
void *FUN_006759b0(uint32_t param_1, uint32_t param_2, uint32_t *param_3)
{
  uint32_t *puVar1;

  puVar1 = (uint32_t *)operator_new(0xC);
  if (puVar1 != nullptr) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = *param_3;
  }
  return puVar1;
}
