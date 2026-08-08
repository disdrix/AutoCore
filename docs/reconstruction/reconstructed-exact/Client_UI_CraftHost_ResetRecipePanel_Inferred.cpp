// =============================================================================
// Client_UI_CraftHost_ResetRecipePanel_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Clear a craft/RE host panel's 5×5 recipe/material cell chrome:
//           destroy owned per-cell objects, invalidate cell TFIDs to
//           0xFFFFFFFF/0xFFFFFFFF, hide/refresh cell + row widgets, then
//           hide/refresh footer chrome at host+0x748 / optional +0x768/+0x76c.
//
// Address:  0x008e2d60  (autoassault.exe, image base 0x400000)
// Stable:   aa_008e2d60
// System:   inventory-transfer
//
// ABI (bytes + callers):
//   stdcall RET 4
//   arg0 = craft/UI host*
//   ECX is NOT host on entry — used as per-widget this for vtbl calls.
//
// Callers:
//   FUN_008e5990 @ 0x008e59df  (bind/rebuild always resets first)
//   undefined ~0x008e6390 @ 0x008e63dc  (float gate path; Ghidra undeffed)
//
// Callees: none direct — widget vtbl only.
//
// Exactness: Behavior-preserving rewrite of sealed CF + ABI.
// Bit-for-bit / runtime / differential: OPEN (no Launcher).
// Dual: MEGA-085 2026-08-05
// =============================================================================

#include <cstdint>

// Widget method slots observed (thiscall ECX=widget; offsets are vtbl byte offs).
// English names are OPEN — port by offset, not by invented product strings.
static constexpr std::uint32_t kVtblDtor           = 0x00;   // scalar-deleting dtor-like (arg 1)
static constexpr std::uint32_t kVtblHideLike       = 0x04;   // (arg 0) on row/footer widgets
static constexpr std::uint32_t kVtblMaybeClear     = 0x58;   // no arg; gated on query
static constexpr std::uint32_t kVtblSetState0      = 0xcc;   // (arg 0)
static constexpr std::uint32_t kVtblQuery          = 0x2bc;  // returns nonzero → MaybeClear
static constexpr std::uint32_t kVtblRefresh        = 0x34c;  // no arg
static constexpr std::uint32_t kVtblFooterState0   = 0xd4;   // (arg 0) on host+0x748

static constexpr int kGridDim = 5;
static constexpr std::uint32_t kInvalidHalf = 0xFFFFFFFFu;

using VtblFn0 = void(__thiscall*)(void* self);
using VtblFn1 = void(__thiscall*)(void* self, int a);
using VtblFn0i = int(__thiscall*)(void* self);

static inline void** Vtbl(void* obj) {
  return *reinterpret_cast<void***>(obj);
}

void __stdcall Client_UI_CraftHost_ResetRecipePanel_Inferred(void* host) {
  auto* base = reinterpret_cast<std::uint8_t*>(host);

  auto* rowWidget = reinterpret_cast<void**>(base + 0x534);   // ×5, stride 4
  auto* cellTfid  = reinterpret_cast<std::uint32_t*>(base + 0x680); // ×25 pairs
  auto* cellWidget = reinterpret_cast<void**>(base + 0x5b8);  // ×25, stride 4
  // owned object* parallel to cells starts at host+0x61c == &cellWidget[0] + 0x64

  int outer = kGridDim;
  do {
    int inner = kGridDim;
    do {
      // puVar5[0x19] == *(cellWidget_as_u32* + 0x19) == object at cellBase+0x64
      void** ownedSlot = reinterpret_cast<void**>(
          reinterpret_cast<std::uint8_t*>(cellWidget) + 0x64);
      void* owned = *ownedSlot;
      if (owned != nullptr) {
        auto dtor = reinterpret_cast<VtblFn1>(Vtbl(owned)[kVtblDtor / 4]);
        dtor(owned, 1);
      }
      *ownedSlot = nullptr;

      cellTfid[0] = kInvalidHalf;
      cellTfid[1] = kInvalidHalf;

      void* cell = *cellWidget;
      auto query = reinterpret_cast<VtblFn0i>(Vtbl(cell)[kVtblQuery / 4]);
      if (query(cell) != 0) {
        auto maybeClear = reinterpret_cast<VtblFn0>(Vtbl(cell)[kVtblMaybeClear / 4]);
        maybeClear(cell);
      }
      auto setState0 = reinterpret_cast<VtblFn1>(Vtbl(cell)[kVtblSetState0 / 4]);
      setState0(cell, 0);
      auto refresh = reinterpret_cast<VtblFn0>(Vtbl(cell)[kVtblRefresh / 4]);
      refresh(cell);

      cellTfid += 2;
      cellWidget += 1;
      --inner;
    } while (inner != 0);

    // row peer at rowWidget[7] (offset +0x1c from current row base)
    void* rowPeer = rowWidget[7];
    auto hidePeer = reinterpret_cast<VtblFn1>(Vtbl(rowPeer)[kVtblHideLike / 4]);
    hidePeer(rowPeer, 0);

    void* row = *rowWidget;
    auto hideRow = reinterpret_cast<VtblFn1>(Vtbl(row)[kVtblHideLike / 4]);
    hideRow(row, 0);

    rowWidget += 1;
    --outer;
  } while (outer != 0);

  void* footer = *reinterpret_cast<void**>(base + 0x748);
  auto footerState = reinterpret_cast<VtblFn1>(Vtbl(footer)[kVtblFooterState0 / 4]);
  footerState(footer, 0);
  auto footerRefresh = reinterpret_cast<VtblFn0>(Vtbl(footer)[kVtblRefresh / 4]);
  footerRefresh(footer);

  void* optA = *reinterpret_cast<void**>(base + 0x768);
  if (optA != nullptr) {
    auto hideA = reinterpret_cast<VtblFn1>(Vtbl(optA)[kVtblHideLike / 4]);
    hideA(optA, 0);
  }

  void* optB = *reinterpret_cast<void**>(base + 0x76c);
  if (optB != nullptr) {
    // Retail: tail-call JMP [vtbl+4] with stack arg rewritten to 0 so the
    // method returns directly to our caller (stdcall RET 4 preserved).
    auto hideB = reinterpret_cast<VtblFn1>(Vtbl(optB)[kVtblHideLike / 4]);
    hideB(optB, 0);
    return;
  }
}
