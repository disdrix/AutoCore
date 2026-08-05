# Raw capture: FUN_0040abb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040abb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040abb0` |
| **Canonical name** | `FUN_0040abb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0040abb0(undefined4 param_1,int param_2)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  
  if (in_EAX != (char *)0x0) {
    iVar2 = (param_2 + 0x1b0) - (int)in_EAX;
    do {
      cVar1 = *in_EAX;
      in_EAX[iVar2] = cVar1;
      in_EAX = in_EAX + 1;
    } while (cVar1 != '\0');
  }
  return;
}
```
