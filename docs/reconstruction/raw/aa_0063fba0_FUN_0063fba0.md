# Raw capture: FUN_0063fba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063fba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0063fba0` |
| **Canonical name** | `FUN_0063fba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0063fba0(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_009e3f9c;
  *(undefined2 *)((int)param_1 + 6) = 1;
  *(undefined2 *)((int)param_1 + 0xe) = 1;
  param_1[2] = &PTR_LAB_009e3f58;
  param_1[4] = 0;
  *(undefined2 *)((int)param_1 + 0x1a) = 1;
  param_1[5] = &PTR_LAB_009e3f80;
  param_1[7] = 0;
  param_1[4] = param_1;
  param_1[7] = param_1;
  return;
}
```
