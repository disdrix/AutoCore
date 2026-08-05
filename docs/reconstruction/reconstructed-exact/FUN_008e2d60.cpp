// =============================================================================
// FUN_008e2d60
// -----------------------------------------------------------------------------
// Stable ID: aa_008e2d60
// Address:   0x008e2d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e2d60 @ 0x008e2d60
// Stable ID: aa_008e2d60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×2.
//  - Notable callees: FUN_008e2d60.
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

void FUN_008e2d60(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int local_4;

  

  puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 0x534);

  puVar6 = (uint32_t /* width from decompiler */ *)(param_1 + 0x680);

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5b8);

  local_4 = 5;

  do {

    iVar3 = 5;

    do {

      if ((uint32_t /* width from decompiler */ *)puVar5[0x19] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)puVar5[0x19])(1);

      }

      piVar1 = (int *)*puVar5;

      puVar5[0x19] = 0;

      *puVar6 = 0xffffffff;

      puVar6[1] = 0xffffffff;

      iVar2 = (**(code **)(*piVar1 + 700))();

      if (iVar2 != 0) {

        (**(code **)(*(int *)*puVar5 + 0x58))();

      }

      (**(code **)(*(int *)*puVar5 + 0xcc))(0);

      (**(code **)(*(int *)*puVar5 + 0x34c))();

      puVar6 = puVar6 + 2;

      puVar5 = puVar5 + 1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

    (**(code **)(*(int *)puVar4[7] + 4))(0);

    (**(code **)(*(int *)*puVar4 + 4))(0);

    puVar4 = puVar4 + 1;

    local_4 = local_4 + -1;

  } while (local_4 != 0);

  (**(code **)(**(int **)(param_1 + 0x748) + 0xd4))(0);

  (**(code **)(**(int **)(param_1 + 0x748) + 0x34c))();

  if (*(int *)(param_1 + 0x768) != 0) {

    (**(code **)(**(int **)(param_1 + 0x768) + 4))(0);

  }

  if (*(int *)(param_1 + 0x76c) != 0) {

                    /* WARNING: Could not recover jumptable at 0x008e2e55. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(param_1 + 0x76c) + 4))();

    return;

  }

  return;

}
