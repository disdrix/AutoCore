// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0040aa60
// -----------------------------------------------------------------------------
// Stable ID: aa_0040aa60
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x0040aa60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: while×3, if×3, do×1, return×1.
//  - Notable callees: FUN_0040aa60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0040aa60(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint32_t /* width from decompiler */ **ppuVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *local_1c;

  uint32_t /* width from decompiler */ *local_18;

  uint32_t /* width from decompiler */ *local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar7 = (int)param_3 - (int)param_1 >> 4;

  iVar9 = param_2 - (int)param_1 >> 4;

  iVar5 = iVar9;

  param_2 = iVar7;

  while (iVar1 = iVar5, iVar1 != 0) {

    iVar5 = param_2 % iVar1;

    param_2 = iVar1;

  }

  if ((param_2 < iVar7) && (0 < param_2)) {

    puVar8 = param_1 + param_2 * 4;

    do {

      local_10 = *puVar8;

      local_c = puVar8[1];

      local_8 = puVar8[2];

      local_4 = puVar8[3];

      if (puVar8 + iVar9 * 4 == param_3) {

        ppuVar6 = &param_1;

      }

      else {

        local_1c = puVar8 + iVar9 * 4;

        ppuVar6 = &local_1c;

      }

      puVar4 = *ppuVar6;

      puVar3 = puVar8;

      while (puVar2 = puVar4, puVar2 != puVar8) {

        *puVar3 = *puVar2;

        puVar3[1] = puVar2[1];

        puVar3[2] = puVar2[2];

        puVar3[3] = puVar2[3];

        iVar5 = (int)param_3 - (int)puVar2 >> 4;

        if (iVar9 < iVar5) {

          local_18 = puVar2 + iVar9 * 4;

          ppuVar6 = &local_18;

        }

        else {

          ppuVar6 = &local_14;

          local_14 = param_1 + (iVar5 * 0xfffffff + iVar9) * 4;

        }

        puVar3 = puVar2;

        puVar4 = *ppuVar6;

      }

      *puVar3 = local_10;

      puVar3[1] = local_c;

      puVar8 = puVar8 + -4;

      param_2 = param_2 + -1;

      puVar3[2] = local_8;

      puVar3[3] = local_4;

    } while (param_2 != 0);

  }

  return;

}
