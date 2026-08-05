# Raw capture: FUN_006ee9c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ee9c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ee9c0` |
| **Canonical name** | `FUN_006ee9c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
FUN_006ee9c0(int param_1,undefined4 param_2,int *param_3,undefined4 param_4,int *param_5)

{
  float *pfVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  iVar4 = *(int *)(*param_5 + 4);
  local_8 = param_3[2];
  local_4 = param_3;
  local_c = param_3[1];
  local_10 = *(undefined4 *)(*param_3 + 0xc);
  (**(code **)(**(int **)(param_1 + 0xc) + 0x10))(&local_10,param_2,param_4,param_5);
  piVar2 = (int *)*param_5;
  if (iVar4 < piVar2[1]) {
    iVar3 = iVar4 * 0x30;
    do {
      pfVar1 = (float *)(*piVar2 + 0x10 + iVar3);
      iVar4 = iVar4 + 1;
      *pfVar1 = -*(float *)(*piVar2 + 0x10 + iVar3);
      iVar3 = iVar3 + 0x30;
      pfVar1[1] = -pfVar1[1];
      pfVar1[2] = -pfVar1[2];
      pfVar1[3] = -pfVar1[3];
      piVar2 = (int *)*param_5;
    } while (iVar4 < piVar2[1]);
  }
  return;
}
```
