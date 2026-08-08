// =============================================================================
// FUN_00513400 — twin of Item_ValidateGadgetAttach_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00513400
// Address:   0x00513400 (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 MEGA-035 — thin alias twin (see named clean source)
// =============================================================================

#include <cstdint>

struct Item;

// Full plate: Item_ValidateGadgetAttach_Inferred.cpp
extern "C" std::uint32_t __thiscall Item_ValidateGadgetAttach_Inferred(
    Item* host,
    void* gadget);

extern "C" std::uint32_t __thiscall FUN_00513400(Item* host, void* gadget)
{
  return Item_ValidateGadgetAttach_Inferred(host, gadget);
}
