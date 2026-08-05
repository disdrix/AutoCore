# Raw capture: FUN_005b0da0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b0da0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b0da0` |
| **Canonical name** | `FUN_005b0da0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005b0da0(int param_1)

{
  if (*(void **)(param_1 + 0x5c) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(param_1 + 0x5c));
  }
  *(undefined4 *)(param_1 + 0x5c) = 0;
  if (*(void **)(param_1 + 0x60) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(param_1 + 0x60));
  }
  *(undefined4 *)(param_1 + 0x60) = 0;
  return;
}
```
