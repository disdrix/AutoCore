// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069ab70
// -----------------------------------------------------------------------------
// Stable ID: aa_0069ab70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069ab70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: while×3, if×3, do×1, return×1.
//  - Notable callees: FUN_0069ab70.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069ab70(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  uint32_t /* width from decompiler */ **ppuVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int iVar11;

  uint32_t /* width from decompiler */ *local_c;

  uint32_t /* width from decompiler */ *local_8 [2];

  

  puVar4 = param_3;

  iVar9 = (int)param_3 - param_1 >> 2;

  iVar11 = param_2 - param_1 >> 2;

  iVar7 = iVar11;

  param_2 = iVar9;

  while (iVar2 = iVar7, iVar2 != 0) {

    iVar7 = param_2 % iVar2;

    param_2 = iVar2;

  }

  if ((param_2 < iVar9) && (0 < param_2)) {

    puVar10 = (uint32_t /* width from decompiler */ *)(param_1 + param_2 * 4);

    do {

      uVar1 = *puVar10;

      if (puVar10 + iVar11 == puVar4) {

        puVar6 = &param_1;

      }

      else {

        param_3 = puVar10 + iVar11;

        puVar6 = &param_3;

      }

      puVar5 = (uint32_t /* width from decompiler */ *)*puVar6;

      puVar6 = puVar10;

      while (puVar3 = puVar5, puVar3 != puVar10) {

        *puVar6 = *puVar3;

        iVar7 = (int)puVar4 - (int)puVar3 >> 2;

        if (iVar11 < iVar7) {

          local_c = puVar3 + iVar11;

          ppuVar8 = &local_c;

        }

        else {

          local_8[0] = (uint32_t /* width from decompiler */ *)(param_1 + (iVar7 * 0x3fffffff + iVar11) * 4);

          ppuVar8 = local_8;

        }

        puVar6 = puVar3;

        puVar5 = *ppuVar8;

      }

      puVar10 = puVar10 + -1;

      param_2 = param_2 + -1;

      *puVar6 = uVar1;

    } while (param_2 != 0);

  }

  return;

}
