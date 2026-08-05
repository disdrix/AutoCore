// =============================================================================
// FUN_00423fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00423fe0
// Address:   0x00423fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00423fe0 @ 0x00423fe0
// Stable ID: aa_00423fe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: LeaveCriticalSection×3, EnterCriticalSection, FUN_00423fe0, FUN_00428010.
//  - Return sites: 3.

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

uint8_t FUN_00423fe0(int param_1)



{

  LPCRITICAL_SECTION lpCriticalSection;

  uint8_t uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int unaff_EDI;

  

  lpCriticalSection = (LPCRITICAL_SECTION)(unaff_EDI + 4);

  uVar1 = 0;

  EnterCriticalSection(lpCriticalSection);

  puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x1c);

  if (*(char *)(unaff_EDI + 0x28) != '\0') {

    LeaveCriticalSection(lpCriticalSection);

    return 0;

  }

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    while (puVar2[1] != param_1) {

      puVar2 = (uint32_t /* width from decompiler */ *)puVar2[2];

      if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

        LeaveCriticalSection(lpCriticalSection);

        return 0;

      }

    }

    FUN_00428010();

    (**(code **)*puVar2)(1);

    uVar1 = 1;

  }

  LeaveCriticalSection(lpCriticalSection);

  return uVar1;

}
