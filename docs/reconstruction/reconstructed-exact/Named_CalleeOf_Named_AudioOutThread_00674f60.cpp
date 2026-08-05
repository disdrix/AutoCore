// =============================================================================
// Named_CalleeOf_Named_AudioOutThread_00674f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00674f60
// Callee of Named_AudioOutThread
// Address:   0x00674f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_AudioOutThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_004e3050, FUN_006743b0, FUN_00674cf0, FUN_00674f60, FUN_00679310.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_AudioOutThread
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_AudioOutThread_00674f60(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int local_4;

  

  uVar1 = param_2;

  local_4 = param_1;

  FUN_004e3050(&local_4,&param_2);

  if (local_4 == *(int *)(param_1 + 0x144)) {

    return 0xffffffff;

  }

  if (*(int *)(local_4 + 0x10) != 0) {

    FUN_00674cf0();

    uVar2 = FUN_00679310();

    FUN_006743b0(uVar1);

    return uVar2;

  }

  return 0xffffffff;

}
