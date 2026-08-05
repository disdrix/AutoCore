// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00429970
// -----------------------------------------------------------------------------
// Stable ID: aa_00429970
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x00429970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×14, return×4, do×1, while×1, for×1.
//  - Notable callees: FUN_004e2e80×4, FUN_004651d0×2, FUN_00429970, FUN_004540b0, memmove.
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00429970(uint param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  int extraout_ECX;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  

  uVar5 = *in_EAX;

  iVar3 = *(int *)(param_2 + 4);

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_2 + 0xc) - iVar3 >> 2;

  }

  if (param_1 != 0) {

    if (iVar3 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_2 + 8) - iVar3 >> 2;

    }

    if (0x3fffffffU - iVar7 < param_1) {

      uVar2 = FUN_004540b0();

      iVar3 = extraout_ECX;

    }

    if (iVar3 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_2 + 8) - iVar3 >> 2;

    }

    if (uVar2 < iVar7 + param_1) {

      if (0x3fffffff - (uVar2 >> 1) < uVar2) {

        uVar2 = 0;

      }

      else {

        uVar2 = uVar2 + (uVar2 >> 1);

      }

      if (iVar3 == 0) {

        iVar7 = 0;

      }

      else {

        iVar7 = *(int *)(param_2 + 8) - iVar3 >> 2;

      }

      if (uVar2 < iVar7 + param_1) {

        if (iVar3 == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = *(int *)(param_2 + 8) - iVar3 >> 2;

        }

        uVar2 = iVar3 + param_1;

      }

      pvVar4 = operator_new(uVar2 * 4);

      FUN_004e2e80(*(uint32_t /* width from decompiler */ *)(param_2 + 4),param_3,pvVar4);

      uVar5 = FUN_004651d0();

      FUN_004e2e80(param_3,*(uint32_t /* width from decompiler */ *)(param_2 + 8),uVar5);

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

      *(void **)(param_2 + 4) = pvVar4;

      *(void **)(param_2 + 0xc) = (void *)(uVar2 * 4 + (int)pvVar4);

      *(void **)(param_2 + 8) = (void *)((int)pvVar4 + (param_1 + iVar3) * 4);

      return;

    }

    iVar3 = *(int *)(param_2 + 8);

    if ((uint)(iVar3 - (int)param_3 >> 2) < param_1) {

      FUN_004e2e80(param_3,iVar3,param_3 + param_1);

      FUN_004651d0();

      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + param_1 * 4;

      puVar8 = (uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 8) + param_1 * -4);

      if (param_3 != puVar8) {

        do {

          *param_3 = uVar5;

          param_3 = param_3 + 1;

        } while (param_3 != puVar8);

        return;

      }

    }

    else {

      iVar7 = iVar3 + param_1 * -4;

      uVar6 = FUN_004e2e80(iVar7,iVar3,iVar3);

      *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar6;

      iVar7 = iVar7 - (int)param_3 >> 2;

      memmove((void *)(iVar3 + iVar7 * -4),param_3,iVar7 * 4);

      puVar8 = param_3 + param_1;

      for (; param_3 != puVar8; param_3 = param_3 + 1) {

        *param_3 = uVar5;

      }

    }

  }

  return;

}
