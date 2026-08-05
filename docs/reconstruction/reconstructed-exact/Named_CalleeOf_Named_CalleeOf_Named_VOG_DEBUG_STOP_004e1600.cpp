// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e1600
// -----------------------------------------------------------------------------
// Stable ID: aa_004e1600
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004e1600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: EnterCriticalSection×2, FUN_004e16b3×2, FUN_004e1600.
//  - Return sites: 3.

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

uint __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e1600(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009a24b0;

  local_10 = ExceptionList;

  if (param_2 == 0) {

    return (uint)ExceptionList & 0xffffff00;

  }

  local_8 = 0;

  ExceptionList = &local_10;

  puVar1 = operator_new(0xc);

  puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1[2] = 0;

    puVar1[1] = 0;

    *puVar1 = &PTR_FUN_009cc1d4;

    puVar3 = puVar1;

  }

  puVar3[1] = param_2;

  if (*(int *)(param_1 + 0xc) < 4) {

    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));

  }

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));

  if (*(int *)(param_1 + 8) == 0) {

    *(uint32_t /* width from decompiler */ **)(param_1 + 4) = puVar3;

    *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar3;

    uVar2 = FUN_004e16b3();

    return uVar2;

  }

  *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 8) + 8) = puVar3;

  *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar3;

  uVar2 = FUN_004e16b3();

  return uVar2;

}
