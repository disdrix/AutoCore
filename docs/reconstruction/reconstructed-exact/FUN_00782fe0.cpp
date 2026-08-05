// =============================================================================
// FUN_00782fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00782fe0
// Address:   0x00782fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00782fe0 @ 0x00782fe0
// Stable ID: aa_00782fe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×10, while×5, goto×4, do×3, return×1.
//  - Notable callees: FUN_00782de0×2, FUN_00782f60×2, FUN_007829b0, FUN_00782d00, FUN_00782e60, FUN_00782fe0.
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

void FUN_00782fe0(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int *piVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  int local_2c;

  uint32_t /* width from decompiler */ local_28 [10];

  

  piVar3 = operator_new(8);

  if (piVar3 == (int *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    *piVar3 = 0;

    piVar3[1] = 0;

  }

  local_28[0] = 7;

  local_28[1] = 6;

  local_28[2] = 9;

  local_28[3] = 3;

  local_28[4] = 8;

  local_28[5] = 2;

  local_28[6] = 10;

  local_28[7] = 1;

  local_28[8] = 5;

  local_28[9] = 4;

  local_2c = 0;

  do {

    puVar4 = operator_new(0x1c);

    if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar4 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      *puVar4 = &PTR_FUN_00a9b608;

      puVar4[1] = 0;

      puVar4[2] = 0;

      puVar4[3] = 0;

      puVar4[4] = 0;

      puVar4[5] = 0;

      *(uint8_t *)(puVar4 + 6) = 1;

    }

    puVar4[5] = local_28[local_2c];

    *(uint8_t *)(puVar4 + 6) = 1;

    piVar7 = (int *)piVar3[1];

    do {

      while( true ) {

        piVar2 = piVar7;

        if (piVar2 == (int *)0x0) goto LAB_007830d3;

        iVar5 = (**(code **)(*piVar2 + 4))(puVar4[5]);

        if (iVar5 < 1) break;

        piVar7 = (int *)piVar2[3];

        if ((int *)piVar2[3] == (int *)0x0) {

          piVar2[3] = (int)puVar4;

          goto LAB_007830d3;

        }

      }

      if (-1 < iVar5) {

        (**(code **)*puVar4)(1);

        goto LAB_0078310f;

      }

      piVar7 = (int *)piVar2[2];

    } while ((int *)piVar2[2] != (int *)0x0);

    piVar2[2] = (int)puVar4;

LAB_007830d3:

    puVar4[4] = piVar2;

    if (piVar2 == (int *)0x0) {

      piVar3[1] = (int)puVar4;

    }

    *piVar3 = *piVar3 + 1;

    puVar4[1] = piVar3;

    FUN_00782de0();

    local_2c = local_2c + 1;

  } while (local_2c < 10);

LAB_0078310f:

  FUN_00782f60();

  iVar5 = FUN_00782e60(piVar3[1]);

  piVar3[1] = iVar5;

  FUN_00782f60();

  iVar5 = 0;

  do {

    piVar7 = (int *)piVar3[1];

    uVar1 = local_28[iVar5];

    while (piVar7 != (int *)0x0) {

      iVar6 = (**(code **)(*piVar7 + 4))(uVar1);

      if (iVar6 < 1) {

        if (-1 < iVar6) goto LAB_0078315c;

        piVar7 = (int *)piVar7[2];

      }

      else {

        piVar7 = (int *)piVar7[3];

      }

    }

    piVar7 = (int *)0x0;

LAB_0078315c:

    (**(code **)(*piVar7 + 4))(uVar1);

    FUN_00782de0();

    iVar5 = iVar5 + 1;

    if (9 < iVar5) {

      FUN_00782d00();

      FUN_007829b0();

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar3);

    }

  } while( true );

}
