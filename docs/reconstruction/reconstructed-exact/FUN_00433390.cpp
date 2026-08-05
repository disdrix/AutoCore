// =============================================================================
// FUN_00433390
// -----------------------------------------------------------------------------
// Stable ID: aa_00433390
// Address:   0x00433390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00433390 @ 0x00433390
// Stable ID: aa_00433390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×2, while×2.
//  - Notable callees: FUN_00433390, free, malloc.
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

uint32_t /* width from decompiler */ FUN_00433390(void)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  uint8_t *puVar4;

  void *pvVar5;

  int unaff_ESI;

  uint8_t *puVar6;

  int local_8;

  

  if (*(int *)(unaff_ESI + 0x1b0) == 0) {

    return 0;

  }

  pvVar1 = malloc(*(int *)(unaff_ESI + 0xc) * *(int *)(unaff_ESI + 0x10));

  if (pvVar1 != (void *)0x0) {

    iVar3 = *(int *)(unaff_ESI + 0xc) + -1;

    puVar4 = (uint8_t *)(*(int *)(unaff_ESI + 0x1b0) + iVar3);

    local_8 = 0;

    pvVar5 = pvVar1;

    if (0 < *(int *)(unaff_ESI + 0x10)) {

      do {

        iVar2 = 0;

        puVar6 = puVar4;

        if (-1 < iVar3) {

          do {

            *(uint8_t *)(iVar2 + (int)pvVar5) = *puVar6;

            iVar2 = iVar2 + 1;

            puVar6 = puVar6 + -1;

          } while (iVar2 <= iVar3);

        }

        puVar4 = puVar4 + *(int *)(unaff_ESI + 0xc);

        local_8 = local_8 + 1;

        pvVar5 = (void *)((int)pvVar5 + *(int *)(unaff_ESI + 0xc));

      } while (local_8 < *(int *)(unaff_ESI + 0x10));

    }

    free(*(void **)(unaff_ESI + 0x1b0));

    *(void **)(unaff_ESI + 0x1b0) = pvVar1;

    return 1;

  }

  return 0;

}
