// =============================================================================
// Named_CalleeOf_Named_gfxBody_00437b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00437b00
// Callee of Named_gfxBody
// Address:   0x00437b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00438c40×2, FUN_00437b00, FUN_0046c1b0, FUN_0076a900.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxBody
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxBody_00437b00(int *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_4;

  

  uVar1 = FUN_0076a900();

  FUN_00438c40();

  FUN_0046c1b0();

  iVar2 = FUN_00438c40();

  if (local_4 == *(int *)(iVar2 + 8)) {

    iVar2 = 0;

  }

  else {

    iVar2 = (**(code **)(local_4 + 0xc))(uVar1);

  }

  *param_1 = iVar2;

  if (iVar2 != 0) {

    uVar1 = (**(code **)(*(int *)(iVar2 + 4) + 4))();

    return uVar1;

  }

  return 0xffffffff;

}
