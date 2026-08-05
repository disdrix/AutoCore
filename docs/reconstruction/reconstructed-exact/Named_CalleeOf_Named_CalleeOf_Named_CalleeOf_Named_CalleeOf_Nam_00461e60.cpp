// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00461e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00461e60
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice
// Address:   0x00461e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00461e60.
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00461e60(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *in_EAX;

  uint8_t *puVar4;

  

  if (param_1 != param_2) {

    puVar4 = (uint8_t *)((int)param_1 + 0x15);

    do {

      *in_EAX = *param_1;

      in_EAX[1] = param_1[1];

      in_EAX[2] = param_1[2];

      in_EAX[3] = param_1[3];

      piVar2 = *(int **)(puVar4 + -5);

      if ((piVar2 != (int *)0x0) && (piVar2[1] = piVar2[1] + 1, piVar2[1] == 1)) {

        (**(code **)(*piVar2 + 4))();

      }

      piVar3 = (int *)in_EAX[4];

      if (piVar3 != (int *)0x0) {

        piVar1 = piVar3 + 1;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*piVar3 + 8))();

        }

      }

      in_EAX[4] = piVar2;

      *(uint8_t *)(in_EAX + 5) = puVar4[-1];

      *(uint8_t *)((int)in_EAX + 0x15) = *puVar4;

      *(uint8_t *)((int)in_EAX + 0x16) = puVar4[1];

      in_EAX[6] = *(uint32_t /* width from decompiler */ *)(puVar4 + 3);

      param_1 = param_1 + 7;

      in_EAX = in_EAX + 7;

      puVar4 = puVar4 + 0x1c;

    } while (param_1 != param_2);

  }

  return in_EAX;

}
