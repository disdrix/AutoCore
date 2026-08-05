// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068fb10
// -----------------------------------------------------------------------------
// Stable ID: aa_0068fb10
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068fb10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~247 non-empty decompiler lines.
//  - Control keywords: if×10, for×7, do×3, while×3, return×2.
//  - Notable callees: FUN_0056f570×16, CONCAT31×6, FUN_0069f950×6, FUN_004490a0, FUN_0068fb10, FUN_0069f850, FUN_0069fa50.
//  - Return sites: 2.

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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068fb10(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  float *pfVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  void *pvVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int local_210;

  float local_20c;

  float local_208;

  float local_204;

  int local_200;

  float local_1fc;

  uint local_1f8;

  void *local_1f0;

  float *local_1ec;

  int local_1e8;

  float local_1e4;

  int local_1d8;

  float local_1d4;

  float local_1d0;

  float local_1cc;

  float local_1c8;

  float local_1c4;

  float local_1c0;

  float local_1bc;

  float local_1b8;

  float local_1b4;

  float local_1b0;

  float local_1ac;

  float local_1a8;

  float local_1a4;

  float local_1a0;

  float local_19c;

  float local_198;

  float local_194;

  float local_190;

  uint32_t /* width from decompiler */ local_18c [12];

  uint8_t local_15c [48];

  uint8_t local_12c [48];

  uint8_t local_fc [48];

  uint8_t local_cc [48];

  uint8_t local_9c [48];

  uint8_t local_6c [48];

  uint8_t local_3c [48];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009aa5f8;

  local_c = ExceptionList;

  if (((*(int *)(param_1 + 0x24) != 0) && (*(int *)(param_1 + 0x20) != 0)) &&

     (*(int *)(param_1 + 0x2c) != 0)) {

    pvVar9 = (void *)0x0;

    local_1f0 = (void *)0x0;

    local_1ec = (float *)0x0;

    local_1e8 = 0;

    local_4 = 0;

    local_200 = 0;

    ExceptionList = &local_c;

    local_1d8 = param_1;

    if (*(short *)(param_1 + 0x1c) != 0) {

      iVar8 = 0;

      pvVar9 = (void *)0x0;

      ExceptionList = &local_c;

      do {

        fVar1 = *(float *)(*(int *)(param_1 + 0x20) + 4 + iVar8) *

                *(float *)(*(int *)(param_1 + 0x24) + 4 + iVar8);

        fVar3 = *(float *)(*(int *)(param_1 + 0x24) + iVar8) *

                *(float *)(*(int *)(param_1 + 0x20) + iVar8);

        local_20c = 0.0;

        fVar2 = (g_flZero - fVar1) * (g_flZero - fVar1);

        local_208 = (g_flZero - fVar3) * (g_flZero - fVar3);

        iVar5 = (int)(local_208 + fVar2) >> 1;

        if (g_flZero < (float)(iVar5 + 0x1fc00000)) {

          local_20c = (float)(iVar5 + 0x1fc00000);

        }

        pfVar6 = (float *)(*(int *)(param_1 + 0x20) + iVar8);

        fVar4 = *(float *)(*(int *)(param_1 + 0x20) + iVar8) - fVar3;

        if (local_20c < (float)(((int)(fVar4 * fVar4 + fVar2) >> 1) + 0x1fc00000)) {

          local_20c = (float)(((int)((*pfVar6 - fVar3) * (*pfVar6 - fVar3) + fVar2) >> 1) +

                             0x1fc00000);

        }

        local_204 = *(float *)(*(int *)(param_1 + 0x20) + iVar8 + 4) - fVar1;

        fVar2 = *(float *)(*(int *)(param_1 + 0x20) + iVar8) - fVar3;

        if (local_20c < (float)(((int)(fVar2 * fVar2 + local_204 * local_204) >> 1) + 0x1fc00000)) {

          local_204 = *(float *)(*(int *)(param_1 + 0x20) + 4 + iVar8) - fVar1;

          fVar3 = *(float *)(*(int *)(param_1 + 0x20) + iVar8) - fVar3;

          local_20c = (float)(((int)(local_204 * local_204 + fVar3 * fVar3) >> 1) + 0x1fc00000);

        }

        if (local_20c <

            (float)(((int)((pfVar6[1] - fVar1) * (pfVar6[1] - fVar1) + local_208) >> 1) + 0x1fc00000

                   )) {

          local_20c = (float)(((int)((pfVar6[1] - fVar1) * (pfVar6[1] - fVar1) + local_208) >> 1) +

                             0x1fc00000);

        }

        if ((pvVar9 == (void *)0x0) ||

           ((uint)(local_1e8 - (int)pvVar9 >> 2) <= (uint)((int)local_1ec - (int)pvVar9 >> 2))) {

          FUN_004490a0(local_1ec,1,&local_20c);

          pvVar9 = local_1f0;

        }

        else {

          *local_1ec = local_20c;

          local_1ec = local_1ec + 1;

        }

        local_200 = local_200 + 1;

        iVar8 = iVar8 + 0xc;

      } while (local_200 < (int)(uint)*(ushort *)(param_1 + 0x1c));

    }

    local_210 = 0;

    if (*(short *)(param_1 + 0x28) != 0) {

      local_204 = 0.0;

      do {

        iVar8 = *(int *)(param_1 + 0x2c) + (int)local_204;

        local_1f8 = 0;

        if (*(short *)(iVar8 + 0xc) != 0) {

          local_200 = 0;

          do {

            FUN_0069fa50();

            local_1fc = *(float *)(*(int *)(iVar8 + 0x18) + 8 + local_200);

            pfVar6 = (float *)(*(int *)(iVar8 + 0x18) + local_200);

            local_208 = pfVar6[1];

            local_1e4 = *pfVar6;

            local_20c = *(float *)((int)pvVar9 +

                                  (uint)(*(byte *)(*(int *)(iVar8 + 0x10) + local_1f8) >> 1) * 4);

            local_198 = local_1e4 + local_20c;

            local_4 = CONCAT31(local_4._1_3_,1);

            local_194 = local_208;

            local_190 = local_1fc;

            puVar7 = (uint32_t /* width from decompiler */ *)FUN_0069f950(local_15c,&local_198);

            puVar10 = local_18c;

            for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {

              *puVar10 = *puVar7;

              puVar7 = puVar7 + 1;

              puVar10 = puVar10 + 1;

            }

            local_4._0_1_ = 2;

            FUN_0056f570();

            local_4 = CONCAT31(local_4._1_3_,1);

            FUN_0056f570();

            local_1a4 = local_1e4 - local_20c;

            local_1a0 = local_208;

            local_19c = local_1fc;

            puVar7 = (uint32_t /* width from decompiler */ *)FUN_0069f950(local_6c,&local_1a4);

            puVar10 = local_18c;

            for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {

              *puVar10 = *puVar7;

              puVar7 = puVar7 + 1;

              puVar10 = puVar10 + 1;

            }

            local_4._0_1_ = 3;

            FUN_0056f570();

            local_4 = CONCAT31(local_4._1_3_,1);

            FUN_0056f570();

            local_1d0 = local_208 + local_20c;

            local_1d4 = local_1e4;

            local_1cc = local_1fc;

            puVar7 = (uint32_t /* width from decompiler */ *)FUN_0069f950(local_cc,&local_1d4);

            puVar10 = local_18c;

            for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {

              *puVar10 = *puVar7;

              puVar7 = puVar7 + 1;

              puVar10 = puVar10 + 1;

            }

            local_4._0_1_ = 4;

            FUN_0056f570();

            local_4 = CONCAT31(local_4._1_3_,1);

            FUN_0056f570();

            local_1ac = local_208 - local_20c;

            local_1b0 = local_1e4;

            local_1a8 = local_1fc;

            puVar7 = (uint32_t /* width from decompiler */ *)FUN_0069f950(local_12c,&local_1b0);

            puVar10 = local_18c;

            for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {

              *puVar10 = *puVar7;

              puVar7 = puVar7 + 1;

              puVar10 = puVar10 + 1;

            }

            local_4._0_1_ = 5;

            FUN_0056f570();

            local_4 = CONCAT31(local_4._1_3_,1);

            FUN_0056f570();

            local_1c0 = local_1fc + local_20c;

            local_1c8 = local_1e4;

            local_1c4 = local_208;

            puVar7 = (uint32_t /* width from decompiler */ *)FUN_0069f950(local_fc,&local_1c8);

            puVar10 = local_18c;

            for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {

              *puVar10 = *puVar7;

              puVar7 = puVar7 + 1;

              puVar10 = puVar10 + 1;

            }

            local_4._0_1_ = 6;

            FUN_0056f570();

            local_4 = CONCAT31(local_4._1_3_,1);

            FUN_0056f570();

            local_1b4 = local_1fc - local_20c;

            local_1bc = local_1e4;

            local_1b8 = local_208;

            puVar7 = (uint32_t /* width from decompiler */ *)FUN_0069f950(local_9c,&local_1bc);

            puVar10 = local_18c;

            for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {

              *puVar10 = *puVar7;

              puVar7 = puVar7 + 1;

              puVar10 = puVar10 + 1;

            }

            local_4._0_1_ = 7;

            FUN_0056f570();

            local_4._0_1_ = 1;

            FUN_0056f570();

            puVar7 = (uint32_t /* width from decompiler */ *)FUN_0069f850(local_3c,local_18c);

            puVar10 = param_2;

            for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {

              *puVar10 = *puVar7;

              puVar7 = puVar7 + 1;

              puVar10 = puVar10 + 1;

            }

            local_4._0_1_ = 8;

            FUN_0056f570();

            local_4._0_1_ = 1;

            FUN_0056f570();

            local_4._0_1_ = 9;

            FUN_0056f570();

            local_4 = (uint)local_4._1_3_ << 8;

            FUN_0056f570();

            local_200 = local_200 + 0xc;

            local_1f8 = local_1f8 + 1;

            param_1 = local_1d8;

            pvVar9 = local_1f0;

          } while (local_1f8 < *(ushort *)(iVar8 + 0xc));

        }

        local_204 = (float)((int)local_204 + 0x44);

        local_210 = local_210 + 1;

      } while (local_210 < (int)(uint)*(ushort *)(param_1 + 0x28));

    }

    if (pvVar9 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar9);

    }

  }

  ExceptionList = local_c;

  return;

}
