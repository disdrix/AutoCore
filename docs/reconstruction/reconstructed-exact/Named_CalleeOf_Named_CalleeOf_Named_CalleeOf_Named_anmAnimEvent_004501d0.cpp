// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_anmAnimEvent_004501d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004501d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_anmAnimEventsImpl
// Address:   0x004501d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_anmAnimEventsImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×12, return×2, for×2.
//  - Notable callees: FUN_00450600×4, CONCAT31×2, FUN_0044ffa0×2, FUN_00450560×2, FUN_00444100, FUN_004501a0, FUN_004501d0, FUN_00450530.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_anmAnimEventsImpl
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_anmAnimEvent_004501d0(int param_1,int param_2,uint param_3,int param_4)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  uint extraout_ECX;

  undefined **local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint8_t local_28 [16];

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009becf8;

  local_10 = ExceptionList;

  local_30 = *(uint32_t /* width from decompiler */ *)(param_4 + 4);

  local_2c = *(uint32_t /* width from decompiler */ *)(param_4 + 8);

  local_14 = &stack0xffffffc0;

  local_34 = &PTR_FUN_009d4828;

  ExceptionList = &local_10;

  FUN_00444100(local_28);

  uVar4 = 0;

  local_8 = 0;

  iVar1 = *(int *)(param_1 + 4);

  if (iVar1 != 0) {

    uVar4 = (*(int *)(param_1 + 0xc) - iVar1) / 0x1c;

  }

  if (param_3 != 0) {

    if (iVar1 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

    }

    if (0x9249249U - iVar1 < param_3) {

      FUN_004540b0();

      uVar4 = extraout_ECX;

    }

    if (*(int *)(param_1 + 4) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

    }

    if (uVar4 < iVar1 + param_3) {

      if (0x9249249 - (uVar4 >> 1) < uVar4) {

        uVar4 = 0;

      }

      else {

        uVar4 = uVar4 + (uVar4 >> 1);

      }

      if (*(int *)(param_1 + 4) == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

      }

      if (uVar4 < iVar1 + param_3) {

        iVar1 = FUN_00469c50();

        uVar4 = iVar1 + param_3;

      }

      pvVar2 = operator_new(uVar4 * 0x1c);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar1 = FUN_00450600(param_2,pvVar2,param_2);

      FUN_00450560(iVar1,param_2);

      FUN_00450600(*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar1 + param_3 * 0x1c,param_2);

      local_8 = 0;

      iVar1 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

      }

      if (*(int *)(param_1 + 4) != 0) {

        FUN_004501a0(*(int *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8));

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar4 * 0x1c + (int)pvVar2);

      *(void **)(param_1 + 8) = (void *)((int)pvVar2 + (param_3 + iVar1) * 0x1c);

      *(void **)(param_1 + 4) = pvVar2;

    }

    else {

      local_18 = *(int *)(param_1 + 8);

      if ((uint)((local_18 - param_2) / 0x1c) < param_3) {

        FUN_00450600(local_18,param_3 * 0x1c + param_2,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_00450560(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x1c;

        iVar1 = *(int *)(param_1 + 8);

        for (; param_2 != iVar1 + param_3 * -0x1c; param_2 = param_2 + 0x1c) {

          FUN_0044ffa0(param_2,&local_34);

        }

      }

      else {

        uVar3 = FUN_00450600(local_18,local_18,param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

        FUN_00450530();

        iVar1 = param_3 * 0x1c + param_2;

        for (; param_2 != iVar1; param_2 = param_2 + 0x1c) {

          FUN_0044ffa0(param_2,&local_34);

        }

      }

    }

  }

  local_8 = 0xffffffff;

  FUN_00987560();

  ExceptionList = local_10;

  return;

}
