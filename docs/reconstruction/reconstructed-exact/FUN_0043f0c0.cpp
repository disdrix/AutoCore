// =============================================================================
// FUN_0043f0c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043f0c0
// Address:   0x0043f0c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043f0c0 @ 0x0043f0c0
// Stable ID: aa_0043f0c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0043f0c0.
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

void FUN_0043f0c0(void)



{

  int *piVar1;

  int iVar2;

  int *in_EAX;

  

  iVar2 = *in_EAX;

  if (iVar2 != 0) {

    piVar1 = (int *)(iVar2 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

                    /* WARNING: Could not recover jumptable at 0x0043f0d1. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*(int *)(iVar2 + 4) + 8))();

      return;

    }

  }

  return;

}
