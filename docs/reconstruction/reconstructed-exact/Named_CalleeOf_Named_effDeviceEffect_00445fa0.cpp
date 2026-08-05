// =============================================================================
// Named_CalleeOf_Named_effDeviceEffect_00445fa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00445fa0
// Callee of Named_effDeviceEffect
// Address:   0x00445fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×13, return×3.
//  - Notable callees: FUN_004487d0×4, FUN_0045f220×2, FUN_00418130, FUN_00445fa0, FUN_00447c60, FUN_00447d70.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_effDeviceEffect
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

void __fastcall Named_CalleeOf_Named_effDeviceEffect_00445fa0(uint param_1,int param_2,int param_3)



{

  void *pvVar1;

  uint uVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  int extraout_ECX;

  int iVar6;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd4d0;

  local_10 = ExceptionList;

  iVar3 = *(int *)(param_2 + 4);

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_2 + 0xc) - iVar3 >> 3;

  }

  if (param_1 != 0) {

    if (iVar3 == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = *(int *)(param_2 + 8) - iVar3 >> 3;

    }

    ExceptionList = &local_10;

    if (0x1fffffffU - iVar6 < param_1) {

      ExceptionList = &local_10;

      uVar2 = FUN_00418130();

      iVar3 = extraout_ECX;

    }

    if (iVar3 == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = *(int *)(param_2 + 8) - iVar3 >> 3;

    }

    if (uVar2 < iVar6 + param_1) {

      if (0x1fffffff - (uVar2 >> 1) < uVar2) {

        uVar2 = 0;

      }

      else {

        uVar2 = uVar2 + (uVar2 >> 1);

      }

      if (iVar3 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_2 + 8) - iVar3 >> 3;

      }

      if (uVar2 < iVar6 + param_1) {

        if (iVar3 == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = *(int *)(param_2 + 8) - iVar3 >> 3;

        }

        uVar2 = iVar3 + param_1;

      }

      pvVar4 = operator_new(uVar2 * 8);

      local_8 = 0;

      FUN_004487d0(param_3);

      FUN_0045f220(param_3);

      FUN_004487d0(param_3);

      pvVar1 = *(void **)(param_2 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_2 + 8) - (int)pvVar1 >> 3;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_2 + 0xc) = (void *)(uVar2 * 8 + (int)pvVar4);

      *(void **)(param_2 + 8) = (void *)((int)pvVar4 + (param_1 + iVar3) * 8);

      *(void **)(param_2 + 4) = pvVar4;

      ExceptionList = local_10;

      return;

    }

    iVar3 = param_1 * 8;

    if ((uint)(*(int *)(param_2 + 8) - param_3 >> 3) < param_1) {

      FUN_004487d0(iVar3);

      local_8 = 2;

      FUN_0045f220(iVar3);

      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + iVar3;

    }

    else {

      uVar5 = FUN_004487d0(iVar3);

      *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar5;

      FUN_00447c60();

    }

    FUN_00447d70();

  }

  ExceptionList = local_10;

  return;

}
