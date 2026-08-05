// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxSubPhaseMap_0046d5b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0046d5b0
// Callee of Named_CalleeOf_Named_gfxSubPhaseMap
// Address:   0x0046d5b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxSubPhaseMap: map/sector helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×13, return×3.
//  - Notable callees: FUN_00467370×4, FUN_00440030×2, FUN_004540b0, FUN_0045f050, FUN_00465bc0, FUN_0046d5b0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxSubPhaseMap
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_gfxSubPhaseMap_0046d5b0(uint param_1,int param_2,int param_3)



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

  puStack_c = &LAB_009bcb70;

  local_10 = ExceptionList;

  iVar3 = *(int *)(param_2 + 4);

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_2 + 0xc) - iVar3 >> 4;

  }

  if (param_1 != 0) {

    if (iVar3 == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = *(int *)(param_2 + 8) - iVar3 >> 4;

    }

    ExceptionList = &local_10;

    if (0xfffffffU - iVar6 < param_1) {

      ExceptionList = &local_10;

      uVar2 = FUN_004540b0();

      iVar3 = extraout_ECX;

    }

    if (iVar3 == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = *(int *)(param_2 + 8) - iVar3 >> 4;

    }

    if (uVar2 < iVar6 + param_1) {

      if (0xfffffff - (uVar2 >> 1) < uVar2) {

        uVar2 = 0;

      }

      else {

        uVar2 = uVar2 + (uVar2 >> 1);

      }

      if (iVar3 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_2 + 8) - iVar3 >> 4;

      }

      if (uVar2 < iVar6 + param_1) {

        if (iVar3 == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = *(int *)(param_2 + 8) - iVar3 >> 4;

        }

        uVar2 = iVar3 + param_1;

      }

      pvVar4 = operator_new(uVar2 * 0x10);

      local_8 = 0;

      FUN_00467370(param_3);

      FUN_00440030(param_3);

      FUN_00467370(param_3);

      pvVar1 = *(void **)(param_2 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_2 + 8) - (int)pvVar1 >> 4;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_2 + 0xc) = (void *)(uVar2 * 0x10 + (int)pvVar4);

      *(void **)(param_2 + 8) = (void *)((param_1 + iVar3) * 0x10 + (int)pvVar4);

      *(void **)(param_2 + 4) = pvVar4;

      ExceptionList = local_10;

      return;

    }

    if ((uint)(*(int *)(param_2 + 8) - param_3 >> 4) < param_1) {

      iVar3 = param_1 * 0x10;

      FUN_00467370(iVar3);

      local_8 = 2;

      FUN_00440030(iVar3);

      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + iVar3;

    }

    else {

      uVar5 = FUN_00467370(param_1 << 4);

      *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar5;

      FUN_0045f050(param_1 << 4);

    }

    FUN_00465bc0();

  }

  ExceptionList = local_10;

  return;

}
