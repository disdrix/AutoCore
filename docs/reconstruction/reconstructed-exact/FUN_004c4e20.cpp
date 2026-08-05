// =============================================================================
// FUN_004c4e20
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4e20
// Address:   0x004c4e20  (autoassault.exe, image base 0x400000)
// Body:      004c4e20 – 004c4e71
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; 2026-07-29 dual A/B seal (live Ghidra)
// Exactness: Behavior-preserving rewrite of decompiler + machine CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Max-speed BASE leaf for PushDriveAxes and sibling speed helpers.
//   return *(this+0x1f4)  [+ *(driver+0xd48) if driver && DAT_00b037d4]
//
// SEALED GATES (dual 2026-07-29):
//   - this+0x1f4  f32 always-path base (decimal +500)
//   - driver+0xd48 f32 ADD under (driver!=0 && DAT_00b037d4)
//   - driver via component host vfunc +0x210(arg0=0); re-called on add path
//   - DAT_00b037d4 image default 0 → add path dead in stock image
//   - NOT the same flag as outer PushDrive DAT_00af1854 (bonus multiplier path)
//
// CALL-SITE NOTE:
//   PushDriveAxes (004fbd05): ECX = return of wobj vfunc +0x1d8, not vehicle ESI.
//   Several other callers: ECX = caller this (ESI).
//
// Dual: reviews/A_aa_004c4e20_FUN_004c4e20.md
//       reviews/B_aa_004c4e20_FUN_004c4e20.md
// =============================================================================

extern char DAT_00b037d4;  // image 0; enables base-add of driver+0xd48

float10 __fastcall FUN_004c4e20(int param_1 /* this ECX */)
{
  int iVar1;  // driver*

  // component_host(this)->vfunc[0x210](0)
  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0);

  if ((iVar1 != 0) && (DAT_00b037d4 != '\0')) {
    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0);
    // driver+0xd48 + this+0x1f4
    return (float10)*(float *)(iVar1 + 0xd48) + (float10)*(float *)(param_1 + 0x1f4 /* 500 */);
  }

  // always-path base
  return (float10)*(float *)(param_1 + 0x1f4 /* 500 */);
}
