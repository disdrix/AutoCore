// =============================================================================
// Named_CalleeOf_Named_Palantir_00735410
// -----------------------------------------------------------------------------
// Stable ID: aa_00735410
// Callee of Named_Palantir
// Address:   0x00735410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Palantir: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: if×22, do×2, while×2, goto×2, return×2, switch×1.
//  - Notable callees: FUN_0040ead0, FUN_0043b800, FUN_00735410.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Palantir
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_Palantir_00735410(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,int param_4)



{

  char cVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  char *pcVar7;

  int local_c;

  uint local_4;

  

  *param_2 = 0;

  *param_3 = 0;

  pcVar7 = *(char **)(param_1 + 0x710);

  local_4 = 0;

  if (pcVar7 != *(char **)(param_1 + 0x714)) {

    do {

      if (*(char *)(param_4 + 10) == *pcVar7) {

        if (*(char *)(param_4 + 8) == '\0') {

LAB_00735474:

          if (pcVar7[0x10] != '\0') {

LAB_0073547e:

            local_c = 0;

            if (*(char *)(param_4 + 10) == '\0') {

              local_c = 4;

            }

            else {

              if ((*(int *)(pcVar7 + 4) == *(int *)(param_4 + 0x34)) &&

                 (*(int *)(pcVar7 + 8) == *(int *)(param_4 + 0x38))) {

                local_c = 2;

              }

              else if ((*(int *)(param_4 + 0x34) < *(int *)(pcVar7 + 4)) &&

                      (*(int *)(param_4 + 0x38) < *(int *)(pcVar7 + 8))) {

                local_c = 1;

              }

              uVar3 = FUN_0040ead0(*(uint32_t /* width from decompiler */ *)(pcVar7 + 0xc));

              if (uVar3 == *(uint *)(param_4 + 0x14)) {

                local_c = local_c + 2;

              }

              else if (*(uint *)(param_4 + 0x14) < uVar3) {

                local_c = local_c + 1;

              }

            }

            piVar5 = *(int **)(pcVar7 + 0x18);

            if (piVar5 != *(int **)(pcVar7 + 0x1c)) {

              do {

                if (*(char *)(param_4 + 8) == '\0') {

                  cVar1 = (char)piVar5[1];

                }

                else {

                  cVar1 = *(char *)((int)piVar5 + 5);

                }

                if (cVar1 != '\0') {

                  iVar4 = *piVar5;

                  iVar6 = 0;

                  switch(iVar4) {

                  case 0x47:

                    uVar3 = 0x20;

                    break;

                  default:

                    uVar3 = 0;

                    break;

                  case 0x49:

                    uVar3 = 0xf;

                    break;

                  case 0x4b:

                  case 0x4d:

                  case 0x4f:

                    uVar3 = 0x18;

                    break;

                  case 0x50:

                    uVar3 = 0x10;

                  }

                  uVar2 = *(uint *)(param_4 + 0x18);

                  if (uVar3 == uVar2) {

                    iVar6 = 2;

                  }

                  else {

                    uVar3 = FUN_0043b800();

                    if (uVar2 < uVar3) {

                      iVar6 = 1;

                    }

                  }

                  if (iVar4 == 0x49) {

                    iVar4 = 1;

                  }

                  else if (iVar4 == 0x4b) {

                    iVar4 = 8;

                  }

                  else if (iVar4 == 0x4f) {

                    iVar4 = 4;

                  }

                  else {

                    iVar4 = 0;

                  }

                  if (iVar4 == *(int *)(param_4 + 0x1c)) {

                    iVar6 = iVar6 + 1;

                  }

                  if (local_4 < (uint)(local_c + iVar6)) {

                    *param_2 = pcVar7;

                    *param_3 = piVar5;

                    local_4 = local_c + iVar6;

                  }

                }

                piVar5 = piVar5 + 4;

              } while (piVar5 != *(int **)(pcVar7 + 0x1c));

            }

          }

        }

        else if (pcVar7[0x11] != '\0') {

          if (*(char *)(param_4 + 8) == '\0') goto LAB_00735474;

          goto LAB_0073547e;

        }

      }

      pcVar7 = pcVar7 + 0x24;

    } while (pcVar7 != *(char **)(param_1 + 0x714));

    if (local_4 != 0) {

      return 0;

    }

  }

  return 0xffffffff;

}
