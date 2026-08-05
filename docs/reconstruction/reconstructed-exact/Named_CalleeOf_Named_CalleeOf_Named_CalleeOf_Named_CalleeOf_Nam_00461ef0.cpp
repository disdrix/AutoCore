// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00461ef0
// -----------------------------------------------------------------------------
// Stable ID: aa_00461ef0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice
// Address:   0x00461ef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00461ef0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00461ef0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t *puVar6;

  

  if (param_1 != param_2) {

    puVar5 = in_EAX;

    puVar6 = (uint8_t *)((int)param_2 + 0x15);

    do {

      puVar4 = param_2 + -7;

      in_EAX = puVar5 + -7;

      *in_EAX = *puVar4;

      puVar5[-6] = param_2[-6];

      puVar5[-5] = param_2[-5];

      puVar5[-4] = param_2[-4];

      piVar2 = *(int **)(puVar6 + -0x21);

      if ((piVar2 != (int *)0x0) && (piVar2[1] = piVar2[1] + 1, piVar2[1] == 1)) {

        (**(code **)(*piVar2 + 4))();

      }

      piVar3 = (int *)puVar5[-3];

      if (piVar3 != (int *)0x0) {

        piVar1 = piVar3 + 1;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*piVar3 + 8))();

        }

      }

      puVar5[-3] = piVar2;

      *(uint8_t *)(puVar5 + -2) = puVar6[-0x1d];

      *(uint8_t *)((int)puVar5 + -7) = puVar6[-0x1c];

      *(uint8_t *)((int)puVar5 + -6) = puVar6[-0x1b];

      puVar5[-1] = *(uint32_t /* width from decompiler */ *)(puVar6 + -0x19);

      param_2 = puVar4;

      puVar5 = in_EAX;

      puVar6 = puVar6 + -0x1c;

    } while (puVar4 != param_1);

  }

  return in_EAX;

}
