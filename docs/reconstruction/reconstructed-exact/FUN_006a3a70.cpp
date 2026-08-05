// =============================================================================
// FUN_006a3a70
// -----------------------------------------------------------------------------
// Stable ID: aa_006a3a70
// Address:   0x006a3a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a3a70 @ 0x006a3a70
// Stable ID: aa_006a3a70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_006a35e0×3, FUN_006a3840, FUN_006a3a70, FUN_006a3db0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 __fastcall FUN_006a3a70(int *param_1)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  float local_8;

  

  if ((char)param_1[4] != '\0') {

    FUN_006a3840(1);

  }

  do {

    local_8 = 1.0;

    fVar4 = (float10)FUN_006a35e0();

    if ((float10)_DAT_00aaa5e0 < fVar4) {

      local_8 = -1.0;

    }

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

  return (float10)fVar2 * (float10)local_8;

}
