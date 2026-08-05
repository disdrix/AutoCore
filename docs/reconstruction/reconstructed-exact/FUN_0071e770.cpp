// =============================================================================
// FUN_0071e770
// -----------------------------------------------------------------------------
// Stable ID: aa_0071e770
// Address:   0x0071e770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071e770 @ 0x0071e770
// Stable ID: aa_0071e770
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: Client_GetMissionCompleteAudioTable×2, CONCAT31, EnterCriticalSection, FUN_0071e770, FUN_0071f010, FUN_0071f930, LeaveCriticalSection.
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

void FUN_0071e770(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ad3e7;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00aa98a0;

  local_4 = 0;

  if (*(char *)((int)param_1 + 0x1c5) != '\0') {

    iVar2 = Client_GetMissionCompleteAudioTable();

    EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x3f8));

    local_4 = CONCAT31(local_4._1_3_,1);

    iVar3 = Client_GetMissionCompleteAudioTable();

    *(uint8_t *)(iVar3 + 0x410) = 1;

    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x3f8));

  }

  pvVar1 = (void *)param_1[5];

  if (pvVar1 != (void *)0x0) {

    FUN_0071f010();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[5] = 0;

  local_4 = 0xffffffff;

  FUN_0071f930();

  ExceptionList = local_c;

  return;

}
