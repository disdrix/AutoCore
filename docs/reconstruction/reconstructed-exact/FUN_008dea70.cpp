// =============================================================================
// FUN_008dea70
// -----------------------------------------------------------------------------
// Stable ID: aa_008dea70
// Address:   0x008dea70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008dea70 @ 0x008dea70
// Stable ID: aa_008dea70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×8, for×1, do×1, while×1, return×1.
//  - Notable callees: sprintf×2, FUN_007fbd30, FUN_008dea70.
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

void __fastcall FUN_008dea70(int param_1)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char acStack_40 [2];

  uint32_t /* width from decompiler */ auStack_3e [15];

  

  if (*(int *)(param_1 + 0x528) != 0) {

    (**(code **)(**(int **)(param_1 + 0x528) + 0x458))();

  }

  if (*(int *)(param_1 + 0x52c) != 0) {

    (**(code **)(**(int **)(param_1 + 0x52c) + 0x458))();

  }

  if (*(int *)(param_1 + 0x530) != 0) {

    (**(code **)(**(int **)(param_1 + 0x530) + 0x458))();

  }

  if ((*(int *)(DAT_00d1da2c + 0x28) != 0) &&

     (0 < *(int *)(DAT_00d1da2c + 0x2c) - *(int *)(DAT_00d1da2c + 0x28) >> 2)) {

    acStack_40[0] = '\0';

    acStack_40[1] = '\0';

    puVar4 = auStack_3e;

    for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    *(uint16_t *)puVar4 = 0;

    piVar3 = *(int **)(DAT_00d1da2c + 0x28);

    piVar2 = (int *)(DAT_00d1da2c + 0x2c);

    if (piVar3 != (int *)*piVar2) {

      do {

        if (*(int *)(param_1 + 0x528) != 0) {

          iVar1 = *piVar3;

          (**(code **)(**(int **)(param_1 + 0x528) + 0x444))

                    (iVar1 + 0x23,*(uint32_t /* width from decompiler */ *)(iVar1 + 8),*(uint32_t /* width from decompiler */ *)(iVar1 + 0xc),1);

        }

        if (*(int *)(param_1 + 0x52c) != 0) {

          sprintf(acStack_40,"%i",*(uint32_t /* width from decompiler */ *)(*piVar3 + 0x18));

          (**(code **)(**(int **)(param_1 + 0x52c) + 0x444))

                    (acStack_40,*(uint32_t /* width from decompiler */ *)(*piVar3 + 8),*(uint32_t /* width from decompiler */ *)(*piVar3 + 0xc),1);

        }

        if (*(int *)(param_1 + 0x530) != 0) {

          sprintf(acStack_40,"%i",*(uint32_t /* width from decompiler */ *)(*piVar3 + 0x1c));

          (**(code **)(**(int **)(param_1 + 0x530) + 0x444))

                    (acStack_40,*(uint32_t /* width from decompiler */ *)(*piVar3 + 8),*(uint32_t /* width from decompiler */ *)(*piVar3 + 0xc),1);

        }

        piVar3 = piVar3 + 1;

      } while (piVar3 != (int *)*piVar2);

    }

    FUN_007fbd30();

  }

  return;

}
