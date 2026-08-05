# Raw capture: FUN_007fbd10

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbd10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fbd10` |
| **Canonical name** | `FUN_007fbd10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint FUN_007fbd10(void)

{
  uint uVar1;
  
  if (DAT_00d1b251 == 1) {
    return 1;
  }
  uVar1 = DAT_00d1b251 - 2;
  if (uVar1 != 0) {
    return uVar1 & 0xffffff00;
  }
  return 2;
}
```
