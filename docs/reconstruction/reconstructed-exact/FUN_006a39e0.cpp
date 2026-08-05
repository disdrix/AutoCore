// =============================================================================
// FUN_006a39e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a39e0
// Address:   0x006a39e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a39e0 @ 0x006a39e0
// Stable ID: aa_006a39e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_006a35e0×3, FUN_006a3840, FUN_006a39e0, FUN_006a3db0.
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

float10 __fastcall FUN_006a39e0(int *param_1)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  

  if ((char)param_1[4] != '\0') {

    FUN_006a3840(0);

  }

  do {

    FUN_006a35e0();

    iVar3 = FUN_006a3db0();

    fVar2 = *(float *)(param_1[2] + iVar3 * 4);

    fVar4 = (float10)FUN_006a35e0();

    pfVar1 = (float *)(param_1[3] + iVar3 * 4);

    fVar2 = (float)(((float10)*(float *)(param_1[2] + 4 + iVar3 * 4) - (float10)fVar2) * fVar4 +

                   (float10)fVar2);

    fVar4 = (float10)FUN_006a35e0();

    fVar4 = fVar4 * (float10)*pfVar1;

    if (fVar4 < (float10)pfVar1[1]) break;

    fVar5 = (float10)(**(code **)(*param_1 + 0xc))(fVar2);

    fVar4 = (float10)(float)fVar4;

  } while (fVar5 < fVar4 != (fVar5 == fVar4));

  return (float10)fVar2;

}
