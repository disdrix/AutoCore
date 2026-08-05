// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008c02d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008c02d0
// Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
// Address:   0x008c02d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RefreshOpenMissionUiWindows: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_004022a0×2, CVOGReaction_FailMissionNotify, FUN_004294f0, FUN_008c0030, FUN_008c02d0, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008c02d0(int param_1)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if ((in_EAX != 0) && (in_EAX != -0x2c)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x574) = 0;

    *(uint8_t *)(param_1 + 0x514) = 0;

    *(uint8_t *)(param_1 + 0x515) = 0;

    *(uint8_t *)(param_1 + 0x516) = 0;

    *(uint8_t *)(param_1 + 0x517) = 0;

    *(uint8_t *)(param_1 + 0x518) = 0;

    *(uint8_t *)(param_1 + 0x519) = 0;

    *(uint8_t *)(param_1 + 0x51a) = 0;

    local_4 = 0;

    FUN_004294f0();

    iVar2 = FUN_004022a0(&local_4,&local_8);

    while (iVar2 == 0) {

      if ((local_8 != 0) && (cVar1 = FUN_008c0030(), cVar1 != '\0')) {

        CVOGReaction_FailMissionNotify(&local_8);

      }

      iVar2 = FUN_004022a0(&local_4,&local_8);

    }

    if (*(char *)(in_EAX + 0x54) != '\0') {

      *(uint8_t *)(in_EAX + 0x54) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x30));

    }

  }

  return;

}
