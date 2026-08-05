// =============================================================================
// FUN_0046c380
// -----------------------------------------------------------------------------
// Stable ID: aa_0046c380
// Address:   0x0046c380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046c380 @ 0x0046c380
// Stable ID: aa_0046c380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0046c380, FUN_0046c450, FUN_0046c680.
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

int FUN_0046c380(void)



{

  int *in_EAX;

  int iVar1;

  int *piVar2;

  int unaff_EDI;

  

  iVar1 = FUN_0046c680();

  if ((iVar1 == *(int *)(unaff_EDI + 4)) ||

     ((*in_EAX << 0x10 | in_EAX[1]) < (int)(*(int *)(iVar1 + 0xc) << 0x10 | *(uint *)(iVar1 + 0x10))

     )) {

    piVar2 = (int *)FUN_0046c450(iVar1);

    iVar1 = *piVar2;

  }

  return iVar1 + 0x14;

}
