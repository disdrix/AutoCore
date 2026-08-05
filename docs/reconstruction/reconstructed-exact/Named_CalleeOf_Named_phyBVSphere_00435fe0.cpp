// =============================================================================
// Named_CalleeOf_Named_phyBVSphere_00435fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00435fe0
// Callee of Named_phyBVSphere (+7 other named callers)
// Address:   0x00435fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_phyBVSphere: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_phyBVSphere (+7 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00435df0, FUN_00435fe0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_phyBVSphere (+7 other named callers)
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_phyBVSphere_00435fe0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0x20) < *(int *)(param_1 + 0x18) + 4) {

    iVar1 = FUN_00435df0(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18));

    if ((iVar1 < 0) || (*(int *)(param_1 + 0x20) < 4)) {

      return 0xffffffff;

    }

  }

  *param_2 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + param_1 + 0x2c);

  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 4;

  return 0;

}
