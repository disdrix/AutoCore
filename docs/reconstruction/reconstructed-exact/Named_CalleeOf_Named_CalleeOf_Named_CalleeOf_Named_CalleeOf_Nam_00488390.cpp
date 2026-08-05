// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00488390
// -----------------------------------------------------------------------------
// Stable ID: aa_00488390
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00488390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×9, while×5, return×2, do×1, goto×1.
//  - Notable callees: FUN_00488130×6, FUN_00488390.
//  - Return sites: 2.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00488390(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,int param_5,

                 int *param_6)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *local_1c;

  

  iVar4 = (param_5 - param_4) + 1;

  if (1 < iVar4) {

    iVar6 = 0;

    iVar1 = DAT_00afd9e8;

    while (iVar1 < iVar4) {

      iVar6 = iVar6 + 1;

      iVar1 = (&DAT_00afd9e8)[iVar6];

    }

joined_r0x004883d3:

    iVar6 = iVar6 + -1;

    if (-1 < iVar6) {

      iVar1 = (&DAT_00afd9e8)[iVar6];

      iVar4 = iVar1 + param_4;

      if (iVar4 <= param_5) {

        local_1c = (uint32_t /* width from decompiler */ *)(param_1 + (iVar4 - iVar1) * 4);

        iVar9 = iVar4;

        do {

          uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + iVar9 * 4);

          cVar3 = FUN_00488130(param_2,param_3,param_6);

          iVar5 = iVar9;

          puVar7 = local_1c;

          while (cVar3 != '\0') {

            *(uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 4) = *puVar7;

            iVar5 = iVar5 - iVar1;

            puVar7 = puVar7 + -iVar1;

            if (iVar5 <= iVar4 + -1) break;

            cVar3 = FUN_00488130(param_2,param_3,param_6);

          }

          puVar7 = local_1c + 1;

          iVar8 = iVar9 + 1;

          *(uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 4) = uVar2;

          if (param_5 < iVar8) break;

          uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + iVar8 * 4);

          cVar3 = FUN_00488130(param_2,param_3,param_6);

          while (cVar3 != '\0') {

            *(uint32_t /* width from decompiler */ *)(param_1 + iVar8 * 4) = *puVar7;

            iVar8 = iVar8 - iVar1;

            puVar7 = puVar7 + -iVar1;

            if (iVar8 <= iVar4 + -1) break;

            cVar3 = FUN_00488130(param_2,param_3,param_6);

          }

          puVar7 = local_1c + 2;

          iVar5 = iVar9 + 2;

          *(uint32_t /* width from decompiler */ *)(param_1 + iVar8 * 4) = uVar2;

          if (param_5 < iVar5) break;

          uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 4);

          cVar3 = FUN_00488130(param_2,param_3,param_6);

          while (cVar3 != '\0') {

            *(uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 4) = *puVar7;

            iVar5 = iVar5 - iVar1;

            puVar7 = puVar7 + -iVar1;

            if (iVar5 <= iVar4 + -1) break;

            cVar3 = FUN_00488130(param_2,param_3,param_6);

          }

          local_1c = local_1c + 3;

          *(uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 4) = uVar2;

          iVar9 = iVar9 + 3;

          if (*param_6 < 0) {

            return;

          }

        } while (iVar9 <= param_5);

      }

      goto joined_r0x004883d3;

    }

  }

  return;

}
