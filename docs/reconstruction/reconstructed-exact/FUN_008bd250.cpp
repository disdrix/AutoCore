// =============================================================================
// FUN_008bd250
// -----------------------------------------------------------------------------
// Stable ID: aa_008bd250
// Address:   0x008bd250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bd250 @ 0x008bd250
// Stable ID: aa_008bd250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_004022a0×2, CVOGReaction_FailMissionNotify, FUN_004294f0, FUN_008bd250, LeaveCriticalSection.
//  - Return sites: 1.

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

void FUN_008bd250(int param_1)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ local_4;

  

  if ((in_EAX != 0) && (in_EAX != -0x2c)) {

    local_4 = 0;

    FUN_004294f0();

    iVar1 = FUN_004022a0(&local_4,&param_1);

    while (iVar1 == 0) {

      if ((param_1 != 0) && (*(int *)(*(int *)(param_1 + 0xa8) + 0x38) == 4)) {

        CVOGReaction_FailMissionNotify(&param_1);

      }

      iVar1 = FUN_004022a0(&local_4,&param_1);

    }

    if (*(char *)(in_EAX + 0x54) != '\0') {

      *(uint8_t *)(in_EAX + 0x54) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x30));

    }

  }

  return;

}
