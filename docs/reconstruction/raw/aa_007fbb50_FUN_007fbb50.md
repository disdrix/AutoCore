# Raw capture: FUN_007fbb50

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbb50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fbb50` |
| **Canonical name** | `FUN_007fbb50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fbb50(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x30b8) = 1;
  *(undefined1 *)(in_EAX + 0x30b9) = 0;
  if (*(int **)(in_EAX + 0x30a4) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x30a4) + 4))(0);
  }
  return;
}
```
