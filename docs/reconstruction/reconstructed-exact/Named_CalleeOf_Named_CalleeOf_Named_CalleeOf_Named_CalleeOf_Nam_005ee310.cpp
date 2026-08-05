// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ee310
// -----------------------------------------------------------------------------
// Stable ID: aa_005ee310
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x005ee310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_005ee310, free, malloc.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ee310(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  size_t _Size;

  uint uVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  if ((uint)param_1[2] <= (uint)param_1[1]) {

    iVar2 = *param_1;

    uVar1 = ((param_1[1] - iVar2) / 0xc) * 2 + 2;

    if (iVar2 == 0) {

      uVar4 = 0;

    }

    else {

      uVar4 = (param_1[2] - iVar2) / 0xc;

    }

    if (uVar4 < uVar1) {

      _Size = uVar1 * 0xc;

      pvVar5 = malloc(_Size);

      puVar3 = (uint32_t /* width from decompiler */ *)param_1[1];

      puVar6 = (uint32_t /* width from decompiler */ *)*param_1;

      if (puVar6 != puVar3) {

        puVar7 = (uint32_t /* width from decompiler */ *)((int)pvVar5 + 8);

        do {

          puVar7[-2] = *puVar6;

          puVar7[-1] = puVar6[1];

          *puVar7 = puVar6[2];

          puVar6 = puVar6 + 3;

          puVar7 = puVar7 + 3;

        } while (puVar6 != puVar3);

      }

      if ((void *)*param_1 != (void *)0x0) {

        free((void *)*param_1);

      }

      param_1[2] = (int)(_Size + (int)pvVar5);

      param_1[1] = (int)((int)pvVar5 + ((param_1[1] - *param_1) / 0xc) * 0xc);

      *param_1 = (int)pvVar5;

    }

  }

  puVar3 = (uint32_t /* width from decompiler */ *)param_1[1];

  *puVar3 = *param_2;

  puVar3[1] = param_2[1];

  puVar3[2] = param_2[2];

  param_1[1] = param_1[1] + 0xc;

  return;

}
