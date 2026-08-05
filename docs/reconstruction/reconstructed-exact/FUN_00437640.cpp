// =============================================================================
// FUN_00437640
// -----------------------------------------------------------------------------
// Stable ID: aa_00437640
// Address:   0x00437640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00437640 @ 0x00437640
// Stable ID: aa_00437640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00437640.
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

void __fastcall FUN_00437640(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  

  *param_1 = &PTR_FUN_00a9da80;

  piVar2 = (int *)param_1[1];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

                    /* WARNING: Could not recover jumptable at 0x00437655. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*piVar2 + 8))();

      return;

    }

  }

  return;

}
