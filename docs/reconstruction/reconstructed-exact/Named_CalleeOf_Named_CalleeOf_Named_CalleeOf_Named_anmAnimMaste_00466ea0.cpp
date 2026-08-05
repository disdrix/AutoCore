// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaste_00466ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00466ea0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaster
// Address:   0x00466ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaster: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×12, return×3.
//  - Notable callees: FUN_004673b0×4, FUN_00467320×2, FUN_004540b0, FUN_0045efe0, FUN_00466ea0, FUN_00469c50, FUN_0046a240.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaster
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaste_00466ea0(uint param_1,int param_2,int param_3)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  uint extraout_ECX;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bdc90;

  local_10 = ExceptionList;

  iVar1 = *(int *)(param_2 + 4);

  if (iVar1 == 0) {

    uVar4 = 0;

  }

  else {

    uVar4 = (*(int *)(param_2 + 0xc) - iVar1) / 0x1c;

  }

  if (param_1 != 0) {

    if (iVar1 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x1c;

    }

    ExceptionList = &local_10;

    if (0x9249249U - iVar1 < param_1) {

      ExceptionList = &local_10;

      FUN_004540b0();

      uVar4 = extraout_ECX;

    }

    if (*(int *)(param_2 + 4) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x1c;

    }

    if (uVar4 < iVar1 + param_1) {

      if (0x9249249 - (uVar4 >> 1) < uVar4) {

        uVar4 = 0;

      }

      else {

        uVar4 = uVar4 + (uVar4 >> 1);

      }

      if (*(int *)(param_2 + 4) == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x1c;

      }

      if (uVar4 < iVar1 + param_1) {

        iVar1 = FUN_00469c50();

        uVar4 = iVar1 + param_1;

      }

      pvVar2 = operator_new(uVar4 * 0x1c);

      local_8 = 0;

      FUN_004673b0(param_3,param_3);

      FUN_00467320(param_3);

      FUN_004673b0(*(uint32_t /* width from decompiler */ *)(param_2 + 8),param_3);

      iVar1 = 0;

      if (*(int *)(param_2 + 4) != 0) {

        iVar1 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x1c;

      }

      if (*(void **)(param_2 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_2 + 4));

      }

      *(void **)(param_2 + 0xc) = (void *)(uVar4 * 0x1c + (int)pvVar2);

      *(void **)(param_2 + 8) = (void *)((int)pvVar2 + (param_1 + iVar1) * 0x1c);

      *(void **)(param_2 + 4) = pvVar2;

      ExceptionList = local_10;

      return;

    }

    iVar1 = *(int *)(param_2 + 8);

    if ((uint)((iVar1 - param_3) / 0x1c) < param_1) {

      FUN_004673b0(iVar1,param_3);

      local_8 = 2;

      FUN_00467320(param_3);

      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + param_1 * 0x1c;

    }

    else {

      uVar3 = FUN_004673b0(iVar1,param_3);

      *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar3;

      FUN_0046a240();

    }

    FUN_0045efe0();

  }

  ExceptionList = local_10;

  return;

}
