// =============================================================================
// FUN_007fd470
// -----------------------------------------------------------------------------
// Stable ID: aa_007fd470
// Address:   0x007fd470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fd470 @ 0x007fd470
// Stable ID: aa_007fd470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×30, return×2.
//  - Notable callees: FUN_0092f000×6, FUN_007fd470.
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

void FUN_007fd470(void)



{

  int iVar1;

  int unaff_ESI;

  

  if (*(char *)(unaff_ESI + 0x30b4) != '\0') {

    *(uint8_t *)(unaff_ESI + 0x30b4) = 0;

    if (*(int *)(unaff_ESI + 0x309c) != 0) {

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xb0))

                (*(int *)(unaff_ESI + 0x309c));

    }

  }

  if (*(char *)(unaff_ESI + 0x30b5) != '\0') {

    iVar1 = *(int *)(unaff_ESI + 0x309c);

    *(uint8_t *)(unaff_ESI + 0x30b5) = 0;

    if (iVar1 != 0) {

      if (*(int **)(iVar1 + 0x2b0) != (int *)0x0) {

        (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

      }

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xa8))

                (*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x309c));

      (**(code **)(**(int **)(unaff_ESI + 0x309c) + 4))(1);

      FUN_0092f000();

    }

  }

  if (*(char *)(unaff_ESI + 0x30b6) != '\0') {

    *(uint8_t *)(unaff_ESI + 0x30b6) = 0;

    if (*(int *)(unaff_ESI + 0x30a0) != 0) {

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xb0))

                (*(int *)(unaff_ESI + 0x30a0));

    }

  }

  if (*(char *)(unaff_ESI + 0x30b7) != '\0') {

    iVar1 = *(int *)(unaff_ESI + 0x30a0);

    *(uint8_t *)(unaff_ESI + 0x30b7) = 0;

    if (iVar1 != 0) {

      if (*(int **)(iVar1 + 0x2b0) != (int *)0x0) {

        (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

      }

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xa8))

                (*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30a0));

      (**(code **)(**(int **)(unaff_ESI + 0x30a0) + 4))(1);

      FUN_0092f000();

    }

  }

  if (*(char *)(unaff_ESI + 0x30b8) != '\0') {

    *(uint8_t *)(unaff_ESI + 0x30b8) = 0;

    if (*(int *)(unaff_ESI + 0x30a4) != 0) {

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xb0))

                (*(int *)(unaff_ESI + 0x30a4));

    }

  }

  if (*(char *)(unaff_ESI + 0x30b9) != '\0') {

    iVar1 = *(int *)(unaff_ESI + 0x30a4);

    *(uint8_t *)(unaff_ESI + 0x30b9) = 0;

    if (iVar1 != 0) {

      if (*(int **)(iVar1 + 0x2b0) != (int *)0x0) {

        (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

      }

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xa8))

                (*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30a4));

      (**(code **)(**(int **)(unaff_ESI + 0x30a4) + 4))(1);

      FUN_0092f000();

    }

  }

  if (*(char *)(unaff_ESI + 0x30ba) != '\0') {

    *(uint8_t *)(unaff_ESI + 0x30ba) = 0;

    if (*(int *)(unaff_ESI + 0x30a8) != 0) {

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xb0))

                (*(int *)(unaff_ESI + 0x30a8));

    }

  }

  if (*(char *)(unaff_ESI + 0x30bb) != '\0') {

    iVar1 = *(int *)(unaff_ESI + 0x30a8);

    *(uint8_t *)(unaff_ESI + 0x30bb) = 0;

    if (iVar1 != 0) {

      if (*(int **)(iVar1 + 0x2b0) != (int *)0x0) {

        (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

      }

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xa8))

                (*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30a8));

      (**(code **)(**(int **)(unaff_ESI + 0x30a8) + 4))(1);

      FUN_0092f000();

    }

  }

  if (*(char *)(unaff_ESI + 0x30bc) != '\0') {

    *(uint8_t *)(unaff_ESI + 0x30bc) = 0;

    if (*(int *)(unaff_ESI + 0x30ac) != 0) {

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xb0))

                (*(int *)(unaff_ESI + 0x30ac));

    }

  }

  if (*(char *)(unaff_ESI + 0x30bd) != '\0') {

    iVar1 = *(int *)(unaff_ESI + 0x30ac);

    *(uint8_t *)(unaff_ESI + 0x30bd) = 0;

    if (iVar1 != 0) {

      if (*(int **)(iVar1 + 0x2b0) != (int *)0x0) {

        (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

      }

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xa8))

                (*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30ac));

      (**(code **)(**(int **)(unaff_ESI + 0x30ac) + 4))(1);

      FUN_0092f000();

    }

  }

  if (*(char *)(unaff_ESI + 0x30be) != '\0') {

    *(uint8_t *)(unaff_ESI + 0x30be) = 0;

    if (*(int *)(unaff_ESI + 0x30b0) != 0) {

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xb0))

                (*(int *)(unaff_ESI + 0x30b0));

    }

  }

  if (*(char *)(unaff_ESI + 0x30bf) != '\0') {

    iVar1 = *(int *)(unaff_ESI + 0x30b0);

    *(uint8_t *)(unaff_ESI + 0x30bf) = 0;

    if (iVar1 != 0) {

      if (*(int **)(iVar1 + 0x2b0) != (int *)0x0) {

        (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

      }

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xa8))

                (*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30b0));

      (**(code **)(**(int **)(unaff_ESI + 0x30b0) + 4))(1);

      FUN_0092f000();

      return;

    }

  }

  return;

}
