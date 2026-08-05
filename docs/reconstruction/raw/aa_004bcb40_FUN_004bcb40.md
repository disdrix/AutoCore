# Raw capture: FUN_004bcb40

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcb40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bcb40` |
| **Canonical name** | `FUN_004bcb40` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __fastcall FUN_004bcb40(undefined4 *param_1)

{
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  *param_1 = &PTR_FUN_009cb334;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  *param_1 = &PTR_FUN_009cb378;
  return param_1;
}
```
