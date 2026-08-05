// =============================================================================
// FUN_00789760
// -----------------------------------------------------------------------------
// Stable ID: aa_00789760
// Address:   0x00789760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00789760 @ 0x00789760
// Stable ID: aa_00789760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×5, while×2, return×2.
//  - Notable callees: FUN_00423f40×4, FUN_004294f0×2, LeaveCriticalSection×2, FUN_00424060, FUN_00789430, FUN_00789760.
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

void __fastcall FUN_00789760(int *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *local_8;

  int *local_4;

  

  local_4 = param_1;

  FUN_004294f0();

  iVar3 = FUN_00423f40(&local_8);

  while( true ) {

    if (iVar3 != 0) {

      if ((char)param_1[0x14d] != '\0') {

        *(uint8_t *)(param_1 + 0x14d) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x144));

      }

      FUN_00424060();

      FUN_004294f0();

      iVar3 = FUN_00423f40(&local_8);

      piVar1 = param_1;

      puVar2 = local_8;

      while (iVar3 == 0) {

        local_8 = puVar2;

        if (puVar2[2] != 0) {

          FUN_00789430();

        }

        *puVar2 = 0xffffffff;

        puVar2[1] = 0xffffffff;

        iVar3 = FUN_00423f40(&local_8);

        piVar1 = local_4;

        puVar2 = local_8;

      }

      if ((char)param_1[0x158] != '\0') {

        *(uint8_t *)(param_1 + 0x158) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14f));

      }

      (**(code **)(*piVar1 + 0x34c))();

      piVar1[0x266] = -1;

      piVar1[0x267] = -1;

      return;

    }

    if ((void *)local_8[2] != (void *)0x0) break;

    local_8[2] = 0;

    iVar3 = FUN_00423f40(&local_8);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)local_8[2]);

}
