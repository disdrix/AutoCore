# Raw capture: GhostCreature_UnpackUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d2e40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d2e40` |
| **Canonical name** | `GhostCreature_UnpackUpdate` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* GhostCreature::unpackUpdate
   
   Applies PositionMask XYZ from server as-is (no terrain/foot correction).
   Initial update also packs enhancement/triggers/level/skills. */

void __thiscall GhostCreature_UnpackUpdate(int *param_1,int param_2,int param_3)

{
  uint *puVar1;
  byte bVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  uint uVar8;
  undefined8 uVar9;
  byte local_10b;
  undefined1 uStack_10a;
  char local_109;
  float fStack_108;
  undefined4 uStack_104;
  char local_fd;
  byte bStack_fc;
  char local_fb;
  char local_fa;
  char local_f9;
  int *local_f8;
  int *local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  float fStack_e8;
  undefined4 uStack_e4;
  float fStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  int *piStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  undefined1 auStack_90 [24];
  int *piStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  float fStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_f4 = param_1;
  if (DAT_00bc5590 != '\0') {
    uVar9 = *(undefined8 *)(param_1 + 0x10);
    uVar8 = (uint)DAT_00d1798c;
    uVar4 = FUN_00780a80(param_1);
    FUN_007a4480(0xffffffff,"unpacking update from net %I64d for ghost %d, %d, %I64d",
                 *(undefined4 *)(param_2 + 0x238),*(undefined4 *)(param_2 + 0x23c),uVar4,uVar8,uVar9
                );
  }
  if (DAT_00d1798c == 0) goto LAB_005d316e;
  FUN_005d2520();
  iVar5 = param_1[0x17];
  FUN_005b1360(param_3,iVar5);
  bVar7 = DAT_00bc5590 != '\0';
  param_1[0x10] = *(int *)(iVar5 + 0x90);
  param_1[0x11] = *(int *)(iVar5 + 0x94);
  param_1[0x12] = *(int *)(iVar5 + 0x98);
  param_1[0x13] = *(int *)(iVar5 + 0x9c);
  if (bVar7) {
    FUN_007a4480(0xffffffff,"Unpacking initial update for creature %I64d",param_1[0x10],
                 param_1[0x11]);
  }
  uVar8 = *(uint *)(param_3 + 0x18);
  if (*(uint *)(param_3 + 0x2c) < uVar8) {
    *(undefined1 *)(param_3 + 0x1c) = 1;
LAB_005d2f0a:
    *(undefined4 *)(iVar5 + 0xd8) = 0xffffffff;
  }
  else {
    bVar2 = *(byte *)((uVar8 >> 3) + *(int *)(param_3 + 0xc));
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
    if ((bVar2 & (byte)(1 << ((byte)uVar8 & 7))) == 0) goto LAB_005d2f0a;
    uVar4 = BitStream_readInt();
    *(undefined4 *)(iVar5 + 0xd8) = uVar4;
  }
  uVar8 = *(uint *)(param_3 + 0x18);
  if (*(uint *)(param_3 + 0x2c) < uVar8) {
    *(undefined1 *)(param_3 + 0x1c) = 1;
LAB_005d2f24:
    *(undefined4 *)(iVar5 + 0x128) = 0xffffffff;
  }
  else {
    bVar2 = *(byte *)((uVar8 >> 3) + *(int *)(param_3 + 0xc));
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
    if ((bVar2 & (byte)(1 << ((byte)uVar8 & 7))) == 0) goto LAB_005d2f24;
    uVar4 = BitStream_readInt();
    *(undefined4 *)(iVar5 + 0x128) = uVar4;
  }
  uVar8 = *(uint *)(param_3 + 0x18);
  if (*(uint *)(param_3 + 0x2c) < uVar8) {
    *(undefined1 *)(param_3 + 0x1c) = 1;
LAB_005d2f3e:
    *(undefined4 *)(iVar5 + 300) = 0xffffffff;
  }
  else {
    bVar2 = *(byte *)((uVar8 >> 3) + *(int *)(param_3 + 0xc));
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
    if ((bVar2 & (byte)(1 << ((byte)uVar8 & 7))) == 0) goto LAB_005d2f3e;
    uVar4 = BitStream_readInt();
    *(undefined4 *)(iVar5 + 300) = uVar4;
  }
  uVar8 = *(uint *)(param_3 + 0x18);
  if (*(uint *)(param_3 + 0x2c) < uVar8) {
    *(undefined1 *)(param_3 + 0x1c) = 1;
LAB_005d2f58:
    *(float *)(iVar5 + 0xe0) = DAT_009da9e0;
    *(undefined4 *)(iVar5 + 0xe4) = DAT_009da9e4;
    *(undefined4 *)(iVar5 + 0xe8) = DAT_009da9e8;
    *(undefined4 *)(iVar5 + 0xec) = DAT_009da9ec;
  }
  else {
    bVar2 = *(byte *)((uVar8 >> 3) + *(int *)(param_3 + 0xc));
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
    if ((bVar2 & (byte)(1 << ((byte)uVar8 & 7))) == 0) goto LAB_005d2f58;
    BitStream_readBits(0x40,&local_f0);
    *(undefined4 *)(iVar5 + 0xe0) = local_f0;
    *(undefined4 *)(iVar5 + 0xe4) = local_ec;
    BitStream_readFlag();
  }
  uVar8 = *(uint *)(param_3 + 0x18);
  if (*(uint *)(param_3 + 0x2c) < uVar8) {
    *(undefined1 *)(param_3 + 0x1c) = 1;
LAB_005d2f8f:
    *(undefined4 *)(iVar5 + 0x108) = 0xffffffff;
  }
  else {
    bVar2 = *(byte *)((uVar8 >> 3) + *(int *)(param_3 + 0xc));
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
    if ((bVar2 & (byte)(1 << ((byte)uVar8 & 7))) == 0) goto LAB_005d2f8f;
    BitStream_readBits(0x40,&local_f0);
    *(undefined4 *)(iVar5 + 0x108) = local_f0;
  }
  uVar8 = *(uint *)(param_3 + 0x18);
  if (*(uint *)(param_3 + 0x2c) < uVar8) {
    *(undefined1 *)(param_3 + 0x1c) = 1;
    bVar7 = false;
  }
  else {
    bVar7 = (*(byte *)((uVar8 >> 3) + *(int *)(param_3 + 0xc)) & (byte)(1 << ((byte)uVar8 & 7))) !=
            0;
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
  }
  *(bool *)(iVar5 + 0xf0) = !bVar7;
  BitStream_readBits(8,&local_10b);
  *(uint *)(iVar5 + 0x114) = (uint)local_10b;
  BitStream_readFlag();
  param_1 = local_f4;
  FUN_005b2690(param_3,0);
LAB_005d316e:
  piVar6 = (int *)0x0;
  local_f8 = (int *)0x0;
  if ((int *)param_1[0x14] == (int *)0x0) {
    if ((char)param_1[0x15] == '\0') {
      (**(code **)(*param_1 + 0xc))();
      *(undefined1 *)(param_1 + 0x15) = 1;
    }
  }
  else {
    piVar6 = (int *)(**(code **)(*(int *)param_1[0x14] + 0x1d8))();
    local_f8 = piVar6;
  }
  uVar8 = *(uint *)(param_3 + 0x18);
  local_10b = 0;
  local_109 = '\0';
  local_fb = '\0';
  local_f9 = '\0';
  local_fd = '\0';
  local_fa = '\0';
  if (*(uint *)(param_3 + 0x2c) < uVar8) {
    *(undefined1 *)(param_3 + 0x1c) = 1;
  }
  else {
    bVar2 = *(byte *)((uVar8 >> 3) + *(int *)(param_3 + 0xc));
    *(uint *)(param_3 + 0x18) = uVar8 + 1;
    piVar6 = local_f8;
    if ((bVar2 & (byte)(1 << ((byte)uVar8 & 7))) != 0) {
      local_fa = '\x01';
      BitStream_readBits(0x40,&uStack_d8);
      local_f0 = uStack_d8;
      local_ec = uStack_d4;
      piVar6 = local_f8;
      if (DAT_00d1798c != 0) {
        iVar5 = local_f4[0x17];
        *(undefined4 *)(iVar5 + 0x130) = uStack_d8;
        *(undefined4 *)(iVar5 + 0x134) = uStack_d4;
      }
    }
  }
  uVar8 = *(uint *)(param_3 + 0x18);
  if (*(uint *)(param_3 + 0x2c) < uVar8) {
    *(undefined1 *)(param_3 + 0x1c) = 1;
  }
  else {
    bVar2 = *(byte *)((uVar8 >> 3) + *(int *)(param_3 + 0xc));
    *(uint *)(param_3 + 0x18) = uVar8 + 1;
    if ((bVar2 & (byte)(1 << ((byte)uVar8 & 7))) != 0) {
      local_fb = '\x01';
      uStack_dc = BitStream_readInt();
      uVar8 = *(uint *)(param_3 + 0x18);
      if (*(uint *)(param_3 + 0x2c) < uVar8) {
        *(undefined1 *)(param_3 + 0x1c) = 1;
        bStack_fc = false;
      }
      else {
        bStack_fc = (*(byte *)((uVar8 >> 3) + *(int *)(param_3 + 0xc)) &
                    (byte)(1 << ((byte)uVar8 & 7))) != 0;
        *(uint *)(param_3 + 0x18) = uVar8 + 1;
      }
      if (DAT_00d1798c != 0) {
        *(undefined4 *)(local_f4[0x17] + 0x10) = uStack_dc;
        *(byte *)(local_f4[0x17] + 0x8a) = bStack_fc;
      }
    }
  }
  uVar8 = *(uint *)(param_3 + 0x18);
  if (*(uint *)(param_3 + 0x2c) < uVar8) {
    *(undefined1 *)(param_3 + 0x1c) = 1;
  }
  else {
    bVar2 = *(byte *)((uVar8 >> 3) + *(int *)(param_3 + 0xc));
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
    if ((bVar2 & (byte)(1 << ((byte)uVar8 & 7))) != 0) {
      local_f9 = '\x01';
      uStack_d8 = BitStream_readInt();
    }
  }
  uVar8 = *(uint *)(param_3 + 0x18);
  if (*(uint *)(param_3 + 0x2c) < uVar8) {
    *(undefined1 *)(param_3 + 0x1c) = 1;
  }
  else {
    bVar2 = *(byte *)((uVar8 >> 3) + *(int *)(param_3 + 0xc));
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
    if ((bVar2 & (byte)(1 << ((byte)uVar8 & 7))) != 0) {
      local_fd = '\x01';
      BitStream_readBits(8,&uStack_10a);
      if (DAT_00d1798c != 0) {
        *(undefined1 *)(local_f4[0x17] + 0x127) = uStack_10a;
      }
    }
  }
  uVar8 = *(uint *)(param_3 + 0x18);
  if (*(uint *)(param_3 + 0x2c) < uVar8) {
    *(undefined1 *)(param_3 + 0x1c) = 1;
  }
  else {
    bVar2 = *(byte *)((uVar8 >> 3) + *(int *)(param_3 + 0xc));
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
    if ((bVar2 & (byte)(1 << ((byte)uVar8 & 7))) != 0) {
      local_10b = 1;
      BitStream_readBits(0x20,&local_f8);
      piStack_c0 = local_f8;
      BitStream_readBits(0x20,&fStack_e0);
      fStack_bc = fStack_e0;
      BitStream_readBits(0x20,&fStack_e8);
      fStack_b8 = fStack_e8;
      BitStream_readBits(0x20,&fStack_108);
      fStack_d0 = fStack_108;
      BitStream_readBits(0x20,&fStack_108);
      fStack_cc = fStack_108;
      BitStream_readBits(0x20,&fStack_108);
      fStack_c8 = fStack_108;
      BitStream_readBits(0x20,&fStack_108);
      fStack_c4 = fStack_108;
      BitStream_readBits(0x20,&fStack_108);
      fStack_b0 = fStack_108;
      BitStream_readBits(0x20,&fStack_108);
      fStack_ac = fStack_108;
      BitStream_readBits(0x20,&fStack_108);
      fStack_a8 = fStack_108;
      BitStream_readBits(0x20,&fStack_108);
      fStack_a0 = fStack_108;
      BitStream_readBits(0x20,&fStack_108);
      fStack_9c = fStack_108;
      BitStream_readBits(0x20,&fStack_108);
      fStack_98 = fStack_108;
      if (DAT_00d1798c != 0) {
        iVar5 = local_f4[0x17];
        *(int **)(iVar5 + 100) = local_f8;
        *(float *)(iVar5 + 0x68) = fStack_e0;
        *(float *)(iVar5 + 0x6c) = fStack_e8;
        FUN_007971b0();
      }
    }
  }
  uVar8 = *(uint *)(param_3 + 0x18);
  if (*(uint *)(param_3 + 0x2c) < uVar8) {
    *(undefined1 *)(param_3 + 0x1c) = 1;
  }
  else {
    bVar2 = *(byte *)((uVar8 >> 3) + *(int *)(param_3 + 0xc));
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
    if ((bVar2 & (byte)(1 << ((byte)uVar8 & 7))) != 0) {
      local_109 = '\x01';
      BitStream_readBits(0x40,&fStack_e8);
      fStack_108 = fStack_e8;
      uStack_104 = uStack_e4;
      BitStream_readFlag();
    }
  }
  if ((piVar6 != (int *)0x0) &&
     (((piVar3 = *(int **)(*(int *)(*(int *)(piVar6[1] + 4) + 0xa8 + (int)piVar6) + 0xe8a0),
       piVar3 == (int *)0x0 ||
       (iVar5 = (**(code **)(*piVar3 + 0x1dc))(), *(char *)(iVar5 + 0x6b9) == '\0')) ||
      (local_f4[0x14] !=
       *(int *)(*(int *)(*(int *)(*(int *)(piVar6[1] + 4) + 0xa8 + (int)piVar6) + 0xe8a0) + 0xa0))))
     ) {
    if (local_fa != '\0') {
      uStack_18 = CONCAT31(uStack_18._1_3_,1);
      (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 600))
                (local_f0,local_ec,uStack_18,uStack_14);
    }
    if (local_fb != '\0') {
      (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x240))();
      puVar1 = (uint *)((int)piVar6 + *(int *)(piVar6[1] + 4) + 0x180);
      *puVar1 = *puVar1 ^ ((uint)bStack_fc << 8 ^
                          *(uint *)((int)piVar6 + *(int *)(piVar6[1] + 4) + 0x180)) & 0x100;
    }
    if (local_f9 != '\0') {
      (**(code **)(*(int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6) + 0x248))();
    }
    if (local_fd != '\0') {
      *(undefined1 *)(piVar6 + 0x9b) = uStack_10a;
    }
    if (local_10b == 0) {
      if (local_109 != '\0') {
        CVOGReaction_ResolveObjectTarget();
        FUN_005172d0();
      }
    }
    else {
      fStack_70 = 0.0;
      fStack_74 = 0.0;
      piStack_78 = (int *)0x0;
      fStack_64 = 0.0;
      fStack_68 = 0.0;
      fStack_6c = 0.0;
      uStack_58 = 0;
      uStack_5c = 0;
      uStack_60 = 0;
      fStack_54 = g_flMsToSeconds_Inferred;
      uStack_48 = 0;
      uStack_4c = 0;
      uStack_50 = 0;
      fStack_38 = 0.0;
      fStack_3c = 0.0;
      fStack_40 = 0.0;
      FUN_007971b0();
      piStack_78 = piStack_c0;
      fStack_74 = fStack_bc;
      fStack_70 = fStack_b8;
      fStack_40 = fStack_a0;
      fStack_3c = fStack_9c;
      fStack_38 = fStack_98;
      fStack_6c = fStack_b0;
      fStack_68 = fStack_ac;
      fStack_64 = fStack_a8;
      if (local_109 == '\0') {
        iVar5 = *(int *)(*(int *)(piVar6[1] + 4) + 0xa4 + (int)piVar6);
        if (iVar5 == 0) {
          fStack_30 = DAT_009da9e0;
          uStack_28 = DAT_009da9e8;
          uStack_24 = DAT_009da9ec;
          uStack_2c = DAT_009da9e4;
        }
        else {
          fStack_30 = *(float *)(iVar5 + 0x160);
          uStack_2c = *(undefined4 *)(iVar5 + 0x164);
          uStack_28 = *(undefined4 *)(iVar5 + 0x168);
          uStack_24 = *(undefined4 *)(iVar5 + 0x16c);
        }
      }
      else {
        uStack_28 = CONCAT31(uStack_28._1_3_,fStack_e8._0_1_);
        fStack_30 = fStack_108;
        uStack_2c = uStack_104;
      }
      (**(code **)(*piVar6 + 0x78))
                (auStack_90,*(float *)(param_2 + 0xbc) * g_flMsToSeconds_Inferred);
    }
    if (DAT_00bc5590 != '\0') {
      FUN_007a4480(0xffffffff,"Updated %I64d, %.2f %.2f %.2f - %.1f %.1f %.1f %.1f",
                   *(undefined4 *)(*(int *)(piVar6[1] + 4) + 0x164 + (int)piVar6),
                   *(undefined4 *)(*(int *)(piVar6[1] + 4) + 0x168 + (int)piVar6),
                   (double)(float)piStack_c0,(double)fStack_bc,(double)fStack_b8,(double)fStack_d0,
                   (double)fStack_cc,(double)fStack_c8,(double)fStack_c4);
    }
  }
  return;
}
```
