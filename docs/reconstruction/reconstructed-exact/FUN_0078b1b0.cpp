// =============================================================================
// FUN_0078b1b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078b1b0
// Address:   0x0078b1b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078b1b0 @ 0x0078b1b0
// Stable ID: aa_0078b1b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_00423f40×2, FUN_00424060×2, FUN_004294f0, FUN_0078b1b0, FUN_00792490, LeaveCriticalSection.
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

void __fastcall FUN_0078b1b0(int *param_1)



{

  int iVar1;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  FUN_004294f0();

  iVar1 = FUN_00423f40(&local_8);

  while( true ) {

    if (iVar1 != 0) {

      if ((char)param_1[0x14d] != '\0') {

        *(uint8_t *)(param_1 + 0x14d) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x144));

      }

      FUN_00424060();

      FUN_00424060();

      (**(code **)(*param_1 + 0x3ac))();

      FUN_00792490();

      return;

    }

    if (*(void **)(local_8 + 8) != (void *)0x0) break;

    *(uint32_t /* width from decompiler */ *)(local_8 + 8) = 0;

    iVar1 = FUN_00423f40(&local_8);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(local_8 + 8));

}
