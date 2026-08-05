# Raw capture: FUN_005d6de0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6de0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d6de0` |
| **Canonical name** | `FUN_005d6de0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005d6de0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(char *)(param_1 + 0xb2) != '\0') {
    *(undefined1 *)(param_1 + 0xb2) = 0;
    FUN_004fc650(param_2,param_3,param_4,*(undefined1 *)(param_1 + 0xb3));
    *(undefined1 *)(param_1 + 0xb3) = 0;
  }
  return;
}
```
