# Raw capture: FUN_007afcf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007afcf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007afcf0` |
| **Canonical name** | `FUN_007afcf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007afcf0(int param_1)

{
  int iVar1;
  undefined4 extraout_EDX;
  float10 fVar2;
  float10 fVar3;
  undefined4 uVar4;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if ((*(int *)(param_1 + 0x298) != 0) && (*(float *)(param_1 + 0x13c) != g_flZero)) {
    FUN_0076f5f0(param_1 + 0x240,param_1 + 0x240);
    FUN_0076f5f0(&local_1c,extraout_EDX);
    fVar2 = (float10)*(float *)(param_1 + 0x13c) * (float10)DAT_00a0f298;
    fVar3 = (float10)fsin(fVar2);
    uVar4 = 3;
    local_10 = (float)((float10)local_1c * fVar3);
    local_c = (float)((float10)local_18 * fVar3);
    local_8 = (float)((float10)local_14 * fVar3);
    fVar2 = (float10)fcos(fVar2);
    local_4 = (float)fVar2;
    (**(code **)(**(int **)(param_1 + 0x298) + 0x10))(3,&local_10);
    FUN_0040d1a0(uVar4);
    iVar1 = (**(code **)(**(int **)(param_1 + 0x298) + 0x10))(3);
    FUN_0076df50(iVar1 + 0x80,iVar1 + 0x80,&local_18);
    *(undefined4 *)(iVar1 + 0xbc) = 0xffffffff;
    *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + 1;
  }
  return;
}
```
