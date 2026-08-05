# Raw capture: FUN_008dbb50

| Field | Value |
|---|---|
| **Stable ID** | `aa_008dbb50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008dbb50` |
| **Canonical name** | `FUN_008dbb50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008dbb50(int *param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 local_8 [8];
  
  if (((char)param_1[0x146] == '\0') && (param_2 != '\0')) {
    piVar2 = (int *)(**(code **)(*param_1 + 0x120))(local_8,1,0);
    iVar1 = piVar2[1];
    param_1[0x147] = *piVar2;
    param_1[0x148] = iVar1;
  }
  *(char *)(param_1 + 0x146) = param_2;
  if (param_2 == '\0') {
    iVar1 = param_1[0x14b];
    if (iVar1 == 0) {
      FUN_008db370(1);
    }
    else {
      FUN_008db370(0);
    }
    FUN_008db2d0(iVar1 != 0);
    if ((int *)param_1[0x168] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x168] + 4))(0);
    }
    if ((int *)param_1[0x16a] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x16a] + 4))(0);
    }
    if ((int *)param_1[0x16b] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x16b] + 4))(0);
    }
    piVar2 = param_1 + 0x147;
  }
  else {
    FUN_008db370(0);
    FUN_008db2d0(0);
    if ((int *)param_1[0x168] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x168] + 4))(1);
    }
    piVar2 = param_1 + 0x149;
  }
  (**(code **)(*param_1 + 0x110))(piVar2);
  FUN_008db890();
  FUN_008db1e0();
  FUN_008db6d0();
  return;
}
```
