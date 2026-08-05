// =============================================================================
// FUN_0062bad0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062bad0
// Address:   0x0062bad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062bad0 @ 0x0062bad0
// Stable ID: aa_0062bad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×4, while×4, do×2, for×2, goto×1, return×1.
//  - Notable callees: FUN_0062bad0.
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

void __thiscall

FUN_0062bad0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)



{

  uint *puVar1;

  uint *puVar2;

  uint *puVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  uint *puVar8;

  uint *puVar9;

  uint *puVar10;

  

  iVar7 = 0;

  if (0 < param_3) {

    do {

      iVar4 = *param_1;

      *(uint32_t /* width from decompiler */ *)(param_6 + iVar7 * 8) = *(uint32_t /* width from decompiler */ *)(iVar4 + iVar7 * 8);

      *(uint32_t /* width from decompiler */ *)(param_6 + 4 + iVar7 * 8) = *(uint32_t /* width from decompiler */ *)(iVar4 + 4 + iVar7 * 8);

      iVar7 = iVar7 + 1;

    } while (iVar7 < param_3);

  }

  puVar8 = (uint *)*param_1;

  puVar9 = (uint *)(param_6 + 8);

  puVar3 = (uint *)(param_6 + -8 + param_3 * 8);

  puVar10 = puVar8 + param_3 * 2;

  puVar2 = puVar8 + (param_3 + param_4) * 2;

  uVar5 = *puVar9;

  while (puVar8 = puVar8 + 2, uVar5 < *puVar10) {

    puVar9 = puVar9 + 2;

    uVar5 = *puVar9;

  }

  if (puVar9 < puVar3) {

    for (; puVar10 < puVar2; puVar10 = puVar10 + 2) {

      while (*puVar9 < *puVar10) {

        *puVar8 = *puVar9;

        puVar8[1] = puVar9[1];

        iVar7 = (int)puVar8 - *param_1;

        uVar5 = *puVar8;

        puVar1 = puVar8 + 1;

        puVar9 = puVar9 + 2;

        puVar8 = puVar8 + 2;

        *(int *)(*(int *)(&DAT_00af4e30 + ((uVar5 & 1) + param_5 * 2) * 4) + *puVar1 * 0x1c +

                param_2) = iVar7 >> 3;

        if (puVar3 <= puVar9) goto joined_r0x0062bb98;

      }

      *puVar8 = *puVar10;

      puVar8[1] = puVar10[1];

      *(int *)(*(int *)(&DAT_00af4e30 + ((*puVar8 & 1) + param_5 * 2) * 4) + puVar8[1] * 0x1c +

              param_2) = (int)puVar8 - *param_1 >> 3;

      puVar8 = puVar8 + 2;

    }

  }

  else {

joined_r0x0062bb98:

    for (; puVar10 < puVar2; puVar10 = puVar10 + 2) {

      *puVar8 = *puVar10;

      uVar5 = *puVar8;

      puVar8[1] = puVar10[1];

      iVar7 = (int)puVar8 - *param_1;

      puVar1 = puVar8 + 1;

      puVar8 = puVar8 + 2;

      *(int *)(*(int *)(&DAT_00af4e30 + ((uVar5 & 1) + param_5 * 2) * 4) + *puVar1 * 0x1c + param_2)

           = iVar7 >> 3;

    }

  }

  if (puVar9 <= puVar3) {

    do {

      *puVar8 = *puVar9;

      uVar5 = puVar9[1];

      uVar6 = *puVar8;

      puVar8[1] = uVar5;

      iVar7 = (int)puVar8 - *param_1;

      puVar9 = puVar9 + 2;

      puVar8 = puVar8 + 2;

      *(int *)(*(int *)(&DAT_00af4e30 + ((uVar6 & 1) + param_5 * 2) * 4) + uVar5 * 0x1c + param_2) =

           iVar7 >> 3;

    } while (puVar9 <= puVar3);

  }

  return;

}
