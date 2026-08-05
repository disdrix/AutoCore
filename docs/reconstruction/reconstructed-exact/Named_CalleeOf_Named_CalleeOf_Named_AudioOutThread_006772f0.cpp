// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_AudioOutThread_006772f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006772f0
// Callee of Named_CalleeOf_Named_AudioOutThread
// Address:   0x006772f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_AudioOutThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00676940, FUN_00676d20, FUN_006772f0, FUN_00680c50.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_AudioOutThread
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_AudioOutThread_006772f0(int param_1,uint param_2)



{

  uint uVar1;

  uint8_t local_14 [8];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a9398;

  local_c = ExceptionList;

  uVar1 = *(uint *)(param_1 + 0x10);

  local_4 = 0;

  if (uVar1 < param_2) {

    ExceptionList = &local_c;

    FUN_00676d20(param_1,*(int *)(param_1 + 0xc) + uVar1,param_2 - uVar1,&stack0x00000008);

  }

  else {

    ExceptionList = &local_c;

    if (param_2 < uVar1) {

      ExceptionList = &local_c;

      FUN_00676940(local_14,param_1,*(int *)(param_1 + 0xc) + param_2,param_1,

                   uVar1 + *(int *)(param_1 + 0xc));

    }

  }

  local_4 = 0xffffffff;

  FUN_00680c50();

  ExceptionList = local_c;

  return;

}
