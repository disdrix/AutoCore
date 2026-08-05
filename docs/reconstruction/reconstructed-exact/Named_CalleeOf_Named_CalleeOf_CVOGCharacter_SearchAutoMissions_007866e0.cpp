// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGCharacter_SearchAutoMissions_007866e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007866e0
// Callee of Named_CalleeOf_CVOGCharacter_SearchAutoMissions
// Address:   0x007866e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGCharacter_SearchAutoMissions: character create/apply helper. Evidence string: "Hermann". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Hermann"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, while×1.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_00480ca0, FUN_00786280, FUN_007866e0, GetCurrentThreadId, QueryPerformanceCounter.
//  - Strings: "Hermann".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGCharacter_SearchAutoMissions
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

int Named_CalleeOf_Named_CalleeOf_CVOGCharacter_SearchAutoMissions_007866e0(int param_1)



{

  DWORD *pDVar1;

  int iVar2;

  void *pvVar3;

  int iVar4;

  int iVar5;

  LARGE_INTEGER local_24;

  LPCRITICAL_SECTION local_1c;

  DWORD local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ace61;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_24.s.LowPart = GetCurrentThreadId();

  local_1c = (LPCRITICAL_SECTION)(param_1 + 0x58);

  EnterCriticalSection(local_1c);

  iVar4 = 0;

  iVar5 = 0;

  while( true ) {

    if (*(int *)(param_1 + 0x4c) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c)) / 0xc;

    }

    if (iVar2 <= iVar4) break;

    if (*(DWORD *)(*(int *)(param_1 + 0x4c) + iVar5) == local_24.s.LowPart) {

      LeaveCriticalSection(local_1c);

      ExceptionList = local_c;

      return iVar4;

    }

    iVar4 = iVar4 + 1;

    iVar5 = iVar5 + 0xc;

  }

  local_18 = local_24.s.LowPart;

  pvVar3 = operator_new(0x5c);

  local_4 = 0;

  if (pvVar3 == (void *)0x0) {

    local_14 = 0;

  }

  else {

    local_14 = FUN_00786280(pvVar3,"Hermann");

  }

  local_4 = 0xffffffff;

  pDVar1 = *(DWORD **)(local_14 + 4);

  *(int *)(local_14 + 0x3c) = *(int *)(local_14 + 0x3c) + 1;

  pDVar1[2] = 0;

  pDVar1[3] = 0;

  pDVar1[8] = 0;

  pDVar1[6] = 0;

  pDVar1[7] = 0;

  pDVar1[9] = 0;

  pDVar1[10] = 0;

  local_10 = local_14;

  QueryPerformanceCounter(&local_24);

  pDVar1[1] = local_24.s.HighPart;

  *pDVar1 = local_24.s.LowPart;

  FUN_00480ca0();

  if (*(int *)(param_1 + 0x4c) == 0) {

    iVar4 = 0;

  }

  else {

    iVar4 = (*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c)) / 0xc;

  }

  LeaveCriticalSection(local_1c);

  ExceptionList = local_c;

  return iVar4 + -1;

}
