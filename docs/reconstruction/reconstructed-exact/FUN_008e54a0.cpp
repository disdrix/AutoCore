// =============================================================================
// FUN_008e54a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e54a0
// Address:   0x008e54a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e54a0 @ 0x008e54a0
// Stable ID: aa_008e54a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_008e3cd0×2, FUN_0040f0c0, FUN_008e4b40, FUN_008e5350, FUN_008e54a0.
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

void FUN_008e54a0(void)



{

  int iVar1;

  int unaff_ESI;

  int iVar2;

  

  FUN_0040f0c0(*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x7ec) + 4));

  *(int *)(*(int *)(unaff_ESI + 0x7ec) + 4) = *(int *)(unaff_ESI + 0x7ec);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x7f0) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x7ec) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x7ec);

  *(int *)(*(int *)(unaff_ESI + 0x7ec) + 8) = *(int *)(unaff_ESI + 0x7ec);

  FUN_008e5350(unaff_ESI);

  FUN_008e3cd0(unaff_ESI + 0x568);

  iVar2 = 0;

  iVar1 = unaff_ESI + 0x61c;

  do {

    FUN_008e3cd0(iVar1 + -100);

    iVar2 = iVar2 + 1;

    iVar1 = iVar1 + 0x14;

  } while (iVar2 < 5);

  FUN_008e4b40(unaff_ESI);

  *(uint8_t *)(unaff_ESI + 0x7e3) = 0;

  return;

}
