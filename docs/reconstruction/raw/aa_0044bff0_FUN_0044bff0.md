# Raw capture: FUN_0044bff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044bff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0044bff0` |
| **Canonical name** | `FUN_0044bff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0044bff0(void)

{
  undefined4 *in_EAX;
  
  if (in_EAX != (undefined4 *)0x0) {
    *in_EAX = DAT_00d21908;
    DAT_00d21908 = in_EAX;
  }
  return;
}
```
