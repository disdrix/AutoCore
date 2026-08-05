// =============================================================================
// Named_CalleeOf_Named_gfxBody_00437c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00437c90
// Callee of Named_gfxBody
// Address:   0x00437c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00438ca0×2, FUN_00437c90, FUN_0046c1b0, FUN_0076a900.
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxBody_00437c90(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_4;

  

  uVar1 = FUN_0076a900();

  FUN_00438ca0();

  FUN_0046c1b0();

  iVar2 = FUN_00438ca0();

  if (local_4 != *(int *)(iVar2 + 8)) {

    uVar1 = (**(code **)(local_4 + 0xc))(uVar1);

    return uVar1;

  }

  return 0;

}
