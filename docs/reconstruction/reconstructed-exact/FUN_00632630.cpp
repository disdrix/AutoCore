// =============================================================================
// FUN_00632630
// -----------------------------------------------------------------------------
// Stable ID: aa_00632630
// Address:   0x00632630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00632630 @ 0x00632630
// Stable ID: aa_00632630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_00632630.
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

void __thiscall FUN_00632630(int param_1,uint8_t *param_2,int *param_3)



{

  int iVar1;

  

  iVar1 = (**(code **)(*param_3 + 0xc))();

  while( true ) {

    if (iVar1 == 0) {

      *param_2 = 0;

      return;

    }

    if (iVar1 == param_1) break;

    iVar1 = *(int *)(iVar1 + 0xc);

  }

  *param_2 = 1;

  return;

}
