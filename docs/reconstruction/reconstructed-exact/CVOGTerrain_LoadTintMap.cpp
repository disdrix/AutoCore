// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×6, do×5, while×5, for×3, return×3.
//  - Notable callees: FUN_007b6a20×2, CVOGTerrain_LoadTintMap, FUN_00403450, FUN_00788e30, FUN_00788e40, FUN_007890b0, FUN_007b70b0, FUN_007b7250.
//  - Return sites: 3.

// =============================================================================
// CVOGTerrain_LoadTintMap
// -----------------------------------------------------------------------------
// Stable ID: aa_004ab100
// Address:   0x004ab100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* WARNING: Removing unreachable block (ram,0x004ab174) */

/* CVOGTerrain::LoadTintMap. Loads <map>_tint.tga into the per-cell RGBA vertex-color buffer

   (+0x3a4); defaults to 0xff7f7f7f mid-gray when missing. The terrain shaders multiply diffuse by

   2*vertColor, so 0x7f = neutral. */



uint32_t /* width from decompiler */ __fastcall CVOGTerrain_LoadTintMap(int param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  int iVar9;

  char *pcVar10;

  int iVar11;

  float fVar12;

  char local_190 [127];

  char cStack_111;

  char local_110 [2];

  uint32_t /* width from decompiler */ local_10e [66];

  

  local_110[0] = '\0';

  local_110[1] = '\0';

  puVar5 = local_10e;

  for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  pcVar4 = local_190;

  uVar3 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(param_1 + 0x124,uVar3);

  iVar6 = -2 - (int)pcVar4;

  do {

    cVar1 = *pcVar4;

    pcVar4[(int)local_10e + iVar6] = cVar1;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  pcVar4 = strrchr(local_110,0x2e);

  if (pcVar4 != (char *)0x0) {

    *pcVar4 = '\0';

    pcVar4 = &cStack_111;

    do {

      pcVar10 = pcVar4;

      pcVar4 = pcVar10 + 1;

    } while (pcVar10[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar10 + 1) = s__tint_tga_009cb140._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar10 + 5) = s__tint_tga_009cb140._4_4_;

    *(uint16_t *)(pcVar10 + 9) = s__tint_tga_009cb140._8_2_;

  }

  pcVar4 = local_110;

  FUN_007b6a20(pcVar4);

  iVar6 = FUN_007b7250(pcVar4);

  puVar5 = operator_new__(*(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x10) * 4);

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x3a4) = puVar5;

  for (uVar7 = *(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x10) & 0x3fffffff; uVar7 != 0;

      uVar7 = uVar7 - 1) {

    *puVar5 = 0xffffffff;

    puVar5 = puVar5 + 1;

  }

  for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {

    *(uint8_t *)puVar5 = 0xff;

    puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

  }

  if (iVar6 == 0) {

    iVar6 = 0;

    if (0 < *(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x10)) {

      do {

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x3a4) + iVar6 * 4) = 0xff7f7f7f;

        iVar6 = iVar6 + 1;

      } while (iVar6 < *(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x10));

    }

    return 1;

  }

  iVar6 = FUN_00788e40();

  iVar8 = FUN_00788e30();

  if ((0 < iVar6) && (0 < iVar8)) {

    iVar9 = 0;

    if (0 < iVar6) {

      do {

        iVar11 = 0;

        if (0 < iVar8) {

          do {

            fVar12 = (float)iVar11;

            iVar2 = *(int *)(param_1 + 0x14);

            uVar7 = FUN_007890b0(iVar11,iVar9);

            iVar11 = iVar11 + 1;

            *(uint *)(*(int *)(param_1 + 0x3a4) + ((int)fVar12 * iVar2 + (int)(float)iVar9) * 4) =

                 uVar7 | 0xff000000;

          } while (iVar11 < iVar8);

        }

        iVar9 = iVar9 + 1;

      } while (iVar9 < iVar6);

    }

    pcVar4 = local_110;

    FUN_007b6a20(pcVar4);

    FUN_007b70b0(pcVar4);

    return 1;

  }

  return 0;

}
