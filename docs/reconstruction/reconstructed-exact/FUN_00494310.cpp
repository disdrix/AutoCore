// =============================================================================
// FUN_00494310
// -----------------------------------------------------------------------------
// Stable ID: aa_00494310
// Address:   0x00494310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00494310 @ 0x00494310
// Stable ID: aa_00494310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×13, goto×1, return×1.
//  - Notable callees: FUN_00494310.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_00494310(int param_1,int param_2)



{

  int iVar1;

  float fVar2;

  float fVar3;

  uint32_t /* width from decompiler */ local_4;

  

  if (0x8000 < *(int *)(param_1 + 100)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  }

  if (0x8000 < *(int *)(param_1 + 0x68)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  }

  if (*(int *)(param_1 + 100) < 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  }

  if (*(int *)(param_1 + 0x68) < 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  }

  if (*(uint *)(param_1 + 4) < *(uint *)(param_1 + 0x6c)) {

    *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 4);

  }

  if (*(uint *)(param_1 + 8) < *(uint *)(param_1 + 0x70)) {

    *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 8);

  }

  if (param_2 == 0) {

    fVar2 = 0.0;

    if (*(int *)(param_1 + 100) == 0) {

      fVar3 = 0.0;

    }

    else {

      fVar3 = (float)*(int *)(param_1 + 100) * DAT_00aefa50;

    }

    *(float *)(param_1 + 0x74) = fVar3;

    if (*(int *)(param_1 + 0x68) != 0) {

      fVar2 = (float)*(int *)(param_1 + 0x68) * DAT_00aefa50;

    }

    *(float *)(param_1 + 0x7c) = fVar2;

    iVar1 = *(int *)(param_1 + 0x70) + 1;

    *(float *)(param_1 + 0x80) = (float)(*(int *)(param_1 + 0x6c) + 1) * DAT_00aefa50;

  }

  else {

    fVar2 = 0.0;

    if (DAT_00aefa50 * (float)(*(int *)(param_1 + 100) + -1) <= 0.0) {

      fVar3 = 0.0;

    }

    else {

      fVar3 = DAT_00aefa50 * (float)(*(int *)(param_1 + 100) + -1);

    }

    *(float *)(param_1 + 0x74) = fVar3;

    if (0.0 < DAT_00aefa50 * (float)(*(int *)(param_1 + 0x68) + -1)) {

      fVar2 = DAT_00aefa50 * (float)(*(int *)(param_1 + 0x68) + -1);

    }

    *(float *)(param_1 + 0x7c) = fVar2;

    fVar2 = (float)*(int *)(param_2 + 0x10) * *(float *)(param_2 + 0x18);

    if (DAT_00aefa50 * (float)(*(int *)(param_1 + 0x6c) + 2) < fVar2) {

      fVar2 = DAT_00aefa50 * (float)(*(int *)(param_1 + 0x6c) + 2);

    }

    *(float *)(param_1 + 0x80) = fVar2;

    local_4 = (float)*(int *)(param_2 + 0x14) * *(float *)(param_2 + 0x18);

    if (local_4 <= (float)(*(int *)(param_1 + 0x70) + 2) * DAT_00aefa50) goto LAB_0049451c;

    iVar1 = *(int *)(param_1 + 0x70) + 2;

  }

  local_4 = (float)iVar1;

  local_4 = local_4 * DAT_00aefa50;

LAB_0049451c:

  *(float *)(param_1 + 0x88) = local_4;

  return;

}
