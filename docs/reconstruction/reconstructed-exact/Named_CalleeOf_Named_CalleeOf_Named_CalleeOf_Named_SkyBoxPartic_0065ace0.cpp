// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_0065ace0
// -----------------------------------------------------------------------------
// Stable ID: aa_0065ace0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x0065ace0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0065ace0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_0065ace0(int *param_1,int param_2)



{

  int *piVar1;

  

  param_2 = param_2 + 1;

  if (param_2 <= param_1[2]) {

    piVar1 = (int *)(*param_1 + param_2 * 4);

    do {

      if (*piVar1 != -1) {

        return;

      }

      param_2 = param_2 + 1;

      piVar1 = piVar1 + 1;

    } while (param_2 <= param_1[2]);

  }

  return;

}
