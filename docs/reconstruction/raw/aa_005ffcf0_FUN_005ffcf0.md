# Raw capture: FUN_005ffcf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffcf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ffcf0` |
| **Canonical name** | `FUN_005ffcf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005ffcf0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = param_1;
  uVar2 = FUN_00650290(param_1);
  FUN_0065ad10(&param_1,uVar2);
  if ((char)param_1 == '\0') {
    if (param_2 != 0) {
      uVar2 = FUN_00638140(param_2);
      FUN_00650210(iVar1,uVar2);
    }
    return;
  }
  uVar3 = FUN_0065acb0(uVar2);
  (**(code **)(*DAT_00b05060 + 4))(uVar3);
  if (param_1 != 0) {
    uVar3 = FUN_00638140(param_1);
    FUN_006501c0(uVar2,uVar3);
    return;
  }
  FUN_00650330(uVar2);
  return;
}
```
