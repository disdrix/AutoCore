// =============================================================================
// FUN_00584290
// -----------------------------------------------------------------------------
// Stable ID: aa_00584290
// Address:   0x00584290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00584290 @ 0x00584290
// Stable ID: aa_00584290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_004962b0, FUN_00581730, FUN_00583f10, FUN_00584290, FUN_005b46a0.
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

void __fastcall FUN_00584290(int *param_1)



{

  int iVar1;

  

  (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0xfc))();

  FUN_00581730(1);

  (**(code **)(*param_1 + 0x18))(0);

  if (param_1[2] != 0) {

    FUN_00583f10(0,param_1[2],0,0xffffffff);

    if (*(void **)(param_1[2] + 0x78) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1[2] + 0x78));

    }

  }

  if ((uint32_t /* width from decompiler */ *)param_1[2] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[2])(1);

  }

  param_1[2] = 0;

  iVar1 = *(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1);

  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xe898) != 0)) {

    FUN_004962b0();

  }

  if (param_1[8] != 0) {

    FUN_005b46a0();

    param_1[8] = 0;

  }

  return;

}
