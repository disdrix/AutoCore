# Raw capture: FUN_004bf7c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bf7c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bf7c0` |
| **Canonical name** | `FUN_004bf7c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004bf7c0(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[2] == 0) {
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(*(int *)(param_1 + 4) + 4);
    }
    else {
      *(undefined4 *)(param_2[2] + 4) = param_2[1];
    }
    if (param_2[1] != 0) {
      *(undefined4 *)(param_2[1] + 8) = param_2[2];
    }
    (**(code **)*param_2)(1);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
  }
  return;
}
```
