// =============================================================================
// FUN_005873a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005873a0
// Address:   0x005873a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005873a0 @ 0x005873a0
// Stable ID: aa_005873a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_005873a0, FUN_005875c0.
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

void __fastcall FUN_005873a0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *local_4;

  

  piVar3 = *(int **)param_1[2];

  if (piVar3 != (int *)param_1[2]) {

    do {

      *(uint32_t /* width from decompiler */ *)(piVar3[2] + 4) = 0;

      piVar3 = (int *)*piVar3;

    } while (piVar3 != (int *)param_1[2]);

  }

  local_4 = param_1 + 6;

  DAT_00b04db8 = 0;

  *local_4 = &PTR_LAB_009d49b8;

  puVar1 = param_1;

  if (param_1[7] != 0) {

    FUN_005875c0(&local_4);

    puVar1 = local_4;

  }

  local_4 = puVar1;

  puVar1 = (uint32_t /* width from decompiler */ *)param_1[2];

  pvVar2 = (void *)*puVar1;

  *puVar1 = puVar1;

  *(uint32_t /* width from decompiler */ *)(param_1[2] + 4) = param_1[2];

  param_1[3] = 0;

  if (pvVar2 != (void *)param_1[2]) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[2]);

}
