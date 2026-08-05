// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxLightManager_004494b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004494b0
// Callee of Named_CalleeOf_Named_gfxLightManager
// Address:   0x004494b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxLightManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_004494b0, FUN_00449680, FUN_00449700.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxLightManager
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

int Named_CalleeOf_Named_CalleeOf_Named_gfxLightManager_004494b0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *local_8;

  uint32_t /* width from decompiler */ *local_4;

  

  FUN_00449700();

  iVar2 = 0;

  for (puVar1 = local_8; puVar1 != local_4; puVar1 = (uint32_t /* width from decompiler */ *)*puVar1) {

    iVar2 = iVar2 + 1;

  }

  FUN_00449680(&local_8,local_8,local_4);

  return iVar2;

}
