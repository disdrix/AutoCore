// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_0073e780
// -----------------------------------------------------------------------------
// Stable ID: aa_0073e780
// Callee of Named_CalleeOf_Named_gfxDevice
// Address:   0x0073e780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00456780, FUN_0073e780.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDevice
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_0073e780(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

  for (puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 4); puVar3 != puVar1; puVar3 = puVar3 + 1) {

    piVar2 = (int *)*puVar3;

    if (piVar2 != (int *)0x0) {

      piVar4 = piVar2 + 5;

      iVar5 = 4;

      do {

        if (*piVar4 != 0) {

          (**(code **)(*(int *)*piVar4 + 8))((int *)*piVar4);

        }

        piVar4 = piVar4 + 2;

        iVar5 = iVar5 + -1;

      } while (iVar5 != 0);

      *piVar2 = (int)DAT_00d219ac;

      DAT_00d219ac = piVar2;

    }

  }

  FUN_00456780(0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  return;

}
