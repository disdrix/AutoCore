// =============================================================================
// FUN_005a4e60
// -----------------------------------------------------------------------------
// Stable ID: aa_005a4e60
// Address:   0x005a4e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a4e60 @ 0x005a4e60
// Stable ID: aa_005a4e60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_005a4e60.
//  - Return sites: 3.

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

void FUN_005a4e60(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  piVar1 = DAT_00b05060;

  if (DAT_00b05060 == (int *)0x0) {

    DAT_00b05060 = (int *)param_1;

    return;

  }

  DAT_00b05060[1] = DAT_00b05060[1] + -1;

  if (piVar1[1] == 0) {

    (**(code **)(*piVar1 + 0x20))(1);

    DAT_00b05060 = (int *)unaff_retaddr;

    return;

  }

  DAT_00b05060 = (int *)param_1;

  return;

}
