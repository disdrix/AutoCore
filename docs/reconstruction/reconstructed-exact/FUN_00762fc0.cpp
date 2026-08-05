// =============================================================================
// FUN_00762fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00762fc0
// Address:   0x00762fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00762fc0 @ 0x00762fc0
// Stable ID: aa_00762fc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, return×1.
//  - Notable callees: FUN_00456960×2, FUN_00762fc0.
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

void FUN_00762fc0(int param_1,int param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int in_EAX;

  int iVar3;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  if (in_EAX != 0) {

    puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xc4);

    for (puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xc0); puVar4 != puVar5; puVar4 = puVar4 + 1) {

      piVar1 = (int *)*puVar4;

      iVar3 = (**(code **)(*piVar1 + 4))();

      if (iVar3 == param_2) {

        iVar3 = *(int *)(in_EAX + 4);

        if ((iVar3 == 0) ||

           ((uint)(*(int *)(in_EAX + 0xc) - iVar3 >> 2) <= (uint)(*(int *)(in_EAX + 8) - iVar3 >> 2)

           )) {

          FUN_00456960(*(uint32_t /* width from decompiler */ *)(in_EAX + 8));

        }

        else {

          puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 8);

          *puVar2 = piVar1;

          *(uint32_t /* width from decompiler */ **)(in_EAX + 8) = puVar2 + 1;

        }

      }

    }

  }

  if (unaff_EBX != 0) {

    puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xd4);

    for (puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xd0); puVar5 != puVar4; puVar5 = puVar5 + 1) {

      piVar1 = (int *)*puVar5;

      iVar3 = (**(code **)(*piVar1 + 4))();

      if (iVar3 == param_2) {

        iVar3 = *(int *)(unaff_EBX + 4);

        if ((iVar3 == 0) ||

           ((uint)(*(int *)(unaff_EBX + 0xc) - iVar3 >> 2) <=

            (uint)(*(int *)(unaff_EBX + 8) - iVar3 >> 2))) {

          FUN_00456960(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8));

        }

        else {

          puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 8);

          *puVar2 = piVar1;

          *(uint32_t /* width from decompiler */ **)(unaff_EBX + 8) = puVar2 + 1;

        }

      }

    }

  }

  return;

}
