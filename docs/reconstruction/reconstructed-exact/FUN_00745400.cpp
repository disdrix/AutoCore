// =============================================================================
// FUN_00745400
// -----------------------------------------------------------------------------
// Stable ID: aa_00745400
// Address:   0x00745400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00745400 @ 0x00745400
// Stable ID: aa_00745400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×18, goto×7, do×4, while×4, return×2.
//  - Notable callees: FUN_0043bfb0×2, FUN_0044e8c0, FUN_00744170, FUN_00744d10, FUN_007451b0, FUN_00745400, FUN_0075d530.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ FUN_00745400(int *param_1,int *param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int *piVar2;

  bool bVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  int *piVar7;

  int iVar8;

  uint32_t /* width from decompiler */ local_28;

  int local_24;

  int local_20;

  uint8_t local_1c [4];

  int *local_18;

  int *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  piVar2 = param_3;

  iVar4 = (int)param_1;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1223;

  local_c = ExceptionList;

  piVar7 = *(int **)((int)param_1 + 0x54);

  piVar6 = *(int **)((int)param_1 + 0x50);

  local_28 = 0;

  if (piVar6 != piVar7) {

    piVar5 = piVar6;

    do {

      if (*piVar5 == *param_3) break;

      piVar5 = piVar5 + 1;

    } while (piVar5 != piVar7);

    if (piVar5 != piVar7) {

      local_28 = 1;

      ExceptionList = &local_c;

      goto LAB_007455f6;

    }

  }

  if (piVar6 != piVar7) {

    do {

      if (*piVar6 == *param_2) break;

      piVar6 = piVar6 + 1;

    } while (piVar6 != piVar7);

    if (piVar6 != piVar7) {

      ExceptionList = &local_c;

      FUN_00744d10(&param_2,piVar6);

      local_18 = (int *)0x0;

      local_14 = (int *)0x0;

      local_10 = 0;

      local_4 = 0;

      FUN_00744170(piVar2,local_1c,0);

      param_1 = local_18;

      iVar8 = DAT_00d1f050;

      if (local_18 != local_14) {

        do {

          piVar7 = *(int **)(iVar4 + 0x50);

          piVar6 = *(int **)(iVar4 + 0x54);

          bVar3 = false;

          if (piVar7 != piVar6) {

            iVar1 = *param_1;

LAB_007454e2:

            if (piVar7 == param_2) {

              bVar3 = true;

            }

            if (*piVar7 != iVar1) goto code_r0x007454f3;

            if (bVar3) {

              local_24 = iVar1;

              if (piVar7 != piVar6) {

                if ((iVar8 != 0) && (FUN_0044e8c0(&local_20), local_20 != *(int *)(iVar8 + 8))) {

                  *(int *)(local_20 + 0x10) = *(int *)(local_20 + 0x10) + -1;

                }

                piVar2 = *(int **)(iVar4 + 0x54);

                piVar6 = piVar7 + 1;

                if (piVar6 != piVar2) {

                  iVar8 = (int)piVar7 - (int)piVar6;

                  do {

                    piVar7 = (int *)(iVar8 + (int)piVar6);

                    if (piVar7 != piVar6) {

                      *piVar7 = *piVar6;

                    }

                    piVar6 = piVar6 + 1;

                  } while (piVar6 != piVar2);

                }

                *(int *)(iVar4 + 0x54) = *(int *)(iVar4 + 0x54) + -4;

              }

              FUN_0043bfb0(param_2,1,&local_24);

              goto joined_r0x00745592;

            }

            goto LAB_007455a5;

          }

LAB_007454fa:

          FUN_0043bfb0(param_2,1,param_1);

joined_r0x00745592:

          iVar8 = DAT_00d1f050;

          if (DAT_00d1f050 != 0) {

            FUN_0075d530();

            iVar8 = DAT_00d1f050;

          }

LAB_007455a5:

          param_1 = param_1 + 1;

        } while (param_1 != local_14);

      }

      local_4 = 0xffffffff;

      if (local_18 != (int *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(local_18);

      }

      local_18 = (int *)0x0;

      local_14 = (int *)0x0;

      local_10 = 0;

      goto LAB_007455f6;

    }

  }

  local_28 = 4;

  ExceptionList = &local_c;

LAB_007455f6:

  local_4 = 0xffffffff;

  FUN_007451b0(param_3,param_4);

  ExceptionList = local_c;

  return local_28;

code_r0x007454f3:

  piVar7 = piVar7 + 1;

  if (piVar7 == piVar6) goto LAB_007454fa;

  goto LAB_007454e2;

}
