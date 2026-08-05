# Raw capture: FUN_004ccf00

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ccf00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ccf00` |
| **Canonical name** | `FUN_004ccf00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_004ccf00(int param_1,uint param_2)

{
  if ((*(int *)(param_1 + 4) != 0) &&
     (param_2 < (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2))) {
    return *(int *)(param_1 + 4) + param_2 * 4;
  }
                    /* WARNING: Subroutine does not return */
  FUN_004ccf30();
}
```
