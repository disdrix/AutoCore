// =============================================================================
// FUN_005a0470
// -----------------------------------------------------------------------------
// Stable ID: aa_005a0470
// Address:   0x005a0470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a0470 @ 0x005a0470
// Stable ID: aa_005a0470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, goto×1, return×1.
//  - Notable callees: FUN_00409220, FUN_004cb4b0, FUN_005a0470.
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

void __thiscall FUN_005a0470(int param_1,uint *param_2)



{

  uint uVar1;

  uint *puVar2;

  int *piVar3;

  int local_4;

  

  puVar2 = param_2;

  local_4 = param_1;

  param_2 = (uint *)FUN_004cb4b0(param_2);

  if (param_2 != (uint *)*(int *)(param_1 + 0x248)) {

    uVar1 = puVar2[1];

    if ((*(int *)((int)param_2 + 0x14) <= (int)uVar1) &&

       ((*(int *)((int)param_2 + 0x14) < (int)uVar1 || (*(uint *)((int)param_2 + 0x10) <= *puVar2)))

       ) {

      piVar3 = (int *)&param_2;

      goto LAB_005a04b2;

    }

  }

  local_4 = *(int *)(param_1 + 0x248);

  piVar3 = &local_4;

LAB_005a04b2:

  if (*piVar3 != *(int *)(param_1 + 0x248)) {

    FUN_00409220(&param_2,*piVar3);

  }

  return;

}
