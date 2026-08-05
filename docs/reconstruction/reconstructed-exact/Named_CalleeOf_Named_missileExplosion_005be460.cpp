// =============================================================================
// Named_CalleeOf_Named_missileExplosion_005be460
// -----------------------------------------------------------------------------
// Stable ID: aa_005be460
// Callee of Named_missileExplosion
// Address:   0x005be460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_missileExplosion: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005bbdd0, FUN_005be460, FUN_005be600.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_missileExplosion
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_missileExplosion_005be460(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6c37;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar1 = FUN_005be600();

  local_4 = 0;

  if (iVar1 != 0) {

    uVar2 = FUN_005bbdd0(param_1);

    ExceptionList = local_c;

    return uVar2;

  }

  ExceptionList = local_c;

  return 0;

}
