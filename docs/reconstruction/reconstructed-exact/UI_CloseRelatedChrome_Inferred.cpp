// =============================================================================
// UI_CloseRelatedChrome_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0090d400
// Address:   0x0090d400 – 0x0090d465 inclusive (autoassault.exe, base 0x400000)
// Size:      0x66 (102 B); bare RET (C3); pad CC then FUN_0090d470 @ 0x0090d470
// System:    skills-abilities / interaction-menu UI chrome
// Generated: 2026-08-05 MEGA-086 dual (live decompile ≡ raw 2026-07-23 + listing)
// Exactness: Behavior-preserving; not modernization. Bit-exact vs EXE: OPEN.
// Prior:     FUN_0090d400 scaffold; Named_CalleeOf_* scaffold RETIRED
// =============================================================================
//
// PURPOSE: Register-contract dual-object UI close helper.
//   ESI = primary object closed (visible? → SetState(0) → Close/Flush).
//   EDI = secondary object notified (Detach/Notify(primary) → optional re-bind
//         of global panel DAT_00d1b978 → Reset/Select(-1)).
//
// Call-site families assign host vs related-chrome into ESI/EDI differently:
//   - Interaction menu (parent UI_InteractionMenu_PopulateTargetButtons):
//       ESI = menu host, EDI = *(host+0x2B0) related chrome — close host path
//       when social pack cannot populate.
//   - Table flush FUN_0090dab0:
//       EDI = host (from EAX), ESI = chrome table entry — close each chrome.
//
// ABI: register contract (not ECX-thiscall entry); no stack args; bare RET.
// Static callees: none (virtual only).
// =============================================================================

#include <cstdint>

struct UiObject {
  void** vtbl;
};

// Optional global UI panel (Tell path 0x11176 in FUN_00830010 also reads this).
extern UiObject* DAT_00d1b978;

using FnVisible = char(__thiscall*)(UiObject*);
using FnSetState = void(__thiscall*)(UiObject*, int);
using FnClose = void(__thiscall*)(UiObject*);
using FnNotify = void(__thiscall*)(UiObject*, UiObject*);
using FnBind = void(__thiscall*)(UiObject*, UiObject*);
using FnReset = void(__thiscall*)(UiObject*, int);

// Retail entry uses ESI/EDI (decompiler: unaff_ESI / unaff_EDI). Documented as
// explicit formals for port clarity; callers must place args in those regs.
extern "C" void UI_CloseRelatedChrome_Inferred(UiObject* primary /*ESI*/,
                                               UiObject* secondary /*EDI*/)
{
  if (primary == nullptr) {
    return;
  }

  // primary->vtbl+0x3d8() — IsVisible / IsActive probe → AL
  if (reinterpret_cast<FnVisible>(primary->vtbl[0x3d8 / 4])(primary) == 0) {
    return;
  }

  // primary->vtbl+0xcc(0) — SetState / Show(0)
  reinterpret_cast<FnSetState>(primary->vtbl[0xcc / 4])(primary, 0);

  // primary->vtbl+0x440() — Close / Hide / Flush
  reinterpret_cast<FnClose>(primary->vtbl[0x440 / 4])(primary);

  // secondary->vtbl+0xb0(primary) — Detach / Notify
  reinterpret_cast<FnNotify>(secondary->vtbl[0xb0 / 4])(secondary, primary);

  // Optional re-bind of global panel when it is visible.
  if (DAT_00d1b978 != nullptr) {
    if (reinterpret_cast<FnVisible>(DAT_00d1b978->vtbl[0x3d8 / 4])(DAT_00d1b978) !=
        0) {
      // secondary->vtbl+0x3bc(DAT_00d1b978)
      reinterpret_cast<FnBind>(secondary->vtbl[0x3bc / 4])(secondary,
                                                           DAT_00d1b978);
    }
  }

  // secondary->vtbl+0x3f4(-1) — Reset / Select(-1)
  reinterpret_cast<FnReset>(secondary->vtbl[0x3f4 / 4])(secondary, -1);
}
