// =============================================================================
// FUN_0042c760
// -----------------------------------------------------------------------------
// Stable ID: aa_0042c760
// Address:   0x0042c760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042c760 @ 0x0042c760
// Stable ID: aa_0042c760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×10, while×4, return×2, do×1.
//  - Notable callees: FUN_0042c760.
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

void __thiscall FUN_0042c760(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  int *piVar5;

  uint uVar6;

  

  iVar3 = 0;

  if (0 < *(int *)(param_1 + 0xc)) {

    piVar5 = *(int **)(param_1 + 0x14);

    do {

      if ((int *)*piVar5 == param_2) {

        if (iVar3 != *(int *)(param_1 + 0xc) + -1) {

          *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + iVar3 * 4) =

               *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + -4 + *(int *)(param_1 + 0xc) * 4);

        }

        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;

        break;

      }

      iVar3 = iVar3 + 1;

      piVar5 = piVar5 + 1;

    } while (iVar3 < *(int *)(param_1 + 0xc));

  }

  uVar4 = ((((uint)*(ushort *)((int)param_2 + 0xfa) ^ param_2[0x40] << 8) * 8 ^ param_2[0x41]) << 5

           ^ (uint)param_2[0x40] >> 0x10 ^ param_2[0x3f]) % *(uint *)(param_1 + 0x18);

  iVar3 = *(int *)(param_1 + 0x20);

  piVar5 = *(int **)(iVar3 + uVar4 * 4);

  uVar6 = uVar4;

  while( true ) {

    if (piVar5 == param_2) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + uVar6 * 4) = 0;

      while( true ) {

        uVar6 = uVar6 + 1;

        if (*(uint *)(param_1 + 0x18) <= uVar6) {

          uVar6 = 0;

        }

        iVar3 = *(int *)(param_1 + 0x20);

        if (*(int *)(iVar3 + uVar6 * 4) == 0) break;

        iVar1 = *(int *)(iVar3 + uVar6 * 4);

        *(uint32_t /* width from decompiler */ *)(iVar3 + uVar6 * 4) = 0;

        uVar4 = ((((uint)*(ushort *)(iVar1 + 0xfa) ^ *(uint *)(iVar1 + 0x100) << 8) * 8 ^

                 *(uint *)(iVar1 + 0x104)) << 5 ^ *(uint *)(iVar1 + 0x100) >> 0x10 ^

                *(uint *)(iVar1 + 0xfc)) % *(uint *)(param_1 + 0x18);

        iVar3 = *(int *)(param_1 + 0x20);

        iVar2 = *(int *)(iVar3 + uVar4 * 4);

        while (iVar2 != 0) {

          uVar4 = uVar4 + 1;

          if (*(uint *)(param_1 + 0x18) <= uVar4) {

            uVar4 = 0;

          }

          iVar2 = *(int *)(iVar3 + uVar4 * 4);

        }

        *(int *)(iVar3 + uVar4 * 4) = iVar1;

      }

      piVar5 = param_2 + 2;

      *piVar5 = *piVar5 + -1;

      if (*piVar5 == 0) {

        (**(code **)(*param_2 + 8))();

      }

      return;

    }

    uVar6 = uVar6 + 1;

    if (*(uint *)(param_1 + 0x18) <= uVar6) {

      uVar6 = 0;

    }

    if (uVar6 == uVar4) break;

    piVar5 = *(int **)(iVar3 + uVar6 * 4);

  }

  return;

}
