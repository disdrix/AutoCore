// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00696490
// -----------------------------------------------------------------------------
// Stable ID: aa_00696490
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00696490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~191 non-empty decompiler lines.
//  - Control keywords: if×15, return×6, while×5, for×3, do×3.
//  - Notable callees: FUN_00695640×2, FUN_00695d40×2, CONCAT31, FUN_0056f570, FUN_00693430, FUN_006957a0, FUN_00695ed0, FUN_00696010.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00696490(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  uint32_t /* width from decompiler */ *puVar11;

  float10 fVar12;

  uint local_50;

  int local_4c;

  float local_48;

  float local_44;

  int local_30;

  uint8_t local_2c [4];

  uint32_t /* width from decompiler */ *local_28;

  uint32_t /* width from decompiler */ *local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ *local_18;

  uint32_t /* width from decompiler */ *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aa9d8;

  local_c = ExceptionList;

  local_44 = 0.0;

  local_4c = 0;

  fVar2 = g_flZero;

  for (uVar10 = 0;

      (*(int *)(param_1 + 0xc) != 0 &&

      (uVar10 < (uint)((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x30)));

      uVar10 = uVar10 + 1) {

    local_44 = local_44 + *(float *)(local_4c + 0x20 + *(int *)(param_1 + 0xc));

    iVar8 = local_4c + *(int *)(param_1 + 0xc);

    if (fVar2 < *(float *)(iVar8 + 0x20)) {

      fVar2 = *(float *)(iVar8 + 0x20);

    }

    local_4c = local_4c + 0x30;

  }

  fVar5 = fVar2 * fVar2;

  ExceptionList = &local_c;

  FUN_006a1cd0();

  fVar6 = g_flOne - *(float *)(param_1 + 0x60);

  local_18 = (uint32_t /* width from decompiler */ *)0x0;

  local_14 = (uint32_t /* width from decompiler */ *)0x0;

  local_10 = 0;

  local_4 = 1;

  local_50 = 0;

  iVar8 = 0;

  while ((*(int *)(param_1 + 0xc) != 0 &&

         (local_50 < (uint)((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x30)))) {

    fVar3 = *(float *)(*(int *)(param_1 + 0xc) + 0x20 + iVar8);

    if (fVar3 <= fVar6 * fVar2) {

      fVar12 = (float10)FUN_006a1be0(0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x5c));

      iVar7 = *(int *)(param_1 + 0xc) + iVar8;

      local_50 = local_50 + 1;

      iVar8 = iVar8 + 0x30;

      *(float *)(iVar7 + 0x24) =

           (float)(fVar12 * (float10)fVar5 + ((float10)g_flOne - fVar12) * (float10)fVar3);

    }

    else {

      FUN_00695d40(*(int *)(param_1 + 0xc) + iVar8);

      iVar7 = *(int *)(param_1 + 0xc) + iVar8;

      FUN_00693430(iVar7 + 0x30,*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),iVar7,fVar5);

      iVar4 = *(int *)(param_1 + 0x10);

      for (iVar7 = iVar4 + -0x30; iVar7 != iVar4; iVar7 = iVar7 + 0x30) {

        if (*(void **)(iVar7 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(*(void **)(iVar7 + 4));

        }

        *(uint32_t /* width from decompiler */ *)(iVar7 + 4) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar7 + 8) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

      }

      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -0x30;

    }

  }

  local_30 = ((uint)fVar5 >> 8) << 8;

  FUN_00695640(*(int *)(param_1 + 0xc),*(int *)(param_1 + 0x10),

               (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x30,local_30);

  uVar10 = ((int)local_14 - (int)local_18) / 0x30;

  local_30 = ((uint)fVar5 >> 8) << 8;

  FUN_00695640(local_18,local_14,uVar10,local_30);

  puVar11 = local_18;

  for (uVar9 = 0; (local_18 != (uint32_t /* width from decompiler */ *)0x0 && (uVar9 < uVar10)); uVar9 = uVar9 + 1) {

    FUN_006957a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),1,puVar11);

    puVar11 = puVar11 + 0xc;

  }

  uVar10 = *(uint *)(param_1 + 0x50);

  local_50 = 0;

  if (uVar10 != 0) {

    do {

      fVar2 = g_flOne;

      if (uVar10 != 1) {

        fVar2 = (float)(int)local_50;

        if ((int)local_50 < 0) {

          fVar2 = fVar2 + _DAT_00aaa5dc;

        }

        local_30 = uVar10 - 1;

        fVar5 = (float)local_30;

        if (local_30 < 0) {

          fVar5 = fVar5 + _DAT_00aaa5dc;

        }

        fVar2 = (*(float *)(param_1 + 0x58) - *(float *)(param_1 + 0x54)) * (fVar2 / fVar5) +

                *(float *)(param_1 + 0x54);

      }

      fVar2 = fVar2 * local_44;

      uVar10 = 0;

      local_48 = 0.0;

      local_28 = (uint32_t /* width from decompiler */ *)0x0;

      local_24 = (uint32_t /* width from decompiler */ *)0x0;

      local_20 = 0;

      local_4 = CONCAT31(local_4._1_3_,2);

      if (g_flZero < fVar2) {

        iVar8 = 0;

        while (((*(int *)(param_1 + 0xc) != 0 &&

                (uVar10 < (uint)((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x30))) &&

               (local_48 < fVar2 != (local_48 == fVar2)))) {

          local_48 = local_48 + *(float *)(*(int *)(param_1 + 0xc) + 0x20 + iVar8);

          FUN_00695d40(*(int *)(param_1 + 0xc) + iVar8);

          uVar10 = uVar10 + 1;

          iVar8 = iVar8 + 0x30;

        }

      }

      iVar8 = *(int *)(param_1 + 0x1c);

      if ((iVar8 == 0) ||

         ((uint)(*(int *)(param_1 + 0x24) - iVar8 >> 4) <=

          (uint)(*(int *)(param_1 + 0x20) - iVar8 >> 4))) {

        FUN_00696010(*(uint32_t /* width from decompiler */ *)(param_1 + 0x20),1,local_2c);

      }

      else {

        iVar8 = *(int *)(param_1 + 0x20);

        FUN_00695ed0(iVar8,1,local_2c,param_1 + 0x18,local_30);

        *(int *)(param_1 + 0x20) = iVar8 + 0x10;

      }

      if (local_28 != (uint32_t /* width from decompiler */ *)0x0) {

        if (local_28 != local_24) {

          puVar11 = local_28 + 1;

          do {

            if ((void *)*puVar11 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

              operator_delete((void *)*puVar11);

            }

            *puVar11 = 0;

            puVar11[1] = 0;

            puVar11[2] = 0;

            puVar1 = puVar11 + 0xb;

            puVar11 = puVar11 + 0xc;

          } while (puVar1 != local_24);

        }

                    /* WARNING: Subroutine does not return */

        operator_delete(local_28);

      }

      uVar10 = *(uint *)(param_1 + 0x50);

      local_50 = local_50 + 1;

      local_28 = (uint32_t /* width from decompiler */ *)0x0;

      local_24 = (uint32_t /* width from decompiler */ *)0x0;

      local_20 = 0;

    } while (local_50 < uVar10);

  }

  if (local_18 == (uint32_t /* width from decompiler */ *)0x0) {

    local_4 = 0xffffffff;

    FUN_0056f570();

    ExceptionList = local_c;

    return;

  }

  if (local_18 != local_14) {

    puVar11 = local_18 + 1;

    do {

      if ((void *)*puVar11 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)*puVar11);

      }

      *puVar11 = 0;

      puVar11[1] = 0;

      puVar11[2] = 0;

      puVar1 = puVar11 + 0xb;

      puVar11 = puVar11 + 0xc;

    } while (puVar1 != local_14);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_18);

}
