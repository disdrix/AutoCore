// =============================================================================
// FUN_007243a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007243a0
// Address:   0x007243a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007243a0 @ 0x007243a0
// Stable ID: aa_007243a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, return×5, do×2, while×2.
//  - Notable callees: FUN_00723b20, FUN_007243a0.
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

void FUN_007243a0(void)



{

  int iVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x28c);

  if (puVar2 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x290)) {

    do {

      if ((void *)*puVar2 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)*puVar2);

      }

      puVar2 = puVar2 + 1;

    } while (puVar2 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x290));

  }

  if (*(void **)(unaff_ESI + 0x28c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 0x28c));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x290) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x294) = 0;

  piVar3 = *(int **)(unaff_ESI + 0x29c);

  if (piVar3 != *(int **)(unaff_ESI + 0x2a0)) {

    do {

      iVar1 = *piVar3;

      FUN_00723b20(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x128),*(uint32_t /* width from decompiler */ *)(iVar1 + 300),

                   *(uint32_t /* width from decompiler */ *)(iVar1 + 0x130),iVar1 + 0x20,0);

      if ((void *)*piVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)*piVar3);

      }

      piVar3 = piVar3 + 1;

    } while (piVar3 != *(int **)(unaff_ESI + 0x2a0));

  }

  if (*(void **)(unaff_ESI + 0x29c) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x29c) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x2a0) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x2a4) = 0;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(unaff_ESI + 0x29c));

}
