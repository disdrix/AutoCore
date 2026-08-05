// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_00788db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00788db0
// Callee of Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx
// Address:   0x00788db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: for×3, if×2, return×1.
//  - Notable callees: FUN_00788db0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_00788db0(uint32_t /* width from decompiler */ *param_1,uint param_2)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  if (4 < (int)param_2) {

    iVar3 = (param_2 - 5 >> 2) + 1;

    puVar4 = param_1;

    for (iVar1 = iVar3; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    param_2 = param_2 + iVar3 * -4;

    param_1 = param_1 + iVar3;

  }

  if (0 < (int)param_2) {

    for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *param_1 = 0;

      param_1 = param_1 + 1;

    }

    for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {

      *(uint8_t *)param_1 = 0;

      param_1 = (uint32_t /* width from decompiler */ *)((int)param_1 + 1);

    }

  }

  return 1;

}
