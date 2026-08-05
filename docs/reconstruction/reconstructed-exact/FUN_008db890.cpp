// =============================================================================
// FUN_008db890
// -----------------------------------------------------------------------------
// Stable ID: aa_008db890
// Address:   0x008db890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008db890 @ 0x008db890
// Stable ID: aa_008db890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~125 non-empty decompiler lines.
//  - Control keywords: if×34, goto×3, return×3, do×1, while×1.
//  - Notable callees: FUN_008db890.
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

void FUN_008db890(void)



{

  int *piVar1;

  int *piVar2;

  int unaff_ESI;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  if (*(char *)(unaff_ESI + 0x518) != '\0') {

    if (*(int *)(unaff_ESI + 0x58c) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x58c) + 4))(0);

    }

    if (*(int *)(unaff_ESI + 0x588) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x588) + 4))(0);

    }

    if (*(int *)(unaff_ESI + 0x594) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x594) + 4))(0);

    }

    if (*(int *)(unaff_ESI + 0x590) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x590) + 4))(0);

    }

    goto LAB_008db8f5;

  }

  piVar1 = *(int **)(unaff_ESI + 0x54c);

  piVar2 = (int *)*piVar1;

  piVar3 = piVar2;

  if (piVar2 != piVar1) {

    do {

      if (piVar3[2] == *(int *)(unaff_ESI + 0x52c)) break;

      piVar3 = (int *)*piVar3;

    } while (piVar3 != piVar1);

  }

  if (piVar3 == piVar2) {

    if (*(int *)(unaff_ESI + 0x58c) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x58c) + 4))(0);

    }

    if (*(int *)(unaff_ESI + 0x588) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x588) + 4))(0);

    }

    if (*(int *)(unaff_ESI + 0x560) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x560) + 4))(0);

    }

    if (*(int *)(unaff_ESI + 0x55c) != 0) {

      uVar4 = 0;

LAB_008dba0e:

      (**(code **)(**(int **)(unaff_ESI + 0x55c) + 4))(uVar4);

    }

  }

  else {

    if (*(int *)(unaff_ESI + 0x58c) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x58c) + 4))(1);

    }

    if (*(int *)(unaff_ESI + 0x588) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x588) + 4))(1);

    }

    if (*(int *)(unaff_ESI + 0x560) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x560) + 4))(1);

    }

    if (*(int *)(unaff_ESI + 0x55c) != 0) {

      uVar4 = 1;

      goto LAB_008dba0e;

    }

  }

  if (((piVar3 == *(int **)(unaff_ESI + 0x54c)) || ((int *)*piVar3 == *(int **)(unaff_ESI + 0x54c)))

     && (*(int *)(unaff_ESI + 0x544) == 0)) {

    if (*(int *)(unaff_ESI + 0x594) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x594) + 4))(0);

    }

    if (*(int *)(unaff_ESI + 0x590) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x590) + 4))(0);

    }

    if (*(int *)(unaff_ESI + 0x568) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x568) + 4))(0);

    }

    if (*(int *)(unaff_ESI + 0x564) != 0) {

      uVar4 = 0;

LAB_008dbacc:

      (**(code **)(**(int **)(unaff_ESI + 0x564) + 4))(uVar4);

    }

  }

  else {

    if (*(int *)(unaff_ESI + 0x594) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x594) + 4))(1);

    }

    if (*(int *)(unaff_ESI + 0x590) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x590) + 4))(1);

    }

    if (*(int *)(unaff_ESI + 0x568) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x568) + 4))(1);

    }

    if (*(int *)(unaff_ESI + 0x564) != 0) {

      uVar4 = 1;

      goto LAB_008dbacc;

    }

  }

  if (*(int *)(unaff_ESI + 0x52c) == 0) {

    if (*(int *)(unaff_ESI + 0x58c) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x58c) + 4))(0);

    }

    if (*(int *)(unaff_ESI + 0x588) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x588) + 4))(0);

    }

    if (*(int *)(unaff_ESI + 0x594) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x594) + 4))(0);

    }

    if (*(int *)(unaff_ESI + 0x590) == 0) {

      return;

    }

    (**(code **)(**(int **)(unaff_ESI + 0x590) + 4))(0);

    return;

  }

LAB_008db8f5:

  if (*(int *)(unaff_ESI + 0x560) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x560) + 4))(0);

  }

  if (*(int *)(unaff_ESI + 0x55c) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x55c) + 4))(0);

  }

  if (*(int *)(unaff_ESI + 0x568) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x568) + 4))(0);

  }

  if (*(int *)(unaff_ESI + 0x564) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x564) + 4))(0);

  }

  return;

}
