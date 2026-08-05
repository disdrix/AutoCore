// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00788280
// -----------------------------------------------------------------------------
// Stable ID: aa_00788280
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00788280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×7, return×6.
//  - Notable callees: FUN_00788280.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_VOG_DEBUG_STOP_00788280(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  if ((*param_2 == *param_4) && (param_2[1] == param_4[1])) {

    return 0;

  }

  if ((*param_2 == *param_5) && (param_2[1] == param_5[1])) {

    return 0;

  }

  if ((*param_3 == *param_4) && (param_3[1] == param_4[1])) {

    return 0;

  }

  if ((*param_3 == *param_5) && (param_3[1] == param_5[1])) {

    return 0;

  }

  fVar3 = *param_3 - *param_2;

  fVar1 = (param_5[1] - param_4[1]) * fVar3 - (param_3[1] - param_2[1]) * (*param_5 - *param_4);

  if (fVar1 != 0.0) {

    fVar1 = g_flOne / fVar1;

    fVar2 = ((param_2[1] - param_4[1]) * (*param_5 - *param_4) -

            (param_5[1] - param_4[1]) * (*param_2 - *param_4)) * fVar1;

    fVar1 = ((param_2[1] - param_4[1]) * fVar3 - (param_3[1] - param_2[1]) * (*param_2 - *param_4))

            * fVar1;

    if ((((0.0 < fVar2) && (fVar2 < g_flOne)) && (0.0 < fVar1)) && (fVar1 < g_flOne)) {

      if (param_1 != (float *)0x0) {

        *param_1 = fVar3 * fVar2 + *param_2;

        param_1[1] = (param_3[1] - param_2[1]) * fVar2 + param_2[1];

      }

      return 1;

    }

  }

  return 0;

}
