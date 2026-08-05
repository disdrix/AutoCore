// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e3330
// -----------------------------------------------------------------------------
// Stable ID: aa_004e3330
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004e3330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: EnterCriticalSection×2, LeaveCriticalSection×2, FUN_004e3330, InterlockedDecrement.
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e3330(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  bool bVar4;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009a24e0;

  local_10 = ExceptionList;

  local_8 = 0;

  if (*(int *)(param_1 + 4) == 0) {

    return 0;

  }

  ExceptionList = &local_10;

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  bVar4 = *(int *)(param_1 + 0xc) < 2;

  if (bVar4) {

    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));

  }

  iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);

  uVar3 = puVar1[1];

  *(int *)(param_1 + 4) = iVar2;

  if (iVar2 == 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  }

  puVar1[1] = 0;

  (**(code **)*puVar1)(1);

  if (bVar4) {

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));

  }

  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));

  InterlockedDecrement((LONG *)(param_1 + 0xc));

  ExceptionList = local_10;

  return uVar3;

}
