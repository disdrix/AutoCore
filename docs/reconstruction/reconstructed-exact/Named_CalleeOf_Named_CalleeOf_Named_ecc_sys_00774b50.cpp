// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00774b50
// -----------------------------------------------------------------------------
// Stable ID: aa_00774b50
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x00774b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_007709e0, FUN_00770f80, FUN_00772df0, FUN_00773ca0, FUN_00774b50.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_ecc_sys
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

void Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00774b50(int *param_1,int param_2)



{

  int iVar1;

  

  iVar1 = *param_1;

  if (DAT_00afa2b8 <= iVar1) {

    FUN_00773ca0(param_2);

    *(uint32_t /* width from decompiler */ *)(param_2 + 8) = 0;

    return;

  }

  if (DAT_00afa2b0 <= iVar1) {

    FUN_00772df0(param_2);

    *(uint32_t /* width from decompiler */ *)(param_2 + 8) = 0;

    return;

  }

  if ((iVar1 * 2 + 1 < 0x200) && (iVar1 < 0x80)) {

    FUN_007709e0(param_1,param_2);

    *(uint32_t /* width from decompiler */ *)(param_2 + 8) = 0;

    return;

  }

  FUN_00770f80(param_1,param_2);

  *(uint32_t /* width from decompiler */ *)(param_2 + 8) = 0;

  return;

}
