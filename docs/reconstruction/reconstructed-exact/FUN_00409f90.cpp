// =============================================================================
// FUN_00409f90
// -----------------------------------------------------------------------------
// Stable ID: aa_00409f90
// Address:   0x00409f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00409f90 @ 0x00409f90
// Stable ID: aa_00409f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~170 non-empty decompiler lines.
//  - Control keywords: if×13, goto×3, while×2, do×1, for×1, return×1.
//  - Notable callees: FUN_00409f90, FUN_0040a730.
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

void FUN_00409f90(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,code *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  char cVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ *local_74;

  

  puVar7 = param_2 + (((int)param_3 - (int)param_2 >> 4) - ((int)param_3 - (int)param_2 >> 0x1f) >>

                     1) * 4;

  FUN_0040a730(param_2,puVar7,param_3 + -4);

  puVar1 = puVar7;

  while (local_74 = puVar1, param_2 < local_74) {

    puVar1 = local_74 + -4;

    cVar6 = (*param_4)(puVar1,local_74);

    if ((cVar6 != '\0') || (cVar6 = (*param_4)(local_74,puVar1), cVar6 != '\0')) break;

  }

  do {

    puVar7 = puVar7 + 4;

    puVar1 = puVar7;

    puVar10 = local_74;

    if (param_3 <= puVar7) break;

    cVar6 = (*param_4)(puVar7,local_74);

    if ((cVar6 != '\0') || (cVar6 = (*param_4)(local_74,puVar7), cVar6 != '\0')) break;

  } while( true );

joined_r0x0040a037:

  puVar9 = local_74;

  if (param_3 <= puVar1) {

joined_r0x0040a0c6:

    for (; param_2 < local_74; local_74 = local_74 + -4) {

      puVar8 = puVar9 + -4;

      cVar6 = (*param_4)(puVar8,puVar10);

      puVar11 = puVar10;

      if (cVar6 == '\0') {

        cVar6 = (*param_4)(puVar10,puVar8);

        if (cVar6 != '\0') break;

        puVar11 = puVar10 + -4;

        uVar2 = *puVar11;

        uVar3 = puVar10[-3];

        uVar4 = puVar10[-2];

        uVar5 = puVar10[-1];

        *puVar11 = *puVar8;

        puVar10[-3] = puVar9[-3];

        puVar10[-2] = puVar9[-2];

        puVar10[-1] = puVar9[-1];

        *puVar8 = uVar2;

        puVar9[-3] = uVar3;

        puVar9[-2] = uVar4;

        puVar9[-1] = uVar5;

      }

      puVar10 = puVar11;

      puVar9 = puVar8;

    }

    if (local_74 == param_2) {

      if (puVar1 == param_3) {

        *param_1 = puVar10;

        param_1[1] = puVar7;

        return;

      }

      if (puVar7 != puVar1) {

        uVar2 = *puVar10;

        uVar3 = puVar10[1];

        uVar4 = puVar10[2];

        uVar5 = puVar10[3];

        *puVar10 = *puVar7;

        puVar10[1] = puVar7[1];

        puVar10[2] = puVar7[2];

        puVar10[3] = puVar7[3];

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7[2] = uVar4;

        puVar7[3] = uVar5;

      }

      uVar2 = *puVar10;

      uVar3 = puVar10[1];

      uVar4 = puVar10[2];

      uVar5 = puVar10[3];

      *puVar10 = *puVar1;

      puVar10[1] = puVar1[1];

      puVar10[2] = puVar1[2];

      puVar10[3] = puVar1[3];

      *puVar1 = uVar2;

      puVar1[1] = uVar3;

      puVar1[2] = uVar4;

      puVar1[3] = uVar5;

      puVar7 = puVar7 + 4;

      puVar1 = puVar1 + 4;

      puVar10 = puVar10 + 4;

    }

    else {

      puVar9 = local_74 + -4;

      if (puVar1 == param_3) {

        puVar11 = puVar10 + -4;

        if (puVar9 != puVar11) {

          uVar2 = *puVar9;

          uVar3 = local_74[-3];

          uVar4 = local_74[-2];

          uVar5 = local_74[-1];

          *puVar9 = *puVar11;

          local_74[-3] = puVar10[-3];

          local_74[-2] = puVar10[-2];

          local_74[-1] = puVar10[-1];

          *puVar11 = uVar2;

          puVar10[-3] = uVar3;

          puVar10[-2] = uVar4;

          puVar10[-1] = uVar5;

        }

        uVar2 = *puVar11;

        uVar3 = puVar10[-3];

        uVar4 = puVar10[-2];

        uVar5 = puVar10[-1];

        puVar8 = puVar7 + -4;

        *puVar11 = *puVar8;

        puVar10[-3] = puVar7[-3];

        puVar10[-2] = puVar7[-2];

        puVar10[-1] = puVar7[-1];

        *puVar8 = uVar2;

        puVar7[-3] = uVar3;

        puVar7[-2] = uVar4;

        puVar7[-1] = uVar5;

        puVar7 = puVar8;

        local_74 = puVar9;

        puVar10 = puVar11;

      }

      else {

        uVar2 = *puVar1;

        uVar3 = puVar1[1];

        uVar4 = puVar1[2];

        uVar5 = puVar1[3];

        *puVar1 = *puVar9;

        puVar1[1] = local_74[-3];

        puVar1[2] = local_74[-2];

        puVar1[3] = local_74[-1];

        *puVar9 = uVar2;

        local_74[-3] = uVar3;

        local_74[-2] = uVar4;

        local_74[-1] = uVar5;

        puVar1 = puVar1 + 4;

        local_74 = puVar9;

      }

    }

    goto joined_r0x0040a037;

  }

  cVar6 = (*param_4)(puVar10,puVar1);

  if (cVar6 == '\0') {

    cVar6 = (*param_4)(puVar1,puVar10);

    if (cVar6 != '\0') goto joined_r0x0040a0c6;

    uVar2 = *puVar7;

    uVar3 = puVar7[1];

    uVar4 = puVar7[2];

    uVar5 = puVar7[3];

    *puVar7 = *puVar1;

    puVar7[1] = puVar1[1];

    puVar7[2] = puVar1[2];

    puVar7[3] = puVar1[3];

    *puVar1 = uVar2;

    puVar1[1] = uVar3;

    puVar1[2] = uVar4;

    puVar7 = puVar7 + 4;

    puVar1[3] = uVar5;

  }

  puVar1 = puVar1 + 4;

  goto joined_r0x0040a037;

}
