# Raw capture: FUN_007fbaf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbaf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fbaf0` |
| **Canonical name** | `FUN_007fbaf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fbaf0(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x30be) = 1;
  *(undefined1 *)(in_EAX + 0x30bf) = 0;
  if (*(int **)(in_EAX + 0x30b0) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x30b0) + 4))(0);
  }
  return;
}
```
