// =============================================================================
// Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_005828b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005828b0
// Callee of Named_ClientSpecialEvent_TeleportIn
// Address:   0x005828b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ClientSpecialEvent_TeleportIn: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_005828b0, FUN_0074e910, FUN_0074eb20, FUN_0074ecf0, FUN_0074ed90, FUN_0074ee40, FUN_0079a110, FUN_00989e00.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_ClientSpecialEvent_TeleportIn
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_005828b0(int param_1,void *param_2,uint32_t /* width from decompiler */ param_3,uint8_t param_4)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  void *unaff_EBX;

  float10 fVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  iVar2 = (int)param_2;

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a5434;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x24) != 0) {

    iVar4 = *(int *)(param_1 + 0x2c + (int)param_2 * 4);

    ExceptionList = &local_c;

    if (iVar4 != 0) {

      ExceptionList = &local_c;

      (**(code **)(**(int **)(param_1 + 0x24) + 0x10))(iVar4);

      FUN_0074eb20();

      pvVar1 = *(void **)(param_1 + 0x2c + iVar2 * 4);

      if (pvVar1 != (void *)0x0) {

        FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c + iVar2 * 4) = 0;

    }

    param_2 = operator_new(0x78);

    uStack_4 = 0;

    if (param_2 == (void *)0x0) {

      uVar3 = 0;

    }

    else {

      uVar3 = FUN_0074ed90();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c + iVar2 * 4) = uVar3;

    uStack_4 = 0xffffffff;

    FUN_00989e00(&param_2,param_3);

    iVar4 = FUN_0074ee40(&param_2);

    if (-1 < iVar4) {

      fVar5 = (float10)FUN_0079a110();

      FUN_0074e910(0,(float)fVar5);

      *(uint8_t *)(*(int *)(param_1 + 0x2c + iVar2 * 4) + 0x4c) = param_4;

      (**(code **)(**(int **)(param_1 + 0x24) + 0xc))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c + iVar2 * 4));

      ExceptionList = unaff_EBX;

      return 1;

    }

  }

  ExceptionList = local_c;

  return 0;

}
