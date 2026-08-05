# Raw capture: FUN_0040abd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040abd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040abd0` |
| **Canonical name** | `FUN_0040abd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0040abd0(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < 3)) {
    return *(undefined4 *)(param_1 + 0xd58 + param_2 * 4);
  }
  return 0xffffffff;
}
```
