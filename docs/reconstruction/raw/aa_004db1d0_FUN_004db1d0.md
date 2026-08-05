# Raw capture: FUN_004db1d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004db1d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004db1d0` |
| **Canonical name** | `FUN_004db1d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004db1d0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  float afStack_180 [6];
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  float fStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined1 local_140 [16];
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined1 auStack_100 [12];
  undefined4 uStack_f4;
  int iStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_68;
  undefined4 uStack_64;
  float fStack_60;
  undefined1 uStack_58;
  undefined1 auStack_40 [32];
  undefined4 uStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a22ec;
  local_1c = ExceptionList;
  if (*(int *)(param_1 + 0xe4f8) != 0) {
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 0xe4f8) + 0x18);
    ExceptionList = &local_1c;
    local_110 = uVar3;
    FUN_006c7d30();
    local_120 = *(undefined4 *)(*(int *)(param_1 + 0xe4f8) + 0x10);
    local_11c = *(undefined4 *)(*(int *)(param_1 + 0xe4f8) + 0x14);
    local_130 = local_110;
    local_12c = DAT_00a0f520;
    local_124 = 0;
    local_118 = 0;
    local_114 = DAT_00a0f520;
    local_128 = uVar3;
    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x70,0x22);
    *(undefined2 *)(iVar2 + 4) = 0x70;
    uStack_14 = 0;
    uVar3 = FUN_005a5b30(local_140,*(undefined4 *)(*(int *)(param_1 + 0xe4f8) + 0x3e0));
    *(undefined4 *)(param_1 + 0xe4e0) = uVar3;
    *(undefined4 *)(*(int *)(param_1 + 0xe4f8) + 0x3d8) = uVar3;
    piVar1 = *(int **)(param_1 + 0xe4e0);
    uStack_14 = 0xffffffff;
    if ((piVar1 != (int *)0x0) && (piVar1[0x18] != 0)) {
      afStack_180[3] = 0.0;
      afStack_180[2] = 0.0;
      afStack_180[1] = 0.0;
      uStack_164 = 0;
      uStack_168 = 0;
      afStack_180[4] = 0.0;
      uStack_154 = 0;
      uStack_15c = 0;
      uStack_160 = 0;
      afStack_180[0] = g_flOne;
      afStack_180[5] = g_flOne;
      fStack_158 = g_flOne;
      uStack_144 = 0;
      uStack_148 = 0;
      uStack_14c = 0;
      uStack_150 = 0;
      (**(code **)(*piVar1 + 0x18))(afStack_180,0x3dcccccd,auStack_40);
      FUN_005e1c80();
      uStack_108 = *(undefined4 *)(param_1 + 0xe4e0);
      iStack_ec = DAT_00b03800;
      uStack_e8 = DAT_00b03804;
      uStack_e4 = DAT_00b03808;
      uStack_e0 = DAT_00b0380c;
      uStack_64 = 0;
      uStack_68 = 0;
      fStack_60 = g_flOne;
      uStack_10c = 6;
      uStack_58 = 7;
      uStack_20 = 1;
      iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);
      *(undefined2 *)(iVar2 + 4) = 0xa0;
      uStack_14._0_1_ = 2;
      uVar3 = FUN_005d4240(auStack_100);
      uStack_14._0_1_ = 1;
      *(undefined4 *)(param_1 + 0xe4e4) = uVar3;
      FUN_00560ec0(uVar3);
      if (*(int *)(DAT_00b037f0 + 4) != 0) {
        pvVar4 = operator_new(0x18);
        uStack_14._0_1_ = 3;
        if (pvVar4 == (void *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_004e7540(*(undefined4 *)(DAT_00b037f0 + 4),*(undefined4 *)(param_1 + 0xe4f8));
        }
        uStack_14 = CONCAT31(uStack_14._1_3_,1);
        FUN_004b4d90(uVar3);
      }
      uStack_14 = 0xffffffff;
      if (-1 < iStack_ec) {
        (**(code **)(*DAT_00b05060 + 0x14))(uStack_f4,iStack_ec * 8,0x12);
      }
    }
  }
  ExceptionList = local_1c;
  return;
}
```
