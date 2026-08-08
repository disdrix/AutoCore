// =============================================================================
// FUN_0090d400 — twin of UI_CloseRelatedChrome_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0090d400
// Address:   0x0090d400 – 0x0090d465 inclusive (102 B / 0x66)
// See:       reconstructed-exact/UI_CloseRelatedChrome_Inferred.cpp
// Name:      INFERRED 2026-08-05 MEGA-086
// Ghidra:    FUN_0090d400 (keep for xref continuity)
// =============================================================================

#include <cstdint>

struct UiObject {
  void** vtbl;
};

extern UiObject* DAT_00d1b978;

using FnVisible = char(__thiscall*)(UiObject*);
using FnSetState = void(__thiscall*)(UiObject*, int);
using FnClose = void(__thiscall*)(UiObject*);
using FnNotify = void(__thiscall*)(UiObject*, UiObject*);
using FnBind = void(__thiscall*)(UiObject*, UiObject*);
using FnReset = void(__thiscall*)(UiObject*, int);

// Retail: ESI = primary (closed), EDI = secondary (notified); bare RET (C3).
// Decompiler: void FUN_0090d400(void) with unaff_ESI / unaff_EDI.

extern "C" void FUN_0090d400(UiObject* primary /*ESI*/,
                             UiObject* secondary /*EDI*/)
{
  if (primary == nullptr) {
    return;
  }

  if (reinterpret_cast<FnVisible>(primary->vtbl[0x3d8 / 4])(primary) == 0) {
    return;
  }

  reinterpret_cast<FnSetState>(primary->vtbl[0xcc / 4])(primary, 0);
  reinterpret_cast<FnClose>(primary->vtbl[0x440 / 4])(primary);

  reinterpret_cast<FnNotify>(secondary->vtbl[0xb0 / 4])(secondary, primary);

  if (DAT_00d1b978 != nullptr) {
    if (reinterpret_cast<FnVisible>(DAT_00d1b978->vtbl[0x3d8 / 4])(DAT_00d1b978) !=
        0) {
      reinterpret_cast<FnBind>(secondary->vtbl[0x3bc / 4])(secondary,
                                                           DAT_00d1b978);
    }
  }

  reinterpret_cast<FnReset>(secondary->vtbl[0x3f4 / 4])(secondary, -1);
}
