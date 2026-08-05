# Raw capture: FUN_005d4cf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4cf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d4cf0` |
| **Canonical name** | `FUN_005d4cf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005d4cf0(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + -0xd8) != 0) {
    FUN_0053d520(param_2);
    (**(code **)(*(int *)(param_1 + -0xe0) + 0x44))();
    return;
  }
  FUN_00582d90(param_2);
  return;
}
```
