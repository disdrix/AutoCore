// =============================================================================
// FUN_00983dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00983dd0
// Address:   0x00983dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00983dd0 @ 0x00983dd0
// Stable ID: aa_00983dd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, for×1.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_0043b9e0, FUN_0076b210, FUN_00983dd0, FUN_00989e00.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall FUN_00983dd0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  LPCRITICAL_SECTION lpCriticalSection;

  undefined *puVar4;

  uint8_t local_14 [4];

  LPCRITICAL_SECTION local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af672;

  local_c = ExceptionList;

  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x38);

  ExceptionList = &local_c;

  local_10 = lpCriticalSection;

  if (*(char *)(param_1 + 0x50) != '\0') {

    ExceptionList = &local_c;

    EnterCriticalSection(lpCriticalSection);

  }

  local_4 = 0;

  if (param_2 == 0) {

    if (*(char *)(param_1 + 0x50) != '\0') {

      LeaveCriticalSection(lpCriticalSection);

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

  for (puVar2 = (uint32_t /* width from decompiler */ *)*puVar1; puVar2 != puVar1; puVar2 = (uint32_t /* width from decompiler */ *)*puVar2) {

    puVar4 = (undefined *)puVar2[2];

    if ((undefined *)puVar2[2] == (undefined *)0x0) {

      puVar4 = PTR_DAT_00afa2bc;

    }

    cVar3 = FUN_0076b210(param_2);

    if (cVar3 != '\0') {

      FUN_00989e00(local_14,puVar4);

      FUN_0043b9e0();

      lpCriticalSection = local_10;

    }

  }

  if (*(char *)&lpCriticalSection[1].DebugInfo != '\0') {

    LeaveCriticalSection(lpCriticalSection);

  }

  ExceptionList = local_c;

  return 0;

}
