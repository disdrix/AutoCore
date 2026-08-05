// =============================================================================
// FUN_008fbaf0
// -----------------------------------------------------------------------------
// Stable ID: aa_008fbaf0
// Address:   0x008fbaf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008fbaf0 @ 0x008fbaf0
// Stable ID: aa_008fbaf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007fca10, FUN_008fbaf0, FUN_00933d60.
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

void FUN_008fbaf0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar3;

  

  iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x520) + 0x1dc))();

  if (iVar1 != 0) {

    uVar3 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x660);

    uVar2 = (**(code **)(**(int **)(unaff_ESI + 0x520) + 0x1dc))(uVar3);

    FUN_00933d60(&DAT_00d1a840,uVar2,uVar3);

  }

  FUN_007fca10();

  return;

}
