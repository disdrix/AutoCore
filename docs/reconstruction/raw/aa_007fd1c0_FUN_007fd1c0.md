# Raw capture: FUN_007fd1c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fd1c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fd1c0` |
| **Canonical name** | `FUN_007fd1c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fd1c0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char *in_EAX;
  undefined4 unaff_ESI;
  int unaff_EDI;
  undefined4 unaff_retaddr;
  
  if (*(int *)(unaff_EDI + 0x30b0) != 0) {
    if ((in_EAX != (char *)0x0) && (*in_EAX != '\0')) {
      cVar1 = (**(code **)(**(int **)(unaff_EDI + 0x1168) + 0xd0))();
      if (cVar1 != '\0') {
        (**(code **)(**(int **)(unaff_EDI + 0x30b0) + 0x444))();
        FUN_0083e810(unaff_ESI,unaff_retaddr,param_1,param_2);
        *(undefined1 *)(unaff_EDI + 0x30be) = 0;
        *(undefined1 *)(unaff_EDI + 0x30bf) = 1;
        return;
      }
    }
    *(undefined1 *)(unaff_EDI + 0x30be) = 1;
    *(undefined1 *)(unaff_EDI + 0x30bf) = 0;
    if (*(int **)(unaff_EDI + 0x30b0) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_EDI + 0x30b0) + 4))(0);
    }
  }
  return;
}
```
