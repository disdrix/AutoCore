// =============================================================================
// FUN_0064acc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0064acc0
// Address:   0x0064acc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064acc0 @ 0x0064acc0
// Stable ID: aa_0064acc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×12, do×6, while×6, return×3.
//  - Notable callees: FUN_0064a880×2, FUN_0064ab50×2, FUN_005b3300, FUN_0064acc0.
//  - Return sites: 3.

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

int __thiscall FUN_0064acc0(int param_1,int param_2)



{

  int *piVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  *(uint16_t *)(param_1 + 4) = *(uint16_t *)(param_2 + 4);

  *(uint16_t *)(param_1 + 6) = *(uint16_t *)(param_2 + 6);

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  iVar5 = *(int *)(param_2 + 0x10);

  piVar1 = (int *)(param_1 + 0xc);

  if ((int)(*(uint *)(param_1 + 0x14) & 0x7fffffff) < iVar5) {

    iVar5 = *(int *)(param_1 + 0x10);

    puVar3 = (uint32_t /* width from decompiler */ *)*piVar1;

    if (0 < iVar5) {

      do {

        (**(code **)*puVar3)(0);

        puVar3 = puVar3 + 7;

        iVar5 = iVar5 + -1;

      } while (iVar5 != 0);

    }

    iVar5 = *(int *)(param_2 + 0x10);

    uVar2 = *(uint *)(param_1 + 0x14) & 0x7fffffff;

    if ((int)uVar2 < iVar5) {

      iVar4 = uVar2 * 2;

      if (iVar4 <= iVar5) {

        iVar4 = iVar5;

      }

      FUN_005b3300(piVar1,iVar4,0x1c);

    }

    *(int *)(param_1 + 0x10) = iVar5;

    iVar5 = *piVar1;

    iVar4 = 0;

    if (0 < *(int *)(param_2 + 0x10)) {

      iVar6 = 0;

      do {

        if (iVar5 != 0) {

          FUN_0064ab50(*(int *)(param_2 + 0xc) + iVar6);

        }

        iVar4 = iVar4 + 1;

        iVar6 = iVar6 + 0x1c;

        iVar5 = iVar5 + 0x1c;

      } while (iVar4 < *(int *)(param_2 + 0x10));

      return param_1;

    }

  }

  else {

    iVar4 = 0;

    if (*(int *)(param_1 + 0x10) < iVar5) {

      if (0 < *(int *)(param_1 + 0x10)) {

        iVar5 = 0;

        do {

          FUN_0064a880(*(int *)(param_2 + 0xc) + iVar5);

          iVar4 = iVar4 + 1;

          iVar5 = iVar5 + 0x1c;

        } while (iVar4 < *(int *)(param_1 + 0x10));

      }

      if (iVar4 < *(int *)(param_2 + 0x10)) {

        iVar5 = iVar4 * 0x1c;

        iVar6 = *piVar1 + iVar5;

        do {

          if (iVar6 != 0) {

            FUN_0064ab50(*(int *)(param_2 + 0xc) + iVar5);

          }

          iVar4 = iVar4 + 1;

          iVar5 = iVar5 + 0x1c;

          iVar6 = iVar6 + 0x1c;

        } while (iVar4 < *(int *)(param_2 + 0x10));

        return param_1;

      }

    }

    else {

      if (0 < iVar5) {

        iVar5 = 0;

        do {

          FUN_0064a880(*(int *)(param_2 + 0xc) + iVar5);

          iVar4 = iVar4 + 1;

          iVar5 = iVar5 + 0x1c;

        } while (iVar4 < *(int *)(param_2 + 0x10));

      }

      if (iVar4 < *(int *)(param_1 + 0x10)) {

        iVar5 = iVar4 * 0x1c;

        do {

          (*(code *)**(uint32_t /* width from decompiler */ **)(*piVar1 + iVar5))(0);

          iVar4 = iVar4 + 1;

          iVar5 = iVar5 + 0x1c;

        } while (iVar4 < *(int *)(param_1 + 0x10));

      }

    }

  }

  return param_1;

}
