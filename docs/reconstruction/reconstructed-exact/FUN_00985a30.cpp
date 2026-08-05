// =============================================================================
// FUN_00985a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00985a30
// Address:   0x00985a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00985a30 @ 0x00985a30
// Stable ID: aa_00985a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, do×1, while×1.
//  - Notable callees: FUN_00743c50×2, FUN_00462390, FUN_004624b0, FUN_00462570, FUN_00985390, FUN_00985a30.
//  - Return sites: 5.

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

void FUN_00985a30(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  int *piVar3;

  int local_4;

  

  if (*(int *)(in_EAX + 0x14) != 2) {

    piVar3 = *(int **)(in_EAX + 0x10);

    if (piVar3 != (int *)0x0) {

      FUN_00743c50();

      piVar3[1] = 0;

      piVar3[2] = -1;

      *piVar3 = (int)DAT_00d219d4;

      DAT_00d219d4 = piVar3;

    }

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = 0;

    return;

  }

  local_4 = *(int *)(*(int *)(in_EAX + 0x10) + 8);

  local_4 = FUN_00462390();

  piVar3 = *(int **)(local_4 + 4);

  if (piVar3 != *(int **)(local_4 + 8)) {

    do {

      if (*piVar3 == *(int *)(in_EAX + 0x10)) {

        cVar2 = FUN_00985390();

        if (cVar2 == '\0') {

          return;

        }

        piVar1 = (int *)*piVar3;

        if (piVar1 != (int *)0x0) {

          FUN_00743c50();

          piVar1[1] = 0;

          piVar1[2] = -1;

          *piVar1 = (int)DAT_00d219d4;

          DAT_00d219d4 = piVar1;

        }

        *piVar3 = 0;

        FUN_00462570(*(uint32_t /* width from decompiler */ *)(piVar3[2] + 4));

        *(int *)(piVar3[2] + 4) = piVar3[2];

        piVar3[3] = 0;

        *(int *)piVar3[2] = piVar3[2];

        *(int *)(piVar3[2] + 8) = piVar3[2];

        if ((void *)piVar3[5] == (void *)0x0) {

          piVar3[5] = 0;

          piVar3[6] = 0;

          piVar3[7] = 0;

          FUN_004624b0(&local_4,piVar3);

          return;

        }

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)piVar3[5]);

      }

      piVar3 = piVar3 + 8;

    } while (piVar3 != *(int **)(local_4 + 8));

  }

  return;

}
