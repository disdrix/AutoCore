// =============================================================================
// Net_UnpackGhostUpdate_005b17b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b17b0
// Address:   0x005b17b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Net_UnpackGhostUpdate_005b17b0 @ 0x005b17b0
// Stable ID: aa_005b17b0
// Embedded strings (evidence for future rename):
//   - "unpacking update from net %I64d for ghost %d, %d, %I64d"
//   - "Unpacking initial update for object %I64d"
//   - "Updated %I64d, %.2f %.2f %.2f - %.1f %.1f %.1f %.1f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~295 non-empty decompiler lines.
//  - Control keywords: if×28, for×2, return×1.
//  - Notable callees: BitStream_readBits×15, BitStream_readInt×3, FUN_007a4480×3, FUN_00424e50×2, FUN_007971b0×2, CONCAT31, FUN_004c00f0, FUN_004d0e90.
//  - Strings: "unpacking update from net %I64d for ghost %d, %d, %I64d"; "Unpacking initial update for object %I64d"; "Updated %I64d, %.2f %.2f %.2f - %.1f %.1f %.1f %.1f".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "unpacking update from net %I64d for ghost %d, %d, %I64d"
 * Domain alias of FUN_005b17b0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Net_UnpackGhostUpdate_005b17b0(int *param_1,int param_2,int param_3)



