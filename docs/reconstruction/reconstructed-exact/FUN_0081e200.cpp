// =============================================================================
// FUN_0081e200
// -----------------------------------------------------------------------------
// Stable ID: aa_0081e200
// Address:   0x0081e200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0081e200 @ 0x0081e200
// Stable ID: aa_0081e200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: CONCAT22×2, FUN_0081e200.
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

void FUN_0081e200(void)



{

  uint16_t uVar1;

  int iVar2;

  int *piVar3;

  int unaff_EDI;

  

  uVar1 = (uint16_t)((uint)DAT_00d1b95c >> 0x10);

  if (*(char *)(unaff_EDI + 0x1084) == '\0') {

    (**(code **)(**(int **)(unaff_EDI + 0x1088 + *(int *)(unaff_EDI + 0x1080) * 4) + 0x444))

              (CONCAT22(uVar1,*(uint16_t *)(DAT_00d1b95c + 0x77c)));

  }

  else {

    (**(code **)(**(int **)(unaff_EDI + 0x1088 + *(int *)(unaff_EDI + 0x1080) * 4) + 0x448))

              (CONCAT22(uVar1,*(uint16_t *)(DAT_00d1b95c + 0x77c)));

  }

  if ((*(short *)(*(int *)(unaff_EDI + 0x1088 + *(int *)(unaff_EDI + 0x1080) * 4) + 0x818) != 0) &&

     (iVar2 = *(int *)(unaff_EDI + 0x1088 + *(int *)(unaff_EDI + 0x1080) * 4),

     *(short *)(iVar2 + 0x818) == *(short *)(iVar2 + 0x81a))) {

    if (*(char *)(unaff_EDI + 0x1084) == '\0') {

      (**(code **)(**(int **)(unaff_EDI + 0x1088 + *(int *)(unaff_EDI + 0x1080) * 4) + 0x448))(0);

    }

    else {

      (**(code **)(**(int **)(unaff_EDI + 0x1088 + *(int *)(unaff_EDI + 0x1080) * 4) + 0x444))();

    }

  }

  iVar2 = 0;

  piVar3 = (int *)(unaff_EDI + 0x1088);

  do {

    if ((*piVar3 != 0) && (iVar2 != *(int *)(unaff_EDI + 0x1080))) {

      if (*(short *)(*piVar3 + 0x818) == *(short *)(DAT_00d1b95c + 0x77c)) {

        (**(code **)(*(int *)*piVar3 + 0x444))(0);

      }

      if (*(short *)(*piVar3 + 0x81a) == *(short *)(DAT_00d1b95c + 0x77c)) {

        (**(code **)(*(int *)*piVar3 + 0x448))(0);

      }

    }

    iVar2 = iVar2 + 1;

    piVar3 = piVar3 + 1;

  } while (iVar2 < 0x13);

  return;

}
