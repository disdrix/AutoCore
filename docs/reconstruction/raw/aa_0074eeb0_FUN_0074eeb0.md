# Raw capture: FUN_0074eeb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074eeb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0074eeb0` |
| **Canonical name** | `FUN_0074eeb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0074eeb0(void)

{
  char cVar1;
  char *in_EAX;
  
  for (; ((((cVar1 = *in_EAX, cVar1 == ' ' || (cVar1 == ',')) || (cVar1 == '\n')) || (cVar1 == '\r')
          ) && (cVar1 != '\0')); in_EAX = in_EAX + 1) {
  }
  return;
}
```
