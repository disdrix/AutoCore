# Raw capture: FUN_0043edf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043edf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043edf0` |
| **Canonical name** | `FUN_0043edf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0043edf0(void)

{
  int in_EAX;
  
  FUN_00436030();
  FUN_00436030();
  FUN_00436030();
  FUN_00436030();
  return *(undefined4 *)(in_EAX + 4);
}
```
