// =============================================================================
// FUN_00882da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00882da0
// Address:   0x00882da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00882da0 @ 0x00882da0
// Stable ID: aa_00882da0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×8, goto×3, return×3, switch×1.
//  - Notable callees: ABS, FUN_00882da0.
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

void __fastcall FUN_00882da0(float param_1)



{

  char cVar1;

  int iVar2;

  int unaff_ESI;

  int unaff_EDI;

  float fVar3;

  

  if (*(int *)(unaff_ESI + 0x538) == 0) goto LAB_00882e8f;

  if (unaff_EDI == 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x538) + 4))();

    goto LAB_00882e8f;

  }

  cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x538) + 0xd0))();

  (**(code **)(**(int **)(unaff_ESI + 0x538) + 4))(1);

  fVar3 = 0.0;

  param_1 = 0.0;

  switch(unaff_EDI) {

  case 1:

    break;

  case 2:

    fVar3 = DAT_00aaa920;

    break;

  case 3:

    fVar3 = DAT_00aaa914;

    break;

  case 4:

    fVar3 = DAT_00aaa924;

    break;

  case 5:

    fVar3 = DAT_00aaa928;

    break;

  case 6:

    fVar3 = DAT_00aaa90c;

    break;

  case 7:

    fVar3 = DAT_00aaa910;

    break;

  case 8:

    fVar3 = DAT_00aaa918;

    break;

  case 9:

    fVar3 = DAT_00aaa91c;

    break;

  default:

    goto switchD_00882dec_default;

  }

  param_1 = fVar3;

switchD_00882dec_default:

  if (DAT_00aaa664 < ABS(*(float *)(*(int *)(unaff_ESI + 0x538) + 0x48c) - param_1)) {

    *(float *)(*(int *)(unaff_ESI + 0x538) + 0x48c) = param_1;

    if (cVar1 == '\0') {

      *(float *)(*(int *)(unaff_ESI + 0x538) + 0x494) = param_1;

    }

    (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x34c))();

  }

LAB_00882e8f:

  if (*(int *)(unaff_ESI + 0x53c) != 0) {

    if (unaff_EDI == 0) {

      iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x53c) + 0x164))();

      if (*(char *)(iVar2 + 3) != -1) {

        iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x53c) + 0x164))();

        *(uint8_t *)(iVar2 + 3) = 0xff;

                    /* WARNING: Could not recover jumptable at 0x00882ed1. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        (**(code **)(**(int **)(unaff_ESI + 0x53c) + 0x34c))(param_1);

        return;

      }

    }

    else {

      iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x53c) + 0x164))(0);

      if (*(char *)(iVar2 + 3) != '\0') {

        iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x53c) + 0x164))(0);

        *(uint8_t *)(iVar2 + 3) = 0;

                    /* WARNING: Could not recover jumptable at 0x00882f05. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        (**(code **)(**(int **)(unaff_ESI + 0x53c) + 0x34c))();

        return;

      }

    }

  }

  return;

}
