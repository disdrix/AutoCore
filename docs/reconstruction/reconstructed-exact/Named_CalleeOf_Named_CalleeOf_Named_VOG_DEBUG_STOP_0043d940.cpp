// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0043d940
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d940
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0043d940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0043d940, FUN_0043df90, FUN_0043e080.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0043d940(int param_1,uint param_2)



{

  uint uVar1;

  uint8_t local_8 [8];

  

  uVar1 = *(uint *)(param_1 + 0x10);

  if (uVar1 < param_2) {

    FUN_0043e080(param_1,*(int *)(param_1 + 0xc) + uVar1,param_2 - uVar1,&stack0x00000008);

    return;

  }

  if (param_2 < uVar1) {

    FUN_0043df90(local_8,param_1,*(int *)(param_1 + 0xc) + param_2,param_1,

                 uVar1 + *(int *)(param_1 + 0xc));

  }

  return;

}
