// =============================================================================
// FUN_00468640
// -----------------------------------------------------------------------------
// Stable ID: aa_00468640
// Address:   0x00468640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00468640 @ 0x00468640
// Stable ID: aa_00468640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00468640.
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

void FUN_00468640(int *param_1,int *param_2,int *param_3,int param_4)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = *param_1;

  fVar2 = *(float *)(iVar3 + param_4 * 4);

  iVar4 = *param_2;

  pfVar1 = (float *)(iVar4 + param_4 * 4);

  if ((*pfVar1 <= fVar2 && fVar2 != *pfVar1) ||

     ((*(float *)(iVar4 + param_4 * 4) == *(float *)(iVar3 + param_4 * 4) &&

      (fVar2 = *(float *)(iVar3 + 0xc + param_4 * 4), pfVar1 = (float *)(iVar4 + 0xc + param_4 * 4),

      *pfVar1 <= fVar2 && fVar2 != *pfVar1)))) {

    iVar3 = *param_2;

    *param_2 = *param_1;

    *param_1 = iVar3;

  }

  iVar3 = *param_2;

  fVar2 = *(float *)(iVar3 + param_4 * 4);

  iVar4 = *param_3;

  pfVar1 = (float *)(iVar4 + param_4 * 4);

  if ((*pfVar1 <= fVar2 && fVar2 != *pfVar1) ||

     ((*(float *)(iVar4 + param_4 * 4) == *(float *)(iVar3 + param_4 * 4) &&

      (fVar2 = *(float *)(iVar3 + 0xc + param_4 * 4), pfVar1 = (float *)(iVar4 + 0xc + param_4 * 4),

      *pfVar1 <= fVar2 && fVar2 != *pfVar1)))) {

    iVar3 = *param_3;

    *param_3 = *param_2;

    *param_2 = iVar3;

  }

  iVar3 = *param_1;

  iVar4 = *param_2;

  fVar2 = *(float *)(iVar3 + param_4 * 4);

  pfVar1 = (float *)(iVar4 + param_4 * 4);

  if ((*pfVar1 <= fVar2 && fVar2 != *pfVar1) ||

     ((*(float *)(iVar4 + param_4 * 4) == *(float *)(iVar3 + param_4 * 4) &&

      (fVar2 = *(float *)(iVar3 + 0xc + param_4 * 4), pfVar1 = (float *)(iVar4 + 0xc + param_4 * 4),

      *pfVar1 <= fVar2 && fVar2 != *pfVar1)))) {

    iVar3 = *param_2;

    *param_2 = *param_1;

    *param_1 = iVar3;

  }

  return;

}
