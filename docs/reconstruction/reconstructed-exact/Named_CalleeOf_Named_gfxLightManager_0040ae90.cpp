// =============================================================================
// Named_CalleeOf_Named_gfxLightManager_0040ae90
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ae90
// Callee of Named_gfxLightManager
// Address:   0x0040ae90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxLightManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0040ae90.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxLightManager
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_gfxLightManager_0040ae90(void)



{

  int *piVar1;

  int *piVar2;

  int *in_EAX;

  

  piVar2 = (int *)*in_EAX;

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

                    /* WARNING: Could not recover jumptable at 0x0040ae9e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*piVar2 + 8))();

      return;

    }

  }

  return;

}
