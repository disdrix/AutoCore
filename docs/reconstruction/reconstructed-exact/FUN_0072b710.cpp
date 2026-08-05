// =============================================================================
// FUN_0072b710
// -----------------------------------------------------------------------------
// Stable ID: aa_0072b710
// Address:   0x0072b710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072b710 @ 0x0072b710
// Stable ID: aa_0072b710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: FUN_0072b310×4, FUN_0072b710.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_0072b710(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  float *pfVar1;

  bool bVar2;

  bool bVar3;

  bool bVar4;

  bool bVar5;

  

  pfVar1 = *(float **)(param_1 + 0x1c);

  bVar2 = false;

  bVar3 = false;

  if ((((*pfVar1 < *(float *)(param_2 + 0x18) || *pfVar1 == *(float *)(param_2 + 0x18)) &&

       (*(float *)(param_2 + 0x10) < pfVar1[2] || *(float *)(param_2 + 0x10) == pfVar1[2])) &&

      (pfVar1[1] < *(float *)(param_2 + 0x1c) || pfVar1[1] == *(float *)(param_2 + 0x1c))) &&

     (*(float *)(param_2 + 0x14) < pfVar1[3] || *(float *)(param_2 + 0x14) == pfVar1[3])) {

    bVar2 = true;

  }

  pfVar1 = *(float **)(param_1 + 0x20);

  if (((*pfVar1 < *(float *)(param_2 + 0x18) || *pfVar1 == *(float *)(param_2 + 0x18)) &&

      (*(float *)(param_2 + 0x10) < pfVar1[2] || *(float *)(param_2 + 0x10) == pfVar1[2])) &&

     ((pfVar1[1] < *(float *)(param_2 + 0x1c) || pfVar1[1] == *(float *)(param_2 + 0x1c) &&

      (*(float *)(param_2 + 0x14) < pfVar1[3] || *(float *)(param_2 + 0x14) == pfVar1[3])))) {

    bVar3 = true;

  }

  bVar5 = false;

  bVar4 = false;

  pfVar1 = *(float **)(param_1 + 0x24);

  if (((*pfVar1 < *(float *)(param_2 + 0x18) || *pfVar1 == *(float *)(param_2 + 0x18)) &&

      (*(float *)(param_2 + 0x10) < pfVar1[2] || *(float *)(param_2 + 0x10) == pfVar1[2])) &&

     ((pfVar1[1] < *(float *)(param_2 + 0x1c) || pfVar1[1] == *(float *)(param_2 + 0x1c) &&

      (*(float *)(param_2 + 0x14) < pfVar1[3] || *(float *)(param_2 + 0x14) == pfVar1[3])))) {

    bVar4 = true;

  }

  pfVar1 = *(float **)(param_1 + 0x28);

  if ((((*pfVar1 < *(float *)(param_2 + 0x18) || *pfVar1 == *(float *)(param_2 + 0x18)) &&

       (*(float *)(param_2 + 0x10) < pfVar1[2] || *(float *)(param_2 + 0x10) == pfVar1[2])) &&

      (pfVar1[1] < *(float *)(param_2 + 0x1c) || pfVar1[1] == *(float *)(param_2 + 0x1c))) &&

     (*(float *)(param_2 + 0x14) < pfVar1[3] || *(float *)(param_2 + 0x14) == pfVar1[3])) {

    bVar5 = true;

  }

  if (bVar2) {

    if (((bVar3) && (bVar4)) && (bVar5)) {

      return 0;

    }

    FUN_0072b310(param_2,param_3);

  }

  if (bVar3) {

    FUN_0072b310(param_2,param_3);

  }

  if (bVar4) {

    FUN_0072b310(param_2,param_3);

  }

  if (bVar5) {

    FUN_0072b310(param_2,param_3);

  }

  return 1;

}
