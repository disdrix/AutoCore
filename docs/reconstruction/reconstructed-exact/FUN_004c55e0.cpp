// =============================================================================
// FUN_004c55e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c55e0
// Address:   0x004c55e0  (autoassault.exe, image base 0x400000)
// Body:      004c55e0 – 004c5699
// System:    input-drive-control
// Generated: 2026-07-23 from raw capture (scaffold)
// Refined:   2026-07-29 dual A/B seal — live Ghidra decompile + read_memory +
//            inspect_memory body bytes. CF ≡ raw (no modernization).
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
//
// PURPOSE:
//   Speed-derived float scale leaf. DriveControlTick multiplies SECTION look
//   vector by this return before FUN_0091a5f0. Other callers zero-gate on ST0.
//
// PATHS:
//   Early (this+0x250 != 0 AND component(+0xa8)+0xf5 == 0):
//     return min( *(f32*)(obj+0x110), *(f32*)(obj+0x10c) )
//   Default:
//     base = FUN_004c4e20(this)                 // aa_004c4e20 → +0x1f4
//     if flags(+0xb8) & 0x1000: base -= 0.7     // DAT_00a0f710
//     else if flags & 0x4000:   base += 0.2     // DAT_00a0f70c
//     return (base + 1.0) * *(f32*)(this+0x1f0)
//
// NOT PushDriveAxes max (aa_004fbc10): different flag deltas and fold field.
//
// Dual:
//   docs/reconstruction/reviews/A_aa_004c55e0_FUN_004c55e0.md
//   docs/reconstruction/reviews/B_aa_004c55e0_FUN_004c55e0.md
// Callee dual:
//   docs/reconstruction/reviews/A_aa_004c4e20_FUN_004c4e20.md
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Constants (read_memory 2026-07-29):
 *   DAT_00a0f70c @ 0x00a0f70c = 0.2f  (LE cd cc 4c 3e)
 *   DAT_00a0f710 @ 0x00a0f710 = 0.7f  (LE 33 33 33 3f)
 *   g_flOne      @ 0x00a0f2a0 = 1.0f
 */

float10 __fastcall FUN_004c55e0(int param_1)

{
  int iVar1;
  uint uVar2;
  float10 fVar3;
  float local_4;

  iVar1 = *(int *)(param_1 + 0x250);
  if ((iVar1 != 0) &&
     (*(char *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xf5) == '\0')) {
    /* min(+0x110, +0x10c) on secondary object */
    if (*(float *)(iVar1 + 0x110) < *(float *)(iVar1 + 0x10c) ||
        *(float *)(iVar1 + 0x110) == *(float *)(iVar1 + 0x10c)) {
      return (float10)*(float *)(iVar1 + 0x110);
    }
    return (float10)*(float *)(iVar1 + 0x10c);
  }
  fVar3 = (float10)FUN_004c4e20();
  local_4 = (float)fVar3;
  uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb8 + param_1);
  if ((uVar2 & 0x1000) == 0) {
    if ((uVar2 & 0x4000) != 0) {
      local_4 = local_4 + DAT_00a0f70c;       /* +0.2 */
    }
  }
  else {
    local_4 = local_4 - DAT_00a0f710;         /* -0.7 priority */
  }
  return ((float10)local_4 + (float10)g_flOne) * (float10)*(float *)(param_1 + 0x1f0);
}
