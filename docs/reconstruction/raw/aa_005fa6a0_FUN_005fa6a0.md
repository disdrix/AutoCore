# Raw capture: FUN_005fa6a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fa6a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fa6a0` |
| **Canonical name** | `FUN_005fa6a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005fa6a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_009dd1f8;
  free((void *)param_1[8]);
  *param_1 = &PTR_LAB_009d7af4;
  return;
}
```
