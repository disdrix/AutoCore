# Raw capture: FUN_0089fef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0089fef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0089fef0` |
| **Canonical name** | `FUN_0089fef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0089fef0(void)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(in_EAX + 0x63c);
  iVar2 = 10;
  do {
    if ((*piVar1 != 0) && (*(char *)(*piVar1 + 0x4fc) != '\0')) {
      FUN_00826780(0);
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}
```
