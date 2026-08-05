// =============================================================================
// FUN_00789430
// -----------------------------------------------------------------------------
// Stable ID: aa_00789430
// Address:   0x00789430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00789430 @ 0x00789430
// Stable ID: aa_00789430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00789430.
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

void FUN_00789430(void)



{

  int *unaff_ESI;

  int unaff_EDI;

  

  if (unaff_ESI != (int *)0x0) {

    (**(code **)(*unaff_ESI + 0x1d8))(0,1,1);

    (**(code **)(*unaff_ESI + 0x15c))(0,unaff_EDI + 0x500);

    (**(code **)(*unaff_ESI + 0x15c))(1,unaff_EDI + 0x504);

    (**(code **)(*unaff_ESI + 0x15c))(2,unaff_EDI + 0x508);

    (**(code **)(*unaff_ESI + 0x1b4))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x4fc));

                    /* WARNING: Could not recover jumptable at 0x00789492. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*unaff_ESI + 0x34c))();

    return;

  }

  return;

}
