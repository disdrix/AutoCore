// =============================================================================
// FUN_00824630
// -----------------------------------------------------------------------------
// Stable ID: aa_00824630
// Address:   0x00824630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00824630 @ 0x00824630
// Stable ID: aa_00824630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00824630.
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

uint8_t __fastcall FUN_00824630(int *param_1)



{

  char cVar1;

  uint8_t uVar2;

  

  cVar1 = (**(code **)(*param_1 + 0xd0))();

  if ((cVar1 != '\0') && (param_1[0x142] != 0)) {

    cVar1 = (**(code **)(*(int *)param_1[0x142] + 0xd8))();

    if (cVar1 == '\0') {

      return 1;

    }

  }

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 != '\0') && (param_1[0x12e] != 0)) {

                    /* WARNING: Could not recover jumptable at 0x00824680. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x380))();

    return uVar2;

  }

  return *(uint8_t *)((int)param_1 + 0x497);

}
