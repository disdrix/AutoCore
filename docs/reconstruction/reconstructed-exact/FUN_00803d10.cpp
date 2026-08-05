// =============================================================================
// FUN_00803d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00803d10
// Address:   0x00803d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00803d10 @ 0x00803d10
// Stable ID: aa_00803d10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00418700, FUN_00418790, FUN_00803b50, FUN_00803d10.
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

void FUN_00803d10(int param_1)



{

  int *piVar1;

  uint uVar2;

  int iVar3;

  int *piVar4;

  uint *puVar5;

  int *piVar6;

  int iVar7;

  uint uVar8;

  int unaff_EBX;

  

  iVar3 = param_1;

  piVar6 = (int *)**(int **)(unaff_EBX + 0x38);

  if (piVar6 != *(int **)(unaff_EBX + 0x38)) {

    do {

      piVar1 = (int *)piVar6[2];

      piVar4 = (int *)(**(code **)(*piVar1 + 0x44))();

      (**(code **)(*piVar1 + 0x3c))(*piVar4 + iVar3,piVar4[1]);

      piVar6 = (int *)*piVar6;

    } while (piVar6 != (int *)*(int *)(unaff_EBX + 0x38));

  }

  puVar5 = (uint *)(**(code **)(**(int **)(unaff_EBX + 0x5c) + 0x44))();

  uVar2 = *puVar5;

  piVar6 = (int *)(**(code **)(**(int **)(unaff_EBX + 0x5c) + 0x90))();

  uVar8 = (int)uVar2 >> 0x1f;

  if (*piVar6 <= (int)((uVar2 ^ uVar8) - uVar8)) {

    piVar6 = (int *)**(int **)(unaff_EBX + 0x38);

    if (piVar6 != *(int **)(unaff_EBX + 0x38)) {

      *(int *)piVar6[1] = *piVar6;

      *(int *)(*piVar6 + 4) = piVar6[1];

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar6);

    }

    iVar3 = *(int *)(unaff_EBX + 0x38);

    param_1 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x5c);

    iVar7 = FUN_00418700(iVar3,*(uint32_t /* width from decompiler */ *)(iVar3 + 4),&param_1);

    FUN_00418790();

    *(int *)(iVar3 + 4) = iVar7;

    **(int **)(iVar7 + 4) = iVar7;

    FUN_00803b50(unaff_EBX);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x5c) = *(uint32_t /* width from decompiler */ *)(**(int **)(unaff_EBX + 0x38) + 8);

  }

  return;

}
