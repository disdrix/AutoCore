// =============================================================================
// UI_InteractionMenu_AddFriendsToggle
// -----------------------------------------------------------------------------
// Stable ID: aa_0082f9a0
// Address:   0x0082f9a0 – 0x0082fa59 exclusive (autoassault.exe, base 0x400000)
// Size:      0xB9 (185 B); pad CC after last RET
// System:    interaction menu / social UI (skills-abilities residual nest)
// Generated: 2026-08-05 MEGA-075 dual (live decompile ≡ raw 2026-07-23)
// Exactness: Behavior-preserving; not modernization. Bit-exact vs EXE: OPEN.
// Prior:     UI_int_btn_generic_0082f9a0 (plate-only alias — retired)
// =============================================================================
//
// PURPOSE: On the interaction / radial menu host, create either an
// "Add to Friends" or "Remove from Friends" generic button for the target
// object and store the button pointer on the host. Toggle is decided by a
// case-insensitive name lookup in the friends-list container DAT_00d1da2c.
//
// ABI (parent-preserved registers — decompiler shows in_EAX + unaff_EDI):
//   EAX = target object*
//   EDI = menu host*
//   ret 0 (no stack cleanup)
//
// Parent: FUN_0082fe20 UI_InteractionMenu_PopulateTargetButtons_Inferred
//   call sites: 0x0082fee3 (order-flag path), 0x0082feff (default order path).
// Twin shape: FUN_0082f8d0 Ignore toggle (ids 0x11179 / 0x1117c).
// =============================================================================

#include <cstdint>

struct Object;
struct UiButton;
struct MenuHost;
struct FriendsListHost; // DAT_00d1da2c — vector of friend entries; undualed layout

extern Object* DAT_00d1b6d8;          // local player character
extern FriendsListHost* DAT_00d1da2c; // friends-list host (may be null)

// Undualed: thiscall friends-list name lookup.
// ECX = friends list; stack = char* name.
// Walks pointer vector [+8,+c); _stricmp(entry+0x1a, name); returns entry* or 0.
extern "C" void* __thiscall FUN_00573a30(FriendsListHost* self, const char* name);

// vtbl helpers (byte offsets sealed from decompile / disasm):
//   target adjustor chain → CALL [vtbl+0x160]  → char* name
//   menu->vtbl+0x444(xml, 0, buttonId, 0xFFFFFFFF) -> UiButton*
//   btn->vtbl+0x1D8(label, 1, 1)

static constexpr uint32_t kBtnIdAddFriends = 0x11177;
static constexpr uint32_t kBtnIdRemoveFriends = 0x1117a;
static constexpr const char* kXmlGeneric = "i_m_int_2d_btn_generic.xml";

// Register contract documented in plate; not a portable C++ prototype.
void UI_InteractionMenu_AddFriendsToggle(
    /* EAX */ Object* target,
    /* EDI */ MenuHost* menu)
{
  Object* local = DAT_00d1b6d8;

  // Gate on +0x6B4 (rank/level-like; English open). Same family as convoy pack.
  // Assembly: enter if target.field < 1 OR local.field >= 1.
  if (!(*(int*)((char*)target + 0x6B4) < 1 ||
        (local != nullptr && *(int*)((char*)local + 0x6B4) >= 1))) {
    return;
  }

  FriendsListHost* friendsList = DAT_00d1da2c;
  if (friendsList != nullptr) {
    // MSVC adjustor thiscall: *( **(target+4)+4 + target + 4 ) vtbl, slot +0x160.
    auto nameGetter = *(const char* (**)(Object*))(
        *(uintptr_t*)(
            *(uintptr_t*)(*(uintptr_t*)((char*)target + 4) + 4) +
            (uintptr_t)target + 4) +
        0x160);
    // this = adjustor ECX (lea ecx, [base+target+4] in asm)
    const char* name = nameGetter(target);

    void* entry = FUN_00573a30(friendsList, name);
    if (entry != nullptr) {
      // --- Remove from Friends ---
      auto createBtn = *(UiButton* (**)(MenuHost*, const char*, int, uint32_t, uint32_t))(
          *(uintptr_t*)menu + 0x444);
      UiButton* btn = createBtn(menu, kXmlGeneric, 0, kBtnIdRemoveFriends, 0xFFFFFFFFu);
      if (btn != nullptr) {
        auto setText = *(void (**)(UiButton*, const char*, int, int))(
            *(uintptr_t*)btn + 0x1D8);
        setText(btn, "Remove from Friends", 1, 1);
      }
      // menu+0x564 = EDI[0x159]
      *(UiButton**)((char*)menu + 0x564) = btn;
      return;
    }
  }

  // --- Add to Friends ---
  auto createBtn = *(UiButton* (**)(MenuHost*, const char*, int, uint32_t, uint32_t))(
      *(uintptr_t*)menu + 0x444);
  UiButton* btn = createBtn(menu, kXmlGeneric, 0, kBtnIdAddFriends, 0xFFFFFFFFu);
  if (btn != nullptr) {
    auto setText = *(void (**)(UiButton*, const char*, int, int))(
        *(uintptr_t*)btn + 0x1D8);
    setText(btn, "Add to Friends", 1, 1);
  }
  // menu+0x558 = EDI[0x156]
  *(UiButton**)((char*)menu + 0x558) = btn;
}
