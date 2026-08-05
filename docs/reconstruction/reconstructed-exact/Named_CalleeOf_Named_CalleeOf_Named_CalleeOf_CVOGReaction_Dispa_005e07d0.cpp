// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_005e07d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e07d0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x005e07d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~201 non-empty decompiler lines.
//  - Control keywords: if×27, while×9, do×7, return×2.
//  - Notable callees: FUN_004073a0×4, CONCAT31, CVOGReaction_RandomUnitScalar, FUN_00418b80, FUN_005e0480, FUN_005e07d0, memmove.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
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



uint __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_005e07d0(int param_1,int param_2,void *param_3,int param_4,int param_5,uint32_t /* width from decompiler */ param_6,

            char param_7,int param_8,void *param_9,void *param_10,int param_11)



{

  ushort uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  bool bVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  void *_Src;

  uint32_t /* width from decompiler */ *puVar9;

  void *_Dst;

  int local_20;

  int local_1c;

  int *local_10;

  int local_4;

  

  iVar5 = (int)param_10;

  if (param_5 == 0) {

    local_1c = 0;

  }

  else if (param_5 == 1) {

    local_1c = 1;

  }

  else if (param_5 == 2) {

    local_1c = 2;

  }

  else {

    local_1c = 3;

  }

  iVar6 = FUN_005e0480(param_6);

  local_20 = param_8;

  bVar4 = false;

  if (param_9 != (void *)0x0) {

    if (param_2 < 6) {

      local_10 = (int *)g_flOne;

    }

    else {

      local_10 = (int *)((float)_DAT_00aaa5f8 - (float)(param_2 + -5) * (float)_DAT_00aaa5f0);

      if ((float)local_10 <= (float)_DAT_009dbf10) {

        local_10 = (int *)(float)_DAT_009dbf10;

      }

    }

    iVar7 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar7 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

    *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

    if ((float)uVar1 * DAT_00aaa638 <= (float)local_10) {

      bVar4 = true;

    }

  }

  if ((int)param_3 < 1) {

    param_3 = (void *)0x1;

  }

  else if (0x50 < (int)param_3) {

    param_3 = (void *)0x4b;

  }

  if (param_4 < 1) {

    param_4 = 5;

  }

  else if (0x50 < param_4) {

    param_4 = 0x50;

  }

  if (0 < (int)param_3) {

    param_3 = (void *)((int)param_3 + -1);

  }

  if (0 < param_4) {

    param_4 = param_4 + -1;

  }

  do {

    param_10 = *(void **)(iVar5 + 4);

    if (((param_10 != (void *)0x0) && (*(int *)(iVar5 + 8) - (int)param_10 >> 2 != 0)) &&

       (local_20 < 0)) {

      return CONCAT31((int3)((uint)param_10 >> 8),1);

    }

    if ((int)param_3 <= param_4) {

      local_10 = (int *)(local_20 * 0x10 + (int)param_3 * 0x90 + 0x65408 + param_11);

      param_10 = param_3;

      do {

        if (iVar6 < 0) {

          iVar7 = 0xc;

          piVar8 = (int *)((local_20 + (int)(local_1c * 0x3c0 + (int)param_10) * 9) * 0x10 + 8 +

                          param_11);

          do {

            puVar9 = (uint32_t /* width from decompiler */ *)piVar8[-1];

            if (puVar9 != (uint32_t /* width from decompiler */ *)*piVar8) {

              do {

                iVar2 = *(int *)(iVar5 + 4);

                if ((iVar2 == 0) ||

                   ((uint)(*(int *)(iVar5 + 0xc) - iVar2 >> 2) <=

                    (uint)(*(int *)(iVar5 + 8) - iVar2 >> 2))) {

                  FUN_004073a0(*(uint32_t /* width from decompiler */ *)(iVar5 + 8),1,puVar9);

                }

                else {

                  puVar3 = *(uint32_t /* width from decompiler */ **)(iVar5 + 8);

                  *puVar3 = *puVar9;

                  *(uint32_t /* width from decompiler */ **)(iVar5 + 8) = puVar3 + 1;

                }

                puVar9 = puVar9 + 1;

              } while (puVar9 != (uint32_t /* width from decompiler */ *)*piVar8);

            }

            piVar8 = piVar8 + 0xb40;

            iVar7 = iVar7 + -1;

          } while (iVar7 != 0);

        }

        else {

          iVar7 = (local_20 + (int)((iVar6 + local_1c * 0xc) * 0x50 + (int)param_10) * 9) * 0x10;

          puVar9 = *(uint32_t /* width from decompiler */ **)(iVar7 + 4 + param_11);

          if (puVar9 != *(uint32_t /* width from decompiler */ **)(iVar7 + 8 + param_11)) {

            do {

              iVar2 = *(int *)(iVar5 + 4);

              if ((iVar2 == 0) ||

                 ((uint)(*(int *)(iVar5 + 0xc) - iVar2 >> 2) <=

                  (uint)(*(int *)(iVar5 + 8) - iVar2 >> 2))) {

                FUN_004073a0(*(uint32_t /* width from decompiler */ *)(iVar5 + 8),1,puVar9);

              }

              else {

                puVar3 = *(uint32_t /* width from decompiler */ **)(iVar5 + 8);

                *puVar3 = *puVar9;

                *(uint32_t /* width from decompiler */ **)(iVar5 + 8) = puVar3 + 1;

              }

              puVar9 = puVar9 + 1;

            } while (puVar9 != *(uint32_t /* width from decompiler */ **)(iVar7 + param_11 + 8));

          }

        }

        if (param_7 == '\0') {

          if (iVar6 < 0) {

            iVar7 = 0xc;

            piVar8 = local_10;

            do {

              puVar9 = (uint32_t /* width from decompiler */ *)piVar8[-1];

              while (puVar9 != (uint32_t /* width from decompiler */ *)*piVar8) {

                iVar2 = *(int *)(iVar5 + 4);

                if ((iVar2 == 0) ||

                   ((uint)(*(int *)(iVar5 + 0xc) - iVar2 >> 2) <=

                    (uint)(*(int *)(iVar5 + 8) - iVar2 >> 2))) {

                  FUN_004073a0(*(uint32_t /* width from decompiler */ *)(iVar5 + 8),1,puVar9);

                  puVar9 = puVar9 + 1;

                }

                else {

                  puVar3 = *(uint32_t /* width from decompiler */ **)(iVar5 + 8);

                  *puVar3 = *puVar9;

                  *(uint32_t /* width from decompiler */ **)(iVar5 + 8) = puVar3 + 1;

                  puVar9 = puVar9 + 1;

                }

              }

              piVar8 = piVar8 + 0xb40;

              iVar7 = iVar7 + -1;

            } while (iVar7 != 0);

          }

          else {

            iVar7 = (local_20 + (int)((iVar6 * 5 + 0xb4) * 0x10 + (int)param_10) * 9) * 0x10;

            puVar9 = *(uint32_t /* width from decompiler */ **)(iVar7 + 4 + param_11);

            while (puVar9 != *(uint32_t /* width from decompiler */ **)(iVar7 + param_11 + 8)) {

              iVar2 = *(int *)(iVar5 + 4);

              if ((iVar2 == 0) ||

                 ((uint)(*(int *)(iVar5 + 0xc) - iVar2 >> 2) <=

                  (uint)(*(int *)(iVar5 + 8) - iVar2 >> 2))) {

                FUN_004073a0(*(uint32_t /* width from decompiler */ *)(iVar5 + 8),1,puVar9);

                puVar9 = puVar9 + 1;

              }

              else {

                puVar3 = *(uint32_t /* width from decompiler */ **)(iVar5 + 8);

                *puVar3 = *puVar9;

                *(uint32_t /* width from decompiler */ **)(iVar5 + 8) = puVar3 + 1;

                puVar9 = puVar9 + 1;

              }

            }

          }

        }

        local_10 = local_10 + 0x24;

        param_10 = (void *)((int)param_10 + 1);

      } while ((int)param_10 <= param_4);

    }

    if ((bVar4) && (_Dst = *(void **)(iVar5 + 4), _Dst != *(void **)(iVar5 + 8))) {

      _Src = (void *)((int)_Dst + 4);

      do {

        param_10 = (void *)FUN_00418b80(&local_4,_Dst);

        if (((local_4 == *(int *)(param_1 + 4)) ||

            (param_10 = *(void **)(local_4 + 0x10), param_10 == param_9)) ||

           ((*(char *)(local_4 + 0x14) != '\0' &&

            (((param_10 == (void *)0x3 && (param_9 == (void *)0x2)) ||

             ((param_10 == (void *)0x2 && (param_9 == (void *)0x3)))))))) {

          _Dst = (void *)((int)_Dst + 4);

          _Src = (void *)((int)_Src + 4);

        }

        else {

          param_10 = memmove(_Dst,_Src,(*(int *)(iVar5 + 8) - (int)_Src >> 2) * 4);

          *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + -4;

        }

      } while (_Dst != *(void **)(iVar5 + 8));

    }

    local_20 = local_20 + -1;

  } while (-1 < local_20);

  return (uint)param_10 & 0xffffff00;

}
