// =============================================================================
// FUN_00906be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00906be0
// Address:   0x00906be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00906be0 @ 0x00906be0
// Stable ID: aa_00906be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, if×1, while×1.
//  - Notable callees: FUN_00906be0.
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

int __fastcall FUN_00906be0(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = (int *)(param_1 + 0x748);

  do {

    if (param_2 == *piVar2) {

      return iVar1;

    }

    iVar1 = iVar1 + 1;

    piVar2 = piVar2 + 1;

  } while (iVar1 < 8);

  return -1;

}
