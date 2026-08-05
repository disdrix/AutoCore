// =============================================================================
// Named_CalleeOf_Auth_AuthServer_006759b0  — SUPERSEDED auto-rename alias
// -----------------------------------------------------------------------------
// Stable ID: aa_006759b0
// Address:   0x006759b0
// Note: Parent-seed name is domain-misleading. This is a shared MSVC list node
// allocator used by Auth *and* many non-auth callers.
// Canonical: StdList_BuyNode_Dword  (see StdList_BuyNode_Dword.cpp)
// Sealed:    2026-07-29 W20-M
// =============================================================================

#include <cstdint>

void *Named_CalleeOf_Auth_AuthServer_006759b0(uint32_t param_1, uint32_t param_2, uint32_t *param_3)
{
  // Forward-equivalent to StdList_BuyNode_Dword / FUN_006759b0
  uint32_t *puVar1 = (uint32_t *)operator_new(0xC);
  if (puVar1 != nullptr) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = *param_3;
  }
  return puVar1;
}
