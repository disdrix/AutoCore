// =============================================================================
// FUN_0074e690
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e690
// Address:   0x0074e690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074e690 @ 0x0074e690
// Stable ID: aa_0074e690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0074e690.
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

float10 __fastcall FUN_0074e690(int param_1)



{

  int *piVar1;

  float10 fVar2;

  

  piVar1 = *(int **)(param_1 + 4);

  if (((piVar1 != (int *)0x0) && (*(int *)(param_1 + 8) - (int)piVar1 >> 2 != 0)) && (*piVar1 != 0))

  {

                    /* WARNING: Could not recover jumptable at 0x0074e6b3. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    fVar2 = (float10)(**(code **)(*(int *)*piVar1 + 4))();

    return fVar2;

  }

  return (float10)g_flZero;

}
