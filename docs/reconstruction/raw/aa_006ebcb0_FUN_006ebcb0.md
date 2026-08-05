# Raw capture: FUN_006ebcb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ebcb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ebcb0` |
| **Canonical name** | `FUN_006ebcb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006ebcb0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  char cVar2;
  undefined1 local_159;
  undefined4 local_158;
  undefined4 local_154;
  undefined1 local_150 [256];
  int *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 *local_3c;
  undefined4 *local_38;
  int *local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 *local_1c;
  int local_14;
  
  FUN_00404d00(DAT_00bc5644 < DAT_00bc5648);
  cVar2 = FUN_00404cf0();
  if (cVar2 != '\0') {
    local_1c = DAT_00bc5644;
    *DAT_00bc5644 = "LtBvTree";
    uVar1 = rdtsc();
    local_20 = (undefined4)uVar1;
    DAT_00bc5644[1] = local_20;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  FUN_006ea6f0(param_1,param_2,param_3,&LAB_006ea160);
  FUN_00404d00(DAT_00bc5644 < DAT_00bc5648);
  cVar2 = FUN_00404cf0();
  if (cVar2 != '\0') {
    local_28 = DAT_00bc5644;
    *DAT_00bc5644 = "StNarrowPhase";
    uVar1 = rdtsc();
    local_2c = (undefined4)uVar1;
    DAT_00bc5644[1] = local_2c;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  local_30 = *(undefined4 **)(local_14 + 0xc);
  local_34 = (int *)(local_14 + 0xc);
  local_38 = (undefined4 *)(*(int *)(local_14 + 0x10) * 0xc + *local_34);
  local_3c = param_2;
  local_40 = param_2[2];
  local_4c = *param_2;
  local_50 = (int *)FUN_00428050();
  for (; local_30 != local_38; local_30 = local_30 + 3) {
    local_154 = (**(code **)(*local_50 + 0x34))(*local_30,local_150);
    local_158 = *local_30;
    local_48 = local_154;
    local_44 = local_158;
    (**(code **)(*(int *)local_30[2] + 4))(param_1,&local_48,param_3,param_4);
    FUN_006e7740(&local_159);
    cVar2 = FUN_00404cf0();
    if (cVar2 != '\0') break;
  }
  FUN_00404d00(DAT_00bc5644 < DAT_00bc5648);
  cVar2 = FUN_00404cf0();
  if (cVar2 != '\0') {
    *DAT_00bc5644 = &DAT_009d282c;
    uVar1 = rdtsc();
    DAT_00bc5644[1] = (int)uVar1;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
```
