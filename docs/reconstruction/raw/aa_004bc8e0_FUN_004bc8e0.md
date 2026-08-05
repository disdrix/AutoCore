# Raw capture: FUN_004bc8e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc8e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bc8e0` |
| **Canonical name** | `FUN_004bc8e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004bc8e0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_2 + 8) == 0) {
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0xc);
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 8) + 0xc) = *(undefined4 *)(param_2 + 0xc);
  }
  if (*(int *)(param_2 + 0xc) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0xc) + 8) = *(undefined4 *)(param_2 + 8);
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
    return;
  }
  uVar1 = *(undefined4 *)(param_2 + 8);
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  return;
}
```
