// =============================================================================
// UI_InteractionMenu_RebuildPopupShell_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0082d2b0
// Address:   0x0082d2b0 – 0x0082d3ce exclusive (autoassault.exe, base 0x400000)
// Size:      0x11E (286 B); RET (C3) @ 0x0082d3cd; pad CC
// System:    skills-abilities / interaction-menu UI shell (shared popup host)
// Generated: 2026-08-05 MEGA-072 dual (live decompile ≡ raw 2026-07-23 + asm seal)
// Exactness: Behavior-preserving; not modernization. Bit-exact vs EXE: OPEN.
// Prior:     FUN_0082d2b0 scaffold; Named_CalleeOf_Skill_i_m_qb_… scaffold RETIRED
// =============================================================================
//
// PURPOSE: When menu host+0x4C0 is active, rebuild the popup shell: replace the
// owned CNDHash at +0x534, destroy prior dialog at +0x538, construct a 0x488
// NDUI dialog, load i_d_pop_2d_wnd_blocker.xml at layer 70000, reattach, update
// depth counters, and fire host vtbl+0x3f4(1). Shared by interaction-menu
// populate (dualed parent 0x0082fe20), skill menu, equip menu, and peers.
//
// ABI: __thiscall; ECX = menu host*; void; ret 0 (no stack cleanup).
// SEH: LAB_009b3381.
// DATA vtbl slot: 0x00a733b8 → this VA.
// Peer dual: CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred
//            (tears down +0x534 hash; not this unit).
// =============================================================================

#include <cstdint>

struct MenuHost;
struct CndHash;
struct NdUiDialog;

// operator_new @ 0x00489892
extern "C" void* __cdecl operator_new(std::uint32_t size);

// 0x34-byte owned hash/container ctor; call site passes CL=2 flag byte.
// Peer dual tags store slot +0x534 as CNDHash*.
extern "C" CndHash* __fastcall FUN_00416920(std::uint8_t flag_cl, void* mem);

// 0x488-byte NDUI dialog/window ctor (PTR_FUN_00a960ac family).
extern "C" NdUiDialog* FUN_007b5dd0(void* mem, std::uint32_t arg1);

// __thiscall
extern "C" void __thiscall UI_InteractionMenu_RebuildPopupShell_Inferred(
    MenuHost* host)
{
  auto* h = reinterpret_cast<std::uint8_t*>(host);
  auto** vtbl = *reinterpret_cast<void***>(host);

  // Gate: host+0x4C0 must be non-zero (same as dualed populate parent).
  if (*reinterpret_cast<std::int32_t*>(h + 0x4c0) == 0) {
    return;
  }

  // Pre-clear / detach prior shell content.
  reinterpret_cast<void(__thiscall*)(MenuHost*)>(vtbl[0x450 / 4])(host);

  // Replace owned CNDHash* @ +0x534 (new 0x34 + ctor flag CL=2).
  void* mem34 = operator_new(0x34);
  CndHash* hash = nullptr;
  if (mem34 != nullptr) {
    hash = FUN_00416920(/*CL=*/2, mem34);
  }
  *reinterpret_cast<CndHash**>(h + 0x534) = hash;

  // Reset depth counters / secondary flag.
  *reinterpret_cast<std::int32_t*>(h + 0x68) = 0;           // count
  *reinterpret_cast<float*>(h + 0x74) = 0.0f;               // float depth
  if (*reinterpret_cast<std::int32_t*>(h + 0x70) < 0) {     // max clamp
    *reinterpret_cast<std::int32_t*>(h + 0x70) = 0;
  }
  *reinterpret_cast<std::int32_t*>(h + 0x4a4) = 0;

  // Destroy prior popup dialog @ +0x538 via host vtbl+0xbc.
  auto* old_dialog = *reinterpret_cast<NdUiDialog**>(h + 0x538);
  if (old_dialog != nullptr) {
    reinterpret_cast<void(__thiscall*)(MenuHost*, NdUiDialog*)>(
        vtbl[0xbc / 4])(host, old_dialog);
  }

  // Construct NDUI dialog (0x488) and attach via host vtbl+0xa8.
  NdUiDialog* dialog = nullptr;
  void* mem488 = operator_new(0x488);
  if (mem488 != nullptr) {
    dialog = FUN_007b5dd0(mem488, 0);
  }
  reinterpret_cast<void(__thiscall*)(MenuHost*, NdUiDialog*)>(
      vtbl[0xa8 / 4])(host, dialog);

  // Load blocker XML + high z-order layer (70000 = 0x11170).
  auto** dvtbl = *reinterpret_cast<void***>(dialog);
  reinterpret_cast<void(__thiscall*)(NdUiDialog*, const char*)>(
      dvtbl[0x28 / 4])(dialog, "i_d_pop_2d_wnd_blocker.xml");
  reinterpret_cast<void(__thiscall*)(NdUiDialog*, std::int32_t)>(
      dvtbl[0x74 / 4])(dialog, 70000);

  // Bump depth, store dialog, write -(float)count, update max.
  std::int32_t count = *reinterpret_cast<std::int32_t*>(h + 0x68) + 1;
  *reinterpret_cast<std::int32_t*>(h + 0x68) = count;
  *reinterpret_cast<NdUiDialog**>(h + 0x538) = dialog;
  *reinterpret_cast<float*>(h + 0x74) = static_cast<float>(-count);
  if (*reinterpret_cast<std::int32_t*>(h + 0x70) < count) {
    *reinterpret_cast<std::int32_t*>(h + 0x70) = count;
  }

  // Post-rebuild notify.
  reinterpret_cast<void(__thiscall*)(MenuHost*, std::int32_t)>(
      vtbl[0x3f4 / 4])(host, 1);
}
