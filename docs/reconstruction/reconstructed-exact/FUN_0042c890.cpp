// =============================================================================
// FUN_0042c890
// -----------------------------------------------------------------------------
// Stable ID: aa_0042c890
// Address:   0x0042c890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042c890 @ 0x0042c890
// Stable ID: aa_0042c890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×8, while×4, do×2, return×2.
//  - Notable callees: FUN_0042b2a0×2, FUN_0042c890, free.
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

uint __thiscall FUN_0042c890(int param_1,uint param_2)



{

  int *piVar1;

  uint *puVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  

  *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;

  piVar1 = (int *)(param_1 + 0xc);

  FUN_0042b2a0();

  *piVar1 = *piVar1 + 1;

  piVar3 = (int *)(*(int *)(param_1 + 0x14) + -4 + *piVar1 * 4);

  if (piVar3 != (int *)0x0) {

    *piVar3 = param_2;

  }

  uVar10 = *(uint *)(param_1 + 0x18);

  iVar4 = *piVar1;

  puVar2 = (uint *)(param_1 + 0x18);

  if ((int)uVar10 / 2 < iVar4) {

    uVar10 = iVar4 * 4 - 1;

    FUN_0042b2a0();

    if (*puVar2 < uVar10) {

      *puVar2 = uVar10;

    }

    else if ((uVar10 < *puVar2) && (*puVar2 = uVar10, uVar10 == 0)) {

      free(*(void **)(param_1 + 0x20));

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    }

    uVar8 = 0;

    if (0 < (int)*puVar2) {

      do {

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x20) + uVar8 * 4) = 0;

        uVar8 = uVar8 + 1;

      } while ((int)uVar8 < (int)*puVar2);

    }

    param_2 = 0;

    if (0 < iVar4) {

      do {

        iVar5 = *(int *)(*(int *)(param_1 + 0x14) + param_2 * 4);

        uVar10 = ((((uint)*(ushort *)(iVar5 + 0xfa) ^ *(uint *)(iVar5 + 0x100) << 8) * 8 ^

                  *(uint *)(iVar5 + 0x104)) << 5 ^ *(uint *)(iVar5 + 0x100) >> 0x10 ^

                 *(uint *)(iVar5 + 0xfc)) % *puVar2;

        iVar6 = *(int *)(param_1 + 0x20);

        iVar7 = *(int *)(iVar6 + uVar10 * 4);

        while (iVar7 != 0) {

          uVar10 = uVar10 + 1;

          if (*puVar2 <= uVar10) {

            uVar10 = 0;

          }

          iVar7 = *(int *)(iVar6 + uVar10 * 4);

        }

        *(int *)(iVar6 + uVar10 * 4) = iVar5;

        param_2 = param_2 + 1;

      } while ((int)param_2 < iVar4);

      return param_2;

    }

  }

  else {

    iVar4 = *(int *)(*(int *)(param_1 + 0x14) + -4 + iVar4 * 4);

    uVar9 = (((uint)*(ushort *)(iVar4 + 0xfa) ^ *(uint *)(iVar4 + 0x100) << 8) * 8 ^

            *(uint *)(iVar4 + 0x104)) << 5 ^ *(uint *)(iVar4 + 0x100) >> 0x10 ^

            *(uint *)(iVar4 + 0xfc);

    uVar8 = uVar9 / uVar10;

    uVar9 = uVar9 % uVar10;

    iVar5 = *(int *)(param_1 + 0x20);

    iVar6 = *(int *)(iVar5 + uVar9 * 4);

    while (iVar6 != 0) {

      uVar9 = uVar9 + 1;

      if (uVar10 <= uVar9) {

        uVar9 = 0;

      }

      iVar6 = *(int *)(iVar5 + uVar9 * 4);

    }

    *(int *)(iVar5 + uVar9 * 4) = iVar4;

  }

  return uVar8;

}
