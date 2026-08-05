// =============================================================================
// FUN_005202d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005202d0
// Address:   0x005202d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005202d0 @ 0x005202d0
// Stable ID: aa_005202d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, while×1, if×1.
//  - Notable callees: CONCAT31, FUN_005202d0.
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

uint __thiscall FUN_005202d0(int param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  

  piVar1 = (int *)(param_1 + 0x5a0);

  iVar2 = 0;

  while ((*piVar1 != param_2 || (piVar1[1] != param_3))) {

    iVar2 = iVar2 + 1;

    piVar1 = piVar1 + 2;

    if (7 < iVar2) {

      return (uint)piVar1 & 0xffffff00;

    }

  }

  return CONCAT31((int3)((uint)piVar1 >> 8),1);

}
