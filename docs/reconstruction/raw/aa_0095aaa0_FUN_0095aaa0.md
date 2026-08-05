# Raw capture: FUN_0095aaa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0095aaa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0095aaa0` |
| **Canonical name** | `FUN_0095aaa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0095aaa0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00a152ec;
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete__((void *)param_1[1]);
  }
  param_1[1] = 0;
  if ((void *)param_1[2] != (void *)0x0) {
    operator_delete__((void *)param_1[2]);
  }
  param_1[2] = 0;
  return;
}
```
