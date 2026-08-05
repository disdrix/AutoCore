# Raw capture: FUN_0041aed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041aed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0041aed0` |
| **Canonical name** | `FUN_0041aed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0041aed0(void)

{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0x28) != '\0') {
    *(undefined1 *)(in_EAX + 0x28) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 4));
  }
  return;
}
```
