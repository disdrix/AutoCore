# Raw capture: FUN_007fbb30

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbb30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fbb30` |
| **Canonical name** | `FUN_007fbb30` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fbb30(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x30ba) = 1;
  *(undefined1 *)(in_EAX + 0x30bb) = 0;
  if (*(int **)(in_EAX + 0x30a8) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x30a8) + 4))(0);
  }
  return;
}
```
