// =============================================================================
// FUN_007972a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007972a0
// Address:   0x007972a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007972a0 @ 0x007972a0
// Stable ID: aa_007972a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_007972a0.
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

int FUN_007972a0(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int unaff_EBX;

  uint uVar4;

  int iVar5;

  

  iVar1 = 0;

  iVar3 = -99999;

  iVar5 = 0;

  for (uVar4 = 0;

      (*(int *)(unaff_EBX + 0x84) != 0 &&

      (uVar4 < (uint)(*(int *)(unaff_EBX + 0x88) - *(int *)(unaff_EBX + 0x84) >> 7)));

      uVar4 = uVar4 + 1) {

    iVar2 = *(int *)(unaff_EBX + 0x84) + iVar5;

    if (*(int *)(iVar2 + 4) != iVar3) {

      iVar1 = iVar1 + 1;

    }

    iVar3 = *(int *)(iVar2 + 4);

    iVar5 = iVar5 + 0x80;

  }

  return iVar1;

}
