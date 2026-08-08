// =============================================================================
// UI_InteractionMenu_AddSendTell_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0082f810
// Address:   0x0082f810 – 0x0082f849 inclusive (autoassault.exe, base 0x400000)
// Size:      0x3A (58 B); epilogue POP ESI; RET (C3)
// System:    interaction menu / tell UI
// Generated: 2026-08-05 MEGA-073 dual (live decompile ≡ raw 2026-07-23)
// Exactness: Behavior-preserving; not modernization. Bit-exact vs EXE: OPEN.
// Prior:     FUN_0082f810 / UI_int_btn_generic (plate-only scaffold)
// =============================================================================
//
// PURPOSE: On the interaction / radial menu host, create a generic
// "Send a Tell" button (id 0x11176) from plate i_m_int_2d_btn_generic.xml
// and store the button pointer at host+0x554.
//
// ABI (parent-preserved register — decompiler shows unaff_EDI):
//   EDI = menu host*
//   ret 0 (no stack cleanup)
//
// Parent: FUN_0082fe20 (UI_InteractionMenu_PopulateTargetButtons_Inferred)
//         calls this unit twice in alternate button-build orders with EDI=ESI.
// Peer:   UI_InteractionMenu_AddConvoyInviteOrKick_Inferred (0x0082fb30)
//         same create/label pattern; different id/caption/slot; has disable.
// =============================================================================

#include <cstdint>

struct UiButton;
struct MenuHost;

// vtbl helpers (indices sealed from disassemble_function + decompile):
//   host->vtbl[0x444/4](xml, 0, buttonId, 0xFFFFFFFF) -> UiButton*   // thiscall ECX=host
//   btn->vtbl[0x1D8/4](label, 1, 1)                                   // thiscall ECX=btn

static constexpr uint32_t kBtnIdSendTell = 0x11176;
static constexpr const char* kXmlGeneric = "i_m_int_2d_btn_generic.xml";
static constexpr const char* kCaptionSendTell = "Send a Tell";

// EDI = menu host; no stack args; ret 0
void UI_InteractionMenu_AddSendTell_Inferred(/* EDI */ MenuHost* menu)
{
  auto createBtn = *(UiButton* (**)(MenuHost*, const char*, int, uint32_t, uint32_t))
      (*(uintptr_t*)menu + 0x444);
  UiButton* btn = createBtn(menu, kXmlGeneric, 0, kBtnIdSendTell, 0xFFFFFFFFu);

  if (btn != nullptr) {
    auto setText = *(void (**)(UiButton*, const char*, int, int))
        (*(uintptr_t*)btn + 0x1D8);
    setText(btn, kCaptionSendTell, 1, 1);
  }

  // menu+0x554 = EDI[0x155]
  *(UiButton**)((char*)menu + 0x554) = btn;
}
