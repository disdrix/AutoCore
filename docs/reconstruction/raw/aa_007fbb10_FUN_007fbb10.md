# Raw capture: FUN_007fbb10

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbb10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fbb10` |
| **Canonical name** | `FUN_007fbb10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fbb10(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x30bc) = 1;
  *(undefined1 *)(in_EAX + 0x30bd) = 0;
  if (*(int **)(in_EAX + 0x30ac) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x30ac) + 4))(0);
  }
  return;
}
```
