// =============================================================================
// FUN_005e5590
// -----------------------------------------------------------------------------
// Stable ID: aa_005e5590
// Address:   0x005e5590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e5590 @ 0x005e5590
// Stable ID: aa_005e5590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_005a6170, FUN_005e5590.
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

void __fastcall FUN_005e5590(int *param_1)



{

  int *piVar1;

  

  FUN_005a6170();

  piVar1 = (int *)param_1[0x66];

  if (piVar1 != (int *)param_1[0x67]) {

    do {

      if ((uint32_t /* width from decompiler */ *)*piVar1 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar1)(1);

      }

      *piVar1 = 0;

      piVar1 = piVar1 + 1;

    } while (piVar1 != (int *)param_1[0x67]);

  }

                    /* WARNING: Could not recover jumptable at 0x005e55ca. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x4c))();

  return;

}
