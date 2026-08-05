// =============================================================================
// FUN_007966b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007966b0
// Address:   0x007966b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007966b0 @ 0x007966b0
// Stable ID: aa_007966b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, while×1, return×1.
//  - Notable callees: FUN_007966b0.
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

void FUN_007966b0(void)



{

  int iVar1;

  int in_EAX;

  int *piVar2;

  int iVar3;

  int unaff_ESI;

  int *unaff_EDI;

  

  if ((*(byte *)(in_EAX + 0x24) & 0xed) != 0) {

    (**(code **)(*unaff_EDI + 0x18))();

  }

  iVar3 = 0;

  piVar2 = (int *)(unaff_ESI + 0xc);

  iVar1 = *(int *)(unaff_ESI + 0xc);

  while (iVar1 != 0) {

    piVar2 = piVar2 + 1;

    iVar3 = iVar3 + 1;

    iVar1 = *piVar2;

  }

  *(int **)(unaff_ESI + 0xc + iVar3 * 4) = unaff_EDI;

  (**(code **)(*unaff_EDI + 4))();

  *(int *)(unaff_ESI + 0x1d0) = *(int *)(unaff_ESI + 0x1d0) + 1;

  return;

}
