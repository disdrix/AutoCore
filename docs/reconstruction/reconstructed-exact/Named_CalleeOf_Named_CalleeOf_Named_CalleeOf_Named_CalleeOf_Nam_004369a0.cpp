// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004369a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004369a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody
// Address:   0x004369a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_004369a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004369a0(uint *param_1,uint param_2,uint *param_3,uint param_4,uint *param_5,uint param_6,

                 uint *param_7)



{

  while ((param_3 != param_5 || (param_2 != param_4))) {

    if ((*param_3 & 1 << ((byte)param_2 & 0x1f)) == 0) {

      *param_7 = *param_7 & ~(1 << ((byte)param_6 & 0x1f));

    }

    else {

      *param_7 = *param_7 | 1 << ((byte)param_6 & 0x1f);

    }

    if (param_6 < 0x1f) {

      param_6 = param_6 + 1;

    }

    else {

      param_6 = 0;

      param_7 = param_7 + 1;

    }

    if (param_2 < 0x1f) {

      param_2 = param_2 + 1;

    }

    else {

      param_2 = 0;

      param_3 = param_3 + 1;

    }

  }

  *param_1 = param_6;

  param_1[1] = (uint)param_7;

  return;

}
