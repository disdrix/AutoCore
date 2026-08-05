# Raw capture: FUN_005bfa60

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bfa60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005bfa60` |
| **Canonical name** | `FUN_005bfa60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005bfa60(int param_1)

{
  FUN_005bf720();
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x14));
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}
```
