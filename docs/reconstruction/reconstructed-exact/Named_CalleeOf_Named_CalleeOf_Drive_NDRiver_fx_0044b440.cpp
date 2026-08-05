// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_0044b440
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b440
// Callee of Named_CalleeOf_Drive_NDRiver_fx
// Address:   0x0044b440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_NDRiver_fx: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: ABS×2, FUN_0044b440.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_NDRiver_fx
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_0044b440(int param_1,float param_2,float param_3,float param_4)



{

  float *pfVar1;

  

  pfVar1 = (float *)(param_1 + 0x9c);

  if (((param_2 != *(float *)(param_1 + 0x9c)) || (param_3 != *(float *)(param_1 + 0xa0))) ||

     (param_4 != *(float *)(param_1 + 0xa4))) {

    *pfVar1 = param_2;

    *(float *)(param_1 + 0xa0) = param_3;

    *(float *)(param_1 + 0xa4) = param_4;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = 0xffffffff;

    if ((ABS(*pfVar1 - *(float *)(param_1 + 0xa0)) <= DAT_00aaa620) &&

       (ABS(*pfVar1 - *(float *)(param_1 + 0xa4)) <= DAT_00aaa620)) {

      *(uint8_t *)(param_1 + 0xb8) = 0;

      *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;

      return;

    }

    *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;

    *(uint8_t *)(param_1 + 0xb8) = 1;

  }

  return;

}
