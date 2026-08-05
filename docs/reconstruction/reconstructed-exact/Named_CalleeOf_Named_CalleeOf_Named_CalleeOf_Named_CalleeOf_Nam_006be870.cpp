// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006be870
// -----------------------------------------------------------------------------
// Stable ID: aa_006be870
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006be870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~250 non-empty decompiler lines.
//  - Control keywords: if×41, do×8, while×8, return×3, goto×1.
//  - Notable callees: FUN_006be710×3, FUN_006be870.
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006be870(char *param_1,int param_2,uint32_t /* width from decompiler */ param_3,char param_4,int *param_5)



{

  short sVar1;

  bool bVar2;

  char cVar3;

  char cVar4;

  int iVar5;

  int iVar6;

  char *pcVar7;

  short *psVar8;

  int iVar9;

  int *piVar10;

  int iVar11;

  int iVar12;

  uint8_t local_1a;

  uint8_t local_19;

  int local_18;

  char local_14;

  int local_10;

  int local_c;

  char local_8;

  int local_4;

  

  local_18 = *(int *)(param_2 + 4);

  iVar11 = 0;

  iVar5 = 0;

  if (0 < *(int *)(param_2 + 8)) {

    do {

      *(uint16_t *)(*(int *)(param_2 + 4) + 6 + iVar5 * 8) = 0;

      iVar5 = iVar5 + 1;

    } while (iVar5 < *(int *)(param_2 + 8));

  }

  if (param_4 == '\0') {

    iVar5 = *(int *)(*param_5 + 4);

  }

  else {

    iVar5 = *(int *)*param_5;

  }

  iVar12 = param_5[1] + -1;

  if (-1 < iVar12) {

    iVar9 = iVar12 * 0x10;

    do {

      if (param_4 == '\0') {

        iVar6 = *(int *)(iVar9 + 4 + *param_5);

      }

      else {

        iVar6 = *(int *)(iVar9 + *param_5);

      }

      if (iVar6 != iVar5) {

        iVar11 = iVar11 + 1;

        iVar5 = iVar6;

        if (param_4 != '\0') {

          iVar5 = local_18 + (uint)*(ushort *)(iVar6 + 2) * 8;

        }

        if (*(short *)(iVar5 + 6) == 3) goto LAB_006be998;

        *(uint16_t *)(iVar5 + 6) = 3;

        iVar5 = iVar6;

      }

      iVar12 = iVar12 + -1;

      iVar9 = iVar9 + -0x10;

    } while (-1 < iVar12);

    if (iVar11 != 0) {

      if (param_4 == '\0') {

        iVar5 = *(int *)(*param_5 + 4);

      }

      else {

        iVar5 = *(int *)*param_5;

      }

      iVar11 = param_5[1] + -1;

      if (-1 < iVar11) {

        iVar12 = iVar11 * 0x10;

        do {

          if (param_4 == '\0') {

            iVar9 = *(int *)(iVar12 + 4 + *param_5);

          }

          else {

            iVar9 = *(int *)(iVar12 + *param_5);

          }

          if (iVar9 != iVar5) {

            iVar6 = iVar9;

            if (param_4 == '\0') {

              iVar6 = local_18 + (uint)*(ushort *)(iVar9 + 2) * 8;

            }

            sVar1 = *(short *)(iVar6 + 6);

            iVar5 = iVar9;

            if (sVar1 == 0) {

              *(uint16_t *)(iVar6 + 6) = 1;

            }

            else {

              if (sVar1 == 1) {

LAB_006be998:

                *param_1 = '\0';

                return;

              }

              if (sVar1 == 3) {

                *(uint16_t *)(iVar6 + 6) = 2;

              }

            }

          }

          iVar11 = iVar11 + -1;

          iVar12 = iVar12 + -0x10;

        } while (-1 < iVar11);

      }

      cVar4 = '\x01';

      local_14 = '\x01';

      if (param_4 == '\0') {

        iVar5 = ((int *)*param_5)[1];

      }

      else {

        iVar5 = *(int *)*param_5;

      }

      local_c = param_5[1];

      cVar3 = local_14;

      if (-1 < local_c + -1) {

        iVar11 = (local_c + -1) * 0x10;

        do {

          if (param_4 == '\0') {

            iVar12 = *(int *)(iVar11 + 4 + *param_5);

          }

          else {

            iVar12 = *(int *)(iVar11 + *param_5);

          }

          if (iVar12 != iVar5) {

            iVar9 = iVar12;

            if (param_4 == '\0') {

              iVar9 = local_18 + (uint)*(ushort *)(iVar12 + 2) * 8;

            }

            if (*(short *)(iVar9 + 6) == 1) {

              if ((cVar4 == '\0') ||

                 (pcVar7 = (char *)FUN_006be710(&local_1a,param_2,iVar9,1), *pcVar7 == '\0')) {

                cVar4 = '\0';

              }

              else {

                cVar4 = '\x01';

              }

            }

            iVar5 = iVar12;

            if (*(short *)(local_18 + 6 + (uint)*(ushort *)(iVar9 + 2) * 8) == 3) {

              if ((cVar4 == '\0') ||

                 (pcVar7 = (char *)FUN_006be710(&local_19,param_2,

                                                local_18 + (uint)*(ushort *)(iVar9 + 2) * 8,3),

                 *pcVar7 == '\0')) {

                cVar4 = '\0';

              }

              else {

                cVar4 = '\x01';

              }

            }

          }

          iVar11 = iVar11 + -0x10;

          local_c = local_c + -1;

          cVar3 = cVar4;

        } while (local_c != 0);

      }

      local_14 = cVar3;

      if (param_4 == '\0') {

        local_10 = ((int *)*param_5)[1];

      }

      else {

        local_10 = *(int *)*param_5;

      }

      local_4 = param_5[1];

      if (-1 < local_4 + -1) {

        local_c = (local_4 + -1) * 0x10;

        do {

          piVar10 = (int *)*param_5;

          if (param_4 == '\0') {

            iVar5 = *(int *)((int)piVar10 + local_c + 4);

          }

          else {

            iVar5 = *(int *)((int)piVar10 + local_c);

          }

          if (iVar5 != local_10) {

            iVar11 = iVar5;

            if (param_4 == '\0') {

              iVar11 = local_18 + (uint)*(ushort *)(iVar5 + 2) * 8;

            }

            local_10 = iVar5;

            if (*(short *)(iVar11 + 6) == 2) {

              local_8 = '\x01';

              if (param_4 == '\0') {

                iVar5 = piVar10[1];

              }

              else {

                iVar5 = *piVar10;

              }

              iVar12 = param_5[1] + -1;

              if (-1 < iVar12) {

                piVar10 = piVar10 + iVar12 * 4;

                do {

                  if (param_4 == '\0') {

                    iVar9 = piVar10[1];

                  }

                  else {

                    iVar9 = *piVar10;

                  }

                  if ((iVar9 != iVar5) && (iVar5 = iVar9, *(short *)(iVar9 + 6) != 2)) {

                    local_8 = '\0';

                    break;

                  }

                  iVar12 = iVar12 + -1;

                  piVar10 = piVar10 + -4;

                } while (-1 < iVar12);

              }

              bVar2 = false;

              iVar5 = 0;

              if (0 < *(int *)(param_2 + 8)) {

                psVar8 = (short *)(*(int *)(param_2 + 4) + 6);

                do {

                  if (*psVar8 == 0) {

                    bVar2 = true;

                    break;

                  }

                  iVar5 = iVar5 + 1;

                  psVar8 = psVar8 + 4;

                } while (iVar5 < *(int *)(param_2 + 8));

              }

              if ((local_8 != '\0') && (bVar2)) {

                if ((local_14 == '\0') ||

                   (pcVar7 = (char *)FUN_006be710(&local_19,param_2,iVar11,3), *pcVar7 == '\0')) {

                  local_14 = '\0';

                }

                else {

                  local_14 = '\x01';

                }

              }

            }

          }

          local_c = local_c + -0x10;

          local_4 = local_4 + -1;

        } while (local_4 != 0);

      }

      iVar5 = 0;

      if (0 < *(int *)(param_2 + 8)) {

        do {

          if ((local_14 == '\0') || (*(short *)(*(int *)(param_2 + 4) + 6 + iVar5 * 8) == 0)) {

            local_14 = '\0';

          }

          else {

            local_14 = '\x01';

          }

          iVar5 = iVar5 + 1;

        } while (iVar5 < *(int *)(param_2 + 8));

      }

      *param_1 = local_14;

      return;

    }

  }

  *param_1 = '\x01';

  return;

}
