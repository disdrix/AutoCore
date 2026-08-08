// =============================================================================
// UI_InteractionMenu_AddConvoyInviteOrKick_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0082fb30
// Address:   0x0082fb30 – 0x0082fc31 exclusive (autoassault.exe, base 0x400000)
// Size:      0x101 (257 B); epilogue pop edi; ret (C3)
// System:    interaction menu / convoy UI
// Generated: 2026-08-04 WQ9D-I dual (from live decompile ≡ raw 2026-07-23)
// Exactness: Behavior-preserving; not modernization. Bit-exact vs EXE: OPEN.
// Prior:     UI_int_btn_generic_0082fb30 (plate-only alias)
// =============================================================================
//
// PURPOSE: On the interaction / radial menu host, create either an
// "Invite To Convoy" or "Kick From Convoy" generic button for the target
// object, store the button pointer on the host, and disable it when the
// local player is not the convoy leader (FUN_00574880 result != local).
//
// ABI (parent-preserved registers — decompiler shows unaff_ESI + __fastcall):
//   ESI = menu host*  (slots +0x540 invite, +0x544 kick)
//   EDX = target object*
//   ret 0 (no stack cleanup)
//
// Parent: FUN_0082fe20 (calls this unit twice in alternate button-build orders).
// =============================================================================

#include <cstdint>

struct Object;
struct UiButton;
struct MenuHost;

extern Object* DAT_00d1b6d8; // local player character

// Dualed: VehicleCrew_ContainsMember_Inferred — thiscall, RET 4, AL bool.
// ECX = crew host (*(localPlayer+0xCB0)), stack = candidate.
extern "C" char FUN_005749d0(void* candidate);

// Undualed: load roster member at host+0x194 slot index (same math as
// ConvoyRoster_GetMemberBySlot_Inferred). Returns object* or 0.
extern "C" Object* FUN_00574880(/* thiscall convoy/crew host */);

// vtbl helpers (indices sealed from decompile).
// host->vtbl[0x444/4](xml, 0, buttonId, 0xFFFFFFFF) -> UiButton*
// btn->vtbl[0x1D8/4](label, 1, 1)
// btn->vtbl[0xD4/4](0)  // disable / hide

static constexpr uint32_t kBtnIdInvite = 0x11171;
static constexpr uint32_t kBtnIdKick = 0x11172;
static constexpr const char* kXmlGeneric = "i_m_int_2d_btn_generic.xml";

void UI_InteractionMenu_AddConvoyInviteOrKick_Inferred(
    /* ESI */ MenuHost* menu,
    /* EDX */ Object* target)
{
  Object* local = DAT_00d1b6d8;

  // Gate on +0x6B4 (rank/level-like). Enter body if target field < 1 OR local > 0.
  if (!(*(int*)((char*)target + 0x6B4) < 1 ||
        (local != nullptr && *(int*)((char*)local + 0x6B4) > 0))) {
    return;
  }

  void* crewHost = (local != nullptr) ? *(void**)((char*)local + 0xCB0) : nullptr;

  // Invite if no crew host or target not a member; else Kick.
  char inCrew = 0;
  if (crewHost != nullptr) {
    // thiscall: ECX = crewHost, stack = target (asm: mov ecx,[local+0xCB0]; push edx)
    inCrew = FUN_005749d0(target);
  }

  if (crewHost == nullptr || inCrew == 0) {
    // --- Invite To Convoy ---
    auto createBtn = *(UiButton* (**)(MenuHost*, const char*, int, uint32_t, uint32_t))
        (*(uintptr_t*)menu + 0x444);
    UiButton* btn = createBtn(menu, kXmlGeneric, 0, kBtnIdInvite, 0xFFFFFFFFu);
    if (btn != nullptr) {
      auto setText = *(void (**)(UiButton*, const char*, int, int))
          (*(uintptr_t*)btn + 0x1D8);
      setText(btn, "Invite To Convoy", 1, 1);
    }
    // menu+0x540 = ESI[0x150]
    *(UiButton**)((char*)menu + 0x540) = btn;

    if (btn != nullptr && crewHost != nullptr) {
      // FUN_00574880 this = crew/roster host (ECX set by caller convention)
      Object* leaderOrSlot = FUN_00574880();
      if (leaderOrSlot != local) {
        auto disable = *(void (**)(UiButton*, int))(*(uintptr_t*)btn + 0xD4);
        disable(btn, 0);
      }
    }
  } else {
    // --- Kick From Convoy ---
    auto createBtn = *(UiButton* (**)(MenuHost*, const char*, int, uint32_t, uint32_t))
        (*(uintptr_t*)menu + 0x444);
    UiButton* btn = createBtn(menu, kXmlGeneric, 0, kBtnIdKick, 0xFFFFFFFFu);
    if (btn != nullptr) {
      auto setText = *(void (**)(UiButton*, const char*, int, int))
          (*(uintptr_t*)btn + 0x1D8);
      setText(btn, "Kick From Convoy", 1, 1);
    }
    // menu+0x544 = ESI[0x151]
    *(UiButton**)((char*)menu + 0x544) = btn;

    if (btn != nullptr) {
      Object* leaderOrSlot = FUN_00574880();
      if (leaderOrSlot != local) {
        auto disable = *(void (**)(UiButton*, int))(*(uintptr_t*)btn + 0xD4);
        disable(btn, 0);
        return;
      }
    }
  }
}
