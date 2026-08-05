// =============================================================================
// Named_CalleeOf_Named_gfxView_00972cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00972cc0
// Callee of Named_gfxView (+2 other named callers)
// Address:   0x00972cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxView: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxView (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_00972cc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxView (+2 other named callers)
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

void __fastcall Named_CalleeOf_Named_gfxView_00972cc0(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  fVar1 = g_flOne;

  puVar3 = &DAT_00afdf70;

  puVar4 = param_1;

  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar4 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar4 = puVar4 + 1;

  }

  puVar3 = &DAT_00afdf70;

  puVar4 = param_1 + 0x10;

  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar4 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar4 = puVar4 + 1;

  }

  param_1[0x20] = 0;

  param_1[0x21] = 0;

  param_1[0x22] = 0;

  param_1[0x23] = fVar1;

  param_1[0x24] = 0;

  param_1[0x25] = 0;

  param_1[0x26] = 0;

  param_1[0x27] = fVar1;

  param_1[0x28] = fVar1;

  param_1[0x29] = fVar1;

  param_1[0x2a] = fVar1;

  param_1[0x2b] = fVar1;

  param_1[0x2c] = fVar1;

  param_1[0x2d] = 0;

  *(uint8_t *)(param_1 + 0x2e) = 0;

  param_1[0x2f] = 0;

  return;

}
