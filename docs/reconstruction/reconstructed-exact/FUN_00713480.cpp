// =============================================================================
// FUN_00713480
// -----------------------------------------------------------------------------
// Stable ID: aa_00713480
// Address:   0x00713480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713480 @ 0x00713480
// Stable ID: aa_00713480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00713480.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_00713480(float param_1,float param_2,float param_3)



{

  float fVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  float local_4;

  

  iVar4 = 0;

  local_4 = (param_3 - _DAT_00a10e10) * (param_3 - _DAT_00a10e10);

  iVar3 = 1;

  pfVar2 = (float *)&DAT_00a10e14;

  do {

    fVar1 = (param_3 - *pfVar2) * (param_3 - *pfVar2);

    if (fVar1 < local_4) {

      iVar4 = iVar3;

      local_4 = fVar1;

    }

    pfVar2 = pfVar2 + 1;

    iVar3 = iVar3 + 1;

  } while ((int)pfVar2 < 0xa10e30);

  if ((param_1 - param_2) * (param_1 - param_2) <=

      (*(float *)(&DAT_00a10e10 + iVar4 * 4) - param_2) *

      (*(float *)(&DAT_00a10e10 + iVar4 * 4) - param_2)) {

    return iVar4;

  }

  return iVar4 + 8;

}
