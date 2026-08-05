// =============================================================================
// FUN_00753860
// -----------------------------------------------------------------------------
// Stable ID: aa_00753860
// Address:   0x00753860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00753860 @ 0x00753860
// Stable ID: aa_00753860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004406e0×2, FUN_00753860.
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

int FUN_00753860(void)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  

  iVar1 = *(int *)(in_EAX + 0x108);

  if (iVar1 == 0) {

    FUN_004406e0();

    return 0;

  }

  iVar2 = *(int *)(in_EAX + 0x10c);

  FUN_004406e0();

  return iVar2 - iVar1 >> 2;

}
