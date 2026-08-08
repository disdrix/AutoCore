// =============================================================================
// UI_InteractionMenu_AddClanInviteOrKick_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0082fa60
// Address:   0x0082fa60 – 0x0082fb2b exclusive (autoassault.exe, base 0x400000)
// Size:      0xCB (203 B); epilogue pop esi; ret (C3)
// System:    interaction menu / clan social UI (skills-abilities partition)
// Generated: 2026-08-05 MEGA-076 dual (live decompile ≡ raw 2026-07-23)
// Exactness: Behavior-preserving; not modernization. Bit-exact vs EXE: OPEN.
// Prior:     UI_int_btn_generic_0082fa60 (plate-only alias; retired)
// =============================================================================
//
// PURPOSE: On the interaction / radial menu host, create either an
// "Invite To Clan" or "Kick From Clan" generic button for the target
// object and store the button pointer on the host.
//
// ABI (parent-preserved registers — not thiscall):
//   EAX = target object*
//   EBX = menu host*   (slots +0x548 invite, +0x54C kick)
//   ret 0 (C3; no stack cleanup)
//
// Parent: FUN_0082fe20 UI_InteractionMenu_PopulateTargetButtons_Inferred
//   (calls this unit once per pack order; sites 0x0082fed0 / 0x0082ff14).
// Sibling: FUN_0082fb30 UI_InteractionMenu_AddConvoyInviteOrKick_Inferred
//   (convoy uses ESI host + EDX target; different register contract).
// =============================================================================

#include <cstdint>

struct Object;
struct UiButton;
struct MenuHost;
struct ClanEntry;
struct ClanTable;

extern Object*    DAT_00d1b6d8; // local player character
extern ClanTable* DAT_00d1da30; // clan table / registry host

// Undualed: linear scan this+0x1E4 vector for entry matching (key_lo, key_hi).
// __thiscall; ECX = ClanTable*; returns ClanEntry* or null.
extern "C" ClanEntry* __thiscall FUN_004c22a0(ClanTable* self,
                                              uint32_t key_lo,
                                              uint32_t key_hi);

// Undualed: host.vtbl+0x444 create + btn.vtbl+0x1D8 setText wrapper.
// __fastcall: ECX = menu host, EDX = 0xFFFFFFFF; stack label, xml, flags, id.
extern "C" UiButton* __fastcall FUN_0082f7d0(MenuHost* menu,
                                             uint32_t edx_ffff,
                                             const char* label,
                                             const char* xml,
                                             int flags,
                                             uint32_t buttonId);

static constexpr uint32_t kBtnIdInvite = 0x11173;
static constexpr uint32_t kBtnIdKick   = 0x11174;
static constexpr const char* kXmlGeneric = "i_m_int_2d_btn_generic.xml";

// Register ABI: EAX=target, EBX=menu. Modeled as explicit params for readability.
void UI_InteractionMenu_AddClanInviteOrKick_Inferred(
    /* EAX */ Object* target,
    /* EBX */ MenuHost* menu)
{
  Object* local = DAT_00d1b6d8;

  // Gate on +0x6B4 (rank/level-like). Enter body if target field < 1 OR local > 0.
  if (!(*(int*)((char*)target + 0x6B4) < 1 ||
        (local != nullptr && *(int*)((char*)local + 0x6B4) > 0))) {
    return;
  }

  ClanTable* table = DAT_00d1da30;
  if (table == nullptr) {
    return;
  }

  // Local clan entry: secondary = *(*(local+4)+4); keys at secondary+local+0x164/0x168
  auto* localSec = *reinterpret_cast<uint8_t**>(
      *reinterpret_cast<uint8_t**>(reinterpret_cast<char*>(local) + 4) + 4);
  uint32_t localKeyLo =
      *reinterpret_cast<uint32_t*>(localSec + reinterpret_cast<uintptr_t>(local) + 0x164);
  uint32_t localKeyHi =
      *reinterpret_cast<uint32_t*>(localSec + reinterpret_cast<uintptr_t>(local) + 0x168);
  ClanEntry* localClan = FUN_004c22a0(table, localKeyLo, localKeyHi);

  auto* targetSec = *reinterpret_cast<uint8_t**>(
      *reinterpret_cast<uint8_t**>(reinterpret_cast<char*>(target) + 4) + 4);
  uint32_t targetKeyLo =
      *reinterpret_cast<uint32_t*>(targetSec + reinterpret_cast<uintptr_t>(target) + 0x164);
  uint32_t targetKeyHi =
      *reinterpret_cast<uint32_t*>(targetSec + reinterpret_cast<uintptr_t>(target) + 0x168);
  ClanEntry* targetClan = FUN_004c22a0(table, targetKeyLo, targetKeyHi);

  if (localClan == nullptr) {
    return;
  }

  if (targetClan == nullptr) {
    // --- Invite To Clan --- requires localClan+0x24 >= 2
    if (*(int*)((char*)localClan + 0x24) >= 2) {
      UiButton* btn = FUN_0082f7d0(menu, 0xFFFFFFFFu,
                                   "Invite To Clan", kXmlGeneric, 0, kBtnIdInvite);
      // menu+0x548
      *(UiButton**)((char*)menu + 0x548) = btn;
      return;
    }
  } else if (*(int*)((char*)targetClan + 0x24) < *(int*)((char*)localClan + 0x24)) {
    // --- Kick From Clan --- target rank field strictly below local
    UiButton* btn = FUN_0082f7d0(menu, 0xFFFFFFFFu,
                                 "Kick From Clan", kXmlGeneric, 0, kBtnIdKick);
    // menu+0x54C
    *(UiButton**)((char*)menu + 0x54C) = btn;
  }
}
