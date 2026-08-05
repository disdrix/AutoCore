// =============================================================================
// FUN_004c2500
// -----------------------------------------------------------------------------
// Stable ID: aa_004c2500
// Address:   0x004c2500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c2500 @ 0x004c2500
// Stable ID: aa_004c2500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×6, return×5, do×2, while×2.
//  - Notable callees: FUN_004c2500.
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

void __fastcall FUN_004c2500(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1e4);

  if (puVar1 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x1e8)) {

    do {

      if ((void *)*puVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)*puVar1);

      }

      *puVar1 = 0;

      puVar1 = puVar1 + 1;

    } while (puVar1 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x1e8));

  }

  if (*(void **)(param_1 + 0x1e4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x1e4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1e4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1e8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ec) = 0;

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 500);

  if (puVar1 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x1f8)) {

    do {

      if ((void *)*puVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)*puVar1);

      }

      *puVar1 = 0;

      puVar1 = puVar1 + 1;

    } while (puVar1 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x1f8));

  }

  if (*(void **)(param_1 + 500) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 500));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 500) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1f8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1fc) = 0;

  *(uint8_t *)(param_1 + 0x200) = 0;

  return;

}
