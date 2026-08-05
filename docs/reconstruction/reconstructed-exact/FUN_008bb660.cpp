// =============================================================================
// FUN_008bb660
// -----------------------------------------------------------------------------
// Stable ID: aa_008bb660
// Address:   0x008bb660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bb660 @ 0x008bb660
// Stable ID: aa_008bb660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~138 non-empty decompiler lines.
//  - Control keywords: if×13, do×5, while×5, return×3, goto×2, for×1.
//  - Notable callees: FUN_007b6730×3, FUN_007b6a20×3, FUN_004ce640, FUN_004ce750, FUN_008bb660.
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

void __fastcall FUN_008bb660(int param_1)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  float fVar6;

  float fVar7;

  ushort *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  int iStack_218;

  uint32_t /* width from decompiler */ uStack_214;

  ushort local_210;

  uint32_t /* width from decompiler */ auStack_20e [4];

  char acStack_1fc [504];

  

  if (((*(char *)(param_1 + 0x510) == '\0') || (DAT_00d1b644 == 0)) ||

     (*(int *)(DAT_00d1b644 + 0xe4f8) == 0)) {

    local_210 = 0;

    puVar5 = auStack_20e;

    for (iVar3 = 0x81; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    *(uint16_t *)puVar5 = 0;

    pcVar2 = (char *)((int)&uStack_214 + 3);

    do {

      pcVar4 = pcVar2;

      pcVar2 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    iVar3 = *(int *)(param_1 + 0x570);

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = s_sec_unknown_dds_00a3970c._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 5) = s_sec_unknown_dds_00a3970c._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 9) = s_sec_unknown_dds_00a3970c._8_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 0xd) = s_sec_unknown_dds_00a3970c._12_4_;

    if (iVar3 != 0) {

      (**(code **)(**(int **)(param_1 + 0x570) + 0x50))(&local_210,1,0);

    }

    if (*(int *)(param_1 + 0x56c) != 0) {

      (**(code **)(**(int **)(param_1 + 0x56c) + 0x50))(&local_210,1,0);

    }

    if (*(int *)(param_1 + 0x574) == 0) {

      return;

    }

    goto LAB_008bb9c6;

  }

  if (*(int *)(param_1 + 0x56c) != 0) {

    FUN_004ce640(&local_210);

    puVar8 = &local_210;

    uVar9 = 0xffffffff;

    FUN_007b6a20(puVar8,0xffffffff);

    cVar1 = FUN_007b6730(puVar8,uVar9);

    if (cVar1 == '\0') {

      pcVar2 = (char *)(DAT_00d1b644 + 0xe3a0);

      iVar3 = -2 - (int)pcVar2;

      do {

        cVar1 = *pcVar2;

        pcVar2[(int)auStack_20e + iVar3] = cVar1;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      puVar8 = &local_210;

      uVar9 = 0xffffffff;

      FUN_007b6a20(puVar8,0xffffffff);

      cVar1 = FUN_007b6730(puVar8,uVar9);

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(param_1 + 0x56c) + 0x50))(&local_210,1,0);

        if (*(int *)(param_1 + 0x570) != 0) {

          local_210 = local_210 & 0xff00;

          pcVar2 = (char *)((int)&uStack_214 + 3);

          do {

            pcVar4 = pcVar2;

            pcVar2 = pcVar4 + 1;

          } while (pcVar4[1] != '\0');

          *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = s_sec_unknown_dds_00a3970c._0_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar4 + 5) = s_sec_unknown_dds_00a3970c._4_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar4 + 9) = s_sec_unknown_dds_00a3970c._8_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar4 + 0xd) = s_sec_unknown_dds_00a3970c._12_4_;

          (**(code **)(**(int **)(param_1 + 0x570) + 0x50))(&local_210,1,0);

        }

        if ((DAT_00d1b644 != 0) && (*(int *)(DAT_00d1b644 + 0xe4f8) != 0)) {

          iVar3 = *(int *)(DAT_00d1b644 + 0xe4f8);

          fVar6 = (float)*(int *)(iVar3 + 0x10) * *(float *)(iVar3 + 0x18);

          fVar7 = (float)*(int *)(iVar3 + 0x14) * *(float *)(iVar3 + 0x18);

          if (fVar6 != fVar7) {

            iStack_218 = *(int *)(param_1 + 0x520);

            uStack_214 = *(int *)(param_1 + 0x524);

            if (fVar6 <= fVar7) {

              iStack_218 = (int)(((float)iStack_218 / fVar7) * fVar6);

            }

            else {

              uStack_214 = (int)(((float)uStack_214 / fVar6) * fVar7);

            }

            (**(code **)(**(int **)(param_1 + 0x56c) + 0x130))(&iStack_218);

            (**(code **)(**(int **)(param_1 + 0x56c) + 0x110))(&stack0xfffffddc);

          }

        }

        goto LAB_008bb8b6;

      }

      local_210 = local_210 & 0xff00;

      pcVar2 = (char *)((int)&uStack_214 + 3);

      do {

        pcVar4 = pcVar2;

        pcVar2 = pcVar4 + 1;

      } while (pcVar4[1] != '\0');

      *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = s_sec_unknown_dds_00a3970c._0_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar4 + 5) = s_sec_unknown_dds_00a3970c._4_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar4 + 9) = s_sec_unknown_dds_00a3970c._8_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar4 + 0xd) = s_sec_unknown_dds_00a3970c._12_4_;

    }

    (**(code **)(**(int **)(param_1 + 0x56c) + 0x50))(&local_210,1,0);

  }

LAB_008bb8b6:

  if (*(int *)(param_1 + 0x574) == 0) {

    return;

  }

  FUN_004ce750(&local_210);

  puVar8 = &local_210;

  uVar9 = 0xffffffff;

  FUN_007b6a20(puVar8,0xffffffff);

  cVar1 = FUN_007b6730(puVar8,uVar9);

  if (cVar1 == '\0') {

    local_210 = local_210 & 0xff00;

    pcVar2 = (char *)((int)&uStack_214 + 3);

    do {

      pcVar4 = pcVar2;

      pcVar2 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = s_sec_unknown_bird_dds_00a4686c._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 5) = s_sec_unknown_bird_dds_00a4686c._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 9) = s_sec_unknown_bird_dds_00a4686c._8_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 0xd) = s_sec_unknown_bird_dds_00a4686c._12_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 0x11) = s_sec_unknown_bird_dds_00a4686c._16_4_;

    pcVar4[0x15] = s_sec_unknown_bird_dds_00a4686c[0x14];

  }

LAB_008bb9c6:

  (**(code **)(**(int **)(param_1 + 0x574) + 0x50))(&local_210,1,0);

  return;

}
