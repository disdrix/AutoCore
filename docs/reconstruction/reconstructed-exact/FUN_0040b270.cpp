// =============================================================================
// FUN_0040b270
// -----------------------------------------------------------------------------
// Stable ID: aa_0040b270
// Address:   0x0040b270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040b270 @ 0x0040b270
// Stable ID: aa_0040b270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0040b270.
//  - Return sites: 2.

// READABILITY:
// Control-flow (from raw @ 0x0040b270; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_0040b270(int *param_1)`.
//  - Branches: if (param_1 != 0x0); if (*piVar1 == 0).
//  - Returns (2 site(s)): `void`.
//  - Assign `param_1 = *param_1`.




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

void __fastcall FUN_0040b270(int *param_1)



{

  int *piVar1;

  

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    piVar1 = param_1 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

                    /* WARNING: Could not recover jumptable at 0x0040b27e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*param_1 + 8))();

      return;

    }

  }

  return;

}
