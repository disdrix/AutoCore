// =============================================================================
// FUN_00590cb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00590cb0
// Address:   0x00590cb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00590cb0 @ 0x00590cb0
// Stable ID: aa_00590cb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×10, goto×3, do×2, while×2, return×2.
//  - Notable callees: CONCAT31×3, FUN_004ed470, FUN_00567ce0, FUN_00590cb0, FUN_005d3ef0, FUN_005d4240, FUN_005e1c80.
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

int FUN_00590cb0(byte *param_1,float param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,float param_5)



{

  float *pfVar1;

  byte bVar2;

  byte *pbVar3;

  int iVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ unaff_EBX;

  undefined3 uVar6;

  uint3 uVar7;

  byte *pbVar8;

  bool bVar9;

  uint32_t /* width from decompiler */ local_120;

  uint32_t /* width from decompiler */ local_11c;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ local_114;

  uint32_t /* width from decompiler */ local_110;

  float local_10c;

  uint32_t /* width from decompiler */ local_108;

  uint32_t /* width from decompiler */ local_104;

  int iStack_f4;

  uint8_t local_f0 [16];

  uint8_t local_e0 [8];

  uint32_t /* width from decompiler */ uStack_d8;

  uint32_t /* width from decompiler */ local_d4;

  int iStack_d0;

  int local_cc;

  void *pvStack_20;

  void *local_1c;

  uint8_t *puStack_18;

  int local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a5904;

  local_1c = ExceptionList;

  ExceptionList = &local_1c;

  FUN_005e1c80();

  local_14 = 0;

  uVar5 = 0;

  do {

    if ((DAT_00b04e34 == 0) || ((uint)(DAT_00b04e38 - DAT_00b04e34 >> 2) <= uVar5))

    goto LAB_00590eae;

    pbVar3 = *(byte **)(DAT_00b04e34 + uVar5 * 4);

    pfVar1 = (float *)(pbVar3 + 0x170);

    pbVar8 = param_1;

    do {

      bVar2 = *pbVar3;

      uVar6 = (undefined3)((uint)unaff_EBX >> 8);

      unaff_EBX = CONCAT31(uVar6,bVar2);

      bVar9 = bVar2 < *pbVar8;

      if (bVar2 != *pbVar8) {

LAB_00590d3c:

        iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);

        goto LAB_00590d41;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar3[1];

      unaff_EBX = CONCAT31(uVar6,bVar2);

      bVar9 = bVar2 < pbVar8[1];

      if (bVar2 != pbVar8[1]) goto LAB_00590d3c;

      pbVar3 = pbVar3 + 2;

      pbVar8 = pbVar8 + 2;

    } while (bVar2 != 0);

    iVar4 = 0;

LAB_00590d41:

    if (iVar4 == 0) {

      if (*(int *)(*(int *)(uVar5 * 4 + DAT_00b04e34) + 0x108) != 0) {

        if (param_2 == *pfVar1) {

          FUN_005d3ef0(local_e0);

          iStack_f4 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

          *(uint16_t *)(iStack_f4 + 4) = 0xa0;

          local_14._0_1_ = 1;

          iVar4 = FUN_005d4240(local_e0);

          local_14 = (uint)local_14._1_3_ << 8;

        }

        else {

          uVar7 = (uint3)((uint)unaff_EBX >> 8);

          if (param_5 == 0.0) {

            iVar4 = CONCAT31(uVar7,1);

          }

          else {

            iVar4 = (uint)uVar7 << 8;

          }

          local_110 = 0;

          local_10c = g_flOne;

          local_108 = 0;

          local_104 = 0;

          FUN_00567ce0(&local_110,0x38d1b717);

          local_120 = 0;

          local_11c = 0;

          local_118 = 0;

          local_114 = 0;

          iVar4 = FUN_004ed470(*(int *)(uVar5 * 4 + DAT_00b04e34) + 0x100,param_2,param_3,param_4,

                               iVar4,&local_120,local_f0,0,0xffffffff);

        }

        (**(code **)(**(int **)(iVar4 + 0x3c) + 0x1c))(param_5);

        puStack_18 = (uint8_t *)0xffffffff;

        if (-1 < iStack_d0) {

          (**(code **)(*DAT_00b05060 + 0x14))(uStack_d8,iStack_d0 * 8,0x12);

        }

        ExceptionList = pvStack_20;

        return iVar4;

      }

LAB_00590eae:

      local_14 = 0xffffffff;

      if (-1 < local_cc) {

        (**(code **)(*DAT_00b05060 + 0x14))(local_d4,local_cc * 8,0x12);

      }

      ExceptionList = local_1c;

      return 0;

    }

    uVar5 = uVar5 + 1;

  } while( true );

}
