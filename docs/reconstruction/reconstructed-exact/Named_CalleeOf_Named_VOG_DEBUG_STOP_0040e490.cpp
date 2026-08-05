// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0040e490
// -----------------------------------------------------------------------------
// Stable ID: aa_0040e490
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x0040e490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: EnterCriticalSection×2, LeaveCriticalSection×2, FUN_0040e490, InterlockedDecrement.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_VOG_DEBUG_STOP_0040e490(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  bool bVar4;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009bc0c0;

  local_10 = ExceptionList;

  local_8 = 0;

  if (*(int *)(param_1 + 4) != 0) {

    ExceptionList = &local_10;

    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

    bVar4 = *(LONG *)(param_1 + 0xc) < 2;

    if (bVar4) {

      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));

    }

    uVar2 = puVar1[1];

    iVar3 = *(int *)(*(int *)(param_1 + 4) + 8);

    *(int *)(param_1 + 4) = iVar3;

    if (iVar3 == 0) {

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

    return uVar2;

  }

  return 0;

}
