# Raw capture: FUN_0083edd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083edd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0083edd0` |
| **Canonical name** | `FUN_0083edd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0083edd0(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *unaff_ESI;
  
  pcVar2 = unaff_ESI;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = (int)pcVar2 - (int)(unaff_ESI + 1);
  if ((0 < iVar3) && (unaff_ESI[iVar3 + -1] == '\n')) {
    unaff_ESI[iVar3 + -1] = '\0';
  }
  return;
}
```
