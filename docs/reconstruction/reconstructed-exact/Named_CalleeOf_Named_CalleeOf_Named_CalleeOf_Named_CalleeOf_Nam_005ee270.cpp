// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ee270
// -----------------------------------------------------------------------------
// Stable ID: aa_005ee270
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x005ee270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005ee270, free, malloc.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ee270(int *param_1,uint param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint uVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  uVar3 = 0;

  if (*param_1 != 0) {

    uVar3 = (param_1[2] - *param_1) / 0xc;

  }

  if (uVar3 < param_2) {

    pvVar4 = malloc(param_2 * 0xc);

    puVar1 = (uint32_t /* width from decompiler */ *)param_1[1];

    puVar5 = (uint32_t /* width from decompiler */ *)*param_1;

    if (puVar5 != puVar1) {

      puVar6 = (uint32_t /* width from decompiler */ *)((int)pvVar4 + 8);

      do {

        puVar6[-2] = *puVar5;

        puVar6[-1] = puVar5[1];

        *puVar6 = puVar5[2];

        puVar5 = puVar5 + 3;

        puVar6 = puVar6 + 3;

      } while (puVar5 != puVar1);

    }

    if ((void *)*param_1 != (void *)0x0) {

      free((void *)*param_1);

    }

    iVar2 = *param_1;

    *param_1 = (int)pvVar4;

    param_1[2] = (int)(param_2 * 0xc + (int)pvVar4);

    param_1[1] = (int)((int)pvVar4 + ((param_1[1] - iVar2) / 0xc) * 0xc);

  }

  return;

}
