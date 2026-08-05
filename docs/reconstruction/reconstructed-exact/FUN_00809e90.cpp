// =============================================================================
// FUN_00809e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00809e90
// Address:   0x00809e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00809e90 @ 0x00809e90
// Stable ID: aa_00809e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00530610, FUN_00809e90, FUN_008a05a0.
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

void FUN_00809e90(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  int unaff_ESI;

  

  if (*(char *)(in_EAX + 0xc) != '\0') {

    FUN_00530610(*(uint32_t /* width from decompiler */ *)(in_EAX + 4),*(uint32_t /* width from decompiler */ *)(in_EAX + 8),1);

    if ((*(int *)(unaff_ESI + 0x10b0) != 0) &&

       (cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x10b0) + 0x3d8))(), cVar2 != '\0')) {

      FUN_008a05a0();

    }

    piVar1 = *(int **)(unaff_ESI + 0x1030);

    cVar2 = (**(code **)(*piVar1 + 0xd0))();

    if ((cVar2 != '\0') && (cVar2 = (**(code **)(*piVar1 + 0x3d8))(), cVar2 != '\0')) {

                    /* WARNING: Could not recover jumptable at 0x00809efd. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(unaff_ESI + 0x1030) + 0x448))();

      return;

    }

  }

  return;

}
