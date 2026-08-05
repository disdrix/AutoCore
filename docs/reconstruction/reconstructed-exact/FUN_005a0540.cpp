// =============================================================================
// FUN_005a0540
// -----------------------------------------------------------------------------
// Stable ID: aa_005a0540
// Address:   0x005a0540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a0540 @ 0x005a0540
// Stable ID: aa_005a0540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, goto×1.
//  - Notable callees: FUN_004e2320, FUN_005a0540.
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

uint32_t /* width from decompiler */ __thiscall FUN_005a0540(int param_1,uint param_2,int param_3)



{

  int *piVar1;

  int local_4;

  

  local_4 = param_1;

  local_4 = FUN_004e2320(&param_2);

  if (local_4 != *(int *)(param_1 + 0xbc)) {

    if ((*(int *)(local_4 + 0x14) <= param_3) &&

       ((*(int *)(local_4 + 0x14) < param_3 || (*(uint *)(local_4 + 0x10) <= param_2)))) {

      piVar1 = &local_4;

      goto LAB_005a0584;

    }

  }

  piVar1 = (int *)&param_2;

LAB_005a0584:

  if (*piVar1 != *(int *)(param_1 + 0xbc)) {

    return *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x18);

  }

  return 0;

}
