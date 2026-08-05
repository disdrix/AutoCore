// =============================================================================
// CVOGHBBase_SetPartnerLink
// -----------------------------------------------------------------------------
// Stable ID: aa_00604db0
// Address:   0x00604db0  (autoassault.exe, image base 0x400000)
// System:    object / combat-target / HB
// Ghidra:    FUN_00604db0
// Generated: 2026-07-29 W20-S dual seal
// Exactness: Byte-sealed leaf. Bit-for-bit vs retail: body is 5 insn + ret 4.
// =============================================================================

// PURPOSE:
//   Conditionally set HB partner pointer at this+0x24.
//   Write when partner == null (clear) OR partner.owner(+0x18) != this.owner(+0x18).
//   Skip write when partner non-null and owners equal (preserve existing +0x24).
//
// ABI: __thiscall ECX=this, stack partner*, RET 4. Void.
//
// Sole direct caller: Object_SetSelectedTarget (0x005172d0) ×2 — cross-link
// self CVOGHBPlayerTargetingLink ↔ target-side targeting HB after dual new(0x28).
//
// Layout (cross-sealed):
//   +0x18  owner object  (CVOGHBBase_AttachOwnerObject)
//   +0x24  partner HB*
//
// Supersedes scaffold misname:
//   Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_00604db0

#include <cstdint>

void __thiscall CVOGHBBase_SetPartnerLink(int thisHb, int partnerHb)
{
  // 8B 44 24 04  85 C0  74 08  8B 50 18  3B 51 18  74 03  89 41 24  C2 04 00
  if ((partnerHb == 0) ||
      (*(int *)(partnerHb + 0x18) != *(int *)(thisHb + 0x18))) {
    *(int *)(thisHb + 0x24) = partnerHb;
  }
  return;
}
