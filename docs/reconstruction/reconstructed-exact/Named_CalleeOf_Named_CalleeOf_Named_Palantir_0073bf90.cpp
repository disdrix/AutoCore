// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Palantir_0073bf90
// -----------------------------------------------------------------------------
// Stable ID: aa_0073bf90
// Callee of Named_CalleeOf_Named_Palantir
// Address:   0x0073bf90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Palantir: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0073bf90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Palantir
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

void Named_CalleeOf_Named_CalleeOf_Named_Palantir_0073bf90(int *param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  

  iVar2 = 0;

  if (0 < *param_1) {

    piVar3 = param_1 + 0x2d;

    piVar4 = param_1 + 9;

    do {

      iVar1 = (*(code *)*piVar4)();

      *piVar3 = iVar1;

      iVar2 = iVar2 + 1;

      piVar3 = piVar3 + 1;

      piVar4 = piVar4 + 0xb;

    } while (iVar2 < *param_1);

  }

  return;

}
