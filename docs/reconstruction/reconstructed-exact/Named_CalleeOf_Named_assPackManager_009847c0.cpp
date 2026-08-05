// =============================================================================
// Named_CalleeOf_Named_assPackManager_009847c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009847c0
// Callee of Named_assPackManager
// Address:   0x009847c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_0044e8c0, FUN_00469c80, FUN_00719630, FUN_009847c0, FUN_00989e00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_assPackManager
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_assPackManager_009847c0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  LPCRITICAL_SECTION lpCriticalSection;

  uint32_t /* width from decompiler */ uVar1;

  int local_11c;

  uint8_t local_118 [4];

  LPCRITICAL_SECTION local_114;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af7a1;

  local_c = ExceptionList;

  lpCriticalSection = (LPCRITICAL_SECTION)(param_2 + 0x38);

  ExceptionList = &local_c;

  local_114 = lpCriticalSection;

  if (*(char *)(param_2 + 0x50) != '\0') {

    ExceptionList = &local_c;

    EnterCriticalSection(lpCriticalSection);

  }

  local_4 = 0;

  FUN_00719630();

  FUN_00989e00(local_118,param_1);

  FUN_0044e8c0(&local_11c);

  if (local_11c == *(int *)(param_2 + 8)) {

    if (*(char *)(param_2 + 0x50) != '\0') {

      LeaveCriticalSection(lpCriticalSection);

    }

    uVar1 = 0xffffffff;

  }

  else {

    *(uint32_t /* width from decompiler */ *)(local_11c + 0x1c) = DAT_00d1eac0;

    FUN_00469c80();

    if (*(char *)(param_2 + 0x50) != '\0') {

      LeaveCriticalSection(lpCriticalSection);

    }

    uVar1 = 0;

  }

  ExceptionList = local_c;

  return uVar1;

}
