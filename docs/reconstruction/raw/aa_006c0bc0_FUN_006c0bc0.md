# Raw capture: FUN_006c0bc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c0bc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c0bc0` |
| **Canonical name** | `FUN_006c0bc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined1 *
FUN_006c0b20(undefined1 *param_1,int param_2,undefined4 *param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 local_7d;
  char local_7c [4];
  undefined4 local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined1 local_20 [28];
  
  local_78 = *(undefined4 *)(param_2 + 0x14);
  local_7c[0] = '\0';
  local_5c = 0;
  local_58 = 0;
  local_54 = -0x80000000;
  local_68 = 0;
  local_64 = 0;
  local_60 = -0x80000000;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0x80000000;
  if (0 < param_4) {
    do {
      if (local_70 == (local_6c & 0x7fffffff)) {
        FUN_005b3370(&local_74,0x10);
      }
      uVar2 = *param_3;
      uVar3 = param_3[1];
      uVar4 = param_3[2];
      uVar5 = param_3[3];
      puVar6 = (undefined4 *)(local_70 * 0x10 + local_74);
      local_70 = local_70 + 1;
      param_3 = param_3 + 4;
      param_4 = param_4 + -1;
      *puVar6 = uVar2;
      puVar6[1] = uVar3;
      puVar6[2] = uVar4;
      puVar6[3] = uVar5;
    } while (param_4 != 0);
  }
  FUN_006bb1c0(param_6,local_40,local_50);
  FUN_006bb1c0(&local_74,local_20,local_30);
  FUN_006bd1c0(&local_7d,param_2,param_5,param_6,&local_68,&local_5c,local_7c);
  if (local_7c[0] == '\0') {
    puVar7 = (undefined1 *)
             FUN_006c0950(&local_7d,&local_74,param_5,param_6,&local_68,&local_5c,local_78);
  }
  else {
    puVar7 = (undefined1 *)
             FUN_006c0850(&local_7d,&local_74,param_5,param_6,&local_68,&local_5c,local_78);
  }
  uVar1 = *puVar7;
  FUN_006bb3a0(param_6,local_40,local_50);
  FUN_006bb3a0(&local_74,local_20,local_30);
  *param_1 = uVar1;
  if (-1 < (int)local_6c) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_74,local_6c << 4,0x12);
  }
  if (-1 < local_60) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_68,local_60 << 4,0x12);
  }
  if (-1 < local_54) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_5c,local_54 << 5,0x12);
  }
  return param_1;
}
```
