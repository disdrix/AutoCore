# Raw capture: FUN_004bd6f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bd6f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bd6f0` |
| **Canonical name** | `FUN_004bd6f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004bd6f0(int *param_1)

{
  param_1[2] = DAT_00b03738;
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  *param_1 = *DAT_00b03730;
  param_1[1] = (int)DAT_00b03730;
  *DAT_00b03730 = (int)param_1;
  *(int **)(*param_1 + 4) = param_1;
  return;
}
```
