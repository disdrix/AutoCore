# Raw capture: FUN_007abfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007abfb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007abfb0` |
| **Canonical name** | `FUN_007abfb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007abfb0(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x22b) = *(undefined1 *)(in_EAX + 0xf8);
  *(undefined1 *)(in_EAX + 0x22f) = *(undefined1 *)(in_EAX + 0xfc);
  *(undefined1 *)(in_EAX + 0x233) = *(undefined1 *)(in_EAX + 0x100);
  return;
}
```
