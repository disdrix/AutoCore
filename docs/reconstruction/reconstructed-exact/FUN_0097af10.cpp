// =============================================================================
// FUN_0097af10
// -----------------------------------------------------------------------------
// Stable ID: aa_0097af10
// Address:   0x0097af10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0097af10 @ 0x0097af10
// Stable ID: aa_0097af10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0097af10.
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

void FUN_0097af10(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int *piVar3;

  int unaff_EDI;

  

  piVar3 = (int *)**(int **)(unaff_EDI + 0x548);

  if (piVar3 != *(int **)(unaff_EDI + 0x548)) {

    do {

      if ((void *)piVar3[2] != (void *)0x0) {

        operator_delete__((void *)piVar3[2]);

      }

      piVar3[2] = 0;

      piVar3 = (int *)*piVar3;

    } while (piVar3 != (int *)*(int *)(unaff_EDI + 0x548));

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x548);

  pvVar2 = (void *)*puVar1;

  *puVar1 = puVar1;

  *(int *)(*(int *)(unaff_EDI + 0x548) + 4) = *(int *)(unaff_EDI + 0x548);

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x54c) = 0;

  if (pvVar2 == *(void **)(unaff_EDI + 0x548)) {

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar2);

}
