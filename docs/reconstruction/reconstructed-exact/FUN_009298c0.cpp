// =============================================================================
// FUN_009298c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009298c0
// Address:   0x009298c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009298c0 @ 0x009298c0
// Stable ID: aa_009298c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, goto×1.
//  - Notable callees: FUN_00928e20×2, FUN_00929050, FUN_009294d0, FUN_009298c0.
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

void FUN_009298c0(void)



{

  int in_EAX;

  int iVar1;

  int unaff_ESI;

  int unaff_EDI;

  

  iVar1 = FUN_00928e20();

  if (iVar1 == unaff_ESI) {

    iVar1 = FUN_00928e20();

    if (iVar1 == unaff_EDI) goto LAB_009298e4;

  }

  if (*(int *)(in_EAX + 0x24) == 0) {

    FUN_009294d0();

    return;

  }

LAB_009298e4:

  FUN_00929050();

  return;

}
