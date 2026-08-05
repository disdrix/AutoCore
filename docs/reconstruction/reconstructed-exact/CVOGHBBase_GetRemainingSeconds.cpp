// READABILITY (auto CF):
//  - Body size: 54 bytes machine; ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: none (leaf).
//  - Strings (callers): "Remaining".
//  - Return sites: 1 (float ST0).

// =============================================================================
// CVOGHBBase_GetRemainingSeconds
// -----------------------------------------------------------------------------
// Purpose:  UI helper — seconds remaining until next HB fire from
//           (period - elapsed) using g_dwClientTickMs and dwLastFireTickMs,
//           plus multi-period stack via nPeriodCounter.
//
// Address:  0x00508280  (autoassault.exe, image base 0x400000)
// Stable:   aa_00508280
// System:   heartbeat / timed-actions
//
// Layout binds (machine-sealed 2026-07-29):
//   this+0x08  nPeriodMs          real pulse period (ms)  — used here + TryFire
//   this+0x0C  nPeriodSentinel    NOT read by this function (SetPeriodAndCounter)
//   this+0x10  nPeriodCounter     multi-period residual count
//   this+0x14  dwLastFireTickMs   last fire / stamp tick
//
// Globals:
//   g_dwClientTickMs          @ 0x00b041cc
//   _DAT_00aaa5dc             @ 0x00aaa5dc = 2^32 float (signed-neg fild bias)
//   g_flMsToSeconds_Inferred  @ 0x00a0f72c = 0.001f
//
// Inputs:  ECX = CVOGHBBase*
// Output:  float seconds in ST0
// Used by: UI "Remaining" tooltips, readiness gates, debug dumps — not list schedule.
//
// Exactness: CF mirrors raw + machine; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-29 (residual seal)
// =============================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* TimedAction_GetRemainingSeconds - UI helper: remaining time until next fire as float seconds
   (integer ms * 0.001). Used for "Remaining" tooltips. */
float __fastcall CVOGHBBase_GetRemainingSeconds(CVOGHBBase *this)
{
  float fVar1;
  int iVar2;

  /* base remaining in current period; clamp at 0 (not yet due → 0 base) */
  iVar2 = (this->dwLastFireTickMs - g_dwClientTickMs) + this->nPeriodMs; /* +0x14, +0x08 */
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  /* stack additional full periods from counter residual */
  iVar2 = (this->nPeriodCounter + -1) * this->nPeriodMs + iVar2; /* +0x10, +0x08 */
  fVar1 = (float)iVar2;
  if (iVar2 < 0) {
    fVar1 = fVar1 + _DAT_00aaa5dc; /* 2^32 unsigned assist */
  }
  return fVar1 * g_flMsToSeconds_Inferred; /* 0.001f */
}
