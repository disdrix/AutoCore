// =============================================================================
// Named_CalleeOf_Named_Server_deleted_00631f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00631f80
// Callee of Named_Server_deleted (+4 other named callers)
// Address:   0x00631f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Server_deleted: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_Server_deleted (+4 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00631f80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Server_deleted (+4 other named callers)
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

int __thiscall Named_CalleeOf_Named_Server_deleted_00631f80(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint8_t local_4;

  undefined3 uStack_3;

  

  _local_4 = CONCAT31((int3)((uint)param_1 >> 8),10);

  (**(code **)(**(int **)(param_2 + 8) + 8))(&local_4,1);

  (**(code **)(**(int **)(param_2 + 8) + 0xc))();

  return param_2;

}
