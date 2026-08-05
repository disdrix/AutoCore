// =============================================================================
// Named_CalleeOf_Named_ChatClientImpl_0067a630
// -----------------------------------------------------------------------------
// Stable ID: aa_0067a630
// Callee of Named_ChatClientImpl
// Address:   0x0067a630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ChatClientImpl: social/chat helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006810a0×3, CONCAT31, FUN_0067a630.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_ChatClientImpl
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

void __thiscall

Named_CalleeOf_Named_ChatClientImpl_0067a630(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint8_t local_4;

  undefined3 uStack_3;

  

  _local_4 = CONCAT31((int3)((uint)param_1 >> 8),0xd);

  FUN_006810a0(&local_4,1);

  FUN_006810a0(&param_3,1);

  param_3 = param_4;

  FUN_006810a0(&param_3,2);

  return;

}
