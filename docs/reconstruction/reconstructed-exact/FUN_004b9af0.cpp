// =============================================================================
// FUN_004b9af0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b9af0
// Address:   0x004b9af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b9af0 @ 0x004b9af0
// Stable ID: aa_004b9af0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~175 non-empty decompiler lines.
//  - Control keywords: if×10, do×5, while×5, return×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable, FUN_0049cc30, FUN_004a6930, FUN_004b7e50, FUN_004b9300, FUN_004b9af0, FUN_004ba6f0, FUN_00590240.
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

void __thiscall FUN_004b9af0(int param_1,int *param_2)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  int iVar17;

  int iStack_6c;

  float fStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  float fStack_38;

  float local_34;

  float fStack_30;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  uint8_t local_10 [4];

  int *piStack_c;

  

  if (param_2 != (int *)0x0) {

    *(uint8_t *)(param_1 + 4) = 1;

    FUN_004b9300(*(int *)(param_2[1] + 4) + 4 + (int)param_2);

    (**(code **)(*(int *)(*(int *)(param_2[1] + 4) + 4 + (int)param_2) + 0x108))

              (0,&local_34,local_10,0);

    fVar9 = (fStack_1c * fStack_20 - fStack_18 * fStack_14) * g_flLevelUpUiBase_Inferred;

    fVar10 = g_flOne - (fStack_20 * fStack_20 + fStack_18 * fStack_18) * g_flLevelUpUiBase_Inferred;

    fVar15 = (fStack_14 * fStack_20 + fStack_1c * fStack_18) * g_flLevelUpUiBase_Inferred;

    fVar11 = (fStack_1c * fStack_18 - fStack_14 * fStack_20) * g_flLevelUpUiBase_Inferred;

    fVar14 = (fStack_18 * fStack_20 + fStack_1c * fStack_14) * g_flLevelUpUiBase_Inferred;

    fVar16 = g_flOne - (fStack_1c * fStack_1c + fStack_20 * fStack_20) * g_flLevelUpUiBase_Inferred;

    fVar13 = g_flOne - (fStack_1c * fStack_1c + fStack_18 * fStack_18) * g_flLevelUpUiBase_Inferred;

    fVar8 = (fStack_18 * fStack_14 + fStack_1c * fStack_20) * g_flLevelUpUiBase_Inferred;

    fVar12 = (fStack_18 * fStack_20 - fStack_1c * fStack_14) * g_flLevelUpUiBase_Inferred;

    piVar5 = (int *)**(int **)(param_1 + 0x1e0);

    if (piVar5 != *(int **)(param_1 + 0x1e0)) {

      fStack_38 = 0.0;

      local_34 = 0.0;

      fStack_30 = 0.0;

      do {

        iVar17 = piVar5[2];

        *(float *)(iVar17 + 0x880) = fStack_44;

        *(uint32_t /* width from decompiler */ *)(iVar17 + 0x884) = uStack_40;

        *(uint32_t /* width from decompiler */ *)(iVar17 + 0x888) = uStack_3c;

        *(float *)(iVar17 + 0x88c) = fVar14;

        *(float *)(iVar17 + 0x890) = fVar11;

        *(float *)(iVar17 + 0x894) = fVar16;

        *(float *)(iVar17 + 0x898) = fVar13;

        *(float *)(iVar17 + 0x89c) = fVar8;

        *(float *)(iVar17 + 0x8a0) = fVar12;

        *(float *)(iVar17 + 0x8a4) = fVar9;

        *(float *)(iVar17 + 0x8a8) = fVar10;

        *(float *)(iVar17 + 0x8ac) = fVar15;

        *(uint32_t /* width from decompiler */ *)(iVar17 + 0x8b0) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar17 + 0x8b4) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar17 + 0x8b8) = 0;

        piVar5 = (int *)*piVar5;

      } while (piVar5 != (int *)*(int *)(param_1 + 0x1e0));

    }

    piVar5 = (int *)**(int **)(param_1 + 0x204);

    iVar17 = 0;

    if (piVar5 != *(int **)(param_1 + 0x204)) {

      do {

        iVar7 = piVar5[2];

        if ((*(byte *)(iVar7 + 0x90e) & 0x40) != 0) {

          FUN_0049cc30(iVar7,*(int *)(*(int *)(param_2[1] + 4) + 0xac + (int)param_2) + 0x188);

        }

        *(float *)(iVar7 + 0x824) = fStack_44;

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x828) = uStack_40;

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x82c) = uStack_3c;

        *(float *)(iVar7 + 0x830) = fVar14;

        *(float *)(iVar7 + 0x834) = fVar11;

        *(float *)(iVar7 + 0x838) = fVar16;

        *(float *)(iVar7 + 0x83c) = fVar13;

        *(float *)(iVar7 + 0x840) = fVar8;

        *(float *)(iVar7 + 0x844) = fVar12;

        *(float *)(iVar7 + 0x848) = fVar9;

        *(float *)(iVar7 + 0x84c) = fVar10;

        *(float *)(iVar7 + 0x850) = fVar15;

        FUN_00590240(&fStack_20,param_2);

        if ((*(byte *)(iVar7 + 0x90e) & 0x20) != 0) {

          iVar17 = piVar5[2];

        }

        piVar5 = (int *)*piVar5;

      } while (piVar5 != (int *)*(int *)(param_1 + 0x204));

    }

    piVar5 = (int *)**(int **)(param_1 + 0x210);

    if (piVar5 != *(int **)(param_1 + 0x210)) {

      do {

        iVar7 = piVar5[2];

        pfVar1 = (float *)(iVar7 + 0x104);

        *pfVar1 = fStack_44;

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x108) = uStack_40;

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x10c) = uStack_3c;

        fVar2 = *(float *)(iVar7 + 0x130);

        *(float *)(iVar7 + 0xe0) = fVar14;

        *(float *)(iVar7 + 0xe4) = fVar11;

        *(float *)(iVar7 + 0xe8) = fVar16;

        fVar3 = *(float *)(iVar7 + 0x128);

        *(float *)(iVar7 + 0xec) = fVar13;

        *(float *)(iVar7 + 0xf0) = fVar8;

        *(float *)(iVar7 + 0xf4) = fVar12;

        *(float *)(iVar7 + 0xf8) = fVar9;

        *(float *)(iVar7 + 0xfc) = fVar10;

        *(float *)(iVar7 + 0x100) = fVar15;

        fVar4 = *(float *)(iVar7 + 300);

        fStack_28 = *(float *)(iVar7 + 0xfc) * fVar4;

        fStack_24 = *(float *)(iVar7 + 0x100) * fVar4;

        fStack_38 = *(float *)(iVar7 + 0xec) * fVar3 + *(float *)(iVar7 + 0xf8) * fVar4 +

                    *(float *)(iVar7 + 0xe0) * fVar2;

        *(float *)(iVar7 + 0x134) = fStack_38;

        local_34 = *(float *)(iVar7 + 0xf0) * fVar3 + fStack_28 + *(float *)(iVar7 + 0xe4) * fVar2;

        *(float *)(iVar7 + 0x138) = local_34;

        fStack_30 = *(float *)(iVar7 + 0xf4) * fVar3 + fStack_24 + *(float *)(iVar7 + 0xe8) * fVar2;

        *(float *)(iVar7 + 0x13c) = fStack_30;

        *pfVar1 = *(float *)(iVar7 + 0x134) + *pfVar1;

        *(float *)(iVar7 + 0x108) = *(float *)(iVar7 + 0x138) + *(float *)(iVar7 + 0x108);

        *(float *)(iVar7 + 0x10c) = *(float *)(iVar7 + 0x13c) + *(float *)(iVar7 + 0x10c);

        piVar5 = (int *)*piVar5;

        param_2 = piStack_c;

        param_1 = iStack_6c;

      } while (piVar5 != (int *)*(int *)(iStack_6c + 0x210));

    }

    piVar5 = (int *)**(int **)(param_1 + 0x21c);

    if (piVar5 != *(int **)(param_1 + 0x21c)) {

      do {

        iVar7 = piVar5[2];

        puVar6 = (uint32_t /* width from decompiler */ *)FUN_004a6930(&fStack_44);

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x2c) = *puVar6;

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x30) = puVar6[1];

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x34) = puVar6[2];

        puVar6 = (uint32_t /* width from decompiler */ *)FUN_004ba6f0(&fStack_20);

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x38) = *puVar6;

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x3c) = puVar6[1];

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x40) = puVar6[2];

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x44) = puVar6[3];

        piVar5 = (int *)*piVar5;

      } while (piVar5 != (int *)*(int *)(param_1 + 0x21c));

    }

    if ((*(int *)(param_1 + 0x1f0) != 0) &&

       (piVar5 = (int *)**(int **)(param_1 + 0x1ec), piVar5 != *(int **)(param_1 + 0x1ec))) {

      do {

        iVar7 = piVar5[2];

        Client_GetMissionCompleteAudioTable(iVar7);

        FUN_00722dc0(iVar7);

        piVar5 = (int *)*piVar5;

      } while (piVar5 != (int *)*(int *)(param_1 + 0x1ec));

    }

    if (((*(int *)(*(int *)(param_2[1] + 4) + 0xb0 + (int)param_2) == 0) ||

        (iVar7 = (**(code **)(*(int *)(*(int *)(param_2[1] + 4) + 4 + (int)param_2) + 0x1d4))(),

        iVar7 != 0)) ||

       (iVar7 = (**(code **)(*(int *)(*(int *)(param_2[1] + 4) + 4 + (int)param_2) + 0x1d8))(),

       iVar7 != 0)) {

      FUN_004b7e50(1,param_2,0,0,0,0);

    }

    if (iVar17 != 0) {

      (**(code **)(*param_2 + 0x30))(iVar17);

    }

  }

  return;

}
