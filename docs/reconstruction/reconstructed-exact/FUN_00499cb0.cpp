// =============================================================================
// FUN_00499cb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00499cb0
// Address:   0x00499cb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00499cb0 @ 0x00499cb0
// Stable ID: aa_00499cb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, do×1, while×1.
//  - Notable callees: FUN_00498dd0, FUN_00499cb0, FUN_0049ba70.
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

void __thiscall FUN_00499cb0(int param_1,float param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  float fVar5;

  float local_54 [5];

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  float fStack_34;

  uint8_t local_30 [48];

  

  if (*(int **)(param_1 + 0x194) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x194) + 0x40))(param_1 + 0x38);

    (**(code **)(**(int **)(param_1 + 0x194) + 0x38))(param_1 + 0x2c);

  }

  if (*(int *)(param_1 + 0x198) != 0) {

    local_54[0] = g_flOne;

    local_54[1] = 0.0;

    local_54[2] = 0.0;

    local_54[3] = 0.0;

    local_54[4] = g_flOne;

    local_40 = 0;

    local_3c = 0;

    local_38 = 0;

    fStack_34 = g_flOne;

    FUN_0049ba70(local_54,param_1 + 0x2c);

    FUN_00498dd0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c4),local_30,0);

  }

  piVar4 = *(int **)(param_1 + 0x1d0);

  if (piVar4 != *(int **)(param_1 + 0x1d4)) {

    do {

      iVar1 = *piVar4;

      if (iVar1 != 0) {

        fVar5 = *(float *)(iVar1 + 0x78) - param_2;

        *(float *)(iVar1 + 0x78) = fVar5;

        if ((0.0 < fVar5) || (*(int **)(iVar1 + 0x70) == (int *)0x0)) {

          iVar3 = *(int *)(iVar1 + 0x80);

          *(int *)(iVar1 + 0x80) = iVar3 + 1;

          if ((iVar3 == 5) && (*(int **)(iVar1 + 0x70) != (int *)0x0)) {

            (**(code **)(**(int **)(iVar1 + 0x70) + 0x70))(0x10,1);

          }

        }

        else {

          (**(code **)(**(int **)(iVar1 + 0x70) + 0x70))(0x10,0);

          piVar2 = *(int **)(param_1 + 0x198);

          if (piVar2 != (int *)0x0) {

            if ((*piVar2 != 0) && (piVar2[1] != 0)) {

              (**(code **)(*(int *)piVar2[1] + 0x1c))(*piVar2);

            }

                    /* WARNING: Subroutine does not return */

            operator_delete(piVar2);

          }

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x198) = 0;

        }

      }

      piVar4 = piVar4 + 1;

    } while (piVar4 != *(int **)(param_1 + 0x1d4));

  }

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 8) != (uint32_t /* width from decompiler */ *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = **(uint32_t /* width from decompiler */ **)(param_1 + 8);

  }

  return;

}
