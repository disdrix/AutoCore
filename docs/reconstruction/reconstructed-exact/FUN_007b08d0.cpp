// =============================================================================
// FUN_007b08d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b08d0
// Address:   0x007b08d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b08d0 @ 0x007b08d0
// Stable ID: aa_007b08d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00797d70, FUN_007b08d0.
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

void __thiscall FUN_007b08d0(int *param_1,int *param_2)



{

  void *pvVar1;

  char cVar2;

  

  param_1[0x20] = *param_2;

  param_1[0x21] = param_2[1];

  if ((int *)param_1[0x28] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x28] + 0x18))(param_2);

  }

  (**(code **)(*param_1 + 0x2ac))();

  cVar2 = (**(code **)(*param_1 + 0x2c8))();

  if (cVar2 != '\0') {

    (**(code **)(*param_1 + 0x2c4))();

  }

  pvVar1 = (void *)param_1[0xa3];

  if (pvVar1 != (void *)0x0) {

    FUN_00797d70(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0xa3] = 0;

  return;

}
