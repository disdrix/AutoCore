// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxIndexBufferImpl_0044eb70
// -----------------------------------------------------------------------------
// Stable ID: aa_0044eb70
// Callee of Named_CalleeOf_Named_gfxIndexBufferImpl
// Address:   0x0044eb70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxIndexBufferImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_004017f0, FUN_0044c9b0, FUN_0044eb70, FUN_0044ebd0, FUN_0044ec90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxIndexBufferImpl
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

int Named_CalleeOf_Named_CalleeOf_Named_gfxIndexBufferImpl_0044eb70(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int local_4;

  

  iVar1 = FUN_0044ec90();

  iVar2 = FUN_0044c9b0();

  iVar3 = 0;

  local_4 = iVar1;

  while (local_4 != iVar2) {

    iVar3 = iVar3 + 1;

    FUN_004017f0();

  }

  FUN_0044ebd0(&local_4,iVar1,iVar2);

  return iVar3;

}
