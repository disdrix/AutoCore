// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00770f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00770f80
// Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
// Address:   0x00770f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, for×2, while×2, return×1.
//  - Notable callees: CARRY4×3, __allmul×3, FUN_007703d0, FUN_007707d0, FUN_00770f80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00770f80(int *param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  uint *puVar8;

  uint *puVar9;

  longlong lVar10;

  uint64_t uVar11;

  int local_24;

  int local_1c;

  int local_18;

  int local_c;

  int local_8;

  uint *local_4;

  

  iVar1 = *param_1;

  iVar7 = iVar1 * 2 + 1;

  iVar3 = FUN_007703d0();

  if (iVar3 == 0) {

    if (0 < iVar1) {

      local_1c = 1;

      local_24 = 0;

      puVar8 = local_4;

      local_18 = iVar1;

      do {

        lVar10 = __allmul(*(uint32_t /* width from decompiler */ *)(param_1[3] + local_24),0,

                          *(uint32_t /* width from decompiler */ *)(param_1[3] + local_24),0);

        uVar4 = (uint)(lVar10 + (ulonglong)*puVar8);

        uVar5 = uVar4 >> 0x1c | (int)(lVar10 + (ulonglong)*puVar8 >> 0x20) * 0x10;

        *puVar8 = uVar4 & 0xfffffff;

        uVar2 = *(uint32_t /* width from decompiler */ *)(local_24 + param_1[3]);

        puVar9 = puVar8;

        for (iVar3 = local_1c; puVar9 = puVar9 + 1, iVar3 < iVar1; iVar3 = iVar3 + 1) {

          uVar11 = __allmul(*(uint32_t /* width from decompiler */ *)(param_1[3] + iVar3 * 4),0,uVar2,0);

          uVar11 = __allmul(uVar11,2,0);

          uVar4 = (uint)uVar11 + *puVar9;

          uVar6 = uVar4 + uVar5;

          uVar5 = uVar6 >> 0x1c |

                  ((int)((ulonglong)uVar11 >> 0x20) + (uint)CARRY4((uint)uVar11,*puVar9) +

                  (uint)CARRY4(uVar4,uVar5)) * 0x10;

          *puVar9 = uVar6 & 0xfffffff;

        }

        for (; uVar5 != 0; uVar5 = uVar6 >> 0x1c | (uint)CARRY4(uVar4,uVar5) << 4) {

          uVar4 = *puVar9;

          uVar6 = uVar4 + uVar5;

          *puVar9 = uVar6 & 0xfffffff;

          puVar9 = puVar9 + 1;

        }

        local_24 = local_24 + 4;

        puVar8 = puVar8 + 2;

        local_1c = local_1c + 1;

        local_18 = local_18 + -1;

      } while (local_18 != 0);

    }

    if (0 < iVar7) {

      puVar8 = local_4 + iVar1 * 2;

      do {

        if (*puVar8 != 0) break;

        iVar7 = iVar7 + -1;

        puVar8 = puVar8 + -1;

      } while (0 < iVar7);

    }

    if (iVar7 == 0) {

      local_8 = 0;

    }

    *param_2 = iVar7;

    param_2[1] = local_c;

    param_2[2] = local_8;

    param_2[3] = (int)local_4;

    FUN_007707d0();

    iVar3 = 0;

  }

  return iVar3;

}
