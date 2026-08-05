# Raw capture: FUN_005c7cd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c7cd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005c7cd0` |
| **Canonical name** | `FUN_005c7cd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_005c7cd0(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 0x66) != '\0') && (iVar1 = FUN_005c72f0(param_2,param_3), iVar1 != 1)) {
    return iVar1;
  }
  if ((*(char *)(param_1 + 0x67) != '\0') && (iVar1 = FUN_005c76f0(param_2,param_3), iVar1 != 1)) {
    return iVar1;
  }
  if ((*(char *)(param_1 + 0x60) != '\0') && (iVar1 = FUN_005c79f0(param_2,param_3), iVar1 != 1)) {
    return iVar1;
  }
  if ((*(char *)(param_1 + 0x61) != '\0') && (iVar1 = FUN_005c7400(param_2,param_3), iVar1 != 1)) {
    return iVar1;
  }
  if (((*(char *)(param_1 + 0x62) != '\0') && (*(char *)(param_1 + 0x51) != '\0')) &&
     (iVar1 = FUN_005c74e0(param_2), iVar1 != 1)) {
    return iVar1;
  }
  if (((*(char *)(param_1 + 99) != '\0') && (*(char *)(param_1 + 0x51) != '\0')) &&
     (iVar1 = FUN_005c78a0(param_2,param_3), iVar1 != 1)) {
    return iVar1;
  }
  if ((*(char *)(param_1 + 100) != '\0') && (iVar1 = CLoadNode_initAI(param_2), iVar1 != 1)) {
    return iVar1;
  }
  if ((*(char *)(param_1 + 0x65) != '\0') && (iVar1 = FUN_005c6960(param_2), iVar1 != 1)) {
    return iVar1;
  }
  if ((*(char *)(param_1 + 0x68) != '\0') && (iVar1 = FUN_005c69e0(param_2), iVar1 != 1)) {
    return iVar1;
  }
  if ((*(int *)(param_1 + 0x6c) != 0) && (iVar1 = FUN_005c6a10(param_2), iVar1 != 1)) {
    return iVar1;
  }
  if (*(char *)(param_1 + 0x51) == '\0') {
    (**(code **)(*(int *)(*(int *)(param_2[1] + 4) + 4 + (int)param_2) + 0xfc))();
    (**(code **)(*param_2 + 0x1c))(0);
  }
  return 2;
}
```
