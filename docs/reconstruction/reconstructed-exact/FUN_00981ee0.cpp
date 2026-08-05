// =============================================================================
// FUN_00981ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00981ee0
// Address:   0x00981ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00981ee0 @ 0x00981ee0
// Stable ID: aa_00981ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00981ee0.
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

uint32_t /* width from decompiler */ FUN_00981ee0(void)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int in_EAX;

  int *unaff_EDI;

  

  if (*(int **)(in_EAX + 4) != (int *)0x0) {

    piVar2 = (int *)**(int **)(in_EAX + 4);

    if ((piVar2 != (int *)0x0) && (piVar2[1] = piVar2[1] + 1, piVar2[1] == 1)) {

      (**(code **)(*piVar2 + 4))();

    }

    piVar3 = (int *)*unaff_EDI;

    if (piVar3 != (int *)0x0) {

      piVar1 = piVar3 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar3 + 8))();

      }

    }

    *unaff_EDI = (int)piVar2;

    return 0;

  }

  piVar2 = (int *)*unaff_EDI;

  if (piVar2 != (int *)0x0) {

    piVar3 = piVar2 + 1;

    *piVar3 = *piVar3 + -1;

    if (*piVar3 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *unaff_EDI = 0;

  return 0xffffffff;

}
