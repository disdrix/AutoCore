// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs_004d9cd0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d9cd0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update
// Address:   0x004d9cd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, do×1, while×1.
//  - Notable callees: FUN_004aaa20, FUN_004ac0e0, FUN_004ac100, FUN_004ad730, FUN_004ce370, FUN_004d8270, FUN_004d9cd0, _eh_vector_constructor_iterator_.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update
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

uint8_t __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs_004d9cd0(int *param_1)



{

  float fVar1;

  char cVar2;

  void *pvVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  int iVar8;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a226c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar3 = operator_new(0x3fc);

  local_4 = 0;

  if (pvVar3 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_004ad730();

  }

  param_1[0x393e] = iVar4;

  *(int **)(iVar4 + 0x340) = param_1;

  local_4 = 0xffffffff;

  cVar2 = FUN_004aaa20(param_1 + 0x3866);

  if (cVar2 == '\0') {

    ExceptionList = local_c;

    return 0;

  }

  FUN_004ac0e0();

  (**(code **)(*param_1 + 8))();

  fVar1 = DAT_00a0f6a4;

  iVar4 = param_1[0x393e];

  iVar8 = (int)(*(int *)(iVar4 + 0x10) + (*(int *)(iVar4 + 0x10) >> 0x1f & 7U)) >> 3;

  param_1[0x39ee] = iVar8;

  iVar5 = (int)(*(int *)(iVar4 + 0x14) + (*(int *)(iVar4 + 0x14) >> 0x1f & 7U)) >> 3;

  param_1[0x39ef] = iVar5;

  iVar5 = iVar5 * iVar8;

  param_1[0x39f0] = (int)(*(float *)(iVar4 + 0x18) * fVar1);

  param_1[0x39f1] = (int)(*(float *)(iVar4 + 0x18) * fVar1);

  piVar6 = operator_new__(iVar5 * 0x20 + 4);

  local_4 = 1;

  if (piVar6 == (int *)0x0) {

    piVar7 = (int *)0x0;

  }

  else {

    piVar7 = piVar6 + 1;

    *piVar6 = iVar5;

    _eh_vector_constructor_iterator_(piVar7,0x20,iVar5,FUN_004e45a0,FUN_004e45e0);

  }

  local_4 = 0xffffffff;

  param_1[0x39ed] = (int)piVar7;

  local_10 = 0;

  if (0 < param_1[0x39ef] * param_1[0x39ee]) {

    iVar4 = 0;

    do {

      pvVar3 = *(void **)(param_1[0x39ed] + 4 + iVar4);

      iVar5 = param_1[0x39ed] + iVar4;

      if (pvVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar3);

      }

      *(uint32_t /* width from decompiler */ *)(iVar5 + 4) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 8) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc) = 0;

      pvVar3 = *(void **)(param_1[0x39ed] + 0x14 + iVar4);

      iVar5 = param_1[0x39ed] + 0x10 + iVar4;

      if (pvVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar3);

      }

      *(uint32_t /* width from decompiler */ *)(iVar5 + 4) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 8) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc) = 0;

      local_10 = local_10 + 1;

      iVar4 = iVar4 + 0x20;

    } while (local_10 < param_1[0x39ef] * param_1[0x39ee]);

  }

  FUN_004ce370();

  if (*(char *)((int)param_1 + 0x7d) == '\0') {

    FUN_004d8270();

  }

  FUN_004ac100(0);

  ExceptionList = local_c;

  return 1;

}
