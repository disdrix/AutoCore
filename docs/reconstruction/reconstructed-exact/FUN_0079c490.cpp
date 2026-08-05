// =============================================================================
// FUN_0079c490
// -----------------------------------------------------------------------------
// Stable ID: aa_0079c490
// Address:   0x0079c490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079c490 @ 0x0079c490
// Stable ID: aa_0079c490
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: CONCAT12, CONCAT13, CONCAT21, CONCAT31, FUN_00758460, FUN_0079c490.
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

void __fastcall FUN_0079c490(int *param_1)



{

  uint uVar1;

  byte *pbVar2;

  uint uVar3;

  byte bVar4;

  int *piVar5;

  int iVar6;

  undefined *puVar7;

  uint uStack_30;

  uint32_t /* width from decompiler */ *puStack_2c;

  int *piStack_28;

  float *pfStack_24;

  uint32_t /* width from decompiler */ local_18;

  float fStack_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if (*(char *)((int)param_1 + 0x22b) != '\0') {

    if (param_1[0xa5] == 0) {

      pfStack_24 = &local_8;

      if (*(char *)((int)param_1 + 0x48d) == '\0') {

        local_10 = 0.0;

        local_c = 0.0;

        piStack_28 = (int *)0x79c636;

        piVar5 = (int *)(**(code **)(*param_1 + 0x140))();

        local_10 = (float)*piVar5;

        piStack_28 = (int *)0x1;

        puStack_2c = (uint32_t /* width from decompiler */ *)&stack0xffffffe0;

        uStack_30 = 0x79c651;

        iVar6 = (**(code **)(*param_1 + 0x140))();

        local_4 = (float)*(int *)(iVar6 + 4);

      }

      else {

        piStack_28 = (int *)0x79c58a;

        piVar5 = (int *)(**(code **)(*param_1 + 0x140))();

        local_10 = (float)*piVar5 * (float)param_1[0x131];

        piStack_28 = (int *)0x1;

        puStack_2c = &local_18;

        uStack_30 = 0x79c5ad;

        iVar6 = (**(code **)(*param_1 + 0x140))();

        fStack_14 = (float)*(int *)(iVar6 + 4) * (float)param_1[0x131];

        uStack_30 = 1;

        piVar5 = (int *)(**(code **)(*param_1 + 0x140))(&stack0xffffffe0);

        piStack_28 = (int *)((g_flOne - (float)param_1[0x131]) * (float)*piVar5);

        iVar6 = (**(code **)(*param_1 + 0x140))(&uStack_30,1);

        local_c = (float)*(int *)(iVar6 + 4) * (g_flOne - (float)param_1[0x131]);

      }

    }

    else {

      local_8 = (float)param_1[0x5e];

      if (*(char *)((int)param_1 + 0x48d) == '\0') {

        local_10 = 0.0;

        local_4 = (float)param_1[0x5f];

        local_c = 0.0;

      }

      else {

        local_8 = local_8 * (float)param_1[0x131];

        local_4 = (float)param_1[0x5f] * (float)param_1[0x131];

        pfStack_24 = &local_10;

        piStack_28 = (int *)0x79c4fa;

        piVar5 = (int *)(**(code **)(*param_1 + 0x140))();

        piStack_28 = (int *)0x1;

        puStack_2c = (uint32_t /* width from decompiler */ *)&stack0xffffffe0;

        local_18 = (g_flOne - (float)param_1[0x131]) * (float)*piVar5;

        uStack_30 = 0x79c529;

        iVar6 = (**(code **)(*param_1 + 0x140))();

        local_c = (float)*(int *)(iVar6 + 4) * (g_flOne - (float)param_1[0x131]);

      }

    }

    uVar1 = param_1[0x8a];

    local_18 = (float)uVar1;

    if (param_1[0x89] != 0) {

      pbVar2 = (byte *)param_1[0x89];

      local_18._3_1_ = (byte)(uVar1 >> 0x18);

      bVar4 = local_18._3_1_;

      local_18._0_3_ =

           CONCAT12((char)(((uint)pbVar2[2] * (uVar1 >> 0x10 & 0xff)) / 0xff),(short)uVar1);

      uVar3 = (uint)(uint3)local_18;

      uVar1 = (uint)(uint3)local_18;

      local_18 = (float)CONCAT31(CONCAT21(local_18._2_2_,

                                          (char)(((uint)pbVar2[1] * ((uVar3 & 0xff00) >> 8)) / 0xff)

                                         ),(char)(((uVar1 & 0xff) * (uint)*pbVar2) / 0xff));

      local_18 = (float)CONCAT13((char)(((uint)pbVar2[3] * (uint)bVar4) / 0xff),(uint3)local_18);

    }

    local_c = local_c + (float)param_1[0x9a];

    puVar7 = (undefined *)param_1[0xa5];

    local_10 = local_10 + (float)param_1[0x99];

    local_8 = (float)param_1[0x9b] + local_8 + (float)param_1[0x99];

    local_4 = (float)param_1[0x9c] + local_4 + (float)param_1[0x9a];

    pfStack_24 = (float *)0x0;

    if (puVar7 == (undefined *)0x0) {

      piStack_28 = (int *)0x0;

      iVar6 = 0;

      puVar7 = &DAT_00d1ec78;

    }

    else if (*(char *)((int)param_1 + 0xd7) == '\0') {

      piStack_28 = (int *)0x0;

      iVar6 = param_1[0x86];

    }

    else {

      piStack_28 = param_1 + 0x60;

      iVar6 = param_1[0x86];

    }

    puStack_2c = (uint32_t /* width from decompiler */ *)0x1;

    uStack_30 = (uint)local_18;

    FUN_00758460(local_10,local_c,local_8,local_4,puVar7,iVar6);

    if (((char)param_1[0x77] != '\0') && (0 < param_1[0x78])) {

      (**(code **)(*param_1 + 0x198))();

    }

  }

  return;

}
