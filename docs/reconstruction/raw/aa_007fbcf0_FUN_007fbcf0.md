# Raw capture: FUN_007fbcf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbcf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fbcf0` |
| **Canonical name** | `FUN_007fbcf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_007fbcf0(void)

{
  int iVar1;
  
  if (DAT_00d1b252 == 1) {
    return 0x4b;
  }
  iVar1 = DAT_00d1b252 - 2;
  if (iVar1 != 0) {
    return CONCAT22((short)((uint)iVar1 >> 0x10),100);
  }
  return 0x32;
}
```
