// =============================================================================
// FUN_00771150
// -----------------------------------------------------------------------------
// Stable ID: aa_00771150
// Address:   0x00771150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00771150 @ 0x00771150
// Stable ID: aa_00771150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×9, do×3, while×3, return×2.
//  - Notable callees: CARRY4×2, FUN_007703d0, FUN_007707d0, FUN_00770b90, FUN_00771150, __allmul.
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

int FUN_00771150(int *param_1,int *param_2,int *param_3,int param_4)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  int *piVar8;

  uint uVar9;

  uint *puVar10;

  uint *puVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint64_t uVar13;

  int local_30;

  int local_2c;

  int local_c;

  int local_8;

  int local_4;

  

  iVar4 = *param_1;

  iVar1 = *param_2;

  if (iVar1 + 1 + iVar4 < 0x200) {

    if (iVar1 <= iVar4) {

      iVar4 = iVar1;

    }

    if (iVar4 < 0x100) {

      iVar4 = FUN_00770b90(param_1,param_3,param_4);

      return iVar4;

    }

  }

  iVar4 = FUN_007703d0();

  if (iVar4 == 0) {

    iVar1 = *param_1;

    iVar2 = *param_2;

    iVar4 = iVar2 + 1 + iVar1;

    if (0 < iVar1) {

      local_30 = param_4 * 4;

      puVar11 = (uint *)(local_4 + local_30);

      iVar7 = 0;

      do {

        uVar3 = *(uint32_t /* width from decompiler */ *)(param_1[3] + iVar7 * 4);

        puVar12 = (uint32_t /* width from decompiler */ *)(param_2[3] + local_30);

        uVar9 = 0;

        puVar10 = puVar11;

        if (param_4 < iVar2) {

          local_2c = iVar2 - param_4;

          do {

            uVar13 = __allmul(*puVar12,0,uVar3,0);

            uVar5 = (uint)uVar13 + *puVar10;

            uVar6 = uVar5 + uVar9;

            uVar9 = uVar6 >> 0x1c |

                    ((int)((ulonglong)uVar13 >> 0x20) + (uint)CARRY4((uint)uVar13,*puVar10) +

                    (uint)CARRY4(uVar5,uVar9)) * 0x10;

            *puVar10 = uVar6 & 0xfffffff;

            puVar12 = puVar12 + 1;

            puVar10 = puVar10 + 1;

            local_2c = local_2c + -1;

          } while (local_2c != 0);

        }

        local_30 = local_30 + -4;

        iVar7 = iVar7 + 1;

        param_4 = param_4 + -1;

        *puVar10 = uVar9;

      } while (iVar7 < iVar1);

    }

    if (0 < iVar4) {

      piVar8 = (int *)(local_4 + -4 + iVar4 * 4);

      do {

        if (*piVar8 != 0) break;

        iVar4 = iVar4 + -1;

        piVar8 = piVar8 + -1;

      } while (0 < iVar4);

    }

    if (iVar4 == 0) {

      local_8 = 0;

    }

    *param_3 = iVar4;

    param_3[1] = local_c;

    param_3[2] = local_8;

    param_3[3] = local_4;

    FUN_007707d0();

    iVar4 = 0;

  }

  return iVar4;

}
