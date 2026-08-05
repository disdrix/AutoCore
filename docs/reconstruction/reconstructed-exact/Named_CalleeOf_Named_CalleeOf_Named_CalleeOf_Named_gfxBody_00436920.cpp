// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00436920
// -----------------------------------------------------------------------------
// Stable ID: aa_00436920
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody
// Address:   0x00436920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_00436920.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00436920(uint param_1,uint *param_2,uint param_3,uint *param_4,char *param_5)



{

  uint uVar1;

  

  while ((param_2 != param_4 || (param_1 != param_3))) {

    uVar1 = 1 << ((byte)param_1 & 0x1f);

    if (*param_5 == '\0') {

      *param_2 = *param_2 & ~uVar1;

    }

    else {

      *param_2 = *param_2 | uVar1;

    }

    if (param_1 < 0x1f) {

      param_1 = param_1 + 1;

    }

    else {

      param_1 = 0;

      param_2 = param_2 + 1;

    }

  }

  return;

}
