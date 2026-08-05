// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00448130
// -----------------------------------------------------------------------------
// Stable ID: aa_00448130
// Callee of Named_CalleeOf_Named_gfxDeviceVB
// Address:   0x00448130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: block×3, FUN_00448130, FUN_00448990.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDeviceVB
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

/* WARNING: Removing unreachable block (ram,0x00448141) */

/* WARNING: Removing unreachable block (ram,0x00448142) */

/* WARNING: Removing unreachable block (ram,0x00448156) */



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00448130(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  if (*(int *)(param_1 + 4) != *(int *)(param_1 + 8)) {

    *(int *)(param_1 + 8) = *(int *)(param_1 + 4);

  }

  FUN_00448990(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,param_3,param_3);

  return;

}
