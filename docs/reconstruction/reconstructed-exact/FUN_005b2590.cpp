// =============================================================================
// FUN_005b2590
// -----------------------------------------------------------------------------
// Stable ID: aa_005b2590
// Address:   0x005b2590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b2590 @ 0x005b2590
// Stable ID: aa_005b2590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×10, return×4, while×1.
//  - Notable callees: FUN_005b2590, FUN_005b2ba0, FUN_00787020.
//  - Return sites: 4.

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

void __fastcall FUN_005b2590(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  void *pvVar2;

  int *piVar3;

  uint uVar4;

  int iVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a6765;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_LAB_009d953c;

  local_4 = 1;

  if ((void *)param_1[0x17] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x17]);

  }

  param_1[0x17] = 0;

  if ((void *)param_1[0x18] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x18]);

  }

  iVar5 = param_1[0x1d];

  param_1[0x18] = 0;

  while( true ) {

    if (iVar5 == 0) {

      FUN_005b2ba0();

      local_4 = 0xffffffff;

      FUN_00787020();

      ExceptionList = local_c;

      return;

    }

    uVar4 = (uint)param_1[0x1c] >> 2;

    iVar5 = uVar4 * -4;

    if ((uint)param_1[0x1b] <= uVar4) {

      uVar4 = uVar4 - param_1[0x1b];

    }

    pvVar2 = *(void **)(*(int *)(param_1[0x1a] + uVar4 * 4) + (param_1[0x1c] + iVar5) * 4);

    if (param_1[0x1d] != 0) {

      param_1[0x1c] = param_1[0x1c] + 1;

      if ((uint)(param_1[0x1b] * 4) <= (uint)param_1[0x1c]) {

        param_1[0x1c] = 0;

      }

      iVar5 = param_1[0x1d] + -1;

      param_1[0x1d] = iVar5;

      if (iVar5 == 0) {

        param_1[0x1c] = 0;

      }

    }

    if (pvVar2 != (void *)0x0) break;

    iVar5 = param_1[0x1d];

  }

  piVar3 = *(int **)((int)pvVar2 + 8);

  if (piVar3 != (int *)0x0) {

    piVar1 = piVar3 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar2);

}
