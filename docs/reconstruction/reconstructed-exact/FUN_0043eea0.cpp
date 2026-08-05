// =============================================================================
// FUN_0043eea0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043eea0
// Address:   0x0043eea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043eea0 @ 0x0043eea0
// Stable ID: aa_0043eea0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0043eea0, FUN_00752370, FUN_00752800, FUN_0096fdf0.
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

uint32_t /* width from decompiler */ FUN_0043eea0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ in_EAX;

  int *piVar2;

  int *unaff_EDI;

  int local_4;

  

  piVar2 = &local_4;

  if (*unaff_EDI == 0) {

    local_4 = -1;

  }

  else {

    piVar2 = (int *)FUN_00752370(&local_4,in_EAX);

  }

  iVar1 = *piVar2;

  if (-1 < iVar1) {

    FUN_0096fdf0();

    FUN_00752800(iVar1);

    return 0;

  }

  return 1;

}
