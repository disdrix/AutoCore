// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_0063fca0
// -----------------------------------------------------------------------------
// Stable ID: aa_0063fca0
// Callee of Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
// Address:   0x0063fca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_0063fca0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_0063fca0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int *piVar2;

  

  if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

    if (param_2[2] == 2) {

      iVar1 = 0;

      if (0 < *(int *)(param_1 + 0x38)) {

        piVar2 = *(int **)(param_1 + 0x34);

        while ((uint32_t /* width from decompiler */ *)*piVar2 != param_2) {

          iVar1 = iVar1 + 1;

          piVar2 = piVar2 + 1;

          if (*(int *)(param_1 + 0x38) <= iVar1) {

            (**(code **)*param_2)(1);

            return;

          }

        }

        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x34) + iVar1 * 4) =

             *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x34) + *(int *)(param_1 + 0x38) * 4);

      }

    }

    (**(code **)*param_2)(1);

  }

  return;

}
