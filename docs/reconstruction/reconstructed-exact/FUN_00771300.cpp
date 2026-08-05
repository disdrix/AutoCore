// =============================================================================
// FUN_00771300
// -----------------------------------------------------------------------------
// Stable ID: aa_00771300
// Address:   0x00771300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00771300 @ 0x00771300
// Stable ID: aa_00771300
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×11, do×3, while×3, return×2.
//  - Notable callees: CARRY4×2, FUN_007703d0, FUN_007707d0, FUN_00770d10, FUN_00771300, __allmul.
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

int FUN_00771300(int *param_1,int *param_2,int *param_3,int param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  uint *puVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint64_t uVar12;

  int local_28;

  int local_24;

  int local_c;

  int local_8;

  int local_4;

  

  if (param_4 < 0x200) {

    iVar2 = *param_1;

    if (*param_2 <= *param_1) {

      iVar2 = *param_2;

    }

    if (iVar2 < 0x100) {

      iVar2 = FUN_00770d10(param_1,param_3,param_4);

      return iVar2;

    }

  }

  iVar2 = FUN_007703d0();

  if (iVar2 == 0) {

    iVar2 = *param_1;

    if (0 < iVar2) {

      local_28 = param_4;

      iVar5 = 0;

      do {

        uVar9 = 0;

        iVar7 = *param_2;

        if (local_28 <= *param_2) {

          iVar7 = local_28;

        }

        uVar1 = *(uint32_t /* width from decompiler */ *)(param_1[3] + iVar5 * 4);

        puVar11 = (uint32_t /* width from decompiler */ *)param_2[3];

        puVar10 = (uint *)(local_4 + iVar5 * 4);

        iVar8 = 0;

        local_24 = iVar7;

        if (0 < iVar7) {

          do {

            uVar12 = __allmul(*puVar11,0,uVar1,0);

            uVar3 = (uint)uVar12 + *puVar10;

            uVar4 = uVar3 + uVar9;

            uVar9 = uVar4 >> 0x1c |

                    ((int)((ulonglong)uVar12 >> 0x20) + (uint)CARRY4((uint)uVar12,*puVar10) +

                    (uint)CARRY4(uVar3,uVar9)) * 0x10;

            *puVar10 = uVar4 & 0xfffffff;

            puVar11 = puVar11 + 1;

            puVar10 = puVar10 + 1;

            local_24 = local_24 + -1;

            iVar8 = iVar7;

          } while (local_24 != 0);

        }

        if (iVar8 + iVar5 < param_4) {

          *puVar10 = uVar9;

        }

        local_28 = local_28 + -1;

        iVar5 = iVar5 + 1;

      } while (iVar5 < iVar2);

    }

    if (0 < param_4) {

      piVar6 = (int *)(local_4 + -4 + param_4 * 4);

      do {

        if (*piVar6 != 0) break;

        param_4 = param_4 + -1;

        piVar6 = piVar6 + -1;

      } while (0 < param_4);

    }

    if (param_4 == 0) {

      local_8 = 0;

    }

    *param_3 = param_4;

    param_3[1] = local_c;

    param_3[2] = local_8;

    param_3[3] = local_4;

    FUN_007707d0();

    iVar2 = 0;

  }

  return iVar2;

}
