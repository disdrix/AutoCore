// =============================================================================
// FUN_0084f760
// -----------------------------------------------------------------------------
// Stable ID: aa_0084f760
// Address:   0x0084f760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084f760 @ 0x0084f760
// Stable ID: aa_0084f760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0084f760.
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

void FUN_0084f760(void)



{

  int *piVar1;

  int iVar2;

  int *unaff_ESI;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint8_t local_8 [8];

  

  puStack_10 = local_8;

  uStack_c = 1;

  piVar1 = (int *)(**(code **)(*unaff_ESI + 0x140))();

  unaff_ESI[0x15c] = *piVar1 / 2;

  iVar2 = (**(code **)(*unaff_ESI + 0x140))(&puStack_10,1);

  unaff_ESI[0x15d] = *(int *)(iVar2 + 4) / 2;

  unaff_ESI[0x15a] = unaff_ESI[0x15c];

  unaff_ESI[0x15b] = unaff_ESI[0x15d];

  return;

}
