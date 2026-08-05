// =============================================================================
// FUN_0081e330
// -----------------------------------------------------------------------------
// Stable ID: aa_0081e330
// Address:   0x0081e330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0081e330 @ 0x0081e330
// Stable ID: aa_0081e330
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×10, do×1, while×1, return×1.
//  - Notable callees: FUN_00816860×2, FUN_00816940×2, FUN_00816a20, FUN_00816a50, FUN_0081e330.
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

void FUN_0081e330(void)



{

  uint16_t uVar1;

  int iVar2;

  int *piVar3;

  char cVar4;

  int *piVar5;

  int unaff_EDI;

  int iStack_4;

  

  uVar1 = *(uint16_t *)(DAT_00d1b95c + 0x77c);

  piVar5 = *(int **)(unaff_EDI + 0xea0 + *(int *)(unaff_EDI + 0x10d4) * 4);

  if (*(char *)(unaff_EDI + 0x10d8) == '\0') {

    *(uint16_t *)((int)piVar5 + 0x81a) = *(uint16_t *)(DAT_00d1b95c + 0x77e);

    *(uint16_t *)(piVar5 + 0x206) = uVar1;

    cVar4 = (**(code **)(*piVar5 + 0x3d8))();

    if (cVar4 != '\0') {

      FUN_00816940();

    }

  }

  else {

    *(uint16_t *)((int)piVar5 + 0x81e) = *(uint16_t *)(DAT_00d1b95c + 0x77e);

    *(uint16_t *)(piVar5 + 0x207) = uVar1;

    cVar4 = (**(code **)(*piVar5 + 0x3d8))();

    if (cVar4 != '\0') {

      FUN_00816860();

    }

  }

  if (((*(short *)(*(int *)(unaff_EDI + 0xea0 + *(int *)(unaff_EDI + 0x10d4) * 4) + 0x818) != 0) &&

      (iVar2 = *(int *)(unaff_EDI + 0xea0 + *(int *)(unaff_EDI + 0x10d4) * 4),

      *(short *)(iVar2 + 0x818) == *(short *)(iVar2 + 0x81c))) &&

     (iVar2 = *(int *)(unaff_EDI + 0xea0 + *(int *)(unaff_EDI + 0x10d4) * 4),

     *(short *)(iVar2 + 0x81a) == *(short *)(iVar2 + 0x81e))) {

    if (*(char *)(unaff_EDI + 0x10d8) == '\0') {

      FUN_00816a20();

    }

    else {

      FUN_00816a50();

    }

  }

  iStack_4 = 0;

  piVar5 = (int *)(unaff_EDI + 0xea0);

  do {

    piVar3 = (int *)*piVar5;

    if ((piVar3 != (int *)0x0) && (iStack_4 != *(int *)(unaff_EDI + 0x10d4))) {

      if (((short)piVar3[0x206] == *(short *)(DAT_00d1b95c + 0x77c)) &&

         (*(short *)((int)piVar3 + 0x81a) == *(short *)(DAT_00d1b95c + 0x77e))) {

        *(uint16_t *)(piVar3 + 0x206) = 0;

        *(uint16_t *)((int)piVar3 + 0x81a) = 0;

        cVar4 = (**(code **)(*piVar3 + 0x3d8))();

        if (cVar4 != '\0') {

          FUN_00816940();

        }

      }

      piVar3 = (int *)*piVar5;

      if (((short)piVar3[0x207] == *(short *)(DAT_00d1b95c + 0x77c)) &&

         (*(short *)((int)piVar3 + 0x81e) == *(short *)(DAT_00d1b95c + 0x77e))) {

        *(uint16_t *)(piVar3 + 0x207) = 0;

        *(uint16_t *)((int)piVar3 + 0x81e) = 0;

        cVar4 = (**(code **)(*piVar3 + 0x3d8))();

        if (cVar4 != '\0') {

          FUN_00816860();

        }

      }

    }

    iStack_4 = iStack_4 + 1;

    piVar5 = piVar5 + 1;

  } while (iStack_4 < 0x78);

  return;

}
