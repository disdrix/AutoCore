// =============================================================================
// FUN_0044cd20
// -----------------------------------------------------------------------------
// Stable ID: aa_0044cd20
// Address:   0x0044cd20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044cd20 @ 0x0044cd20
// Stable ID: aa_0044cd20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~158 non-empty decompiler lines.
//  - Control keywords: if×16, while×4, goto×2, do×1, return×1.
//  - Notable callees: FUN_00746810×16, FUN_0044cd20, FUN_0044d090.
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

void FUN_0044cd20(uint *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ *local_18;

  uint32_t /* width from decompiler */ *local_14;

  

  puVar9 = param_2 + (((int)param_3 - (int)param_2 >> 3) - ((int)param_3 - (int)param_2 >> 0x1f) >>

                     1) * 2;

  FUN_0044d090(param_2,puVar9,param_3 + -2,param_4);

  puVar8 = puVar9 + 2;

  if (param_2 < puVar9) {

    while( true ) {

      puVar1 = puVar9 + -2;

      iVar4 = FUN_00746810();

      iVar5 = FUN_00746810();

      if (iVar4 < iVar5) break;

      iVar4 = FUN_00746810();

      iVar5 = FUN_00746810();

      if ((iVar5 < iVar4) || (puVar9 = puVar1, puVar1 <= param_2)) break;

    }

  }

  puVar1 = puVar8;

  local_18 = puVar8;

  local_14 = puVar9;

  puVar10 = puVar9;

  if (puVar8 < param_3) {

    while( true ) {

      iVar4 = FUN_00746810();

      iVar5 = FUN_00746810();

      puVar1 = puVar8;

      local_18 = puVar8;

      if (iVar4 < iVar5) break;

      iVar4 = FUN_00746810();

      iVar5 = FUN_00746810();

      if ((iVar5 < iVar4) ||

         (puVar8 = puVar8 + 2, puVar1 = puVar8, local_18 = puVar8, param_3 <= puVar8)) break;

    }

  }

joined_r0x0044cde4:

  do {

    puVar11 = puVar9;

    if (param_3 <= puVar1) {

joined_r0x0044ce3c:

      while (puVar6 = puVar9, param_2 < puVar9) {

        puVar7 = puVar11 + -2;

        iVar4 = FUN_00746810();

        iVar5 = FUN_00746810();

        puVar6 = puVar10;

        puVar8 = local_18;

        if (iVar5 <= iVar4) {

          iVar4 = FUN_00746810();

          iVar5 = FUN_00746810();

          puVar6 = local_14;

          if (iVar5 < iVar4) break;

          uVar2 = puVar10[-2];

          uVar3 = puVar10[-1];

          puVar6 = puVar10 + -2;

          *puVar6 = *puVar7;

          puVar10[-1] = puVar11[-1];

          *puVar7 = uVar2;

          puVar11[-1] = uVar3;

        }

        local_14 = local_14 + -2;

        puVar11 = puVar7;

        puVar10 = puVar6;

        puVar9 = local_14;

      }

      if (puVar6 == param_2) {

        if (puVar1 == param_3) {

          *param_1 = (uint)puVar10;

          param_1[1] = (uint)puVar8;

          return;

        }

        if (puVar8 != puVar1) {

          uVar2 = *puVar10;

          uVar3 = puVar10[1];

          *puVar10 = *puVar8;

          puVar10[1] = puVar8[1];

          *puVar8 = uVar2;

          puVar8[1] = uVar3;

        }

        uVar2 = *puVar10;

        uVar3 = puVar10[1];

        *puVar10 = *puVar1;

        puVar10[1] = puVar1[1];

        puVar8 = puVar8 + 2;

        *puVar1 = uVar2;

        puVar1[1] = uVar3;

        puVar9 = puVar6;

        puVar1 = puVar1 + 2;

        local_18 = puVar8;

        puVar10 = puVar10 + 2;

      }

      else {

        puVar9 = puVar6 + -2;

        local_14 = puVar9;

        if (puVar1 == param_3) {

          puVar11 = puVar10 + -2;

          if (puVar9 != puVar11) {

            uVar2 = *puVar9;

            uVar3 = puVar6[-1];

            *puVar9 = *puVar11;

            puVar6[-1] = puVar10[-1];

            *puVar11 = uVar2;

            puVar10[-1] = uVar3;

          }

          uVar2 = *puVar11;

          uVar3 = puVar10[-1];

          local_18 = puVar8 + -2;

          *puVar11 = puVar8[-2];

          puVar10[-1] = puVar8[-1];

          *local_18 = uVar2;

          puVar8[-1] = uVar3;

          puVar8 = local_18;

          puVar10 = puVar11;

        }

        else {

          uVar2 = puVar1[1];

          uVar3 = *puVar1;

          *puVar1 = *puVar9;

          puVar1[1] = puVar6[-1];

          *puVar9 = uVar3;

          puVar6[-1] = uVar2;

          puVar1 = puVar1 + 2;

        }

      }

      goto joined_r0x0044cde4;

    }

    iVar4 = FUN_00746810();

    iVar5 = FUN_00746810();

    puVar9 = local_14;

    if (iVar4 <= iVar5) {

      iVar4 = FUN_00746810();

      iVar5 = FUN_00746810();

      puVar11 = local_14;

      local_18 = puVar8;

      if (iVar4 < iVar5) goto joined_r0x0044ce3c;

      uVar2 = *puVar8;

      uVar3 = puVar8[1];

      *puVar8 = *puVar1;

      puVar8[1] = puVar1[1];

      puVar8 = puVar8 + 2;

      *puVar1 = uVar2;

      puVar1[1] = uVar3;

    }

    puVar1 = puVar1 + 2;

    local_18 = puVar8;

  } while( true );

}
