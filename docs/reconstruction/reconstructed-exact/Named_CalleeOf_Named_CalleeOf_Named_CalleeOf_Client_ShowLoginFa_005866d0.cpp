// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFa_005866d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005866d0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFailureDialog
// Address:   0x005866d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFailureDialog: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, do×1, while×1.
//  - Notable callees: FUN_0074ecf0×2, FUN_0040bfc0, FUN_00581730, FUN_005866d0, FUN_0074d420, FUN_0074d750, FUN_0074e910, FUN_0074ed90.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFailureDialog
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFa_005866d0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  float10 fVar7;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a558a;

  local_c = ExceptionList;

  iVar5 = 0;

  piVar3 = param_1 + 0xb;

  do {

    if (*piVar3 == 0) break;

    iVar5 = iVar5 + 1;

    piVar3 = piVar3 + 1;

  } while (iVar5 < 0x13);

  ExceptionList = &local_c;

  if (iVar5 == 0x13) {

    iVar5 = 0x12;

    ExceptionList = &local_c;

    if ((int *)param_1[9] != (int *)0x0) {

      ExceptionList = &local_c;

      (**(code **)(*(int *)param_1[9] + 0x10))(param_1[0x1d]);

    }

    pvVar1 = (void *)param_1[0x1d];

    if (pvVar1 != (void *)0x0) {

      FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    param_1[0x1d] = 0;

  }

  local_10 = operator_new(0x78);

  local_4 = 0;

  if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_0074ed90();

  }

  param_1[iVar5 + 0xb] = iVar4;

  local_4 = 0xffffffff;

  FUN_00989e00(&param_2,param_2);

  iVar4 = FUN_0074ee40(&param_2);

  if (iVar4 < 0) {

    pvVar1 = (void *)param_1[iVar5 + 0xb];

    if (pvVar1 != (void *)0x0) {

      FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    param_1[iVar5 + 0xb] = 0;

  }

  else {

    fVar7 = (float10)FUN_0079a110();

    FUN_0074e910(0,(float)fVar7);

    if (param_1[9] == 0) {

      local_10 = operator_new(0x5c);

      local_4 = 1;

      if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = FUN_0074d750();

      }

      local_4 = 0xffffffff;

      param_1[9] = iVar4;

    }

    if (param_1[10] == 0) {

      local_10 = operator_new(0x14);

      local_4 = 2;

      if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

        puVar6 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        *local_10 = &PTR_FUN_009c7938;

        iVar4 = FUN_0040bfc0();

        local_10[2] = iVar4;

        *(uint8_t *)(iVar4 + 0x19) = 1;

        *(uint32_t /* width from decompiler */ *)(local_10[2] + 4) = local_10[2];

        *(uint32_t /* width from decompiler */ *)local_10[2] = local_10[2];

        *(uint32_t /* width from decompiler */ *)(local_10[2] + 8) = local_10[2];

        local_10[3] = 0;

        *local_10 = &PTR_FUN_009c7948;

        local_10[4] = 0;

        puVar6 = local_10;

      }

      local_4 = 0xffffffff;

      param_1[10] = (int)puVar6;

    }

    FUN_0074d420(param_1[2]);

    (**(code **)(*(int *)param_1[9] + 4))(param_1[10],0);

    (**(code **)(*(int *)param_1[9] + 0xc))(param_1[iVar5 + 0xb]);

    cVar2 = (**(code **)(*(int *)param_1[9] + 0x18))(param_1[iVar5 + 0xb],0,0x3f800000);

    if (cVar2 != '\0') {

      *(uint8_t *)(param_1 + 3) = 1;

      param_1[0x1e] = iVar5;

      (**(code **)(*param_1 + 0x24))(iVar5);

      ExceptionList = local_10;

      return iVar5;

    }

    FUN_00581730(1);

  }

  ExceptionList = local_c;

  return -1;

}
