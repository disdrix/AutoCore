// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_0073d940
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d940
// Callee of Named_gfxDeviceVB (+1 other named callers)
// Address:   0x0073d940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxDeviceVB (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×4, for×1, while×1.
//  - Notable callees: FUN_0073d940, FUN_00752590.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceVB (+1 other named callers)
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

int __thiscall Named_CalleeOf_Named_gfxDeviceVB_0073d940(int param_1,int param_2)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int *piVar4;

  

  if ((param_2 != 0) && (*(int *)(param_2 + 8) != 0)) {

    for (piVar3 = *(int **)(param_1 + 4); piVar3 != *(int **)(param_1 + 8); piVar3 = piVar3 + 5) {

      if (*piVar3 == *(int *)(param_2 + 8)) {

        piVar4 = (int *)piVar3[2];

        piVar3 = (int *)piVar3[3];

        if (piVar4 == piVar3) {

          return 0;

        }

        while ((iVar1 = *piVar4, iVar1 == param_2 || (cVar2 = FUN_00752590(), cVar2 == '\0'))) {

          piVar4 = piVar4 + 1;

          if (piVar4 == piVar3) {

            return 0;

          }

        }

        return iVar1;

      }

    }

  }

  return 0;

}
