// =============================================================================
// Named_CalleeOf_Named_gfxDevice_00966630
// -----------------------------------------------------------------------------
// Stable ID: aa_00966630
// Callee of Named_gfxDevice
// Address:   0x00966630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_00966630.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDevice
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

void __fastcall Named_CalleeOf_Named_gfxDevice_00966630(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = &DAT_00d0e128;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_00d0e0e8;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  DAT_00d1a568 = 0;

  DAT_00d1a564 = 0;

  DAT_00d1a558 = 0;

  DAT_00d1a55c = 0;

  *param_2 = 0;

  param_2[1] = 0;

  param_2[2] = 0;

  param_2[0xf] = 0;

  return;

}
