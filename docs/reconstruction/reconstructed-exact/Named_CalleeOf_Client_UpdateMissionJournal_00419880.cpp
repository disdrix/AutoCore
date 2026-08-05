// =============================================================================
// Named_CalleeOf_Client_UpdateMissionJournal_00419880
// -----------------------------------------------------------------------------
// Stable ID: aa_00419880
// Callee of Client_UpdateMissionJournal
// Address:   0x00419880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_UpdateMissionJournal: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×14, return×4, do×1, while×1, for×1.
//  - Notable callees: FUN_0040c7c0×4, FUN_004651d0×2, FUN_00418130, FUN_00419880, memmove.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Client_UpdateMissionJournal
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

void __thiscall Named_CalleeOf_Client_UpdateMissionJournal_00419880(uint param_1,int param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  uint uVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  int extraout_ECX;

  int iVar8;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd050;

  local_10 = ExceptionList;

  uVar5 = *param_4;

  iVar3 = *(int *)(param_2 + 4);

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_2 + 0xc) - iVar3 >> 2;

  }

  if (param_1 != 0) {

    if (iVar3 == 0) {

      iVar8 = 0;

    }

    else {

      iVar8 = *(int *)(param_2 + 8) - iVar3 >> 2;

    }

    ExceptionList = &local_10;

    if (0x3fffffffU - iVar8 < param_1) {

      ExceptionList = &local_10;

      uVar2 = FUN_00418130();

      iVar3 = extraout_ECX;

    }

    if (iVar3 == 0) {

      iVar8 = 0;

    }

    else {

      iVar8 = *(int *)(param_2 + 8) - iVar3 >> 2;

    }

    if (uVar2 < iVar8 + param_1) {

      if (0x3fffffff - (uVar2 >> 1) < uVar2) {

        uVar2 = 0;

      }

      else {

        uVar2 = uVar2 + (uVar2 >> 1);

      }

      if (iVar3 == 0) {

        iVar8 = 0;

      }

      else {

        iVar8 = *(int *)(param_2 + 8) - iVar3 >> 2;

      }

      if (uVar2 < iVar8 + param_1) {

        if (iVar3 == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = *(int *)(param_2 + 8) - iVar3 >> 2;

        }

        uVar2 = iVar3 + param_1;

      }

      pvVar4 = operator_new(uVar2 * 4);

      local_8 = 0;

      FUN_0040c7c0(pvVar4);

      uVar5 = FUN_004651d0();

      FUN_0040c7c0(uVar5);

      local_8 = 0xffffffff;

      pvVar1 = *(void **)(param_2 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_2 + 8) - (int)pvVar1 >> 2;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_2 + 0xc) = (void *)(uVar2 * 4 + (int)pvVar4);

      *(void **)(param_2 + 8) = (void *)((int)pvVar4 + (param_1 + iVar3) * 4);

      *(void **)(param_2 + 4) = pvVar4;

      ExceptionList = local_10;

      return;

    }

    iVar3 = *(int *)(param_2 + 8);

    if ((uint)(iVar3 - (int)param_3 >> 2) < param_1) {

      FUN_0040c7c0(param_3 + param_1);

      local_8 = 2;

      FUN_004651d0();

      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + param_1 * 4;

      puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 8) + param_1 * -4);

      if (param_3 != puVar6) {

        do {

          *param_3 = uVar5;

          param_3 = param_3 + 1;

        } while (param_3 != puVar6);

        ExceptionList = local_10;

        return;

      }

    }

    else {

      uVar7 = FUN_0040c7c0(iVar3);

      *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar7;

      iVar8 = (int)((iVar3 + param_1 * -4) - (int)param_3) >> 2;

      memmove((void *)(iVar3 + iVar8 * -4),param_3,iVar8 * 4);

      puVar6 = param_3 + param_1;

      for (; param_3 != puVar6; param_3 = param_3 + 1) {

        *param_3 = uVar5;

      }

    }

  }

  ExceptionList = local_10;

  return;

}
