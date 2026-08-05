// =============================================================================
// FUN_00817420
// -----------------------------------------------------------------------------
// Stable ID: aa_00817420
// Address:   0x00817420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00817420 @ 0x00817420
// Stable ID: aa_00817420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, goto×3, while×2, do×1.
//  - Notable callees: FUN_00817420.
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

void FUN_00817420(void)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uVar6;

  int unaff_ESI;

  

  if (1 < *(uint *)(unaff_ESI + 0x718)) {

    piVar1 = *(int **)(unaff_ESI + 0x714);

    piVar5 = (int *)*piVar1;

    piVar3 = piVar5;

    if (piVar5 != piVar1) {

      do {

        piVar4 = (int *)*piVar3;

        if (*(int *)(piVar3[2] + 4) == *(int *)(unaff_ESI + 0x70c)) {

          if (piVar4 == piVar1) {

            piVar4 = piVar5;

          }

          iVar2 = *(int *)(piVar4[2] + 4);

          *(int *)(unaff_ESI + 0x70c) = iVar2;

          if (*(int **)(unaff_ESI + 0x708) == (int *)0x0) {

            return;

          }

          piVar5 = (int *)*piVar1;

          if (piVar5 != piVar1) goto LAB_00817476;

          goto LAB_00817488;

        }

        piVar3 = piVar4;

      } while (piVar4 != *(int **)(unaff_ESI + 0x714));

    }

  }

  return;

  while (piVar5 = (int *)*piVar5, piVar5 != *(int **)(unaff_ESI + 0x714)) {

LAB_00817476:

    if (*(int *)(piVar5[2] + 4) == iVar2) {

      uVar6 = *(uint32_t /* width from decompiler */ *)piVar5[2];

      goto LAB_0081748a;

    }

  }

LAB_00817488:

  uVar6 = 0;

LAB_0081748a:

  (**(code **)(**(int **)(unaff_ESI + 0x708) + 0x1d8))(uVar6,1,1);

                    /* WARNING: Could not recover jumptable at 0x008174a1. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(**(int **)(unaff_ESI + 0x708) + 0x34c))();

  return;

}
