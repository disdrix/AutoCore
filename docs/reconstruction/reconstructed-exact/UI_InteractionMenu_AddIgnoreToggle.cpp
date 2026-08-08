// =============================================================================
// UI_InteractionMenu_AddIgnoreToggle
// -----------------------------------------------------------------------------
// Stable ID: aa_0082f8d0
// Address:   0x0082f8d0 – 0x0082f989 exclusive (autoassault.exe, base 0x400000)
// Size:      0xB9 (185 B); pad CC after last RET
// System:    interaction menu / social UI (skills-abilities residual nest)
// Generated: 2026-08-05 MEGA-074 dual (live decompile ≡ raw 2026-07-23)
// Exactness: Behavior-preserving; not modernization. Bit-exact vs EXE: OPEN.
// Prior:     UI_int_btn_generic_0082f8d0 (plate-only alias — retired)
// =============================================================================
//
// PURPOSE: On the interaction / radial menu host, create either an
// "Add to Ignore" or "Remove from Ignore" generic button for the target
// object and store the button pointer on the host. Toggle is decided by a
// case-insensitive name lookup in the ignore-list container on DAT_00d1da2c
// via FUN_00573af0 (vector @ +0x38; entry name @ +0x10).
//
// ABI (parent-preserved registers — decompiler shows in_EAX + unaff_EDI):
//   EAX = target object*
//   EDI = menu host*
//   ret 0 (no stack cleanup)
//
// Parent: FUN_0082fe20 UI_InteractionMenu_PopulateTargetButtons_Inferred
//   call sites: 0x0082feea (order-flag path), 0x0082fef6 (default order path).
// Twin shape: FUN_0082f9a0 Friends toggle (ids 0x11177 / 0x1117a).
// =============================================================================

#include <cstdint>

struct Object;
struct UiButton;
struct MenuHost;
struct SocialListHost; // DAT_00d1da2c — shared social host; ignore vector @ +0x38

extern Object* DAT_00d1b6d8;         // local player character
extern SocialListHost* DAT_00d1da2c; // social-list host (may be null)

// Undualed: thiscall ignore-list name lookup.
// ECX = social host; stack = char* name.
// Walks pointer vector [+0x38,+0x3c); _stricmp(entry+0x10, name); returns entry* or 0.
extern "C" void* __thiscall FUN_00573af0(SocialListHost* self, const char* name);

// vtbl helpers (byte offsets sealed from decompile / disasm):
//   target adjustor chain → CALL [vtbl+0x160]  → char* name
//   menu->vtbl+0x444(xml, 0, buttonId, 0xFFFFFFFF) -> UiButton*
//   btn->vtbl+0x1D8(label, 1, 1)

static constexpr uint32_t kBtnIdAddIgnore = 0x11179;
static constexpr uint32_t kBtnIdRemoveIgnore = 0x1117c;
static constexpr const char* kXmlGeneric = "i_m_int_2d_btn_generic.xml";

// Register contract documented in plate; not a portable C++ prototype.
void UI_InteractionMenu_AddIgnoreToggle(
    /* EAX */ Object* target,
    /* EDI */ MenuHost* menu)
{
  Object* local = DAT_00d1b6d8;

  // Gate on +0x6B4 (rank/level-like; English open). Same family as convoy/friends packs.
  // Assembly: enter if target.field < 1 OR local.field >= 1.
  if (!(*(int*)((char*)target + 0x6B4) < 1 ||
        (local != nullptr && *(int*)((char*)local + 0x6B4) >= 1))) {
    return;
  }

  SocialListHost* socialHost = DAT_00d1da2c;
  if (socialHost != nullptr) {
    // MSVC adjustor thiscall: *( **(target+4)+4 + target + 4 ) vtbl, slot +0x160.
    auto nameGetter = *(const char* (**)(Object*))(
        *(uintptr_t*)(
            *(uintptr_t*)(*(uintptr_t*)((char*)target + 4) + 4) +
            (uintptr_t)target + 4) +
        0x160);
    // this = adjustor ECX (lea ecx, [base+target+4] in asm)
    const char* name = nameGetter(target);

    void* entry = FUN_00573af0(socialHost, name);
    if (entry != nullptr) {
      // --- Remove from Ignore ---
      auto createBtn = *(UiButton* (**)(MenuHost*, const char*, int, uint32_t, uint32_t))(
          *(uintptr_t*)menu + 0x444);
      UiButton* btn = createBtn(menu, kXmlGeneric, 0, kBtnIdRemoveIgnore, 0xFFFFFFFFu);
      if (btn != nullptr) {
        auto setText = *(void (**)(UiButton*, const char*, int, int))(
            *(uintptr_t*)btn + 0x1D8);
        setText(btn, "Remove from Ignore", 1, 1);
      }
      // menu+0x56c = EDI[0x15b]
      *(UiButton**)((char*)menu + 0x56c) = btn;
      return;
    }
  }

  // --- Add to Ignore ---
  auto createBtn = *(UiButton* (**)(MenuHost*, const char*, int, uint32_t, uint32_t))(
      *(uintptr_t*)menu + 0x444);
  UiButton* btn = createBtn(menu, kXmlGeneric, 0, kBtnIdAddIgnore, 0xFFFFFFFFu);
  if (btn != nullptr) {
    auto setText = *(void (**)(UiButton*, const char*, int, int))(
        *(uintptr_t*)btn + 0x1D8);
    setText(btn, "Add to Ignore", 1, 1);
  }
  // menu+0x560 = EDI[0x158]
  *(UiButton**)((char*)menu + 0x560) = btn;
}
