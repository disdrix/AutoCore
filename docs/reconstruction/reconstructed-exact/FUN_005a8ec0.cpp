// =============================================================================
// FUN_005a8ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a8ec0
// Address:   0x005a8ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a8ec0 @ 0x005a8ec0
// Stable ID: aa_005a8ec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, while×3, do×2.
//  - Notable callees: FUN_004b7150×2, FUN_004b99c0×2, FUN_005a8ec0.
//  - Return sites: 5.

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

void __fastcall FUN_005a8ec0(int param_1)



{

  void *pvVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int local_4;

  

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x124);

  if (puVar3 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x128)) {

    do {

      pvVar1 = (void *)*puVar3;

      if (pvVar1 != (void *)0x0) {

        FUN_004b7150();

        FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      puVar3 = puVar3 + 1;

    } while (puVar3 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x128));

  }

  if (*(void **)(param_1 + 0x124) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x124) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x128) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 300) = 0;

    piVar2 = (int *)(param_1 + 0x134);

    local_4 = 2;

    while( true ) {

      puVar3 = (uint32_t /* width from decompiler */ *)*piVar2;

      if (puVar3 != (uint32_t /* width from decompiler */ *)piVar2[1]) {

        do {

          pvVar1 = (void *)*puVar3;

          if (pvVar1 != (void *)0x0) {

            FUN_004b7150();

            FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar1);

          }

          puVar3 = puVar3 + 1;

        } while (puVar3 != (uint32_t /* width from decompiler */ *)piVar2[1]);

      }

      if ((void *)*piVar2 != (void *)0x0) break;

      *piVar2 = 0;

      piVar2[1] = 0;

      piVar2[2] = 0;

      piVar2 = piVar2 + 4;

      local_4 = local_4 + -1;

      if (local_4 == 0) {

        return;

      }

    }

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)*piVar2);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x124));

}
