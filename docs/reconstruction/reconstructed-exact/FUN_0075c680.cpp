// =============================================================================
// FUN_0075c680
// -----------------------------------------------------------------------------
// Stable ID: aa_0075c680
// Address:   0x0075c680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075c680 @ 0x0075c680
// Stable ID: aa_0075c680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0043f660, FUN_0075b7f0, FUN_0075c680, FUN_00969d10, FUN_00972e50, FUN_009730e0.
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

void FUN_0075c680(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_ESI;

  

  FUN_0075b7f0();

  if ((*(byte *)(*(int *)(unaff_ESI + 8) + 0xbc) & 1) != 0) {

    FUN_00972e50();

  }

  if ((*(uint *)(*(int *)(unaff_ESI + 8) + 0xbc) >> 1 & 1) == 0) {

    iVar1 = *(int *)(unaff_ESI + 8) + 0x40;

  }

  else {

    iVar1 = FUN_009730e0();

  }

  uVar2 = FUN_0043f660();

  FUN_00969d10(iVar1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x50),uVar2);

  return;

}
