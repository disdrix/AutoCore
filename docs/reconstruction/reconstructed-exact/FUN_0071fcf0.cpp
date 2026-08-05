// =============================================================================
// FUN_0071fcf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071fcf0
// Address:   0x0071fcf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071fcf0 @ 0x0071fcf0
// Stable ID: aa_0071fcf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_0071f760, FUN_0071fcf0.
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

uint8_t * FUN_0071fcf0(int param_1)



{

  LPCRITICAL_SECTION lpCriticalSection;

  int iVar1;

  int iVar2;

  int *piVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab658;

  local_c = ExceptionList;

  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x158);

  ExceptionList = &local_c;

  EnterCriticalSection(lpCriticalSection);

  iVar2 = 0;

  local_4 = 0;

  piVar3 = (int *)(param_1 + 0x88);

  do {

    if (*piVar3 != 0) {

      iVar1 = FUN_0071f760(1);

      if (iVar1 != 0) {

        iVar2 = *(int *)(param_1 + 0x88 + iVar2 * 4);

        LeaveCriticalSection(lpCriticalSection);

        ExceptionList = local_c;

        return (uint8_t *)(iVar2 + 0x48);

      }

    }

    iVar2 = iVar2 + 1;

    piVar3 = piVar3 + 1;

  } while (iVar2 < 2);

  LeaveCriticalSection(lpCriticalSection);

  ExceptionList = local_c;

  return &DAT_00a1419b;

}
