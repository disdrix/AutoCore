// =============================================================================
// FUN_00906c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00906c60
// Address:   0x00906c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00906c60 @ 0x00906c60
// Stable ID: aa_00906c60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: return×24, if×5, switch×4, goto×2, do×1, while×1.
//  - Notable callees: FUN_00906ba0, FUN_00906bc0, FUN_00906be0, FUN_00906c60.
//  - Return sites: 24.

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

uint32_t /* width from decompiler */ FUN_00906c60(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int *piVar4;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x7dc) != 0) {

    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x7dc) + 0x464))();

    iVar3 = 0;

    piVar4 = (int *)(unaff_ESI + 0x720);

    do {

      if (iVar1 == *piVar4) {

        switch(iVar3) {

        case 0:

          goto switchD_00906c9e_caseD_0;

        default:

          return 0xff;

        case 3:

          if (*(int *)(unaff_ESI + 0x7e4) != 0) {

            (**(code **)(**(int **)(unaff_ESI + 0x7e4) + 0x464))();

            uVar2 = FUN_00906be0();

            switch(uVar2) {

            case 0:

              return 7;

            case 1:

              return 8;

            case 2:

              return 9;

            case 3:

switchD_00906d48_caseD_2:

              return 10;

            case 4:

              return 0xb;

            case 5:

              return 0x10;

            case 6:

              return 0x14;

            default:

              return 0xff;

            }

          }

          return 0xff;

        case 4:

          if (*(int *)(unaff_ESI + 0x7e8) != 0) {

            (**(code **)(**(int **)(unaff_ESI + 0x7e8) + 0x464))();

            uVar2 = FUN_00906ba0();

            switch(uVar2) {

            case 0:

              return 0xc;

            case 1:

              return 0x1c;

            case 2:

              goto switchD_00906d48_caseD_2;

            case 3:

              return 0x46;

            case 4:

              return 0x44;

            case 5:

              return 0xe;

            default:

              return 0xff;

            }

          }

          return 0xff;

        }

      }

      iVar3 = iVar3 + 1;

      piVar4 = piVar4 + 1;

    } while (iVar3 < 10);

  }

  return 0xff;

switchD_00906c9e_caseD_0:

  if (*(int *)(unaff_ESI + 0x7e0) == 0) {

    return 0xff;

  }

  (**(code **)(**(int **)(unaff_ESI + 0x7e0) + 0x464))();

  uVar2 = FUN_00906bc0();

  switch(uVar2) {

  case 0:

    return 1;

  case 1:

    return 0;

  case 2:

    return 2;

  case 3:

    return 3;

  default:

    return 0xff;

  }

}
