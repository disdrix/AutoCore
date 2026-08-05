# Raw capture: FUN_005acc30

| Field | Value |
|---|---|
| **Stable ID** | `aa_005acc30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005acc30` |
| **Canonical name** | `FUN_005acc30` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_005acc30(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)(param_1 + 0x6c) != '\0') {
    local_4 = param_3;
    local_8 = param_2;
    piVar2 = (int *)FUN_005ae140(&local_8);
    piVar1 = *(int **)(param_1 + 0x74);
    if (piVar2 != (int *)*piVar1) {
      FUN_005adff0();
    }
    if (piVar2 != piVar1) {
      return piVar2[6];
    }
  }
  return 0;
}
```
