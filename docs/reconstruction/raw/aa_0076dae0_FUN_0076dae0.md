# Raw capture: FUN_0076dae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076dae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0076dae0` |
| **Canonical name** | `FUN_0076dae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_0076dae0(void)

{
  if ((_DAT_00d1f8a4 & 1) == 0) {
    _DAT_00d1f8a4 = _DAT_00d1f8a4 | 1;
    DAT_00d1f898 = '\0';
    _DAT_00d1f89c = 0;
    _DAT_00d1f8a0 = 0;
    _atexit((_func_4879 *)&LAB_009c3280);
  }
  if (DAT_00d1f898 == '\0') {
    FUN_0076d6f0();
  }
  return &DAT_00d1f898;
}
```
