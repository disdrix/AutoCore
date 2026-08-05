// =============================================================================
// FUN_0074f4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074f4d0
// Address:   0x0074f4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074f4d0 @ 0x0074f4d0
// Stable ID: aa_0074f4d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: do×2, if×2, return×2, while×2.
//  - Notable callees: _aligned_free×2, FUN_00445a90, FUN_0074f4d0.
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

void FUN_0074f4d0(void)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_EDI;

  int local_4;

  

  _aligned_free(*(void **)(unaff_EDI + 0x10));

  _aligned_free(*(void **)(unaff_EDI + 0x1c));

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x1c) = 0;

  FUN_00445a90();

  puVar3 = (uint32_t /* width from decompiler */ *)(unaff_EDI + 0x40);

  local_4 = 5;

  do {

    iVar2 = 5;

    do {

      if ((void *)*puVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)*puVar3);

      }

      *puVar3 = 0;

      puVar3[1] = 0;

      puVar3[2] = 0;

      puVar3 = puVar3 + 4;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

    local_4 = local_4 + -1;

  } while (local_4 != 0);

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x20) = 0;

  *(uint16_t *)(unaff_EDI + 0x24) = 0xffff;

  *(uint16_t *)(unaff_EDI + 0x26) = 0xffff;

  piVar1 = *(int **)(unaff_EDI + 0xc);

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc) = 0;

  return;

}
