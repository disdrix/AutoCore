// =============================================================================
// FUN_007031d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007031d0
// Address:   0x007031d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007031d0 @ 0x007031d0
// Stable ID: aa_007031d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_007031d0, rand.
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



void FUN_007031d0(float param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  if (0 < param_3) {

    do {

      iVar1 = rand();

      iVar2 = iVar2 + 1;

      *(float *)(param_2 + -4 + iVar2 * 4) =

           ((float)iVar1 * _DAT_009eb468 - (float)_DAT_00aaa5e0) * param_1 * (float)_DAT_009cd988 +

           *(float *)(param_2 + -4 + iVar2 * 4);

    } while (iVar2 < param_3);

  }

  return;

}
