// =============================================================================
// FUN_00748b90
// -----------------------------------------------------------------------------
// Stable ID: aa_00748b90
// Address:   0x00748b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00748b90 @ 0x00748b90
// Stable ID: aa_00748b90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×14, return×2.
//  - Notable callees: FUN_00748b90.
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

uint32_t /* width from decompiler */ FUN_00748b90(int param_1,int *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ local_8;

  int local_4;

  

  iVar3 = *(int *)(param_1 + 0xc);

  local_8 = 0;

  if (iVar3 == 0) {

    *param_2 = 0;

  }

  else {

    piVar2 = *(int **)(iVar3 + 0x10);

    if (piVar2 == (int *)0x0) {

      local_4 = 0;

    }

    else {

      piVar1 = (int *)*piVar2;

      if (piVar1 == (int *)0x0) {

        local_4 = 0;

      }

      else {

        iVar3 = (**(code **)(*piVar1 + 0x2c))

                          (piVar1,piVar2[2] * *(int *)(iVar3 + 0x14),

                           piVar2[2] * *(int *)(iVar3 + 0x18),&local_4,0x800);

        if (iVar3 < 0) {

          local_4 = 0;

        }

        else {

          piVar2[4] = piVar2[4] + 1;

        }

      }

    }

    *param_2 = local_4;

    if (local_4 == 0) {

      local_8 = 0xffffffff;

    }

    else {

      *(uint8_t *)(param_1 + 0x19) = 1;

    }

  }

  iVar3 = *(int *)(param_1 + 0x14);

  if (iVar3 == 0) {

    *param_3 = 0;

  }

  else {

    piVar2 = *(int **)(iVar3 + 0x10);

    if (piVar2 == (int *)0x0) {

      piVar2 = (int *)0x0;

    }

    else {

      piVar1 = (int *)*piVar2;

      if (piVar1 == (int *)0x0) {

        piVar2 = (int *)0x0;

      }

      else {

        iVar3 = (**(code **)(*piVar1 + 0x2c))

                          (piVar1,piVar2[2] * *(int *)(iVar3 + 0x14),

                           piVar2[2] * *(int *)(iVar3 + 0x18),&param_2,0x800);

        if (iVar3 < 0) {

          piVar2 = (int *)0x0;

        }

        else {

          piVar2[4] = piVar2[4] + 1;

          piVar2 = param_2;

        }

      }

    }

    *param_3 = piVar2;

    if (piVar2 == (int *)0x0) {

      local_8 = 0xffffffff;

    }

    else {

      *(uint8_t *)(param_1 + 0x1a) = 1;

    }

  }

  iVar3 = *(int *)(param_1 + 4);

  piVar2 = *(int **)(iVar3 + 0x10);

  if (piVar2 == (int *)0x0) {

    param_2 = (int *)0x0;

  }

  else {

    piVar1 = (int *)*piVar2;

    if (piVar1 == (int *)0x0) {

      param_2 = (int *)0x0;

    }

    else {

      iVar3 = (**(code **)(*piVar1 + 0x2c))

                        (piVar1,piVar2[4] * *(int *)(iVar3 + 0x18),

                         piVar2[4] * *(int *)(iVar3 + 0x1c),&param_2,0x800);

      if (iVar3 < 0) {

        param_2 = (int *)0x0;

      }

      else {

        piVar2[3] = piVar2[3] + 1;

      }

    }

  }

  *param_4 = param_2;

  if (param_2 == (int *)0x0) {

    return 0xffffffff;

  }

  *(uint8_t *)(param_1 + 0x18) = 1;

  return local_8;

}
