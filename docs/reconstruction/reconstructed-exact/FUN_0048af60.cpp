// =============================================================================
// FUN_0048af60
// -----------------------------------------------------------------------------
// Stable ID: aa_0048af60
// Address:   0x0048af60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048af60 @ 0x0048af60
// Stable ID: aa_0048af60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_0048af60.
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

uint32_t /* width from decompiler */ __fastcall FUN_0048af60(int *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  while( true ) {

    if (param_1 == (int *)0x0) {

      return 0;

    }

    iVar1 = (**(code **)(*param_1 + 0x10))();

    if (iVar1 != 0) break;

    param_1 = (int *)param_1[4];

  }

                    /* WARNING: Could not recover jumptable at 0x0048af82. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar2 = (**(code **)(*param_1 + 0x10))();

  return uVar2;

}
