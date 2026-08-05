# Raw capture: FUN_004bae00

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bae00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bae00` |
| **Canonical name** | `FUN_004bae00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_004bae00(int param_1,char param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == '\0') {
    if ((*(char *)(param_1 + 0xd) != '\0') && (*(int *)(param_1 + 8) != 0)) {
      FUN_00402c40();
      uVar1 = FUN_004bc530(param_3);
      *(undefined1 *)(*(int *)(param_1 + 8) + 0x1d) = 0;
      return uVar1;
    }
  }
  else if ((*(char *)(param_1 + 0xc) != '\0') && (*(int *)(param_1 + 4) != 0)) {
    FUN_00402c40();
    uVar1 = FUN_004bc530(param_3);
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x1d) = 0;
    return uVar1;
  }
  return 0;
}
```
