// =============================================================================
// FUN_0097c560
// -----------------------------------------------------------------------------
// Stable ID: aa_0097c560
// Address:   0x0097c560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0097c560 @ 0x0097c560
// Stable ID: aa_0097c560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×10, return×5, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_004b99c0, FUN_0076c4d0, FUN_0097af10, FUN_0097c560.
//  - Return sites: 5.

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

void __fastcall FUN_0097c560(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  undefined **local_14;

  int local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009b497f;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a6696c;

  local_4 = 2;

  iVar1 = param_1[0xaa];

  if (iVar1 != 0) {

    *(uint8_t *)(iVar1 + 0x48) = 1;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x40);

    FUN_0076c4d0();

    local_14 = &PTR_LAB_00a9f4d8;

    local_10 = iVar1;

    (**(code **)(**(int **)(iVar1 + 8) + 0x20))(&local_14);

    (**(code **)(**(int **)(iVar1 + 8) + 0x10))(0);

  }

  puVar3 = (uint32_t /* width from decompiler */ *)param_1[0x155];

  if (puVar3 != (uint32_t /* width from decompiler */ *)param_1[0x156]) {

    do {

      pvVar2 = (void *)*puVar3;

      if (pvVar2 != (void *)0x0) {

        FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar2);

      }

      puVar3 = puVar3 + 1;

    } while (puVar3 != (uint32_t /* width from decompiler */ *)param_1[0x156]);

  }

  if ((void *)param_1[0x155] == (void *)0x0) {

    param_1[0x155] = 0;

    param_1[0x156] = 0;

    param_1[0x157] = 0;

    if ((uint32_t /* width from decompiler */ *)param_1[0x143] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x143])(1);

    }

    param_1[0x143] = 0;

    if ((uint32_t /* width from decompiler */ *)param_1[0x144] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x144])(1);

    }

    param_1[0x144] = 0;

    if ((uint32_t /* width from decompiler */ *)param_1[0x145] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x145])(1);

    }

    param_1[0x145] = 0;

    if ((uint32_t /* width from decompiler */ *)param_1[0x146] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x146])(1);

    }

    param_1[0x146] = 0;

    FUN_0097af10();

    local_4 = CONCAT31(local_4._1_3_,1);

    if ((void *)param_1[0x155] == (void *)0x0) {

      param_1[0x155] = 0;

      param_1[0x156] = 0;

      param_1[0x157] = 0;

      local_4 = (uint)local_4._1_3_ << 8;

      puVar3 = (uint32_t /* width from decompiler */ *)param_1[0x152];

      pvVar2 = (void *)*puVar3;

      *puVar3 = puVar3;

      *(uint32_t /* width from decompiler */ *)(param_1[0x152] + 4) = param_1[0x152];

      param_1[0x153] = 0;

      if (pvVar2 == (void *)param_1[0x152]) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)param_1[0x152]);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x155]);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x155]);

}
