// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_0096f740
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f740
// Callee of Named_gfxDeviceVB (+3 other named callers)
// Address:   0x0096f740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxDeviceVB (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0073d940, FUN_0096f740.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceVB (+3 other named callers)
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

void __fastcall Named_CalleeOf_Named_gfxDeviceVB_0096f740(int *param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  

  piVar3 = (int *)FUN_0073d940(*param_1);

  if (piVar3 != (int *)0x0) {

    piVar3[1] = piVar3[1] + 1;

    if (piVar3[1] == 1) {

      (**(code **)(*piVar3 + 4))();

    }

    piVar2 = (int *)*param_1;

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

    *param_1 = (int)piVar3;

  }

  return;

}
