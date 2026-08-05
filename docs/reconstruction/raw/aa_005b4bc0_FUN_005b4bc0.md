# Raw capture: FUN_005b4bc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b4bc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b4bc0` |
| **Canonical name** | `FUN_005b4bc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __fastcall FUN_005b4bc0(undefined4 *param_1)

{
  FUN_00748960();
  *param_1 = &PTR_FUN_009d9924;
  param_1[1] = &PTR_LAB_009d9914;
  param_1[0x34] = 0xffffffff;
  param_1[0x35] = 0xffffffff;
  param_1[0x36] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x33) = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  return param_1;
}
```
