// =============================================================================
// FUN_004c3a40 / CVOGObject_SetLocalPosition4_Gated_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3a40
// Address:   0x004c3a40  (autoassault.exe, image base 0x400000)
// Body:      0x004c3a40 – 0x004c3ab0 (113 bytes, ret 4)
// System:    input-drive-control (DriveControlTick callee) + object pose
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      reviews/A_aa_004c3a40_*.md + B_aa_004c3a40_*.md (accept-with-gaps)
// =============================================================================

// PURPOSE:
//   Gated store of float4 into this+0x240..+0x24c (local position override).
//   NaN on xyz → FUN_007a4480(0,"VOG_DEBUG_STOP") then continue (logger no-op @ mode 0).
//   Write iff (component_flags at typeOff+0xb8 & 0xC7) == 0, via FUN_004cb3e0.
//
// Embedded strings:
//   - "VOG_DEBUG_STOP" @ 0x00a15844 (NaN trap only — not primary role)
//
// Sibling getter FUN_004c3ac0: returns this+0x240 when (flags&7)==0.

/*
 * Behavioral notes (2026-07-29 dual):
 * - ABI: __thiscall, ECX=object, stack float* in, ret 4.
 * - NaN checks indices 0,1,2 only; W still stored by leaf.
 * - Gate home differs from SetSteerInput (direct +0xb8 vs wobj ptr +0xb4); mask same 0xC7.
 * - Callers: DriveControlTick @ 0x00922866; FUN_0091a5f0 ×2; FUN_005cc7c0 ×1.
 * - Runtime / differential: OPEN.
 */

void __thiscall FUN_004c3a40(int param_1, float *param_2)
{
  int iVar1;

  iVar1 = _isnan((double)*param_2);
  if (iVar1 == 0) {
    iVar1 = _isnan((double)param_2[1]);
    if (iVar1 == 0) {
      iVar1 = _isnan((double)param_2[2]);
      if (iVar1 == 0) goto LAB_004c3a93;
    }
  }
  /* mode 0 → FUN_007a4480 does not log; fall through either way */
  FUN_007a4480(0, "VOG_DEBUG_STOP");
LAB_004c3a93:
  /* typeOff = *(*(param_1+4)+4); test byte [param_1+typeOff+0xb8], 0xC7 */
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb8 + param_1) & 199) == 0) {
    /* copies param_2[0..3] → param_1+0x240..0x24c */
    FUN_004cb3e0(param_1, param_2);
  }
  return;
}
