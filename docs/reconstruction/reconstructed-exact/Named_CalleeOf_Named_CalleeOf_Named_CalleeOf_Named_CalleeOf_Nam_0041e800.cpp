// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0041e800
// -----------------------------------------------------------------------------
// Stable ID: aa_0041e800
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x0041e800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, for×1.
//  - Notable callees: FUN_00404530×2, FUN_00421920×2, FUN_00421ec0×2, FUN_00422670×2, FUN_00403960, FUN_0041e800, FUN_00421ee0, FUN_004540b0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0041e800(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint uVar6;

  uint extraout_ECX;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ local_ac [38];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bce40;

  local_10 = ExceptionList;

  puVar8 = local_ac;

  for (iVar5 = 0x26; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar8 = *param_4;

    param_4 = param_4 + 1;

    puVar8 = puVar8 + 1;

  }

  iVar5 = *(int *)(param_1 + 4);

  if (iVar5 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = (*(int *)(param_1 + 0xc) - iVar5) / 0x98;

  }

  if (param_3 != 0) {

    if (iVar5 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar5) / 0x98;

    }

    ExceptionList = &local_10;

    local_14 = &stack0xffffff48;

    if (0x1af286bU - iVar2 < param_3) {

      ExceptionList = &local_10;

      local_14 = &stack0xffffff48;

      FUN_004540b0();

      uVar6 = extraout_ECX;

    }

    if (iVar5 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar5) / 0x98;

    }

    if (uVar6 < iVar2 + param_3) {

      if (0x1af286b - (uVar6 >> 1) < uVar6) {

        uVar6 = 0;

      }

      else {

        uVar6 = uVar6 + (uVar6 >> 1);

      }

      if (iVar5 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = (*(int *)(param_1 + 8) - iVar5) / 0x98;

      }

      if (uVar6 < iVar5 + param_3) {

        iVar5 = FUN_00403960();

        uVar6 = iVar5 + param_3;

      }

      pvVar3 = operator_new(uVar6 * 0x98);

      local_8 = 0;

      uVar4 = FUN_00422670(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar3,param_1,param_2);

      uVar4 = FUN_00421920(uVar4,param_3,local_ac);

      FUN_00422670(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),uVar4,param_1,param_2);

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar5 = 0;

      }

      else {

        iVar5 = (*(int *)(param_1 + 8) - (int)pvVar1) / 0x98;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar6 * 0x98 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar5) * 0x98);

      *(void **)(param_1 + 4) = pvVar3;

      ExceptionList = local_10;

      return;

    }

    iVar5 = *(int *)(param_1 + 8);

    iVar2 = param_3 * 0x98;

    if ((uint)((iVar5 - param_2) / 0x98) < param_3) {

      FUN_00421ec0(param_2,iVar5,iVar2 + param_2);

      local_8 = 2;

      FUN_00421920(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x98,local_ac

                  );

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar2;

      FUN_00404530(param_2,*(int *)(param_1 + 8) + param_3 * -0x98,local_ac);

      ExceptionList = local_10;

      return;

    }

    iVar7 = iVar5 + param_3 * -0x98;

    uVar4 = FUN_00421ec0(iVar7,iVar5,iVar5);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

    FUN_00421ee0(param_2,iVar7,iVar5);

    FUN_00404530(param_2,iVar2 + param_2,local_ac);

  }

  ExceptionList = local_10;

  return;

}
