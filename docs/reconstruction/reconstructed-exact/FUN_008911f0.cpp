// =============================================================================
// FUN_008911f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008911f0
// Address:   0x008911f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008911f0 @ 0x008911f0
// Stable ID: aa_008911f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: do×3, if×3, while×3, return×1.
//  - Notable callees: LeaveCriticalSection×2, FUN_004113b0, FUN_004294f0, FUN_00890b70, FUN_008911f0.
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

void FUN_008911f0(int param_1)



{

  int iVar1;

  int *local_4;

  

  do {

    FUN_004294f0();

    do {

      do {

        iVar1 = FUN_004113b0(param_1 + 0x50c,&local_4);

        if (iVar1 != 0) {

          if (*(char *)(param_1 + 0x534) != '\0') {

            *(uint8_t *)(param_1 + 0x534) = 0;

            LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x510));

          }

          return;

        }

      } while ((local_4 == (int *)0x0) || ((char)local_4[0x16a] == '\0'));

      iVar1 = (**(code **)(*local_4 + 0xe8))();

    } while (iVar1 == -1);

    if (*(char *)(param_1 + 0x534) != '\0') {

      *(uint8_t *)(param_1 + 0x534) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x510));

    }

    FUN_00890b70();

  } while( true );

}
