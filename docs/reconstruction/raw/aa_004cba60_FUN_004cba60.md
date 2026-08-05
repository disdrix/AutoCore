# Raw capture: FUN_004cba60

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cba60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cba60` |
| **Canonical name** | `FUN_004cba60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004cba60(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_004cb680();
  if (*(undefined4 **)(param_1 + 0x10) != (undefined4 *)0x0) {
    free((void *)**(undefined4 **)(param_1 + 0x10));
    operator_delete__(*(void **)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}
```
