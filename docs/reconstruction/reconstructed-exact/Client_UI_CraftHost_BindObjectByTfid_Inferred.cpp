// =============================================================================
// Client_UI_CraftHost_BindObjectByTfid_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Resolve a 64-bit object id (TFID/COID lo+hi) to a live item pointer
//           (cargo/locker grid, else equip-slot TFID table + ResolveObjectTarget)
//           and bind it into a craft/RE host panel via FUN_008e5990. Invalid
//           sentinel TFID (both halves 0xFFFFFFFF) clears the bind.
//
// Address:  0x008e5ce0  (autoassault.exe, image base 0x400000)
// Stable:   aa_008e5ce0
// System:   inventory-transfer
//
// ABI (bytes + callers):
//   stdcall RET 0x0C
//   arg0 = craft/UI host*  (becomes ECX this for FUN_008e5990)
//   arg1 = coidLo
//   arg2 = coidHi
//
// Callees:
//   FUN_008e5990                         — bind/clear host selection
//   InventoryGrid_FindItemByCoid (0x00571010)
//   FUN_00522000                         — equip slot count (unsealed)
//   CVOGReaction_ResolveObjectTarget
//
// Exactness: Behavior-preserving rewrite of sealed CF + ABI.
// Bit-for-bit / runtime / differential: OPEN (no Launcher).
// Dual: WQ8R-H 2026-08-04
// =============================================================================

#include <cstdint>

extern int* DAT_00d1b6d8;          // local character
extern char  DAT_00d1b644[];       // client aux; +0xf5 locker-visible flag

extern int*  InventoryGrid_FindItemByCoid(std::uint32_t lo, std::uint32_t hi);
extern int   FUN_00522000(/* character context — unsealed */);
extern int*  CVOGReaction_ResolveObjectTarget(int mode, std::uint32_t lo, std::uint32_t hi);
// thiscall: ECX = host, stack = object* (or null)
extern void  __thiscall FUN_008e5990(void* host, int* object);

static constexpr int kBrokenBitShift = 19;
static constexpr std::uint32_t kInvalidHalf = 0xFFFFFFFFu;

static bool ItemIsBroken(const int* obj) {
  return ((static_cast<unsigned>(obj[0x5f /* +0x17c */]) >> kBrokenBitShift) & 1u) != 0;
}

void __stdcall Client_UI_CraftHost_BindObjectByTfid_Inferred(
    void* host,
    std::uint32_t coidLo,
    std::uint32_t coidHi) {

  if ((coidLo & coidHi) == kInvalidHalf) {
    FUN_008e5990(host, nullptr);
    return;
  }

  int* character = DAT_00d1b6d8;
  if (character == nullptr)
    return;

  int* obj = nullptr;

  // Vehicle cargo present?
  int* veh = *reinterpret_cast<int**>(reinterpret_cast<char*>(character) + 0x250);
  bool hasCargo = veh && *reinterpret_cast<int*>(reinterpret_cast<char*>(veh) + 0x2b0) != 0;
  bool hasLocker = *reinterpret_cast<int*>(reinterpret_cast<char*>(character) + 0xcbc) != 0;
  bool lockerUi = DAT_00d1b644[0xf5] != 0;

  if (hasCargo) {
    obj = InventoryGrid_FindItemByCoid(coidLo, coidHi);
    if (obj != nullptr && !ItemIsBroken(obj)) {
      FUN_008e5990(host, obj);
      return;
    }
    // fall through when null or broken
  }

  if ((obj == nullptr || ItemIsBroken(obj)) && hasLocker && lockerUi) {
    obj = InventoryGrid_FindItemByCoid(coidLo, coidHi);
  }

  if (obj == nullptr || ItemIsBroken(obj)) {
    int n = FUN_00522000();
    if (n < 1)
      return;
    for (int i = 0; i < n; ++i) {
      auto* base = reinterpret_cast<char*>(character) + 0x5a0 + (i & 0xff) * 8;
      std::uint32_t slo = *reinterpret_cast<std::uint32_t*>(base);
      std::uint32_t shi = *reinterpret_cast<std::uint32_t*>(base + 4);
      if ((slo & shi) == kInvalidHalf)
        continue;
      if (slo == coidLo && shi == coidHi) {
        obj = CVOGReaction_ResolveObjectTarget(1, slo, shi);
        break;
      }
    }
    if (obj == nullptr)
      return;
  }

  if (obj != nullptr)
    FUN_008e5990(host, obj);
}
