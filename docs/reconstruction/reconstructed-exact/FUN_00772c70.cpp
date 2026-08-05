// =============================================================================
// FUN_00772c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00772c70
// Address:   0x00772c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00772c70 @ 0x00772c70
// Stable ID: aa_00772c70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, do×3, while×3, for×1.
//  - Notable callees: CARRY4×2, FUN_00770280, FUN_00770490, FUN_00770710, FUN_00770ea0, FUN_007723e0, FUN_00772c70, __allmul.
//  - Return sites: 3.

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

int FUN_00772c70(int *param_1,int *param_2,int param_3)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  uint *puVar7;

  uint64_t uVar8;

  uint32_t /* width from decompiler */ *local_c;

  int local_8;

  int local_4;

  

  iVar2 = *param_2 * 2 + 1;

  if ((iVar2 < 0x200) && (*param_2 < 0x100)) {

    iVar2 = FUN_007723e0(param_1,param_2,param_3);

    return iVar2;

  }

  if ((iVar2 <= param_1[1]) || (iVar3 = FUN_00770490(), iVar3 == 0)) {

    *param_1 = iVar2;

    iVar2 = *param_2;

    local_4 = 0;

    if (0 < iVar2) {

      do {

        iVar3 = *(int *)(param_1[3] + local_4 * 4);

        puVar7 = (uint *)(param_1[3] + local_4 * 4);

        local_c = (uint32_t /* width from decompiler */ *)param_2[3];

        uVar6 = 0;

        local_8 = 0;

        if (0 < iVar2) {

          do {

            uVar8 = __allmul(*local_c,0,iVar3 * param_3 & 0xfffffff,0);

            uVar1 = *puVar7;

            uVar4 = (uint)uVar8 + uVar1;

            uVar5 = uVar4 + uVar6;

            local_c = local_c + 1;

            *puVar7 = uVar5 & 0xfffffff;

            uVar6 = uVar5 >> 0x1c |

                    ((int)((ulonglong)uVar8 >> 0x20) + (uint)CARRY4((uint)uVar8,uVar1) +

                    (uint)CARRY4(uVar4,uVar6)) * 0x10;

            local_8 = local_8 + 1;

            puVar7 = puVar7 + 1;

          } while (local_8 < *param_2);

          for (; uVar6 != 0; uVar6 = uVar6 >> 0x1c) {

            *puVar7 = *puVar7 + uVar6;

            uVar6 = *puVar7;

            *(byte *)((int)puVar7 + 3) = *(byte *)((int)puVar7 + 3) & 0xf;

            puVar7 = puVar7 + 1;

          }

        }

        iVar2 = *param_2;

        local_4 = local_4 + 1;

      } while (local_4 < iVar2);

    }

    iVar2 = *param_1;

    if (0 < iVar2) {

      do {

        if (*(int *)(param_1[3] + -4 + *param_1 * 4) != 0) break;

        iVar2 = *param_1 + -1;

        *param_1 = iVar2;

      } while (0 < iVar2);

      iVar2 = *param_1;

    }

    if (iVar2 == 0) {

      param_1[2] = 0;

    }

    FUN_00770280();

    iVar2 = FUN_00770710();

    if (iVar2 != -1) {

      iVar2 = FUN_00770ea0();

      return iVar2;

    }

    iVar3 = 0;

  }

  return iVar3;

}
