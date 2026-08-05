// =============================================================================
// FUN_0063fb50
// -----------------------------------------------------------------------------
// Stable ID: aa_0063fb50
// Address:   0x0063fb50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063fb50 @ 0x0063fb50
// Stable ID: aa_0063fb50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0063fb50.
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

int __thiscall FUN_0063fb50(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  if (0 < param_3) {

    do {

      iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))(iVar2 + param_2,param_3 - iVar2);

      iVar2 = iVar2 + iVar1;

      if (iVar1 == 0) {

        return iVar2;

      }

    } while (iVar2 < param_3);

  }

  return param_3;

}
