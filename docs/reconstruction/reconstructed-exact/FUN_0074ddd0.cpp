// =============================================================================
// FUN_0074ddd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074ddd0
// Address:   0x0074ddd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074ddd0 @ 0x0074ddd0
// Stable ID: aa_0074ddd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: return×7, if×6, for×2, while×1.
//  - Notable callees: CONCAT31, FUN_00734830, FUN_0074d530, FUN_0074ddd0, FUN_0074ecf0.
//  - Return sites: 7.

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

void __fastcall FUN_0074ddd0(int *param_1)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t local_1c [4];

  uint32_t /* width from decompiler */ *local_18;

  uint32_t /* width from decompiler */ *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b0917;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = (int)&PTR_FUN_00aa05cc;

  local_18 = (uint32_t /* width from decompiler */ *)0x0;

  local_14 = (uint32_t /* width from decompiler */ *)0x0;

  local_10 = 0;

  local_4 = 2;

  FUN_0074d530(local_1c);

  iVar1 = param_1[6];

  while (puVar3 = local_18, iVar1 != 0) {

    (**(code **)(*param_1 + 0x10))(*(uint32_t /* width from decompiler */ *)(*(int *)param_1[5] + 8));

    iVar1 = param_1[6];

  }

  for (; puVar3 != local_14; puVar3 = puVar3 + 1) {

    pvVar2 = (void *)*puVar3;

    if (pvVar2 != (void *)0x0) {

      FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

  }

  for (puVar3 = *(uint32_t /* width from decompiler */ **)param_1[0xf]; puVar3 != (uint32_t /* width from decompiler */ *)param_1[0xf];

      puVar3 = (uint32_t /* width from decompiler */ *)*puVar3) {

    pvVar2 = (void *)puVar3[3];

    if (pvVar2 != (void *)0x0) {

      local_4._1_3_ = (undefined3)((uint)local_4 >> 8);

      local_4._0_1_ = 3;

      FUN_00734830(pvVar2);

      local_4 = CONCAT31(local_4._1_3_,2);

      if (*(void **)((int)pvVar2 + 0x2c) == (void *)0x0) {

        *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x2c) = 0;

        *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x30) = 0;

        *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x34) = 0;

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar2);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)((int)pvVar2 + 0x2c));

    }

  }

  if (local_18 != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_18);

  }

  if ((void *)param_1[0x12] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x12]);

  }

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  puVar3 = (uint32_t /* width from decompiler */ *)param_1[0xf];

  pvVar2 = (void *)*puVar3;

  *puVar3 = puVar3;

  *(int *)(param_1[0xf] + 4) = param_1[0xf];

  param_1[0x10] = 0;

  if (pvVar2 == (void *)param_1[0xf]) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xf]);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar2);

}
