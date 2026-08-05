// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a3170
// -----------------------------------------------------------------------------
// Stable ID: aa_006a3170
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006a3170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~111 non-empty decompiler lines.
//  - Control keywords: if×11, return×3, do×2, while×2.
//  - Notable callees: CONCAT31, FUN_004365e0, FUN_00436920, FUN_006a2c10, FUN_006a2c70, FUN_006a2ec0, FUN_006a3170.
//  - Return sites: 3.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a3170(uint32_t /* width from decompiler */ param_1,int *param_2,int *param_3)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  void *pvVar6;

  uint uVar7;

  int *piVar8;

  int iVar9;

  uint8_t local_41;

  float local_40;

  int *local_3c;

  uint local_38;

  int local_34;

  int local_30;

  float local_2c;

  int local_28;

  int local_24;

  uint local_20;

  void *local_18;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ab398;

  local_c = ExceptionList;

  local_4 = 0;

  if (param_2 == (int *)0x0) {

    iVar9 = 0;

  }

  else {

    iVar9 = (int)param_3 - (int)param_2 >> 2;

  }

  local_20 = 0;

  local_38 = 0;

  ExceptionList = &local_c;

  FUN_006a2ec0(iVar9 + 0x1fU >> 5,&local_38);

  local_4._0_1_ = 1;

  FUN_004365e0(iVar9);

  uVar7 = 0;

  local_4 = CONCAT31(local_4._1_3_,2);

  local_41 = 0;

  pvVar6 = local_18;

  if (local_20 != 0) {

    uVar7 = local_20 & 0x1f;

    pvVar6 = (void *)((int)local_18 + (local_20 >> 5) * 4);

  }

  FUN_00436920(0,local_18,uVar7,pvVar6,&local_41);

  if (param_2 != param_3) {

    local_30 = -4 - (int)param_2;

    local_3c = param_2;

    do {

      iVar9 = local_34;

      local_28 = *local_3c;

      local_3c = local_3c + 1;

      uVar7 = local_30 + (int)local_3c >> 2;

      local_24 = 0;

      local_38 = 0xffffffff;

      piVar8 = local_3c;

      fVar5 = DAT_00aaa630;

      if (local_3c != param_3) {

        do {

          uVar7 = uVar7 + 1;

          local_2c = 1.4013e-45;

          if ((*(uint *)((int)local_18 + (uVar7 >> 5) * 4) & 1 << ((byte)uVar7 & 0x1f)) != 0) break;

          local_2c = 1.4013e-45;

          if ((*(uint *)((int)local_18 + (uVar7 >> 5) * 4) & 1 << ((byte)uVar7 & 0x1f)) == 0) {

            iVar1 = *piVar8;

            fVar2 = *(float *)(iVar1 + 0xc) - *(float *)(local_28 + 0xc);

            fVar4 = *(float *)(iVar1 + 8) - *(float *)(local_28 + 8);

            fVar3 = *(float *)(iVar1 + 4) - *(float *)(local_28 + 4);

            local_2c = fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3;

            local_40 = (float)(((int)local_2c >> 1) + 0x1fc00000);

            if ((local_40 < *(float *)(local_34 + 0x10)) && (local_40 < fVar5)) {

              local_38 = uVar7;

              local_24 = iVar1;

              fVar5 = local_40;

            }

          }

          piVar8 = piVar8 + 1;

        } while (piVar8 != param_3);

        if (local_24 != 0) {

          *(uint *)((int)local_18 + (local_38 >> 5) * 4) =

               *(uint *)((int)local_18 + (local_38 >> 5) * 4) | 1 << ((byte)local_38 & 0x1f);

          iVar1 = *(int *)(local_34 + 4);

          if ((iVar1 == 0) ||

             ((uint)(*(int *)(local_34 + 0xc) - iVar1 >> 3) <=

              (uint)(*(int *)(local_34 + 8) - iVar1 >> 3))) {

            FUN_006a2c70(*(uint32_t /* width from decompiler */ *)(local_34 + 8),1,&local_28);

          }

          else {

            iVar1 = *(int *)(local_34 + 8);

            FUN_006a2c10(iVar1,1,&local_28,local_34,param_1);

            *(int *)(iVar9 + 8) = iVar1 + 8;

          }

        }

      }

    } while (local_3c != param_3);

  }

  if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_18);

  }

  if (param_2 != (int *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_2);

  }

  ExceptionList = local_c;

  return;

}
