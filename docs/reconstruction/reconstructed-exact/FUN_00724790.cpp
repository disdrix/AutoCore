// =============================================================================
// FUN_00724790
// -----------------------------------------------------------------------------
// Stable ID: aa_00724790
// Address:   0x00724790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00724790 @ 0x00724790
// Stable ID: aa_00724790
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×2, do×1.
//  - Notable callees: FUN_0071f010, FUN_00723dc0, FUN_007243a0, FUN_00724790.
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

void FUN_00724790(void)



{

  void *pvVar1;

  int unaff_EBX;

  int iVar2;

  int *piVar3;

  

  FUN_00723dc0(unaff_EBX);

  FUN_007243a0();

  *(uint8_t *)(unaff_EBX + 0x2f5) = 0;

  piVar3 = (int *)(unaff_EBX + 0x70);

  iVar2 = 100;

  while( true ) {

    pvVar1 = *(void **)(*piVar3 + 0x104);

    if (pvVar1 != (void *)0x0) {

      FUN_0071f010();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(*piVar3 + 0x104) = 0;

    if ((void *)*piVar3 != (void *)0x0) break;

    *piVar3 = 0;

    pvVar1 = operator_new(0x114);

    *piVar3 = (int)pvVar1;

    piVar3 = piVar3 + 1;

    iVar2 = iVar2 + -1;

    if (iVar2 == 0) {

      piVar3 = (int *)(unaff_EBX + 0x31c);

      iVar2 = 0x30;

      do {

        if ((uint32_t /* width from decompiler */ *)*piVar3 != (uint32_t /* width from decompiler */ *)0x0) {

          (*(code *)**(uint32_t /* width from decompiler */ **)*piVar3)(1);

        }

        *piVar3 = 0;

        piVar3 = piVar3 + 1;

        iVar2 = iVar2 + -1;

      } while (iVar2 != 0);

      return;

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)*piVar3);

}
