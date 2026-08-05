// =============================================================================
// Named_CalleeOf_Named_effVertexDecl_00463e30
// -----------------------------------------------------------------------------
// Stable ID: aa_00463e30
// Callee of Named_effVertexDecl (+4 other named callers)
// Address:   0x00463e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effVertexDecl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_effVertexDecl (+4 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×14, return×4, do×1, while×1, for×1.
//  - Notable callees: FUN_0044ea70×4, FUN_00436ef0×2, FUN_0044ea50, FUN_004540b0, FUN_00463e30.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_effVertexDecl (+4 other named callers)
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

void __thiscall Named_CalleeOf_Named_effVertexDecl_00463e30(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  void *pvVar2;

  uint uVar3;

  int iVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  int extraout_ECX;

  uint uVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint64_t uVar10;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd510;

  local_10 = ExceptionList;

  uVar1 = *param_4;

  iVar4 = *(int *)(param_1 + 4);

  if (iVar4 == 0) {

    uVar3 = 0;

  }

  else {

    uVar3 = *(int *)(param_1 + 0xc) - iVar4 >> 2;

  }

  if (param_3 != 0) {

    if (iVar4 == 0) {

      iVar8 = 0;

    }

    else {

      iVar8 = *(int *)(param_1 + 8) - iVar4 >> 2;

    }

    uVar7 = param_3;

    ExceptionList = &local_10;

    if (0x3fffffffU - iVar8 < param_3) {

      ExceptionList = &local_10;

      uVar10 = FUN_004540b0();

      uVar7 = (uint)((ulonglong)uVar10 >> 0x20);

      uVar3 = (uint)uVar10;

      iVar4 = extraout_ECX;

    }

    if (iVar4 == 0) {

      iVar8 = 0;

    }

    else {

      iVar8 = *(int *)(param_1 + 8) - iVar4 >> 2;

    }

    if (uVar3 < iVar8 + uVar7) {

      if (0x3fffffff - (uVar3 >> 1) < uVar3) {

        uVar3 = 0;

      }

      else {

        uVar3 = uVar3 + (uVar3 >> 1);

      }

      if (iVar4 == 0) {

        iVar8 = 0;

      }

      else {

        iVar8 = *(int *)(param_1 + 8) - iVar4 >> 2;

      }

      if (uVar3 < iVar8 + uVar7) {

        if (iVar4 == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = *(int *)(param_1 + 8) - iVar4 >> 2;

        }

        uVar3 = iVar4 + uVar7;

      }

      pvVar5 = operator_new(uVar3 * 4);

      local_8 = 0;

      FUN_0044ea70(param_3);

      FUN_00436ef0(param_3);

      FUN_0044ea70(param_3);

      pvVar2 = *(void **)(param_1 + 4);

      if (pvVar2 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(param_1 + 8) - (int)pvVar2 >> 2;

      }

      if (pvVar2 == (void *)0x0) {

        *(void **)(param_1 + 0xc) = (void *)(uVar3 * 4 + (int)pvVar5);

        *(void **)(param_1 + 8) = (void *)((int)pvVar5 + (param_3 + iVar4) * 4);

        *(void **)(param_1 + 4) = pvVar5;

        ExceptionList = local_10;

        return;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

    if ((uint)(*(int *)(param_1 + 8) - (int)param_2 >> 2) < uVar7) {

      FUN_0044ea70(param_3);

      local_8 = 2;

      FUN_00436ef0(param_3);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar7 * 4;

      puVar9 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + uVar7 * -4);

      if (param_2 != puVar9) {

        do {

          *param_2 = uVar1;

          param_2 = param_2 + 1;

        } while (param_2 != puVar9);

        ExceptionList = local_10;

        return;

      }

    }

    else {

      uVar6 = FUN_0044ea70(*(int *)(param_1 + 8) + uVar7 * -4);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar6;

      FUN_0044ea50();

      puVar9 = param_2 + uVar7;

      for (; param_2 != puVar9; param_2 = param_2 + 1) {

        *param_2 = uVar1;

      }

    }

  }

  ExceptionList = local_10;

  return;

}
