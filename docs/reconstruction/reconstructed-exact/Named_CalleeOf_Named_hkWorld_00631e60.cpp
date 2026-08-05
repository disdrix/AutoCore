// =============================================================================
// Named_CalleeOf_Named_hkWorld_00631e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00631e60
// Callee of Named_hkWorld
// Address:   0x00631e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_hkWorld: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00631e60, FUN_00637f30, FUN_00638060.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_hkWorld
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

int __thiscall Named_CalleeOf_Named_hkWorld_00631e60(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t local_400 [1024];

  

  FUN_00637f30(local_400,0x400,&DAT_00a9d718,param_2);

  iVar1 = **(int **)(param_1 + 8);

  uVar2 = FUN_00638060(local_400);

  (**(code **)(iVar1 + 8))(local_400,uVar2);

  return param_1;

}
