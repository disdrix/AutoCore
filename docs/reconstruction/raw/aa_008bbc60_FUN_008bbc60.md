# Raw capture: FUN_008bbc60

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bbc60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008bbc60` |
| **Canonical name** | `FUN_008bbc60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008bbc60(int *param_1,undefined4 param_2)

{
  FUN_008bb2c0();
  NDUIWindow_ReloadInterface(param_2);
  if (param_1[0x130] != 0) {
    (**(code **)(*param_1 + 0x448))();
    (**(code **)(*param_1 + 0x34c))();
  }
  return;
}
```