{

  uint *puVar1;

  byte bVar2;

  int iVar3;

  uint8_t uVar4;

  char cVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  int *piVar8;

  bool bVar9;

  uint uVar10;

  uint64_t uVar11;

  char cStack_ed;

  bool bStack_e9;

  float fStack_e8;

  uint32_t /* width from decompiler */ uStack_e4;

  char local_db;

  char local_da;

  char local_d9;

  int *local_d8;

  int *local_d4;

  float fStack_d0;

  float fStack_cc;

  float fStack_c8;

  float fStack_c0;

  float fStack_bc;

  float fStack_b8;

  float fStack_b4;

  float local_b0;

  float local_ac;

  float local_a8;

  uint32_t /* width from decompiler */ local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  uint32_t /* width from decompiler */ local_94;

  int local_88;

  int local_84;

  float fStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  float fStack_58;

  float fStack_54;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  

  local_d8 = param_1;

  if (DAT_00b051e0 != '\0') {

    uVar11 = *(uint64_t *)(param_1 + 0x10);

    uVar10 = (uint)DAT_00d1798c;

    uVar6 = FUN_00780a80(param_1);

    FUN_007a4480(0xffffffff,"unpacking update from net %I64d for ghost %d, %d, %I64d",

                 *(uint32_t /* width from decompiler */ *)(param_2 + 0x238),*(uint32_t /* width from decompiler */ *)(param_2 + 0x23c),uVar6,uVar10,

                 uVar11);

  }

  if (DAT_00d1798c != 0) {

    uVar10 = *(uint *)(param_3 + 0x18);

    if (*(uint *)(param_3 + 0x2c) < uVar10) {

      *(uint8_t *)(param_3 + 0x1c) = 1;

      bVar9 = false;

    }

    else {

      bVar9 = (*(byte *)((uVar10 >> 3) + *(int *)(param_3 + 0xc)) & (byte)(1 << ((byte)uVar10 & 7)))

              != 0;

      *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;

      local_d4 = param_1;

    }

    *(bool *)(param_1 + 0x12) = bVar9;

    if (bVar9 == false) {

      FUN_005b0e30();

      iVar7 = BitStream_readInt();

      local_84 = 0;

    }

    else {

      BitStream_readBits(0x40,&local_88);

      iVar7 = local_88;

    }

    iVar3 = param_1[0x17];

    param_1[0x10] = iVar7;

    param_1[0x11] = local_84;

    if (iVar3 != 0) {

      *(int *)(iVar3 + 0x90) = iVar7;

      *(int *)(iVar3 + 0x94) = local_84;

      *(char *)(param_1[0x17] + 0x98) = (char)param_1[0x12];

    }

    if (DAT_00b051e0 != '\0') {

      FUN_007a4480(0xffffffff,"Unpacking initial update for object %I64d",param_1[0x10],

                   param_1[0x11]);

    }

  }

  piVar8 = (int *)0x0;

  if ((int *)param_1[0x14] == (int *)0x0) {

    if ((char)param_1[0x15] == '\0') {

      (**(code **)(*param_1 + 0xc))();

      *(uint8_t *)(param_1 + 0x15) = 1;

    }

  }

  else {

    piVar8 = (int *)(**(code **)(*(int *)param_1[0x14] + 0x1c8))();

  }

  uVar10 = *(uint *)(param_3 + 0x18);

  local_da = '\0';

  local_db = '\0';

  local_b0 = DAT_00b051f0;

  local_ac = DAT_00b051f4;

  local_a8 = DAT_00b051f8;

  local_a4 = DAT_00b051fc;

  local_a0 = DAT_00b051f0;

  local_9c = DAT_00b051f4;

  local_98 = DAT_00b051f8;

  local_94 = DAT_00b051fc;

  local_d9 = '\0';

  if (*(uint *)(param_3 + 0x2c) < uVar10) {

    *(uint8_t *)(param_3 + 0x1c) = 1;

  }

  else {

    bVar2 = *(byte *)((uVar10 >> 3) + *(int *)(param_3 + 0xc));

    *(uint *)(param_3 + 0x18) = uVar10 + 1;

    param_1 = local_d8;

    if ((bVar2 & (byte)(1 << ((byte)uVar10 & 7))) != 0) {

      local_db = '\x01';

      local_d4 = (int *)BitStream_readInt();

      uVar10 = *(uint *)(param_3 + 0x18);

      if (*(uint *)(param_3 + 0x2c) < uVar10) {

        *(uint8_t *)(param_3 + 0x1c) = 1;

        bStack_e9 = false;

      }

      else {

        bStack_e9 = (*(byte *)((uVar10 >> 3) + *(int *)(param_3 + 0xc)) &

                    (byte)(1 << ((byte)uVar10 & 7))) != 0;

        *(uint *)(param_3 + 0x18) = uVar10 + 1;

        if ((bStack_e9) && (local_d9 = FUN_00424e50(), local_d9 != '\0')) {

          local_88 = BitStream_readInt();

          BitStream_readBits(0x40,&fStack_e8);

          uStack_7c = uStack_e4;

          fStack_80 = fStack_e8;

          uVar4 = FUN_00424e50();

          uStack_78 = CONCAT31(uStack_78._1_3_,uVar4);

        }

      }

      param_1 = local_d8;

      if ((DAT_00d1798c != 0) && (local_d8[0x17] != 0)) {

        *(int **)(local_d8[0x17] + 0x10) = local_d4;

        *(bool *)(local_d8[0x17] + 0x8a) = bStack_e9;

      }

    }

  }

  uVar10 = *(uint *)(param_3 + 0x18);

  if (*(uint *)(param_3 + 0x2c) < uVar10) {

    *(uint8_t *)(param_3 + 0x1c) = 1;

  }

  else {

    bVar2 = *(byte *)((uVar10 >> 3) + *(int *)(param_3 + 0xc));

    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;

    if ((bVar2 & (byte)(1 << ((byte)uVar10 & 7))) != 0) {

      local_da = '\x01';

      BitStream_readBits(0x20,&fStack_e8);

      fStack_d0 = fStack_e8;

      BitStream_readBits(0x20,&fStack_e8);

      fStack_cc = fStack_e8;

      BitStream_readBits(0x20,&fStack_e8);

      fStack_c8 = fStack_e8;

      BitStream_readBits(0x20,&fStack_e8);

      fStack_c0 = fStack_e8;

      BitStream_readBits(0x20,&fStack_e8);

      fStack_bc = fStack_e8;

      BitStream_readBits(0x20,&fStack_e8);

      fStack_b8 = fStack_e8;

      BitStream_readBits(0x20,&fStack_e8);

      uVar10 = *(uint *)(param_3 + 0x18);

      fStack_b4 = fStack_e8;

      if (*(uint *)(param_3 + 0x2c) < uVar10) {

        *(uint8_t *)(param_3 + 0x1c) = 1;

      }

      else {

        bVar2 = *(byte *)((uVar10 >> 3) + *(int *)(param_3 + 0xc));

        *(uint *)(param_3 + 0x18) = uVar10 + 1;

        param_1 = local_d8;

        if ((bVar2 & (byte)(1 << ((byte)uVar10 & 7))) != 0) {

          BitStream_readBits(0x20,&fStack_e8);

          local_a0 = fStack_e8;

          BitStream_readBits(0x20,&fStack_e8);

          local_9c = fStack_e8;

          BitStream_readBits(0x20,&fStack_e8);

          local_98 = fStack_e8;

          param_1 = local_d8;

        }

      }

      uVar10 = *(uint *)(param_3 + 0x18);

      if (*(uint *)(param_3 + 0x2c) < uVar10) {

        *(uint8_t *)(param_3 + 0x1c) = 1;

      }

      else {

        bVar2 = *(byte *)((uVar10 >> 3) + *(int *)(param_3 + 0xc));

        *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;

        if ((bVar2 & (byte)(1 << ((byte)uVar10 & 7))) != 0) {

          BitStream_readBits(0x20,&fStack_e8);

          local_b0 = fStack_e8;

          BitStream_readBits(0x20,&fStack_e8);

          local_ac = fStack_e8;

          BitStream_readBits(0x20,&fStack_e8);

          local_a8 = fStack_e8;

        }

      }

      if ((DAT_00d1798c != 0) && (iVar7 = param_1[0x17], iVar7 != 0)) {

        *(float *)(iVar7 + 100) = fStack_d0;

        *(float *)(iVar7 + 0x68) = fStack_cc;

        *(float *)(iVar7 + 0x6c) = fStack_c8;

        FUN_007971b0();

      }

    }

  }

  if (piVar8 != (int *)0x0) {

    if (local_db != '\0') {

      (**(code **)(*(int *)(*(int *)(piVar8[1] + 4) + 4 + (int)piVar8) + 0x240))();

      cVar5 = (**(code **)(*(int *)(*(int *)(piVar8[1] + 4) + 4 + (int)piVar8) + 0x198))();

      if ((cVar5 == '\0') || (cStack_ed != '\0')) {

        cVar5 = (**(code **)(*(int *)(*(int *)(piVar8[1] + 4) + 4 + (int)piVar8) + 0x198))();

        if ((cVar5 == '\0') && (bStack_e9 != false)) {

          if (local_d9 == '\0') {

            *(uint32_t /* width from decompiler */ *)(*(int *)(piVar8[1] + 4) + 0xd0 + (int)piVar8) = 0;

          }

          else {

            (**(code **)(*(int *)(*(int *)(piVar8[1] + 4) + 4 + (int)piVar8) + 600))

                      (fStack_80,uStack_7c,uStack_78,uStack_74);

            *(int *)(*(int *)(piVar8[1] + 4) + 0xd0 + (int)piVar8) = local_88;

          }

          FUN_004d0e90();

        }

        else {

          puVar1 = (uint *)((int)piVar8 + *(int *)(piVar8[1] + 4) + 0x180);

          *puVar1 = *puVar1 ^ ((uint)bStack_e9 << 8 ^

                              *(uint *)((int)piVar8 + *(int *)(piVar8[1] + 4) + 0x180)) & 0x100;

        }

      }

      else {

        FUN_0053dd40();

        iVar7 = (**(code **)(*(int *)(*(int *)(piVar8[1] + 4) + 4 + (int)piVar8) + 0x1cc))();

        if (iVar7 != 0) {

          (**(code **)(*(int *)((int)piVar8 + *(int *)(piVar8[1] + 4) + 4) + 0x1cc))();

          FUN_004c00f0();

        }

      }

    }

    if (local_da != '\0') {

      fStack_50 = 0.0;

      fStack_54 = 0.0;

      fStack_58 = 0.0;

      fStack_44 = 0.0;

      fStack_48 = 0.0;

      fStack_4c = 0.0;

      uStack_38 = 0;

      uStack_3c = 0;

      uStack_40 = 0;

      fStack_34 = g_flMsToSeconds_Inferred;

      fStack_28 = 0.0;

      fStack_2c = 0.0;

      fStack_30 = 0.0;

      uStack_18 = 0;

      uStack_1c = 0;

      uStack_20 = 0;

      FUN_007971b0();

      fStack_58 = fStack_d0;

      fStack_54 = fStack_cc;

      fStack_50 = fStack_c8;

      fStack_30 = local_b0;

      fStack_2c = local_ac;

      fStack_28 = local_a8;

      fStack_4c = local_a0;

      fStack_48 = local_9c;

      fStack_44 = local_98;

      (**(code **)(*piVar8 + 0x24))();

    }

    if (DAT_00b051e0 != '\0') {

      FUN_007a4480(0xffffffff,"Updated %I64d, %.2f %.2f %.2f - %.1f %.1f %.1f %.1f",

                   *(uint32_t /* width from decompiler */ *)(param_1[0x14] + 0x160),*(uint32_t /* width from decompiler */ *)(param_1[0x14] + 0x164),

                   (double)fStack_d0,(double)fStack_cc,(double)fStack_c8,(double)fStack_c0,

                   (double)fStack_bc,(double)fStack_b8,(double)fStack_b4);

    }

  }

  return;

}
