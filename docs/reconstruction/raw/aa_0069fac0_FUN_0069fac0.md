# Raw capture: FUN_0069fac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0069fac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0069fac0` |
| **Canonical name** | `FUN_0069fac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
char * FUN_0069fac0(void)

{
  char *pcVar1;
  char cVar2;
  char *in_EAX;
  int iVar3;
  char *unaff_EBX;
  
  iVar3 = isspace((int)*in_EAX);
  while (iVar3 != 0) {
    pcVar1 = in_EAX + 1;
    in_EAX = in_EAX + 1;
    iVar3 = isspace((int)*pcVar1);
  }
  sscanf(in_EAX,"%s");
  pcVar1 = unaff_EBX + 1;
  do {
    cVar2 = *unaff_EBX;
    unaff_EBX = unaff_EBX + 1;
  } while (cVar2 != '\0');
  return in_EAX + ((int)unaff_EBX - (int)pcVar1);
}
```
