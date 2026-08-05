// =============================================================================
// Named_CalleeOf_Named_ChatClientImpl_0067a1b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067a1b0
// Callee of Named_ChatClientImpl
// Address:   0x0067a1b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ChatClientImpl: social/chat helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006810a0×7, FUN_006812f0×3, CONCAT31, FUN_0067a1b0.
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

Named_CalleeOf_Named_ChatClientImpl_0067a1b0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint8_t param_8,

            uint8_t param_9,uint32_t /* width from decompiler */ param_10,uint32_t /* width from decompiler */ param_11)



{

  uint8_t local_4;

  undefined3 uStack_3;

  

  _local_4 = CONCAT31((int3)((uint)param_1 >> 8),10);

  FUN_006810a0(&local_4,1);

  FUN_006810a0(&param_3,4);

  param_3 = param_4;

  FUN_006810a0(&param_3,4);

  param_3 = param_5;

  FUN_006810a0(&param_3,4);

  param_3 = param_6;

  FUN_006810a0(&param_3,4);

  FUN_006812f0(param_7);

  FUN_006810a0(&param_8,1);

  param_8 = param_9;

  FUN_006810a0(&param_8,1);

  FUN_006812f0(param_10);

  FUN_006812f0(param_11);

  return;

}
