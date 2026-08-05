// =============================================================================
// Net_UnpackGhostUpdate
// -----------------------------------------------------------------------------
// Stable ID: aa_0060a820
// Address:   0x0060a820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Net_UnpackGhostUpdate @ 0x0060a820
// Stable ID: aa_0060a820
// Embedded strings (evidence for future rename):
//   - "unpacking update from net %I64d for ghost %d, %d, %I64d"
//   - "Updated %I64d, %.2f %.2f %.2f - %.1f %.1f %.1f %.1f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~362 non-empty decompiler lines.
//  - Control keywords: if×30, for×1, return×1.
//  - Notable callees: BitStream_readBits×28, BitStream_readInt×5, FUN_0042ba90×3, BitStream_readFlag×2, FUN_007971b0×2, FUN_007a4480×2, CONCAT11, CONCAT31.
//  - Strings: "unpacking update from net %I64d for ghost %d, %d, %I64d"; "Updated %I64d, %.2f %.2f %.2f - %.1f %.1f %.1f %.1f".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "unpacking update from net %I64d for ghost %d, %d, %I64d"
 * Domain alias of FUN_0060a820 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Net_UnpackGhostUpdate(int *param_1,int param_2,int param_3)



{

  byte bVar1;

  uint8_t uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  uint uVar7;

  uint64_t uVar8;

  short local_14c [3];

  char local_146;

  char local_145;

  int *local_144;

  int *piStack_140;

  uint32_t /* width from decompiler */ uStack_13c;

  char local_134;

  char local_133;

  char local_132;

  char local_131;

  int *piStack_130;

  uint32_t /* width from decompiler */ uStack_12c;

  int *local_124;

  uint local_120;

  float fStack_11c;

  int *local_118;

  uint32_t /* width from decompiler */ local_114;

  int *piStack_110;

  int *piStack_10c;

  int *piStack_108;

  int *piStack_104;

  int *piStack_100;

  float fStack_fc;

  int *piStack_f8;

  int *piStack_e8;

  int *piStack_e4;

  int *piStack_e0;

  int *piStack_dc;

  int *piStack_d8;

  int *piStack_d0;

  int *piStack_cc;

  int *piStack_c8;

  uint8_t auStack_b8 [24];

  int *piStack_a0;

  float fStack_9c;

  int *piStack_98;

  int *piStack_94;

  int *piStack_90;

  int *piStack_8c;

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  float fStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  uint32_t /* width from decompiler */ uStack_70;

  int *piStack_68;

  int *piStack_64;

  int *piStack_60;

  int *piStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint8_t local_44;

  uint8_t local_12;

  

  local_124 = param_1;

  if (DAT_00d02a30 != '\0') {

    uVar8 = *(uint64_t *)(param_1 + 0x10);

    uVar7 = (uint)DAT_00d1798c;

    uVar3 = FUN_00780a80(param_1);

    FUN_007a4480(0xffffffff,"unpacking update from net %I64d for ghost %d, %d, %I64d",

                 *(uint32_t /* width from decompiler */ *)(param_2 + 0x238),*(uint32_t /* width from decompiler */ *)(param_2 + 0x23c),uVar3,uVar7,uVar8

                );

  }

  if (DAT_00d1798c != 0) {

    FUN_00609f80();

    iVar4 = param_1[0x17];

    FUN_005b1360(param_3,iVar4);

    param_1[0x10] = *(int *)(iVar4 + 0x90);

    param_1[0x11] = *(int *)(iVar4 + 0x94);

    param_1[0x12] = *(int *)(iVar4 + 0x98);

    param_1[0x13] = *(int *)(iVar4 + 0x9c);

    FUN_0042ba90();

    FUN_0042ba90();

    BitStream_readBits(8,&local_146);

    *(char *)(iVar4 + 0x128) = local_146;

    BitStream_readBits(0x40,&local_118);

    *(int **)(iVar4 + 0xd8) = local_118;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xdc) = local_114;

    BitStream_readBits(0x10,local_14c);

    *(int *)(iVar4 + 0xe8) = (int)local_14c[0];

    BitStream_readBits(0x10,local_14c);

    *(int *)(iVar4 + 0xec) = (int)local_14c[0];

    BitStream_readBits(0x10,local_14c);

    *(int *)(iVar4 + 0xf0) = (int)local_14c[0];

    BitStream_readBits(0x10,local_14c);

    *(int *)(iVar4 + 0xf4) = (int)local_14c[0];

    BitStream_readBits(0x10,local_14c);

    *(int *)(iVar4 + 0xfc) = (int)local_14c[0];

    BitStream_readBits(0x10,local_14c);

    *(int *)(iVar4 + 0x100) = (int)local_14c[0];

    BitStream_readBits(0x10,local_14c);

    *(int *)(iVar4 + 0x104) = (int)local_14c[0];

    BitStream_readBits(0x10,local_14c);

    *(int *)(iVar4 + 0xf8) = (int)local_14c[0];

    BitStream_readBits(0x20,&local_120);

    *(uint *)(iVar4 + 0x1a0) = local_120;

    uVar3 = BitStream_readInt();

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x108) = uVar3;

    uVar3 = BitStream_readInt();

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x10c) = uVar3;

    uVar3 = BitStream_readInt();

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x118) = uVar3;

    uVar3 = BitStream_readInt();

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x114) = uVar3;

    FUN_005b2690(param_3,0);

  }

  piVar6 = (int *)0x0;

  local_144 = (int *)0x0;

  if ((int *)param_1[0x14] == (int *)0x0) {

    if ((char)param_1[0x15] == '\0') {

      (**(code **)(*param_1 + 0xc))();

      *(uint8_t *)(param_1 + 0x15) = 1;

    }

  }

  else {

    piVar6 = (int *)(**(code **)(*(int *)param_1[0x14] + 0x1d8))();

    local_144 = piVar6;

  }

  uVar7 = *(uint *)(param_3 + 0x18);

  local_134 = '\0';

  local_145 = '\0';

  local_133 = '\0';

  local_131 = '\0';

  local_132 = '\0';

  local_146 = '\0';

  local_44 = 0;

  local_12 = 0;

  local_120 = local_120 & 0xffffff00;

  if (*(uint *)(param_3 + 0x2c) < uVar7) {

    *(uint8_t *)(param_3 + 0x1c) = 1;

  }

  else {

    bVar1 = *(byte *)((uVar7 >> 3) + *(int *)(param_3 + 0xc));

    *(uint *)(param_3 + 0x18) = uVar7 + 1;

    param_1 = local_124;

    piVar6 = local_144;

    if ((bVar1 & (byte)(1 << ((byte)uVar7 & 7))) != 0) {

      local_133 = '\x01';

      uVar2 = BitStream_readInt();

      local_14c[0] = CONCAT11(local_14c[0]._1_1_,uVar2);

      param_1 = local_124;

      piVar6 = local_144;

      if (DAT_00d1798c != 0) {

        *(uint8_t *)(local_124[0x17] + 0x12a) = uVar2;

      }

    }

  }

  uVar7 = *(uint *)(param_3 + 0x18);

  if (*(uint *)(param_3 + 0x2c) < uVar7) {

    *(uint8_t *)(param_3 + 0x1c) = 1;

  }

  else {

    bVar1 = *(byte *)((uVar7 >> 3) + *(int *)(param_3 + 0xc));

    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;

    piVar6 = local_144;

    piStack_130 = param_1;

    if ((bVar1 & (byte)(1 << ((byte)uVar7 & 7))) != 0) {

      local_132 = '\x01';

      BitStream_readBits(0x20,&piStack_130);

      piStack_e4 = piStack_130;

      BitStream_readBits(0x20,&piStack_130);

      local_118 = piStack_130;

      FUN_0042ba90();

      piVar6 = local_144;

    }

  }

  uVar7 = *(uint *)(param_3 + 0x18);

  if (*(uint *)(param_3 + 0x2c) < uVar7) {

    *(uint8_t *)(param_3 + 0x1c) = 1;

  }

  else {

    bVar1 = *(byte *)((uVar7 >> 3) + *(int *)(param_3 + 0xc));

    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;

    piVar6 = local_144;

    piStack_130 = param_1;

    if ((bVar1 & (byte)(1 << ((byte)uVar7 & 7))) != 0) {

      local_131 = '\x01';

      BitStream_readBits(0x10,&piStack_130);

      piStack_e8 = piStack_130;

      piVar6 = local_144;

      if (DAT_00d1798c != 0) {

        param_1[0x20] = (int)(short)piStack_130;

      }

    }

  }

  uVar7 = *(uint *)(param_3 + 0x18);

  if (*(uint *)(param_3 + 0x2c) < uVar7) {

    *(uint8_t *)(param_3 + 0x1c) = 1;

  }

  else {

    bVar1 = *(byte *)((uVar7 >> 3) + *(int *)(param_3 + 0xc));

    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;

    piVar6 = local_144;

    piStack_130 = param_1;

    if ((bVar1 & (byte)(1 << ((byte)uVar7 & 7))) != 0) {

      local_134 = '\x01';

      BitStream_readBits(0x20,&local_124);

      piStack_100 = local_124;

      BitStream_readBits(0x20,&fStack_11c);

      fStack_fc = fStack_11c;

      BitStream_readBits(0x20,&piStack_130);

      piStack_f8 = piStack_130;

      BitStream_readBits(0x20,&piStack_140);

      piStack_110 = piStack_140;

      BitStream_readBits(0x20,&piStack_140);

      piStack_10c = piStack_140;

      BitStream_readBits(0x20,&piStack_140);

      piStack_108 = piStack_140;

      BitStream_readBits(0x20,&piStack_140);

      piStack_104 = piStack_140;

      BitStream_readBits(0x20,&piStack_140);

      piStack_d0 = piStack_140;

      BitStream_readBits(0x20,&piStack_140);

      piStack_cc = piStack_140;

      BitStream_readBits(0x20,&piStack_140);

      piStack_c8 = piStack_140;

      BitStream_readBits(0x20,&piStack_140);

      piStack_e0 = piStack_140;

      BitStream_readBits(0x20,&piStack_140);

      piStack_dc = piStack_140;

      BitStream_readBits(0x20,&piStack_140);

      piStack_d8 = piStack_140;

      piVar6 = local_144;

      if (DAT_00d1798c != 0) {

        iVar4 = param_1[0x17];

        *(int **)(iVar4 + 100) = local_124;

        *(float *)(iVar4 + 0x68) = fStack_11c;

        *(int **)(iVar4 + 0x6c) = piStack_130;

        FUN_007971b0();

        piVar6 = local_144;

      }

    }

  }

  uVar7 = *(uint *)(param_3 + 0x18);

  if (*(uint *)(param_3 + 0x2c) < uVar7) {

    *(uint8_t *)(param_3 + 0x1c) = 1;

  }

  else {

    bVar1 = *(byte *)((uVar7 >> 3) + *(int *)(param_3 + 0xc));

    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;

    if ((bVar1 & (byte)(1 << ((byte)uVar7 & 7))) != 0) {

      local_145 = '\x01';

      BitStream_readBits(0x40,&piStack_130);

      piStack_140 = piStack_130;

      uStack_13c = uStack_12c;

      BitStream_readFlag();

    }

  }

  uVar7 = *(uint *)(param_3 + 0x18);

  if (*(uint *)(param_3 + 0x2c) < uVar7) {

    *(uint8_t *)(param_3 + 0x1c) = 1;

  }

  else {

    bVar1 = *(byte *)((uVar7 >> 3) + *(int *)(param_3 + 0xc));

    *(uint *)(param_3 + 0x18) = uVar7 + 1;

    piVar6 = local_144;

    if ((bVar1 & (byte)(1 << ((byte)uVar7 & 7))) != 0) {

      local_146 = '\x01';

      BitStream_readFlag();

      piVar6 = local_144;

    }

  }

  if (piVar6 != (int *)0x0) {

    iVar4 = (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x1dc))();

    if (local_133 != '\0') {

      *(uint *)(iVar4 + 0x634) = *(uint *)(iVar4 + 0x634) | 1;

      *(uint *)(iVar4 + 0x6b4) = (uint)(byte)local_14c[0];

    }

    if (local_131 != '\0') {

      FUN_00524680();

      FUN_00522f70();

    }

    if (local_132 != '\0') {

      FUN_00521480();

      FUN_005214b0();

      FUN_00521440();

    }

    if ((*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xa8 + iVar4) + 0xe8a0) == 0) ||

       (iVar5 = (**(code **)(**(int **)(*(int *)(*(int *)(piVar6[1] + 4) + 0xa8 + (int)piVar6) +

                                       0xe8a0) + 0x1dc))(), iVar4 != iVar5)) {

      if (local_134 == '\0') {

        if (local_145 != '\0') {

          CVOGReaction_ResolveObjectTarget();

          FUN_005172d0();

        }

      }

      else {

        piStack_98 = (int *)0x0;

        fStack_9c = 0.0;

        piStack_a0 = (int *)0x0;

        piStack_8c = (int *)0x0;

        piStack_90 = (int *)0x0;

        piStack_94 = (int *)0x0;

        uStack_80 = 0;

        uStack_84 = 0;

        uStack_88 = 0;

        fStack_7c = g_flMsToSeconds_Inferred;

        uStack_70 = 0;

        uStack_74 = 0;

        uStack_78 = 0;

        piStack_60 = (int *)0x0;

        piStack_64 = (int *)0x0;

        piStack_68 = (int *)0x0;

        FUN_007971b0();

        piStack_a0 = piStack_100;

        fStack_9c = fStack_fc;

        piStack_98 = piStack_f8;

        piStack_68 = piStack_e0;

        piStack_64 = piStack_dc;

        piStack_60 = piStack_d8;

        piStack_94 = piStack_d0;

        piStack_90 = piStack_cc;

        piStack_8c = piStack_c8;

        if (local_145 == '\0') {

          iVar4 = *(int *)(*(int *)(piVar6[1] + 4) + 0xa4 + (int)piVar6);

          if (iVar4 == 0) {

            piStack_58 = DAT_009df5b0;

            uStack_50 = DAT_009df5b8;

            uStack_4c = DAT_009df5bc;

            uStack_54 = DAT_009df5b4;

          }

          else {

            piStack_58 = *(int **)(iVar4 + 0x160);

            uStack_54 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164);

            uStack_50 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x168);

            uStack_4c = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x16c);

          }

        }

        else {

          uStack_50 = CONCAT31(uStack_50._1_3_,piStack_130._0_1_);

          piStack_58 = piStack_140;

          uStack_54 = uStack_13c;

        }

        (**(code **)(*piVar6 + 0x78))

                  (auStack_b8,*(float *)(param_2 + 0xbc) * g_flMsToSeconds_Inferred);

      }

      if (local_146 != '\0') {

        FUN_005208e0();

      }

    }

    if (DAT_00d02a30 != '\0') {

      FUN_007a4480(0xffffffff,"Updated %I64d, %.2f %.2f %.2f - %.1f %.1f %.1f %.1f",

                   *(uint32_t /* width from decompiler */ *)(*(int *)(piVar6[1] + 4) + 0x164 + (int)piVar6),

                   *(uint32_t /* width from decompiler */ *)(*(int *)(piVar6[1] + 4) + 0x168 + (int)piVar6),

                   (double)(float)piStack_100,(double)fStack_fc,(double)(float)piStack_f8,

                   (double)(float)piStack_110,(double)(float)piStack_10c,(double)(float)piStack_108,

                   (double)(float)piStack_104);

    }

  }

  return;

}
