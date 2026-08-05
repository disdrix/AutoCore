// =============================================================================
// Named scaffold (HISTORICAL alias) — primary role corrected 2026-07-29
// -----------------------------------------------------------------------------
// Prefer: CVOGObject_SetLocalPosition4_Gated_Inferred / FUN_004c3a40
// Stable ID: aa_004c3a40
// Address:   0x004c3a40
// NOTE: "VOG_DEBUG_STOP" is the NaN-trap string only. FUN_007a4480(0, ...) is a
//       logger no-op. Do not treat this unit as a fatal debug stop.
// Dual: reviews/A_aa_004c3a40_*.md + B_aa_004c3a40_*.md
// =============================================================================

// See FUN_004c3a40.cpp for the authoritative clean plate (same CF).

void __thiscall Named_VOG_DEBUG_STOP_004c3a40(int param_1, float *param_2)
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
  FUN_007a4480(0, "VOG_DEBUG_STOP");
LAB_004c3a93:
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb8 + param_1) & 199) == 0) {
    FUN_004cb3e0(param_1, param_2);
  }
  return;
}
