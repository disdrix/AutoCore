// =============================================================================
// FUN_00803b50
// -----------------------------------------------------------------------------
// Stable ID: aa_00803b50
// Address:   0x00803b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00803b50 @ 0x00803b50
// Stable ID: aa_00803b50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00803b50.
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

void FUN_00803b50(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  int iVar7;

  

  if (1 < *(uint *)(param_1 + 0x3c)) {

    piVar6 = (int *)**(int **)(param_1 + 0x38);

    iVar7 = 0;

    if (piVar6 != *(int **)(param_1 + 0x38)) {

      do {

        piVar5 = (int *)piVar6[2];

        iVar3 = *piVar5;

        puVar1 = (uint32_t /* width from decompiler */ *)(**(code **)(iVar3 + 0x90))();

        iVar2 = (**(code **)(iVar3 + 0x90))();

        (**(code **)(iVar3 + 0x48))(*puVar1,*(uint32_t /* width from decompiler */ *)(iVar2 + 4));

        iVar3 = (**(code **)(*piVar5 + 0x44))();

        if (iVar7 == 0) {

          piVar4 = (int *)(**(code **)(*piVar5 + 0x44))();

          iVar7 = *piVar4;

        }

        (**(code **)(*piVar5 + 0x3c))(iVar7,*(uint32_t /* width from decompiler */ *)(iVar3 + 4));

        piVar5 = (int *)(**(code **)(*piVar5 + 0x90))();

        iVar7 = iVar7 + *piVar5;

        piVar6 = (int *)*piVar6;

      } while (piVar6 != (int *)*(int *)(param_1 + 0x38));

    }

  }

  return;

}
