// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_008a20b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008a20b0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x008a20b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, goto×2, while×2, return×1, for×1.
//  - Notable callees: FUN_008a20b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_008a20b0(int param_1)



{

  int iVar1;

  byte bVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  byte *pbVar5;

  byte *pbVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  bool bVar10;

  

  uVar9 = 0;

  do {

    if ((*(int *)(param_1 + 4) == 0) ||

       ((uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2) <= uVar9)) {

      return;

    }

    for (uVar8 = 0;

        (iVar7 = *(int *)(param_1 + 4), iVar7 != 0 &&

        (uVar8 < (uint)(*(int *)(param_1 + 8) - iVar7 >> 2))); uVar8 = uVar8 + 1) {

      if ((((uVar9 != uVar8) && (*(int *)(iVar7 + uVar9 * 4) != 0)) &&

          (iVar1 = uVar8 * 4, *(int *)(iVar7 + uVar8 * 4) != 0)) &&

         ((iVar3 = *(int *)(iVar7 + uVar9 * 4), *(int *)(iVar3 + 0x52c) != 0 &&

          (*(int *)(*(int *)(iVar7 + iVar1) + 0x52c) != 0)))) {

        pbVar5 = (byte *)(**(code **)(**(int **)(iVar3 + 0x52c) + 0x1dc))();

        pbVar6 = (byte *)(**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + iVar1) + 0x52c) +

                                     0x1dc))();

        if ((pbVar5 != (byte *)0x0) && (pbVar6 != (byte *)0x0)) {

          do {

            bVar2 = *pbVar5;

            bVar10 = bVar2 < *pbVar6;

            if (bVar2 != *pbVar6) {

LAB_008a2194:

              iVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);

              goto LAB_008a2199;

            }

            if (bVar2 == 0) break;

            bVar2 = pbVar5[1];

            bVar10 = bVar2 < pbVar6[1];

            if (bVar2 != pbVar6[1]) goto LAB_008a2194;

            pbVar5 = pbVar5 + 2;

            pbVar6 = pbVar6 + 2;

          } while (bVar2 != 0);

          iVar7 = 0;

LAB_008a2199:

          if (iVar7 < 0) {

            iVar7 = *(int *)(param_1 + 4);

            uVar4 = *(uint32_t /* width from decompiler */ *)(iVar7 + uVar9 * 4);

            *(uint32_t /* width from decompiler */ *)(iVar7 + uVar9 * 4) = *(uint32_t /* width from decompiler */ *)(iVar7 + iVar1);

            *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + iVar1) = uVar4;

          }

        }

      }

    }

    uVar9 = uVar9 + 1;

  } while( true );

}
