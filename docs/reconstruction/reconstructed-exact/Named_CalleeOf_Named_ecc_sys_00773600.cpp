// =============================================================================
// Named_CalleeOf_Named_ecc_sys_00773600
// -----------------------------------------------------------------------------
// Stable ID: aa_00773600
// Callee of Named_ecc_sys
// Address:   0x00773600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~178 non-empty decompiler lines.
//  - Control keywords: if×26, goto×6, return×4, while×2, for×1, do×1.
//  - Notable callees: FUN_007707d0×5, FUN_00771c00×3, FUN_007701d0×2, FUN_00770440×2, FUN_00770540×2, FUN_00770650×2, FUN_00770710×2, FUN_007707a0×2.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_ecc_sys
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

int Named_CalleeOf_Named_ecc_sys_00773600(int *param_1,int *param_2,int param_3,int param_4)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  uint32_t /* width from decompiler */ uVar9;

  int iVar10;

  int iVar11;

  uint64_t uVar12;

  int local_60;

  int local_50 [2];

  int local_48;

  int local_44;

  int local_40 [2];

  uint32_t /* width from decompiler */ local_38;

  int local_34;

  uint32_t /* width from decompiler */ local_30 [3];

  uint32_t /* width from decompiler */ *local_24;

  int local_20;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ *local_4;

  

  if (*param_2 == 0) {

    return -3;

  }

  iVar6 = FUN_00770710();

  if (iVar6 == -1) {

    if (param_4 == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = FUN_00770650();

    }

    if (param_3 != 0) {

      FUN_007701d0();

    }

    return iVar6;

  }

  iVar6 = FUN_007703d0();

  if (iVar6 != 0) {

    return iVar6;

  }

  local_20 = *param_1 + 2;

  iVar6 = FUN_00770440();

  if (iVar6 != 0) goto LAB_00773a79;

  iVar6 = FUN_00770440();

  if (iVar6 == 0) {

    iVar6 = FUN_00771d10();

    if (iVar6 == 0) {

      iVar6 = FUN_00771d10();

      if (iVar6 == 0) {

        iVar3 = param_1[2];

        iVar2 = param_2[2];

        local_38 = 0;

        local_48 = 0;

        iVar6 = FUN_00770620();

        if (iVar6 % 0x1c < 0x1b) {

          local_60 = 0x1b - iVar6 % 0x1c;

          iVar6 = FUN_00772b90(local_60);

          if ((iVar6 == 0) && (iVar6 = FUN_00772b90(local_60), iVar6 == 0)) goto LAB_00773740;

        }

        else {

          local_60 = 0;

LAB_00773740:

          iVar7 = local_40[0] + -1;

          iVar10 = local_50[0] + -1;

          iVar6 = FUN_00771c00();

          if (iVar6 == 0) {

            iVar6 = FUN_007707a0();

            while (iVar6 != -1) {

              piVar1 = (int *)(local_14 + (iVar10 - iVar7) * 4);

              *piVar1 = *piVar1 + 1;

              iVar6 = FUN_007716f0(local_50);

              if (iVar6 != 0) goto LAB_00773a55;

              iVar6 = FUN_007707a0();

            }

            FUN_00770280();

            for (; local_40[0] <= iVar10; iVar10 = iVar10 + -1) {

              if (iVar10 <= local_50[0]) {

                uVar8 = *(uint *)(local_44 + iVar10 * 4);

                uVar4 = *(uint *)(local_34 + iVar7 * 4);

                if (uVar8 == uVar4) {

                  iVar11 = iVar10 - iVar7;

                  *(uint32_t /* width from decompiler */ *)(local_14 + -4 + iVar11 * 4) = 0xfffffff;

                }

                else {

                  uVar12 = __aulldiv(uVar8 << 0x1c | *(uint *)(local_44 + -4 + iVar10 * 4),

                                     uVar8 >> 4,uVar4,0);

                  uVar8 = (uint)uVar12;

                  if (((int)((ulonglong)uVar12 >> 0x20) != 0) || (0xfffffff < uVar8)) {

                    uVar8 = 0xfffffff;

                  }

                  iVar11 = iVar10 - iVar7;

                  *(uint *)(local_14 + -4 + iVar11 * 4) = uVar8 & 0xfffffff;

                }

                iVar5 = local_14;

                *(uint *)(local_14 + -4 + iVar11 * 4) =

                     *(int *)(local_14 + -4 + iVar11 * 4) + 1U & 0xfffffff;

                do {

                  *(uint *)(iVar5 + -4 + iVar11 * 4) =

                       *(int *)(iVar5 + -4 + iVar11 * 4) - 1U & 0xfffffff;

                  FUN_007701d0();

                  if (local_40[0] + -2 < 0) {

                    uVar9 = 0;

                  }

                  else {

                    uVar9 = *(uint32_t /* width from decompiler */ *)(local_34 + -4 + iVar7 * 4);

                  }

                  *local_24 = uVar9;

                  local_24[1] = *(uint32_t /* width from decompiler */ *)(local_34 + iVar7 * 4);

                  local_30[0] = 2;

                  iVar6 = FUN_00771920(local_30,*(uint32_t /* width from decompiler */ *)(iVar5 + -4 + iVar11 * 4),local_30);

                  if (iVar6 != 0) goto LAB_00773a55;

                  if (iVar10 + -2 < 0) {

                    uVar9 = 0;

                  }

                  else {

                    uVar9 = *(uint32_t /* width from decompiler */ *)(local_44 + (iVar10 + -2) * 4);

                  }

                  *local_4 = uVar9;

                  if (iVar10 + -1 < 0) {

                    uVar9 = 0;

                  }

                  else {

                    uVar9 = *(uint32_t /* width from decompiler */ *)(local_44 + -4 + iVar10 * 4);

                  }

                  local_4[1] = uVar9;

                  local_4[2] = *(uint32_t /* width from decompiler */ *)(local_44 + iVar10 * 4);

                  local_10 = 3;

                  iVar6 = FUN_00770710();

                } while (iVar6 == 1);

                iVar6 = FUN_00771920(local_40,*(uint32_t /* width from decompiler */ *)(iVar5 + -4 + iVar11 * 4),local_30);

                if (((iVar6 != 0) || (iVar6 = FUN_00771c00(), iVar6 != 0)) ||

                   (iVar6 = FUN_007716f0(local_50), iVar6 != 0)) goto LAB_00773a55;

                if (local_48 == 1) {

                  iVar6 = FUN_00770650();

                  if (((iVar6 != 0) || (iVar6 = FUN_00771c00(), iVar6 != 0)) ||

                     (iVar6 = FUN_00772390(), iVar6 != 0)) goto LAB_00773a55;

                  *(uint *)(local_14 + -4 + iVar11 * 4) =

                       *(int *)(local_14 + -4 + iVar11 * 4) - 1U & 0xfffffff;

                }

              }

            }

            iVar6 = 0;

            if (local_50[0] == 0) {

              local_48 = 0;

            }

            else {

              local_48 = param_1[2];

            }

            if (param_3 != 0) {

              FUN_00770820();

              FUN_00770540();

              *(uint *)(param_3 + 8) = (uint)(iVar3 != iVar2);

            }

            if (param_4 != 0) {

              FUN_00772050(local_60,local_50,0);

              FUN_00770540();

            }

          }

        }

LAB_00773a55:

        FUN_007707d0();

      }

      FUN_007707d0();

    }

    FUN_007707d0();

  }

  FUN_007707d0();

LAB_00773a79:

  FUN_007707d0();

  return iVar6;

}
