// =============================================================================
// FUN_008aa610
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa610
// Address:   0x008aa610  (autoassault.exe, image base 0x400000)
// System:    client UI / mission (WQ7R-B dual 2026-08-04)
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008aa610 @ 0x008aa610
// Stable ID: aa_008aa610
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: ifÃ—5, returnÃ—4.
//  - Notable callees: FUN_008aa610.
//  - Return sites: 4.

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

void FUN_008aa610(void)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  int unaff_ESI;

  int iStack_20;

  uint32_t /* width from decompiler */ auStack_10 [4];

  

  if (*(int *)(unaff_ESI + 0x700) == 0) {

    return;

  }

  if ((*(int **)(unaff_ESI + 0x6e0) != (int *)0x0) &&

     (iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x6e0) + 0x1b8))(), iVar2 != 0)) {

    iStack_20 = 1;

    puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_ESI + 0x6e0) + 0x140))(auStack_10);

    auStack_10[0] = *puVar3;

    iVar2 = puVar3[1];

    (**(code **)(**(int **)(unaff_ESI + 0x6e0) + 0x204))(&iStack_20);

    if (iStack_20 <= iVar2) {

      (**(code **)(**(int **)(unaff_ESI + 0x700) + 4))(0);

      return;

    }

    piVar4 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x6e0) + 0x1b8))();

    iVar2 = ((*(int *)(*piVar4 + 0x7c) - iVar2) + -1 + iStack_20) / *(int *)(*piVar4 + 0x7c);

    *(int *)(unaff_ESI + 0x704) = iVar2;

    if (iVar2 < 1) {

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x704) = 1;

    }

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x700) + 0xd0))();

    if (cVar1 == '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x700) + 0xfc))(1,0x3f000000);

    }

    (**(code **)(**(int **)(unaff_ESI + 0x700) + 0x460))

              (g_flOne / (float)*(int *)(unaff_ESI + 0x704));

    iVar2 = **(int **)(unaff_ESI + 0x700);

    iVar5 = (**(code **)(**(int **)(unaff_ESI + 0x6e0) + 0x218))(0);

    (**(code **)(iVar2 + 0x454))((float)iVar5 / (float)*(int *)(unaff_ESI + 0x704));

    return;

  }

  iStack_20 = 0x8aa755;

  (**(code **)(**(int **)(unaff_ESI + 0x700) + 4))();

  return;

}
