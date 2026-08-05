# Raw capture: FUN_005bf5e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bf5e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005bf5e0` |
| **Canonical name** | `FUN_005bf5e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __fastcall FUN_005bf5e0(undefined4 *param_1)

{
  FUN_00748960();
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  *(undefined1 *)(param_1 + 0x31) = 0;
  *(undefined1 *)((int)param_1 + 0xc5) = 0;
  *param_1 = &PTR_LAB_009d9d54;
  param_1[1] = &PTR_LAB_009d9d44;
  return param_1;
}
```
