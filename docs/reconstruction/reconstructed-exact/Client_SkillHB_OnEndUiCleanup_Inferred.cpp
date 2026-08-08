// =============================================================================
// Client_SkillHB_OnEndUiCleanup_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00802b70
// Address:   0x00802b70 – 0x00802c7b exclusive (0x10B / 267 B)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities (client UI side of skill HB OnEnd)
// Generated: 2026-08-05 MEGA-020 dual (decompile + disassemble_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow with ABI
//            corrections from assembly. Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Client-side skill HB **OnEnd UI cleanup** rebound into `PTR_FUN_00af31e0`
//   during Client InitInstance. Invoked first from dualed
//   Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred as:
//       PTR_FUN_00af31e0(hb, 0);
//
//   Branches:
//     1) If UI tracker DAT_00d1d8e0+0x514 holds this HB → clear client bind
//        (FUN_007fc970 with ESI = client 0x00d1a840).
//     2) If owner is local player (or local+0x250 peer) → optional vehicle
//        inventory sheet label rebuild (UI_VehicleInvSheet_RebuildStatsLabels).
//     3) Else if gate +0xfe and resolved reaction target is local-related →
//        FUN_008027e0(owner) UI panel stack teardown.
//     4) Common: FUN_0083bf40(uiHost+0x590, hb) skill-list remove.
//
// ABI:
//   __stdcall; two stack args; RET 0x8.
//   Arg1 = skill HB*; Arg2 present but unused (caller pushes 0).
//   Not thiscall. Void return.
//
// Dual: reviews/A|B_aa_00802b70_Client_SkillHB_OnEndUiCleanup_Inferred.md
// =============================================================================

#include <cstdint>

// Globals (image addresses)
extern "C" void* DAT_00d1d8e0;   // UI tracker; +0x514 = bound skill HB*
extern "C" void* DAT_00d1b6d8;   // local player object*
extern "C" int*  DAT_00d1b8b8;   // vehicle inventory sheet*
extern "C" void* DAT_00d1b8ec;   // UI host; +0x590 = skill-list controller

// Callees
// FUN_007fc970 expects ESI = client singleton 0x00d1a840 (not stack/ECX this).
extern "C" void FUN_007fc970(void);

extern "C" void* __fastcall Object_ResolveTargetViaReaction_Inferred(void* host /*ECX*/);

// cdecl — caller ADD ESP,4
extern "C" void FUN_008027e0(void* owner);

extern "C" void UI_VehicleInvSheet_RebuildStatsLabels_Inferred(void* sheet /* stack */);

// stdcall-ish two stack args (callee cleanup matches dualed parent push order)
extern "C" void FUN_0083bf40(void* uiList, void* skillHb);

// Layout (skill HB — absolute offsets used here):
//   +0x18  pOwner
//   +0xfe  non-player path gate (u8)
// Owner / target identity vfuncs:
//   vtbl+0x1dc  compare-key getter (vs DAT_00d1b6d8)
//   vtbl+0x1d4  peer-key getter (vs local+0x250)
// Sheet readiness:
//   DAT_00d1b8b8.vtbl+0x3d8  → bool

void __stdcall Client_SkillHB_OnEndUiCleanup_Inferred(void* skillHb, int /*unused*/)
{
  if (skillHb == nullptr)
    return;

  auto* hb = reinterpret_cast<std::uint8_t*>(skillHb);

  // --- clear UI "current skill" bind when this HB is tracked ---
  if (DAT_00d1d8e0 != nullptr
      && *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(DAT_00d1d8e0) + 0x514)
         == skillHb) {
    // Assembly: MOV ESI, 0x00d1a840; CALL FUN_007fc970
    // (decompiler elides ESI; FUN_007fc970 writes client+0x30a0 sheet fields)
    FUN_007fc970();
  }

  if (DAT_00d1b6d8 == nullptr)
    return;

  void* owner = *reinterpret_cast<void**>(hb + 0x18);
  if (owner == nullptr)
    return;

  auto** ownerVtbl = *reinterpret_cast<void***>(owner);
  using VFn0 = void* (__thiscall*)(void*);
  using VFnBool = char (__thiscall*)(void*);

  void* ownerKey = reinterpret_cast<VFn0>(ownerVtbl[0x1dc / 4])(owner);
  bool isLocalOwned =
      (ownerKey == DAT_00d1b6d8)
      || (reinterpret_cast<VFn0>(ownerVtbl[0x1d4 / 4])(owner)
          == *reinterpret_cast<void**>(
                 reinterpret_cast<std::uint8_t*>(DAT_00d1b6d8) + 0x250));

  if (isLocalOwned) {
    // Player / local-vehicle owned skill ending → rebuild vehicle inv labels.
    if (DAT_00d1b8b8 != nullptr) {
      auto** sheetVtbl = *reinterpret_cast<void***>(DAT_00d1b8b8);
      char ready = reinterpret_cast<VFnBool>(sheetVtbl[0x3d8 / 4])(DAT_00d1b8b8);
      if (ready != 0)
        UI_VehicleInvSheet_RebuildStatsLabels_Inferred(DAT_00d1b8b8);
    }
  } else {
    // Non-player owner path: gate +0xfe and local-related resolved target.
    if (*(hb + 0xfe) == 0)
      return;

    void* resolved = Object_ResolveTargetViaReaction_Inferred(skillHb);
    if (resolved == nullptr)
      return;

    // Live body re-resolves before each vfunc (three CALL sites to 00578270).
    resolved = Object_ResolveTargetViaReaction_Inferred(skillHb);
    auto** rVtbl = *reinterpret_cast<void***>(resolved);
    void* rKey = reinterpret_cast<VFn0>(rVtbl[0x1dc / 4])(resolved);
    if (rKey != DAT_00d1b6d8) {
      resolved = Object_ResolveTargetViaReaction_Inferred(skillHb);
      rVtbl = *reinterpret_cast<void***>(resolved);
      void* localPeer = *reinterpret_cast<void**>(
          reinterpret_cast<std::uint8_t*>(DAT_00d1b6d8) + 0x250);
      if (reinterpret_cast<VFn0>(rVtbl[0x1d4 / 4])(resolved) != localPeer)
        return;
    }

    FUN_008027e0(owner);
  }

  // Common post-branch: remove skill from UI list controller.
  if (DAT_00d1b8ec != nullptr) {
    void* list = *reinterpret_cast<void**>(
        reinterpret_cast<std::uint8_t*>(DAT_00d1b8ec) + 0x590);
    if (list != nullptr)
      FUN_0083bf40(list, skillHb);
  }
}
