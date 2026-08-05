// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0058c850
// -----------------------------------------------------------------------------
// Stable ID: aa_0058c850
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0058c850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~161 non-empty decompiler lines.
//  - Control keywords: if×9, while×2, return×2, do×1, for×1.
//  - Notable callees: FUN_0040b020×2, FUN_004bcbf0×2, InitializeCriticalSection×2, CONCAT31, CVOGReaction_ResolveObjectTarget, Client_EnqueueCombatFloater_INFERRED, FUN_004024d0, FUN_004cf080.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

int Named_CalleeOf_Named_VOG_DEBUG_STOP_0058c850(int param_1,uint *param_2,int param_3,uint32_t /* width from decompiler */ param_4,int param_5,int param_6)



{

  uint *puVar1;

  uint *puVar2;

  char cVar3;

  int iVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint uVar7;

  ushort *puVar8;

  float10 fVar9;

  uint8_t local_c5;

  int local_c4;

  int local_c0;

  int local_bc;

  uint32_t /* width from decompiler */ local_b8;

  int local_b4;

  uint32_t /* width from decompiler */ local_b0;

  uint local_ac;

  float local_a8;

  int local_a4;

  int local_a0;

  int local_9c;

  uint32_t /* width from decompiler */ local_98;

  uint32_t /* width from decompiler */ local_94;

  uint8_t local_90;

  uint32_t /* width from decompiler */ local_8c;

  uint32_t /* width from decompiler */ local_88 [4];

  int local_78;

  int local_74;

  int local_70;

  int local_6c;

  uint8_t local_60;

  uint8_t local_5e;

  uint32_t /* width from decompiler */ local_58;

  undefined **local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  int local_44;

  _RTL_CRITICAL_SECTION local_40;

  _RTL_CRITICAL_SECTION local_28;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5758;

  local_c = ExceptionList;

  if (param_2 != (uint *)0x0) {

    local_50 = &PTR_FUN_009cb368;

    local_4c = 0;

    local_48 = 0;

    local_44 = 0;

    local_10 = 0xffffffff;

    ExceptionList = &local_c;

    InitializeCriticalSection(&local_40);

    InitializeCriticalSection(&local_28);

    local_4 = 0;

    uVar7 = *param_2 & param_2[1];

    while (uVar7 != 0xffffffff) {

      iVar4 = CVOGReaction_ResolveObjectTarget((char)param_2[2],*param_2,param_2[1]);

      if (iVar4 != 0) {

        FUN_004024d0(iVar4);

      }

      puVar1 = param_2 + 4;

      puVar2 = param_2 + 5;

      param_2 = param_2 + 4;

      uVar7 = *puVar1 & *puVar2;

    }

    if (local_44 != 0) {

      local_c4 = 0;

      local_bc = 0;

      piVar5 = (int *)FUN_0040b020();

      if (piVar5 != (int *)0x0) {

        param_6 = param_6 * 6;

        local_c0 = param_6;

        do {

          local_c5 = 0;

          if ((local_c4 < 1) ||

             (cVar3 = FUN_00553240(param_1,piVar5,*(uint16_t *)(param_5 + (param_6 % 600) * 2),

                                   &local_c5), cVar3 != '\0')) {

            local_a4 = *(int *)(param_3 + 0x54);

            local_a0 = *(int *)(param_3 + 0x58);

            local_9c = *(int *)(param_3 + 0x5c);

            local_b8 = *(uint32_t /* width from decompiler */ *)(param_3 + 0x60);

            local_b4 = *(int *)(param_3 + 100);

            local_b0 = *(int *)(param_3 + 0x68);

            local_98 = 0;

            local_94 = 0;

            local_90 = 0;

            if (*(char *)(param_3 + 0x140) == '\0') {

              local_8c = *(uint32_t /* width from decompiler */ *)(param_3 + 0x144);

              puVar8 = (ushort *)(param_5 + (param_6 % 600) * 2);

              iVar4 = (**(code **)(*piVar5 + 0x4c))

                                (param_1,&local_a4,&local_b8,1,1,1,0,puVar8,&local_98,local_8c);

            }

            else {

              iVar4 = (int)(short)local_a4 + (local_a4 >> 0x10) + (int)(short)local_a0 +

                      (local_a0 >> 0x10) + (int)(short)local_9c + (local_9c >> 0x10);

              local_b8._2_2_ = (short)((uint)local_b8 >> 0x10);

              puVar8 = (ushort *)(param_5 + (param_6 % 600) * 2);

              iVar4 = (int)((longlong)(ulonglong)*puVar8 %

                           (longlong)

                           ((((int)(short)local_b8 + (int)(short)local_b4 + (local_b4 >> 0x10) +

                              (int)(short)local_b0 + (local_b0 >> 0x10) + (int)local_b8._2_2_) -

                            iVar4) + 1)) + iVar4;

            }

            fVar9 = (float10)FUN_004cf080(param_1,piVar5,*puVar8);

            uVar7 = local_ac;

            local_a8 = (float)fVar9;

            local_ac = local_ac & 0xffffff00;

            if (g_flOne < local_a8) {

              iVar4 = (int)((float)iVar4 * local_a8);

              local_ac = CONCAT31(SUB43(uVar7,1),1);

            }

            if ((0 < local_b8._2_2_) || (0 < local_b0._2_2_)) {

              piVar5[0x33] = 4;

            }

            FUN_004d7e30(local_ac,iVar4,param_1,piVar5,1,1,0,DAT_009d4d28,DAT_009d4d2c,DAT_009d4d30,

                         DAT_009d4d34,&local_98);

            local_bc = local_bc + iVar4;

          }

          else {

            puVar6 = local_88;

            for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {

              *puVar6 = 0;

              puVar6 = puVar6 + 1;

            }

            puVar6 = (uint32_t /* width from decompiler */ *)(param_1 + 0x160);

            if (param_1 == 0) {

              puVar6 = &DAT_009d4d28;

            }

            local_88[0] = *puVar6;

            local_88[1] = puVar6[1];

            local_88[2] = puVar6[2];

            local_88[3] = puVar6[3];

            local_78 = piVar5[0x58];

            local_74 = piVar5[0x59];

            local_70 = piVar5[0x5a];

            local_6c = piVar5[0x5b];

            local_5e = 1;

            local_60 = 0;

            local_58 = 0;

            Client_EnqueueCombatFloater_INFERRED(local_88);

            local_c0 = param_6;

          }

          local_c4 = local_c4 + 1;

          param_6 = local_c0 + 6;

          local_c0 = param_6;

          piVar5 = (int *)FUN_0040b020();

        } while (piVar5 != (int *)0x0);

      }

      FUN_004bcbf0();

      ExceptionList = local_c;

      return local_bc;

    }

    FUN_004bcbf0();

  }

  ExceptionList = local_c;

  return 0;

}
