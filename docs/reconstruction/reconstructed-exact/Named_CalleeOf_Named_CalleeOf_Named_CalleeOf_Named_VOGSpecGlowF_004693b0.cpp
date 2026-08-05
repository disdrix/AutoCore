// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGSpecGlowF_004693b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004693b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGSpecGlowFilter
// Address:   0x004693b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOGSpecGlowFilter: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, do×1, return×1.
//  - Notable callees: FUN_00468970×2, FUN_004693b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGSpecGlowFilter
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGSpecGlowF_004693b0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  float10 fVar5;

  float10 fVar6;

  

  puVar2 = param_1;

  if (param_1 != param_2) {

    while (puVar2 = puVar2 + 1, puVar2 != param_2) {

      piVar1 = (int *)*param_1;

      fVar5 = (float10)(**(code **)(*(int *)*puVar2 + 8))();

      fVar6 = (float10)(**(code **)(*piVar1 + 8))();

      puVar3 = puVar2;

      if (fVar6 <= (float10)(float)fVar5) {

        do {

          puVar4 = puVar3;

          piVar1 = (int *)puVar4[-1];

          fVar5 = (float10)(**(code **)(*(int *)*puVar2 + 8))();

          fVar6 = (float10)(**(code **)(*piVar1 + 8))();

          puVar3 = puVar4 + -1;

        } while ((float10)(float)fVar5 < fVar6);

        if ((puVar4 != puVar2) && (puVar2 != puVar2 + 1)) {

          FUN_00468970(puVar4,puVar2,puVar2 + 1);

        }

      }

      else if ((param_1 != puVar2) && (puVar2 != puVar2 + 1)) {

        FUN_00468970(param_1,puVar2,puVar2 + 1);

      }

    }

  }

  return;

}
