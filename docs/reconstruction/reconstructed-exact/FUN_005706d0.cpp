// =============================================================================
// FUN_005706d0  (clean twin → InventoryGrid_SetDirtyFlag_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005706d0
// Address:   0x005706d0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-04 WQ8R-J (supersedes 2026-07-23 scaffold paste)
// Canonical: InventoryGrid_SetDirtyFlag_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_00512670(void* obj);

void __fastcall FUN_005706d0(int param_1)
{
  auto* grid = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(param_1));
  void* owner = *reinterpret_cast<void**>(grid + 0x24);
  if (owner != nullptr) {
    FUN_00512670(owner);
  }
  *(grid + 0x21) = 1;
}
