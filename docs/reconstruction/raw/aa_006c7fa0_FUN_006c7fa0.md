# Raw capture: FUN_006c7fa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c7fa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c7fa0` |
| **Canonical name** | `FUN_006c7fa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006c7fa0(undefined4 *param_1,undefined4 param_2)

{
  *(undefined2 *)((int)param_1 + 6) = 1;
  param_1[2] = 0;
  param_1[3] = param_2;
  *param_1 = &PTR_FUN_00a0d610;
  return;
}
```
